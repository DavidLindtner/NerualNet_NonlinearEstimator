#include"EstimatedFunction.h"
#include<math.h>

double functionToEstimate(double in1, double in2)
{
	//return((0.3*in2 * in2 - 2 * in2 - 4) / (10 * exp(-sqrt(in1 + 20))));
	//return(sqrt(abs(in1)) + 0.1*in2*in2 - 0.3*in2 + 3);
	//return(exp(-in1) + in2 * in2 - 0.5 * in2 + 1.5);
	//return(in1 + in2 * in2 * 0.1 - 4.8);
	return(sqrt(abs(in1)) - 7*in2);
}
