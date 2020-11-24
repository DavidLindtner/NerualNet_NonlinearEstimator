#include<stdio.h>

#include"Net.h"
#include"Generation.h"


void testNet(struct Generation* gen,  double in1, double in2)
{
	int bestBrain = gen->bestBrains[0];

	setInput(&gen->brains[bestBrain], in1, in2);
	//gen->brains[bestBrain].realOutput = functionToEstimate(in1, in2);
	think(&gen->brains[bestBrain]);
	printf("IN1: %f, IN2: %f\n", in1, in2);
	printf("REAL OUTPUT: %f\nNEURAL OUTPUT: %f\n\n", functionToEstimate(in1, in2), gen->brains[bestBrain].neuraloutput);
}

int main(void)
{
	printf("Genetic Algorithm starts!\n");

	struct Generation generation;
	
	initGen(&generation);

	generationLive(&generation);
	selection(&generation);
	newGeneration(&generation);

	testNet(&generation, 3, 4);
	testNet(&generation, -2, 4);
	testNet(&generation, -3, 0.2);
	testNet(&generation, 1, 1);

	printf("Start to live\n");
	printf("Fitnesses:\n");
	for (int i = 0; i < 3000; i++)
	{
		generationLive(&generation);
		selection(&generation);
		newGeneration(&generation);
		if (i % 100 == 0)
			printf("%f, ", generation.fitnesses[generation.bestBrains[0]]);
	}

	generationLive(&generation);
	selection(&generation);

	printf("\nfitness\n");
	for (int i = 0; i < POPULATION_SIZE; i++)
		printf("%d, %f\n", generation.brains[i].index, generation.fitnesses[i]);

	printf("\nbest fitness\n");
	for (int i = 0; i < NO_BEST_BRAINS; i++)
		printf("%d\n", generation.bestBrains[i]);


	testNet(&generation, 3, 4);
	testNet(&generation, -2, 4);
	testNet(&generation, -13, 18);
	testNet(&generation, 1, 1);
	testNet(&generation, 1.3, -0.1);
	testNet(&generation, 0.6, 2.8);
	testNet(&generation, 1, -1.8);



	printf("DONE\n");

	return 0;
}





