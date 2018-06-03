#include "Graph.h"
#include "WaterCans.h"
#include "EightPuzzle.h"
#include "PathFinder.h"

void test();
void waterCan();
void pathFinding();
void puzzle();
int main() {
    puzzle();
//    waterCan();
//    g.breadthFirstSearchTree(0,1);
//    g.depthFirstSearch(0,2,8);


//    g.breadthFirstSearchTree(0,17);
//    g.twoDirectionalSearch(0,17);
//    test();
//    WaterCans waterCan(3,4,2);
//    waterCan.fill(waterCan.B);
//    waterCan.pour(waterCan.B,waterCan.A);
//    printf("can A: %d\ncan B: %d",waterCan.A->water,waterCan.B->water);
    return 0;
}
void pathFinding(){
    PathFinder init = PathFinder(15,20,0,0,14,19);
    init.makeWall(1,1);
    init.makeWall(2,2);
    init.makeWall(3,5);
    init.makeWall(7,8);
    init.makeWall(13,19);
    Problem e;
    e.pathFinder(init);
    Graph g(&e);
//    g.uniformCostSearch(0);
//    g.AStar(0);
    g.twoDirectionalSearch(0,299);

}
void waterCan(){
    WaterCans waterCans = WaterCans(3,4,2);
    Problem w;
    w.waterCans(waterCans);
    Graph g(&w);
    g.breadthFirstSearchTree(0);
//    g.depthFirstSearch(0,10,8);
//    g.breadthFirstSearchTree(0,17);
}
void puzzle(){
    EightPuzzle init = EightPuzzle();
    Problem e;
    e.eightPuzzle(init);
    Graph g(&e);
//    g.AStar(0);
//    g.breadthFirstSearchTree(0);
//    g.depthFirstSearch(0,8);
    g.AStar(0);
}
void test(){
//    Graph g("//home//arya11//ClionProjects//graphCol//Graph.txt");
    Graph g(15);
    g.addEdge(0, 1,true,3);
    g.addEdge(0, 2,true,5);
//    g.addEdge(1, 2,true,7);
//    g.addEdge(2, 0,true);
    g.addEdge(2, 3,true,9);
//    g.addEdge(3, 3,true,10);
    g.addEdge(1, 4,true,11);
    g.addEdge(1, 5,true,2);
    g.addEdge(5, 6,true,5);
    g.addEdge(6, 7,true,7);
    g.addEdge(6, 8,true,5);
    g.addEdge(8, 9,true,6);
    g.addEdge(8, 11,true,1);
    g.addEdge(8, 10,true,12);
    g.addEdge(8, 12,true,13);
    g.addEdge(8, 13,true,7);
    g.addEdge(8, 14,true,6);
//    g.depthFirstSearch(0);
//    g.printGraph();
//    g.breadthFirstSearch();
//    g.iterativeDeepeningDfs(0);
//    g.uniformCostSearch(0,10)
//    g.twoDirectionalSearch(0,10);
    int h[] = {26,23,28,30,30,22,15,22,9,13,0,12,14,15,16};
    g.breadthFirstSearch(0,10);
//    g.depthFirstSearch(0,10);
//    g.depthFirstSearch(0,10,5);
//    g.iterativeDeepeningDfs(0,10);
//    g.twoDirectionalSearch(0,10);
//    g.AStar(0,10);
//    g.uniformCostSearch(0,10);
//    g.breadthFirstSearchTree(0,10);
//    g.depthFirstSearchTree(0,10);
//    g.depthFirstSearchTree(0,10,5);
//    g.iterativeDeepeningDfsTree(0,10);
//    g.twoDirectionalSearchTree(0,10);
//    g.AStarTree(0,10);
//    g.uniformCostSearchTree(0,10);
}



