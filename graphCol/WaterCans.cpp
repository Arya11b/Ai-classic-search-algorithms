//
// Created by arya11 on 11/22/17.
//

#include <cstdio>
#include "WaterCans.h"
WaterCans::WaterCans(int capacityA, int capacityB,int goal) {
    A = new can(capacityA);
    B = new can(capacityB);
    this->goal = goal;
    nodeCount = (capacityA + 1) * (capacityB + 1);
}
WaterCans::WaterCans(int capacityA,int capacityB,int waterA,int waterB,int goal){
    A = new can(capacityA);
    B = new can(capacityB);
    this->goal = goal;
    nodeCount = (capacityA + 1) * (capacityB + 1);
    A->water = waterA;
    B->water = waterB;
}


void WaterCans::expand(Graph *g, Problem *p){
    int expandingNode = getCurrentNode();
    int acts = p->statesWc[0].possibleActions();
    printf("( %d , %d )\n",expandingNode / (p->statesWc[0].B->capacity + 1),expandingNode % (p->statesWc[0].B->capacity + 1));
    for (int i = 0; i < acts; ++i) {
        WaterCans temp(p->statesWc[expandingNode].A->capacity,p->statesWc[expandingNode].B->capacity,p->statesWc[expandingNode].A->water,p->statesWc[expandingNode].B->water,p->statesWc[expandingNode].goal);
        temp.doAction(i);
        int currentNode = temp.getCurrentNode();
        p->statesWc[currentNode] = temp;
        g->addEdgeWC(expandingNode,currentNode,false,i);
    }
}

int WaterCans::getNodeCount() {
    return nodeCount;
}
void WaterCans::pour(can* p, can* t) {
    if(t->capacity - t->water > p->water){
        t->water += p->water;
        p->water = 0;
    }else{
        p->water -= t->capacity - t->water;
        t->water = t->capacity;
    }
}

void WaterCans::fill(can* f){
    f->water = f->capacity;
}
void WaterCans::empty(can* e){
    e->water = 0;
}
bool WaterCans::goalState() {
    return B->water == goal;
}
int WaterCans::possibleActions() {
    return 6;
}
int WaterCans::getCurrentNode() {
    return A->water * (B->capacity + 1) + B->water;
}
void WaterCans::doAction(int action) {
    switch(action){
        case 0:
            fill(A);
            break;
        case 1:
            fill(B);
            break;
        case 2:
            pour(A,B);
            break;
        case 3:
            pour(B,A);
            break;
        case 4:
            empty(A);
            break;
        case 5:
            empty(B);
            break;
        default:
            break;
    }
}

WaterCans::WaterCans() {

}
WaterCans::~WaterCans() {
    A = 0;
    B = 0;
}
// 0,0 0
// 0,1 1
// 0,2 2
// 0,3 3
// 0,4 4
// 1,0 5
// 1,1 6
// 1,2 7
// 1,3 8
// 1,4 9
// 2,0 10
// 2,1 11
// 2,2 12
// 2,3 13
// 2,4 14
// 3,0 15
// 3,1 16
// 3,2 17
// 3,3 18
// 3,4 19
// i * 5 + j

