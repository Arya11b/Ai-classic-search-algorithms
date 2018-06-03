//
// Created by arya11 on 11/27/17.
//

#ifndef GRAPHCOL_PATHFINDER_H
#define GRAPHCOL_PATHFINDER_H

#include "Problem.h"

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
class Graph;
class Problem;
class PathFinder {
    static int** map;
    int positionX = 0;
    int positionY = 0;
    static int goalX;
    static int goalY;
    static int n;
public:
    PathFinder(int n,int m,int positionX,int positionY,int goalX,int goalY);
    PathFinder(int positionX,int positionY);
    void makeWall(int i,int j);
    bool isWall(int i,int j);
    int getPositionX();
    int getPositionY();
    void move(int direction);
    void doAction(int i);
    bool canMove(int direction);
    int getNodeCount();
    void expand(Graph *g,Problem* p);

    PathFinder(){};

    int getCurrentNode();

    bool canDoAction(int i);

    bool goalState();

    double calcH();

    static int m;
};


#endif //GRAPHCOL_PATHFINDER_H
