//
// Created by arya11 on 11/22/17.
//

#include <algorithm>
#include "Problem.h"
#include "PathFinder.h"


Problem::Problem() {
//    waterCans();
//    eightPuzzle();
}
//int Problem::getHeuristic(int node) {
//    epState[node].calcDistance();
//    return epState[node].sumDistance();
//}
void Problem::waterCans(WaterCans init){
    nodeCount = init.getNodeCount();
    statesWc=new WaterCans[nodeCount];
    statesWc[0] = init;
}
void Problem::eightPuzzle(EightPuzzle init){
    nodeCount = init.getNodeCount();
    epState=new EightPuzzle[nodeCount];
    epState[0] = init;
}
void Problem::pathFinder(PathFinder init) {
    nodeCount = init.getNodeCount();
    statesPF = new PathFinder[nodeCount];
    for (int i = 0; i < nodeCount; ++i) {
        statesPF[i] = PathFinder(i/PathFinder::m,i%PathFinder::m);
    }

}