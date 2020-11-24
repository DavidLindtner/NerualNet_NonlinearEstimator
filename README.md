# NerualNet NonlinearEstimator

Goal of the project is to implement a genetic learning algorighm in order to approximate any nonlinear function with 2 input variables.

## Neural Network

The nerual network is composed of 1 hidden layer. It is possible to adjust number of nodes of hidden layer with macro `NO_NEURONS` in file `Net.h`. The network has 1 output neuron.

## Nonlinear function

It is possible to change nonliear function which network is estimated. In the file `EstimatedFunction.c` you can uncomment one of multiple options or you can create your own nonlinear function. The current nonlinear function is:

$ y = \frac{0.3\cdot x_2^2 - 2\cdot x_2 - 4}{10\cdot e^{-\sqrt{x_1 + 20}}} $

