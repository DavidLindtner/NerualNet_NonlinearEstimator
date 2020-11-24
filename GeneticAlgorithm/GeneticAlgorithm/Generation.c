#include"Generation.h"
#include"Net.h"

void initGen(struct Generation* gen)
{
	for (int i = 0; i < POPULATION_SIZE; i++)
	{
		gen->brains[i].index = i;
		initNet(&gen->brains[i]);
	}
}

void generationLive(struct Generation* gen)
{
	for (int i = 0; i < POPULATION_SIZE; i++)
	{
		gen->brains[i].error = 0;
		for (int j = -10; j < 10; j++)
		{
			for (int k = -10; k < 10; k++)
			{
				setInput((&gen->brains[i]), j/2, k/2);
				//	count output and error of calculation of neural network
				think(&gen->brains[i]);
			}
		}
		//printf("Error: %f\n", gen->brains[i].error);
	}
	calculateFitness(gen);
}

void calculateFitness(struct Generation *gen)
{
	for (int i = 0; i < POPULATION_SIZE; i++)
		gen->fitnesses[i] = gen->brains[i].error;
}


void selection(struct Generation* gen)
{
	double fit[POPULATION_SIZE];
	//	copy fitness to temporary variable for fitness
	for (int i = 0; i < POPULATION_SIZE; i++)
		fit[i] = gen->fitnesses[i];

	//	find best brains of 1 generation and store it to array "bestBrains"
	for (int i = 0; i < NO_BEST_BRAINS; i++)
	{
		int location = 0;
		for (int j = 1; j < POPULATION_SIZE; j++)
			if (fit[j] < fit[location])
				location = j;
		fit[location] += 1E6;
		gen->bestBrains[i] = location;
	}
}


void newGeneration(struct Generation* gen)
{
	struct Generation copiedGen = *gen;

	//	get best brains into new generation without change
	for (int i = 0; i < NO_BEST_BRAINS; i++)
	{
		gen->brains[i] = copiedGen.brains[copiedGen.bestBrains[i]];
		gen->brains[i].index = i;
	}

	//	mutate best brains into new generation
	int j = 0;
	for (int i = NO_BEST_BRAINS; i < POPULATION_SIZE; i++)
	{
		gen->brains[i] = copiedGen.brains[copiedGen.bestBrains[j]];
		//mutateBrain(&copiedGen.brains[copiedGen.bestBrains[j]]);
		mutateBrain(&gen->brains[i]);
		gen->brains[i].index = i;
		j++;
		if (j >= NO_BEST_BRAINS)
			j = 0;
	}

}

void mutateBrain(struct Brain* brain)
{
	double range = MUTATION_STRENGTH;
	double weights[NO_NEURONS * NO_INPUTS + 2 * NO_NEURONS];

	for (int i = 0; i < NO_NEURONS * NO_INPUTS; i++)
		weights[i] = brain->weights1[i];

	for (int i = 0; i < NO_NEURONS; i++)
		weights[i + NO_NEURONS * NO_INPUTS] = brain->weights2[i];

	for (int i = 0; i < NO_NEURONS; i++)
		weights[i + NO_NEURONS + NO_NEURONS * NO_INPUTS] = brain->bias[i];

	int weightsLen = NO_NEURONS * NO_INPUTS + 2 * NO_NEURONS;
	int noOfMutaions = weightsLen * MUTATION_RATE;

	for (int i = 0; i < noOfMutaions; i++)
	{
		int index = rand() % (NO_NEURONS * NO_INPUTS + 2 * NO_NEURONS);
		double randNumber = randfrom(-range, range);
		weights[index] += randNumber;
	}


	for (int i = 0; i < NO_NEURONS * NO_INPUTS; i++)
		brain->weights1[i] = weights[i];

	for (int i = 0; i < NO_NEURONS; i++)
		brain->weights2[i] = weights[i + NO_NEURONS * NO_INPUTS];

	for (int i = 0; i < NO_NEURONS; i++)
		brain->bias[i] = weights[i + NO_NEURONS + NO_NEURONS * NO_INPUTS];



}