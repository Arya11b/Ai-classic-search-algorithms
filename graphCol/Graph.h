//
// Created by arya11 on 11/17/17.
//

#ifndef GRAPHCOL_GRAPH_H
#define GRAPHCOL_GRAPH_H

#include <string>
#include <list>
#include <stack>
#include <queue>
#include "Problem.h"

class Problem;
class PathFinder;

class Graph {
    Problem* problem;
    void doSearchStuff(int vertex);
    void printStack(std::stack<int> s);
    void printArray(int *arr,int length);
    bool overlappingVisited(bool *visited1, bool *visited2);
    int findMinimumWeightChilds(int* g,bool *visited);
    int findMinimumWeightChilds(int *g);
    int findMinimumWeightChilds(int *h, int *g);
    int findMinimumWeightChild(int vertex);
    void calculateHeuristic(int h[],int startingVertex,int targetVertex);
    int vertexNo;
    int** weightTable;
    std::list<int>* adjNodes;

public:
    int addNode();
    Graph(int vertexNo);
    Graph(Problem* problem);
    int getVertexNo();
    void addEdge(int n1, int n2,bool twoWays, int weight);
    void addEdge(int n1,int n2,bool twoWays);
    void depthFirstSearch(int startingVertex);
    void breadthFirstSearch(int startingVertex,int targetVertex);
    void depthFirstSearch(int startingVertex,int limit);
    void iterativeDeepeningDfs(int startingVertex,int targetVertex);
    void uniformCostSearch(int startingVertex);
    void twoDirectionalSearch(int startingVertex, int targetVertex);
    void AStar(int startingVertex);
    void printGraph();
    int findMinimumWeightChilds(int *h, int *g, bool *visited);
    void breadthFirstSearchTree(int startingVertex);
    void depthFirstSearchTree(int startingVertex, int targetVertex);
    void depthFirstSearchTree(int startingVertex, int targetVertex, int limit);
    void iterativeDeepeningDfsTree(int startingVertex, int targetVertex);
    void uniformCostSearchTree(int startingVertex, int targetVertex);
    void AStarTree(int startingVertex, int targetVertex);

    void printQueue(std::queue<int> q);

    void twoDirectionalSearchTree(int startingVertex, int targetVertex);

    void printAdjNodes(int node);

    void addEdgeWC(int n1, int n2, bool twoWays, int i);

    int findMinimumWeightChildsD(double *h, int *g, bool *visited);
};


#endif //GRAPHCOL_GRAPH_H
