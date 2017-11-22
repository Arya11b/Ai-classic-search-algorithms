#include "Graph.h"

int main() {
//    Graph g("//home//arya11//ClionProjects//graphCol//Graph.txt");
    Graph g(15);
    g.addEdge(0, 1,true,3);
    g.addEdge(0, 2,true,5);
    g.addEdge(1, 2,true,7);
//    g.addEdge(2, 0,true);
    g.addEdge(2, 3,true,9);
    g.addEdge(3, 3,true,10);
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
    g.heuristic = h;
    g.breadthFirstSearch(0,10);
    g.depthFirstSearch(0,10);
    g.depthFirstSearch(0,10,2);
    g.iterativeDeepeningDfs(0,10);
    g.twoDirectionalSearch(0,10);
    g.AStar(0,10);
    g.uniformCostSearch(0,10);
    return 0;
}