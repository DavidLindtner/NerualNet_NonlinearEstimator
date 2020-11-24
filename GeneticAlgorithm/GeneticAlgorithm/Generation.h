#ifndef __PROPAGATION_H__
#define __PROPAGATION_H__

#include"Net.h"
#include"EstimatedFunction.h"

#define POPULATION_SIZE 10
#define NO_BEST_BRAINS 3
#define MUTATION_STRENGTH 0.2
#define MUTATION_RATE 0.05


struct Generation
{
	struct Brain brains[POPULATION_SIZE];			//	array of brains of whole population
	double fitnesses[POPULATION_SIZE];				//	fitness of all brains
	int bestBrains[NO_BEST_BRAINS];					//	indexes of best brains
};

void initGen(struct Generation* gen);
void generationLive(struct Generation* gen);
void calculateFitness(struct Generation* gen);
void selection(struct Generation* gen);
void newGeneration(struct Generation* gen);
void mutateBrain(struct Brain* brain);

#endif __PROPAGATION_H__
