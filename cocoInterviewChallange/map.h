//
//  map.h
//  cocoInterviewChallange
//
//  Copyright © 2017 FangaiuihaCode. All rights reserved.
//

#ifndef map_h
#define map_h

#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

struct node
{
    node()
    {
        companyName = "";
        materialAmount = 0;
        materialCost = 0.0;
        next = prev = NULL;
    }
    
    node(string companyName, int materialAmount, double materialCost)
    {
        this->companyName = companyName;
        this->materialAmount = materialAmount;
        this->materialCost = materialCost;
    }
    
    
    string companyName;
    int materialAmount;
    double materialCost;
    node *next;
    node *prev;
};

class map
{
public:
    map()
    {
        head = NULL;
        tail = NULL;
        current = NULL;
        del = NULL;
        count = 0;
    }
    
    ~ map()
    {
        
    }
    
    void findBestCustomer(map *);
    
    node *head;
    node *tail;
    node *current;
    node *del;
    int count;
    
};

void map::findBestCustomer(map *mp)
{
    int materialCount;
    double materialCost;
    double bestCust = 0.0;
    double temp = 0.0;
    mp->current = mp->head;
    node *n;
    
    materialCount = mp->current -> materialAmount;
    materialCost = mp->current -> materialCost;
    bestCust = materialCost/materialCount;
    n = mp->head;
    
    for(int i = 0; i < mp->count; i++)
    {
        materialCount = mp->current -> materialAmount;
        materialCost = mp->current -> materialCost;
        
        temp = materialCost/materialCount;
        
        if(temp > bestCust)
        {
            bestCust = temp;
            n = mp->current;
        }
        
        mp->current = mp->current -> next;
    }
    
    cout << "The best customer for maximum profit is Company " << n->companyName << endl;
    cout << "at $" << setprecision(2) << fixed << temp << " per material" << endl;
    
}

#endif /* map_h */
