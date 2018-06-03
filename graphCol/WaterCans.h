//
// Created by arya11 on 11/22/17.
//

#ifndef GRAPHCOL_WATERCANPROBLEM_H
#define GRAPHCOL_WATERCANPROBLEM_H


#include "Problem.h"
class Graph;
class Problem;
class WaterCans{
    /*
             * each state is determined by how much water two cans contain
             * possible actions Are :
                *Filling can A or B
                * Emptying can A or B
                * Pouring from either Can A or B to the other
             * each state not be traversed further if it's a duplicate
             * goal state are the ones which can B has 4 litres of water
             */
    struct can{
    public:
        const int capacity;
        int water;
        can(int cap):capacity(cap),water(0){}
    };
    int nodeCount;

public:
    can* A;
    can* B;
    int goal;
    WaterCans(int capacityA,int capacityB,int goal);
    WaterCans(int capacityA,int capacityB,int waterA,int waterB,int goal);
    void pour(can* p,can* t);
    void fill(can* f);
    void empty(can* e);
    bool goalState();
    int getNodeCount();
    int possibleActions();
    int getCurrentNode();
    void doAction(int action);

    WaterCans();
    ~WaterCans();
    static void printWaterStuff(int node){
                printf("(can A: %d , can B: %d)\n",node / 5,node % 5);
    }
    static void printAction(int action){
        switch(action){
            case 0:
                printf("fill A:\n");
                break;
            case 1:
                printf("fill B:\n");
                break;
            case 2:
                printf("A->B:\n");
                break;
            case 3:
                printf("B->A:\n");
                break;
            case 4:
                printf("drain A:\n");
                break;
            case 5:
                printf("drain B:\n");
                break;
            default:
                break;
        }
    };

    void expand(Graph *g, Problem *p);
};


#endif //GRAPHCOL_WATERCANPROBLEM_H
