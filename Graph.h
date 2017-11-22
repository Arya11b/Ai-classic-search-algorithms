//
// Created by arya11 on 11/17/17.
//

#ifndef GRAPHCOL_GRAPH_H
#define GRAPHCOL_GRAPH_H

#include <string>
#include <list>
#include <stack>

class Graph {
    void readFromFile(std::string fileName);
    void doSearchStuff(int vertex);
    void printStack(std::stack<int> s);
    void printArray(int *arr,int length);
    bool overlappingVisited(bool *visited1, bool *visited2);
    int findMinimumWeightChilds(int* g,bool *visited);
    int findMinimumWeightChild(int vertex);
    void calculateHeuristic(int h[],int startingVertex,int targetVertex);
    int vertexNo;
    int** weightTable;
    std::list<int>* adjNodes;

public:
    int* heuristic;
    Graph(int vertexNo);
    Graph(std::string fileName);
    int getVertexNo();
    void addEdge(int n1, int n2,bool twoWays, int weight);
    void addEdge(int n1,int n2,bool twoWays);
    void depthFirstSearch(int startingVertex,int targetVertex);
    void breadthFirstSearch(int startingVertex,int targetVertex);
    void depthFirstSearch(int startingVertex,int targetVertex,int limit);
    void iterativeDeepeningDfs(int startingVertex,int targetVertex);
    void uniformCostSearch(int startingVertex,int targetVertex);
    void twoDirectionalSearch(int startingVertex, int targetVertex);
    void AStar(int startingVertex, int targetVertex);
    void printGraph();
    int findMinimumWeightChilds(int *h, int *g, bool *visited);
};


#endif //GRAPHCOL_GRAPH_H
