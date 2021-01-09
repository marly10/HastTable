//
// Created by Ricky Marly on 10/30/20.
//
#include "HashTable.h"
#include <iostream>
HashTable::HashTable()
{
    numberOfEntries = 0;
    sizeOfTable = 2;
    hashTable.resize(sizeOfTable);
}

void HashTable::insertTrainHash(Train* trainObject)
{
    insertHasData(trainObject, sizeOfTable);
}

void HashTable::reHashTable() //rehash the insert function
{
    vector<Train*> safetyVec;//temp storage for items

    for (int i = 0; i < hashTable.size(); i++)
    {
        for (int j = 0; j < hashTable[i].size(); j++)//loops all trains [index]
        {
            safetyVec.push_back(hashTable[i].at(j));;//push back all item in hashTable to safetyVec
        }
    }

    hashTable.erase(hashTable.begin(), hashTable.end());//erase old table for new
    sizeOfTable = sizeOfTable * 2;//Double sizeOfTable
    hashTable.resize(sizeOfTable);
    numberOfEntries = 0;//entries to 0

    for (int i = 0; i < safetyVec.size(); i++)//insert temp vector into new bigger table
    {
        insertTrainHash(safetyVec[i]);
    }
}


bool HashTable::insertHasData(Train* trainObject, int sizeOfTable)
{
    int locationOfIndex = trainObject->hash(sizeOfTable);
    bool find = false, boolItem = false;

    for(int i = 0; i < hashTable[locationOfIndex].size(); i++)//confirm the train in in index
    {
        if(hashTable[locationOfIndex].at(i)->getNum() == trainObject->getNum())
        {
            find = true;
        }
    }
    if(!find)//train does not exist in vector
    {
        vector<Train*>::iterator itrObject;//create a new vector and insert
        itrObject = hashTable[locationOfIndex].begin();
        hashTable[locationOfIndex].insert(itrObject,trainObject);
        numberOfEntries++;
        boolItem = true;
    }
    if (numberOfEntries > sizeOfTable * 2)
    {
        reHashTable();
    }
    return boolItem;
}

Train* HashTable::findHash(Train* trainObject)//find trains
{
    for(auto & i : hashTable)
    {
        for(auto & j : i)
        {
            if (j->getNum() == trainObject->getNum())//check if index match
            {
                return j;
            }
        }
    }
}

void HashTable::removeHash(Train* trainObject)//Remove should call find to determine if something is in the hash table
{
    Train* trainToFind = findHash(trainObject);//defining the train to find train

    if(trainToFind != nullptr)//checks if its in the vector
    {
        for(int i = 0; i < hashTable.size(); i++ )
        {
            for(int j = 0; j < hashTable[i].size(); j++)
            {
                if (hashTable[i].at(j)->getNum() == trainObject->getNum())//check if index match
                {
                    cout << "[TEST-PURPOSE][INFO] TRAIN was Found @ "<<hashTable[i].at(j)<< "\n";
                    vector<Train*>::iterator itrObj;//creates an iterator
                    itrObj = hashTable[i].begin();//sets itr to begining
                    advance(itrObj, j);//moves them forward
                    hashTable[i].erase(itrObj);//erases the found item
                }
            }
        }
    }

    else
    {
        cout << "[WARNING] Train IS NOT HERE!\n";
    }
}//end remove


void HashTable::printHashTable()//print function
{
    cout << hashTable;
}

ostream & operator << (ostream & out, vector<vector<Train*>> hashTable)
{

    for (int i = 0; i < hashTable.size(); i++)//loops through all item in the hashTable
    {
        out << i << ": ";
        //loops through all trains at a certain value of the table
        for (int j = 0; j < hashTable[i].size(); j++)
        {
            out << hashTable[i].at(j) << " ";
        }
        out << "\n";
    }
    return out;
}


