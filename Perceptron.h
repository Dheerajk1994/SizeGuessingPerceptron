#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <ctime>
#include <stdlib.h>

class Perceptron {

private:
	float weights[2];
	float learningRate = 0.1;

public:
	Perceptron(float f1, float f2) {
		//initialize the weights
		srand(time(NULL));
		weights[0] = f1;
		weights[1] = f2;
	}

	int guess(const float inputs[]) {
		float weightedSum = 0;
		weightedSum += (weights[0] * inputs[0]) + (weights[1] * inputs[1]);

		return (weightedSum >= 0) ? 1 : -1;
		 
	}

	void train(const float inputs[], const int targetAns) {
		int prediction = guess(inputs);

		//calculate error
		float error = targetAns - prediction;

		//tune weights 
		weights[0] += error * inputs[0] * learningRate;
		weights[1] += error * inputs[1] * learningRate;
	}

};

#endif // !PERCEPTRON_H
