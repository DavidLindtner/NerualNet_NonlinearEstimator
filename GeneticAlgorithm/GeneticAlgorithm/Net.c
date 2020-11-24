#include <time.h>
#include <stdlib.h>
#include <math.h>

#include "Net.h"
#include"EstimatedFunction.h"

void initNet(struct Brain* brain)
{
	time_t t;
	srand((unsigned)time(&t));

	brain->neuraloutput = 0;
	setWeights1(brain->weights1);
	setWeights2(brain->weights2);
	setBias(brain->bias);
}

double randfrom(double min, double max)
{
	double range = (max - min);
	double div = RAND_MAX / range;
	return min + (rand() / div);
}

void setWeights1(double* weights1)
{
	for (int i = 0; i < NO_INPUTS * NO_NEURONS; i++)
		*(weights1 + i) = randfrom(-1, 1);
}

void setWeights2(double* weights2)
{
	for (int i = 0; i < NO_NEURONS; i++)
		*(weights2 + i) = randfrom(-1, 1);
}

void setBias(double* bias)
{
	for (int i = 0; i < NO_NEURONS; i++)
		*(bias + i) = randfrom(-1, 1);
}

void setInput(struct Brain* brain, double in1, double in2)
{
	brain->input[0] = in1;
	brain->input[1] = in2;
}

void think(struct Brain* brain)
{
	double neuron[NO_NEURONS];
	brain->realOutput = functionToEstimate(brain->input[0], brain->input[1]) + randfrom(-1,1);

	for (int i = 0; i < NO_NEURONS; i++)
		neuron[i] = brain->input[0] * brain->weights1[i] + brain->input[1] * brain->weights1[i + NO_NEURONS] + brain->bias[i];

	brain->neuraloutput = 0;
	for (int i = 0; i < NO_NEURONS; i++)
		brain->neuraloutput += Sigmoid(neuron[i]) * brain->weights2[i];

	brain->error += (brain->neuraloutput - brain->realOutput) * (brain->neuraloutput - brain->realOutput);
}

double ReLU(double in)
{
	return max(0, in);
}

double Sigmoid(double in)
{
	return (1/(1+exp(-in)));
}