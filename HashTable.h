//
// Created by Ricky Marly on 10/30/20.
//
#include "vector"
#include "Train.h"
#include <iostream>

//hey man so th
//
//yes this is how we do our labs

#pragma once

class HashTable{
private:
    int numberOfEntries = 0;
    int sizeOfTable = 0;
    vector<vector<Train*>> hashTable;//vector<vector<Train*>> somethingLikeThisVector;
    bool insertHasData(Train* trainObject, int sizeOfTable);

public:
    HashTable();
    void insertTrainHash(Train* trainObject);
    void printHashTable();
    void reHashTable();
    void removeHash(Train *trainObject);
    Train *findHash(Train *trainObject);
};
ostream & operator << (ostream & out, vector<vector<Train*>> hashTable);