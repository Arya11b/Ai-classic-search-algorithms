//
// Created by arya11 on 11/27/17.
//

#include "PathFinder.h"
#include <math.h>

int** PathFinder::map;
int PathFinder::m;
int PathFinder::n;
int PathFinder::goalX;
int PathFinder::goalY;
PathFinder::PathFinder(int positionX,int positionY) {
    this->positionX = positionX;
    this->positionY = positionY;
}
PathFinder::PathFinder(int n, int m,int positionX,int positionY,int goalX,int goalY) {
    PathFinder::n = n;
    PathFinder::m = m;
    map = new int*[n];
    for (int i = 0; i <n ; ++i) {
        map[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            map[i][j] = 1;
        }
    }
    this->positionX = positionX;
    this->positionY = positionY;
    this->goalX = goalX;
    this->goalY = goalY;

}
void PathFinder::makeWall(int i, int j) {
    map[i][j] = 0;
}
int PathFinder::getPositionX() {
    return positionX;
}
int PathFinder::getPositionY() {
    return positionY;
}
bool PathFinder::isWall(int i,int j){
    return !map[i][j];
}
void PathFinder::move(int direction) {
    switch (direction){
        case UP:
            if(canMove(UP))
                positionX--;
            break;
        case DOWN:
            if(canMove(DOWN))
                positionX++;
            break;
        case LEFT:
            if(canMove(LEFT))
                positionY--;
            break;
        case RIGHT:
            if(canMove(RIGHT))
                positionY++;
            break;
        default:
            break;
    }
}
int PathFinder::getCurrentNode() {
    return positionX * m + positionY;
}
void PathFinder::expand(Graph* g,Problem* p) {
    int expandingNode = getCurrentNode();
    int actions = 4;
    printf("Current Position: (%d,%d)\n",this->positionX,this->positionY);
    for (int act = 0; act < actions; ++act) {
        PathFinder temp = PathFinder(positionX,positionY);
        if(temp.canDoAction(act)) {
            temp.doAction(act);
            int currentNode = temp.getCurrentNode();
            p->statesPF[currentNode] = temp;
            g->addEdge(expandingNode, currentNode, false);
        }
    }
}
bool PathFinder::goalState() {
    return positionX == goalX && positionY == goalY;
}
void PathFinder::doAction(int i){
    move(i);
}
bool PathFinder::canDoAction(int i){
    return canMove(i);
}
bool PathFinder::canMove(int direction) {
    switch (direction){
        case UP:
            if(positionX)
                if(map[positionX-1][positionY])
                    return true;
            break;
        case DOWN:
            if(positionX != n-1)
                if(map[positionX+1][positionY])
                    return true;
            break;
        case LEFT:
            if(positionY)
                if( map[positionX][positionY-1])
                return true;
            break;
        case RIGHT:
            if(positionY != m-1)
                if(map[positionX][positionY+1])
                return true;
            break;
        default:
            break;
    }
    return false;
}
int PathFinder::getNodeCount() {
    return PathFinder::m * PathFinder::n;
}

double PathFinder::calcH() {
    int xDist = (positionX-goalX)*(positionX-goalX);
    int yDist = (positionY-goalY)*(positionY-goalY);
    return sqrt(xDist+yDist);
}

