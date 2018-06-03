//
// Created by arya11 on 11/26/17.
//

#ifndef GRAPHCOL_EIGHTPUZZLE_H
#define GRAPHCOL_EIGHTPUZZLE_H


#include "Graph.h"

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3


class EightPuzzle {
 int zeroPosI;
 int zeroPosJ;
public:
    int puzzle[3][3];
    int distance[9] = {0};
    EightPuzzle();
    EightPuzzle(int Puzzle[3][3]);
    void swap(int direction);


    bool isGoalState();
    int possibleActions();
    bool existed(Problem *p,int node);
    int getNodeCount();
    bool isEqual(int puzzle[][3]);
    int calcDistance();

    int sumDistance();

    void expand(Graph *g, Problem *p,int node);

    bool canSwap(int direction);


    void printPuzzle(int node);

    void printPuzzle();
};


#endif //GRAPHCOL_EIGHTPUZZLE_H
