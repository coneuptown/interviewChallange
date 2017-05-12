//
//  main.cpp
//  cocoInterviewChallange
//
//  Created by Sione on 5/5/17.
//  Copyright © 2017 FangaiuihaCode. All rights reserved.
//

#include <iostream>
#include "map.h"
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
//#include "dataTable.txt"

using namespace std;

int main()
{
    map *mp = new map;
    string companyName;
    int materialCount;
    double materialCost;
    node *n;
    
    ifstream dataFile;
    dataFile.open("dataTable.txt", ios::in);
    
    while(dataFile >> companyName)
    {
        dataFile >> materialCount;
        dataFile >> materialCost;
        
        n = new node(companyName, materialCount, materialCost);
        
        if(mp->head == NULL)
        {
            mp->head = n;
            mp->tail = n;
            mp->current = n;
            
            n -> next = NULL;
            n -> prev = NULL;
            mp->count++;
        }
        else
        {
            mp->tail -> next = n;
            n -> prev = mp->tail;
            n -> next = mp->head;
            mp->tail = n;
            mp->count++;
        }

    }
    
    mp->findBestCustomer(mp);
    
    return 0;
    
}
