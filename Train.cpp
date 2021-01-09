#include "Train.h"

Train::Train(string name_in, int number_in)
{
	trainNumber = number_in;
	trainName = name_in;
}

int Train::getNum()
{
    return trainNumber;
}

unsigned int Train::hash(int tablesize)
{
	unsigned int value = trainNumber;
	for (int i = 0; i<trainName.size(); i++)
	{
		value += (trainNumber + 11) * value + trainName[i];
	}
	return value % tablesize;
}


ostream & operator << (ostream & out, Train * t)
{
	out << t->trainName << " " << t->trainNumber;
	return out;
}
