#ifndef TRAIN_H
#define TRAIN_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Train
{
public:
	string trainName;
	int trainNumber;

	Train(string name_in, int number_in);
	unsigned int hash(int tablesize);
    int getNum();
};

ostream & operator << (ostream & out, Train * t);

#endif