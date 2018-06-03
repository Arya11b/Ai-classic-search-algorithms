//
// Created by arya11 on 11/26/17.
//

#include <cstdio>
#include <cstdlib>
#include "EightPuzzle.h"
#include "Graph.h"

EightPuzzle::EightPuzzle() {
    puzzle[0][0] = 5;
    puzzle[0][1] = 1;
    puzzle[0][2] = 2;
    puzzle[1][0] = 3;
    puzzle[1][1] = 4;
    puzzle[1][2] = 0;
    puzzle[2][0] = 6;
    puzzle[2][1] = 7;
    puzzle[2][2] = 8;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if(!puzzle[i][j]){
                zeroPosI = i;
                zeroPosJ = j;
            }
//    srand(time(NULL));
//    for (int i = 0; i < 9; ++i)
//            puzzle[i/3][i%3] = (rand() % (9-i));
}
EightPuzzle::EightPuzzle(int puzzle[3][3]){
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            this->puzzle[i][j] = puzzle[i][j];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if(!puzzle[i][j]){
                zeroPosI = i;
                zeroPosJ = j;
            }
}
void EightPuzzle::swap(int direction) {
    switch (direction){
        case UP:
            if(zeroPosI){
                puzzle[zeroPosI][zeroPosJ] = puzzle[zeroPosI - 1][zeroPosJ];
                puzzle[--zeroPosI][zeroPosJ] = 0;
            }
            break;
        case DOWN:
            if((zeroPosI + 1)%3){
                puzzle[zeroPosI][zeroPosJ] = puzzle[zeroPosI + 1][zeroPosJ];
                puzzle[++zeroPosI][zeroPosJ] = 0;
            }
            break;
        case RIGHT:
            if((zeroPosJ + 1)%3){
                puzzle[zeroPosI][zeroPosJ] = puzzle[zeroPosI][zeroPosJ + 1];
                puzzle[zeroPosI][++zeroPosJ] = 0;
            }
            break;
        case LEFT:
            if(zeroPosJ){
                puzzle[zeroPosI][zeroPosJ] = puzzle[zeroPosI][zeroPosJ - 1];
                puzzle[zeroPosI][--zeroPosJ] = 0;
            }
            break;
        default:
            break;
    }
}
bool EightPuzzle::canSwap(int direction) {
    switch (direction){
        case UP:
            if(zeroPosI)
                return true;
            break;
        case DOWN:
            if(zeroPosI != 2)
                return true;
            break;
        case RIGHT:
            if(zeroPosJ != 2)
                return true;
            break;
        case LEFT:
            if(zeroPosJ)
                return true;
            break;
        default:
            break;
    }
    return false;
}
//void EightPuzzle::printPuzzle(){
//    for (int i = 0; i < 3; ++i) {
//        for (int j = 0; j < 3; ++j)
//            printf("%d ", puzzle[i][j]);
//        printf("\n");
//    }
//}
int EightPuzzle::possibleActions() {
    return 4;
}
bool EightPuzzle::isGoalState() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if(puzzle[i][j] != i*3 + j)
                return false;
    return true;
}
int EightPuzzle::calcDistance(){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(puzzle[i][j] == 0)
                continue;
            int I = i - (puzzle[i][j] / 3);
            int J = j - (puzzle[i][j] % 3);
            if(I<0)
                I=-I;
            if(J<0)
                J=-J;
            distance[puzzle[i][j]] = I + J;
        }
    }
}
int EightPuzzle::sumDistance(){
    int sum =0;
    calcDistance();
    for (int i = 0; i < 9; ++i)
        sum += distance[i];
    return sum;
}

void EightPuzzle::printPuzzle(){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ",puzzle[i][j]);
        }
        printf("\n");
    }
}
void EightPuzzle::expand(Graph *g, Problem* p,int node){
    int expandingNode = node;
    int acts = possibleActions();
    printPuzzle();
    printf("\n");
//    printf("( %d , %d )\n",node / (epState[0].B->capacity + 1),node % (epState[0].B->capacity + 1));
    for (int i = 0; i < acts; ++i) {
        EightPuzzle temp(puzzle);
//        temp.printPuzzle();
        temp.swap(i);
//        printf("%d\n",i);
        if (canSwap(i)) {
//            temp.printPuzzle();
//            printf("\n");
            int currentNode = g->addNode();
            if (!temp.existed(p, currentNode)) {
                p->epState[currentNode] = temp;
                g->addEdge(expandingNode, currentNode, false);
            }
        }
    }
}

bool EightPuzzle::isEqual(int puzzle[][3]){
//    for (int i = 0; i < 3; ++i) {
//        for (int j = 0; j < 3; ++j)
//            printf("Wat?! %d %d ", this->puzzle[i][j], puzzle[i][j]);
//        printf("\n");
//    }
//    printf("\n");
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (this->puzzle[i][j] != puzzle[i][j])
                return false;
    return true;
}
int EightPuzzle::getNodeCount() {
    return 20000;
}
bool EightPuzzle::existed(Problem* p,int node){
    for (int k = 0; k < node;k++)
        if (isEqual(p->epState[k].puzzle))
            return true;
    return false;
}

