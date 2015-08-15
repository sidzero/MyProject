
#include <stdio.h>
#include<iostream>
#include <random>
#include<time.h>
using namespace std;
int main()
{
	default_random_engine randomGenerator(time(0));
	uniform_real<float> attack(0.0f,1.0f);

	cout << "attack"<<attack(randomGenerator)<<"\n";

	system("PAUSE");
	return 0;
}