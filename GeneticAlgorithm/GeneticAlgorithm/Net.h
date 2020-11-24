#ifndef __NET_H__
#define __NET_H__

#define NO_NEURONS 5
#define NO_INPUTS 2

struct Brain
{
	int index;
	double input[NO_INPUTS];
	double weights1[NO_NEURONS * NO_INPUTS];
	double weights2[NO_NEURONS];
	double bias[NO_NEURONS];
	double realOutput;
	double neuraloutput;
	double error;
};

void initNet(struct Brain* brain);
double randfrom(double min, double max);
void setWeights1(double* weights1);
void setWeights2(double* weights2);
void setBias(double* bias);
void setInput(struct Brain* brain, double in1, double in2);
void think(struct Brain* brain);

double ReLU(double in);
double Sigmoid(double in);

#endif __NET_H__