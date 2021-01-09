//
// Created by Ricky Marly on 10/30/20.
//

#include <iostream>
#include <string>
#include "Train.h"
#include "HashTable.h"

using namespace std;

int main() {
    

    //Create trains “4-4-2” with number 343, “2-8-0” with number 344, and “4-0-4” with number 345.
    auto *trainNumber1 = new Train("4-4-2", 343);
    auto *trainNumber2 = new Train("2-8-0", 344);
    auto *trainNumber3 = new Train("4-0-4", 345);

    //•	Create a hash table, print it out.
    HashTable hashVariable;
    hashVariable.printHashTable();

    //•	Insert the three trains, print the hash table out.
    cout << "original print: \n";
    hashVariable.insertTrainHash(trainNumber1);
    hashVariable.insertTrainHash(trainNumber2);
    hashVariable.insertTrainHash(trainNumber3);

    hashVariable.printHashTable();

    //Then add the three trains again and print it out again.

    hashVariable.insertTrainHash(trainNumber1);
    hashVariable.insertTrainHash(trainNumber2);
    hashVariable.insertTrainHash(trainNumber3);
    
    hashVariable.printHashTable();

    //Add in some more trains! “2-8-0” 1, “2-8-0” 2, “2-8-0” 3, “12-0-0” 42, “12-0-12” 84, “2-2” 2, and “4-4” 4.
    auto *trainNumber4 = new Train("2-8-0", 1);
    auto *trainNumber5 = new Train("2-8-0", 2);
    auto *trainNumber6 = new Train("2-8-0", 3);
    auto *trainNumber7 = new Train("12-0-0", 42);
    auto *trainNumber8 = new Train("12-0-12", 84);
    auto *trainNumber9 = new Train("2-2", 2);
    auto *trainNumber10 = new Train("4-4", 4);

    //Then print out the new table.
    cout << "\nprint after adding more trains:\n";
    hashVariable.insertTrainHash(trainNumber4);
    hashVariable.insertTrainHash(trainNumber5);
    hashVariable.insertTrainHash(trainNumber6);
    hashVariable.insertTrainHash(trainNumber7);
    hashVariable.insertTrainHash(trainNumber8);
    hashVariable.insertTrainHash(trainNumber9);
    hashVariable.insertTrainHash(trainNumber10);
    hashVariable.printHashTable();

    //•	Remove the first three trains from the hash table.
    cout << "\nprint after deleting the trains:\n";
    hashVariable.removeHash(trainNumber1);
    hashVariable.removeHash(trainNumber2);
    hashVariable.removeHash(trainNumber3);

    //•	Then print again.
    hashVariable.printHashTable();

    //Create a new train, “2-8-0” 99, and remove it from the list.
    auto *trainNumber11 = new Train("2-8-0", 99);
    hashVariable.removeHash(trainNumber11);

    //Then print again.
    cout << "\nThen print again:\n";
    hashVariable.printHashTable();


    return 0;
}
