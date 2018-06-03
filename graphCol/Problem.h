//
// Created by arya11 on 11/22/17.
//

#ifndef GRAPHCOL_PROBLEM_H
#define GRAPHCOL_PROBLEM_H
#include <list>
#include "Graph.h"
#include "WaterCans.h"
#include "EightPuzzle.h"
#include "PathFinder.h"

class WaterCans;
class Graph;
class EightPuzzle;

class Problem {
public:
    Problem();

    WaterCans* statesWc; // further adjustments needed.
    EightPuzzle* epState; // further adjustments needed.
    PathFinder* statesPF;
    void eightPuzzle(EightPuzzle init);
    void pathFinder(PathFinder init);

    int getHeuristic(int node);

//    void printPuzzle(int node);

    int nodeCount;

    void waterCans(WaterCans init);
};


#endif //GRAPHCOL_PROBLEM_H
