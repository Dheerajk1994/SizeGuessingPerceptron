#include "Perceptron.h"
#include "DataPoint.h"

#include <iostream>
#include <random>


int main() {

	const int DATA_SIZE = 1000;

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<float> weightDist(-1.0, 1.0);
	std::uniform_real_distribution<float> dataPointDist(-1.0, 1.0);

	DataPoint data[DATA_SIZE];

	for (int i = 0; i < DATA_SIZE; i++) {
		data[i].setData(dataPointDist(mt), dataPointDist(mt));
	}

	//initialize perceptron
	Perceptron *p = new Perceptron(weightDist(mt), weightDist(mt));

	std::cout << "BEFORE TRAINING:\n";
	for (int i = 0;  i < DATA_SIZE; ++i)
	{
		float input[2] = { data[i].x, data[i].y };
		int prediction = p->guess(input);
		std::cout << "x: " << data[i].x << "\t y: " << data[i].y << "\t guess: " << prediction << "\t ";
		(prediction == data[i].label) ? std::cout << "correct guess\n" : std::cout << "wrong guess\n";
	}

	for (int i = 0; i < DATA_SIZE; ++i)
	{
		float input[2] = { data[i].x, data[i].y };
		p->train(input, data[i].label);
	}

	std::cout << "AFTER TRAINING:\n";
	for (int i = 0; i < DATA_SIZE; ++i)
	{
		float input[2] = { data[i].x, data[i].y };
		int prediction = p->guess(input);
		std::cout << "x: " << data[i].x << "\t y: " << data[i].y << "\t guess: " << prediction << "\t ";
		(prediction == data[i].label) ? std::cout << "correct guess\n" : std::cout << "wrong guess\n";
	}

	system("PAUSE");
	return 0;
}


