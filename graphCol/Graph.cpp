//
// Created by arya11 on 11/17/17.
//

#include "Graph.h"
#include <iostream>
#include "Problem.h"
#include <string.h>
#include <queue>
#include <cstring>
#include <fstream>
#include <stack>

Graph::Graph(int vertexNo){
    this->vertexNo = vertexNo;
    adjNodes = new std::list<int>[vertexNo];
    weightTable = new int*[vertexNo];
    for (int i = 0; i < vertexNo; ++i) {
        weightTable[i] = new int[vertexNo];
        for (int j = 0; j < vertexNo; ++j)
            weightTable[i][j] = 0;
    }
}
Graph::Graph(Problem* problem){
    this->problem = problem;
    vertexNo = problem->nodeCount;
    adjNodes = new std::list<int>[vertexNo];
    weightTable = new int*[vertexNo];
    for (int i = 0; i < vertexNo; ++i) {
        weightTable[i] = new int[vertexNo];
        for (int j = 0; j < vertexNo; ++j)
            weightTable[i][j] = 0;
    }

}
void Graph::printAdjNodes(int node){
    printf("Adj nodes: ");
    for (int i: adjNodes[node])
        printf("%d ",i);
    printf("\n");
}
void Graph::breadthFirstSearch(int startingVertex,int targetVertex){
    printf("Breadth First Search Route:\n");
    bool visited[vertexNo] = {false};
    std::queue<int> q;
    q.push(startingVertex);
    visited[startingVertex] = true;
//    doSearchStuff(0);
    while (!q.empty()) {
//        problem->wcExpand(this, q.front());
//        printAdjNodes(q.front());
        for (int i: adjNodes[q.front()]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
        doSearchStuff(q.front());
//        if(q.front() == targetVertex)
//            break;
        q.pop();
        printQueue(q);
    }
    printf("\n");
}
void Graph::breadthFirstSearchTree(int startingVertex){
    printf("Breadth First Search (tree) Route:\n");
    std::queue<int> q;
    q.push(startingVertex);
//    doSearchStuff(0);
    while (!q.empty()) {
//        problem->statesWc[q.front()].expand(this, problem);           for WaterCans
        printf("node: %d\n",q.front());
        problem->epState[q.front()].expand(this,problem,q.front());
        for (int i: adjNodes[q.front()])
                q.push(i);
        doSearchStuff(q.front());
//        if(problem->statesWc[q.front()].goalState())
        if (problem->epState[q.front()].isGoalState())
            break;
        q.pop();
    }
    printf("\n");
}
void Graph::depthFirstSearch(int startingVertex){
    int targetVertex = 10;
    printf("Depth First Search Route:\t");
    bool visited[vertexNo] = {false};
    bool allChildNodesVisited;
    std::stack<int> s;
    s.push(startingVertex);
    visited[startingVertex] = true;
    doSearchStuff(startingVertex);
    while (!s.empty()) {
        allChildNodesVisited = true;
        int curr = vertexNo;
        for (int i: adjNodes[s.top()]) {
            if (!visited[i]) {
                s.push(i);
                visited[i] = true;
                doSearchStuff(i);
                allChildNodesVisited = false;
                curr = i;
                break;
            }
        }
        if (targetVertex == curr)
            break;
        if(allChildNodesVisited)
            s.pop();
    }
    printf("\n");
}
void Graph::depthFirstSearchTree(int startingVertex,int targetVertex){
    printf("Depth First Search (tree) Route:\t");
    bool allChildNodesVisited;
    std::stack<int> s;
    s.push(startingVertex);
    doSearchStuff(startingVertex);
    while (!s.empty()) {
        allChildNodesVisited = true;
        int curr = vertexNo;
        for (int i: adjNodes[s.top()]) {
                s.push(i);
                doSearchStuff(i);
                allChildNodesVisited = false;
                curr = i;
                break;
        }
        if (targetVertex == curr)
            break;
        if(allChildNodesVisited)
            s.pop();
    }
    printf("\n");
}
void Graph::depthFirstSearch(int startingVertex,int limit){
    printf("Depth First Search (Limit: %d) Route:\t",limit);
    bool visited[vertexNo] = {false};
    bool allChildNodesVisited = false;
    int depth = 0;
    std::stack<int> s;
    s.push(startingVertex);
    visited[startingVertex] = true;
    doSearchStuff(startingVertex);
    problem->epState[startingVertex].expand(this,problem,startingVertex);

//    problem->epExpand(this,startingVertex);
    while (!s.empty()) {
        int curr = vertexNo;
        allChildNodesVisited = true;
        for (int i: adjNodes[s.top()]) {
            if (!visited[i] && limit > depth) {
                depth++;
                s.push(i);
                visited[i] = true;
                doSearchStuff(i);
                problem->epState[i].expand(this,problem,startingVertex);
//                problem->epExpand(this,i);
                allChildNodesVisited = false;
                curr = i;
                break;
            }
        }
        if(problem->epState[curr - 1].isGoalState()) {
            printf("goal found");
//            printStack(s);
            return;
        }
        if(allChildNodesVisited) {
            s.pop();
            depth--;
        }
    }
    printf("\ntarget not found.\n");

}
void Graph::depthFirstSearchTree(int startingVertex,int targetVertex,int limit){
    printf("Depth First Search (Limit: %d) (tree) Route:\t",limit);
    bool allChildNodesVisited = false;
    int depth = 0;
    std::stack<int> s;
    s.push(startingVertex);
    doSearchStuff(startingVertex);
    while (!s.empty()) {
        int curr = vertexNo;
        allChildNodesVisited = true;
        for (int i: adjNodes[s.top()]) {
            if (limit > depth) {
                depth++;
                s.push(i);
                doSearchStuff(i);
                allChildNodesVisited = false;
                curr = i;
                break;
            }
        }
        if(targetVertex == curr) {
            printf("\ntarget %d found.\n",targetVertex);
            return;
        }
        if(allChildNodesVisited) {
            s.pop();
            depth--;
        }
    }
    printf("\ntarget not found.\n");
}
void Graph::iterativeDeepeningDfs(int startingVertex,int targetVertex){
    printf("Iterative Deepening Depth First Search Route:\n");
    for (int n = 0; n < vertexNo; ++n) {
        bool visited[vertexNo] = {false};
        bool allChildNodesVisited = false;
        int depth = 0;
        std::stack<int> s;
        s.push(startingVertex);
        visited[startingVertex] = true;
        doSearchStuff(startingVertex);
        while (!s.empty()) {
            int curr = vertexNo;
            allChildNodesVisited = true;
            for (int i: adjNodes[s.top()]) {
                if (!visited[i] && n > depth) {
                    depth++;
                    s.push(i);
                    visited[i] = true;
                    doSearchStuff(i);
                    allChildNodesVisited = false;
                    curr = i;
                    break;
                }
            }
            if(targetVertex == curr) {
                printf("\ntarget %d found in depth %d.\n",targetVertex,n);
                return;
            }
            if(allChildNodesVisited) {
                s.pop();
                depth--;
            }
        }
        printf("\n");
    }
}
void Graph::iterativeDeepeningDfsTree(int startingVertex,int targetVertex){
    printf("Iterative Deepening Depth First Search (tree) Route:\n");
    for (int n = 0; n < vertexNo; ++n) {
        bool allChildNodesVisited = false;
        int depth = 0;
        std::stack<int> s;
        s.push(startingVertex);
        doSearchStuff(startingVertex);
        while (!s.empty()) {
            int curr = vertexNo;
            allChildNodesVisited = true;
            for (int i: adjNodes[s.top()]) {
                if (n > depth) {
                    depth++;
                    s.push(i);
                    doSearchStuff(i);
                    allChildNodesVisited = false;
                    curr = i;
                    break;
                }
            }
            if(targetVertex == curr) {
                printf("\ntarget %d found in depth %d.\n",targetVertex,n);
                return;
            }
            if(allChildNodesVisited) {
                s.pop();
                depth--;
            }
        }
        printf("\n");
    }
}
void Graph::uniformCostSearch(int startingVertex){
    printf("Uniform Cost Route:\t");
    bool visited[vertexNo] = {false};
    int g[vertexNo] = {0};
    visited[startingVertex] = true;
    int v = startingVertex;
    problem->statesPF[v].expand(this,problem);
    while (!problem->statesPF[v].goalState()) {
        doSearchStuff(v);
        v = findMinimumWeightChilds(g,visited);
        visited[v] = true;
        problem->statesPF[v].expand(this,problem);
    }
    printf("\ng(n) Completed Array: ");
    printArray(g,vertexNo);
}
void Graph::uniformCostSearchTree(int startingVertex,int targetVertex){
    printf("Uniform Cost (tree) Route:\t");
    int g[vertexNo] = {0};
    int v = startingVertex;
    while (v != targetVertex) {
        doSearchStuff(v);
        v = findMinimumWeightChilds(g);
    }
    printf("\ng(n) Completed Array: ");
    printArray(g,vertexNo);
    printf("target vertex: %d with %d cost.\n",targetVertex,g[targetVertex]);

}
void Graph::twoDirectionalSearch(int startingVertex,int targetVertex){
    printf("two directional Depth First Search Route:\t");
    bool visited1[vertexNo] = {false};
    bool visited2[vertexNo] = {false};
    std::queue<int> q1,q2;
    q1.push(startingVertex);
    problem->statesPF[q1.front()].expand(this,problem);
    visited1[startingVertex] = true;
    q2.push(targetVertex);
    problem->statesPF[q2.front()].expand(this,problem);
    visited2[targetVertex] = true;
    while (!q1.empty() || !q2.empty()) {
//        problem->wcExpand(this, q1.front());
        for (int i: adjNodes[q1.front()]) {
            if (!visited1[i]) {
                q1.push(i);
                problem->statesPF[q1.back()].expand(this,problem);
                visited1[i] = true;
            }
        }
//        problem->wcExpand(this, q2.front());
        for (int i: adjNodes[q2.front()]) {
            if (!visited2[i]) {
                q2.push(i);
                problem->statesPF[q2.back()].expand(this,problem);
                visited2[i] = true;
            }
        }
        printf("\nSearching Route1: ");
        doSearchStuff(q1.front());
        printf("\tSearching Route2: ");
        doSearchStuff(q2.front());
        q1.pop();
        q2.pop();
        printf("Queue 1:");
        printQueue(q1);
        printf("Queue 2:");
        printQueue(q2);
        if (overlappingVisited(visited1,visited2)) {
            printf("\nFirst Route: ");
            printQueue(q1);
            printf("Second Route: ");
            printQueue(q2);
            break;
        }
    }
}
void Graph::twoDirectionalSearchTree(int startingVertex,int targetVertex){
    printf("two directional Depth First Search (tree) Route:\t");
    std::queue<int> q1,q2;
    q1.push(startingVertex);
    q2.push(targetVertex);
    while (!q1.empty() || !q2.empty()) {
        for (int i: adjNodes[q1.front()])
                q1.push(i);
        for (int i: adjNodes[q2.front()])
                q2.push(i);
        printf("\nSearching Route1: ");
        doSearchStuff(q1.front());
        printf("\tSearching Route2: ");
        doSearchStuff(q2.front());
        int v1 = q1.front();
        int v2 = q2.front();
        q1.pop();
        q2.pop();
        if (v1 == v2) {
            printf("\nFirst Route: ");
            printQueue(q1);
            printf("Second Route: ");
            printQueue(q2);
            break;
        }
    }
}
void Graph::AStar(int startingVertex){
    printf("A* Algorithm: \n");
    bool visited[vertexNo] = {false};
    int g[vertexNo] = {0};
//    double h[vertexNo] = {0};
    int h[vertexNo] = {0};
    visited[startingVertex] = true;
    int v = startingVertex;
//    h[v] = problem->statesPF[v].calcH();
//    problem->statesPF[v].expand(this,problem); //PFF
    h[v] = problem->epState[v].sumDistance();
    problem->epState[v].expand(this,problem,v);
//    while (!problem->statesPF[v].goalState()) {
    while (!problem->epState[v].isGoalState()) {
//        h[v] = problem->getHeuristic(startingVertex);
        doSearchStuff(v);
        v = findMinimumWeightChilds(h,g,visited);
//        h[v] = problem->statesPF[v].calcH();
        h[v] = problem->epState[v].sumDistance();
        visited[v] = true;
        problem->epState[v].expand(this,problem,v);
//        problem->statesPF[v].expand(this,problem);
//        printf("H(n): %f,G(n): %d \n",h[v],g[v]);
        printf("H(n): %d,G(n): %d \n",h[v],g[v]);
        printf("----------------------\n");
    }
    int f[vertexNo] = {0};
    int index = addNode();
    for (int i = 0; i <index; ++i)
        f[i] = (int) (g[i] + h[i]);
    printf("\nf(n) Completed Array: ");
    printArray(f,vertexNo);
}
void Graph::AStarTree(int startingVertex,int targetVertex){
    printf("A* Algorithm (tree): ");
    int g[vertexNo] = {0};
    int h[vertexNo] = {0};
//    calculateHeuristic(h,startingVertex,targetVertex);
    int v = startingVertex;
    while (v != targetVertex) {
        doSearchStuff(v);
        v = findMinimumWeightChilds(h,g);
    }
    int f[vertexNo] = {0};
    for (int i = 0; i < vertexNo; ++i)
        f[i] = g[i] + h[i];
    printf("\nf(n) Completed Array: ");
    printArray(f,vertexNo);
    printf("target vertex: %d with %d cost.\n",targetVertex,g[targetVertex]);
}
bool Graph::overlappingVisited(bool* visited1,bool* visited2){
    for (int i = 0; i < vertexNo; ++i)
        if (visited1[i] && visited2[i])
            return true;
    return false;
}
void Graph::doSearchStuff(int vertex){
//    printf("%d ",vertex);
//    problem->printPuzzle(vertex);
}
void Graph::addEdge(int n1, int n2,bool twoWays) {
    for (int i:adjNodes[n1])
        if(n2 == i)
            return;
    adjNodes[n1].push_back(n2);
    if(twoWays) {
        for (int i:adjNodes[n2])
            if (n1 == i)
                return;
        adjNodes[n2].push_back(n1);
        weightTable[n2][n1] = 1;
    }
    weightTable[n1][n2] = 1;
}
void Graph::addEdgeWC(int n1, int n2,bool twoWays,int i) {
    for (int i:adjNodes[n1])
        if(n2 == i)
            return;
    adjNodes[n1].push_back(n2);
    WaterCans::printAction(i);
    if(twoWays) {
        for (int i:adjNodes[n2])
            if (n1 == i)
                return;
        adjNodes[n2].push_back(n1);
        weightTable[n2][n1] = 1;
    }
    weightTable[n1][n2] = 1;
}
void Graph::addEdge(int n1, int n2,bool twoWays,int weight){
    adjNodes[n1].push_back(n2);
    if(twoWays)
        adjNodes[n2].push_back(n1);
    weightTable[n1][n2] = weight;
}
void Graph::printGraph(){
    for (int i = 0; i < vertexNo; ++i) {
        for (int j: adjNodes[i])
            printf("%d -> %d weight: %d\n",i,j,weightTable[i][j]);
    }
}
int Graph::findMinimumWeightChild(int vertex) {
    int min = INT32_MAX;
    int minimumVertex;
    for (int i = 0; i < vertexNo; ++i) {
        if (min > weightTable[vertex][i]) {
            min = weightTable[vertex][i];
            minimumVertex = i;
        }
    }
    return minimumVertex;
}
int Graph::findMinimumWeightChilds(int* g,bool* visited) {
    int min = INT32_MAX;
    int minimumVertex;
    for (int i = 0; i < vertexNo; ++i) {
        for (int j = 0; j < vertexNo; ++j) {
            if (min > weightTable[i][j] + g[i] && weightTable[i][j] && *(visited + i) && !*(visited + j)) {
                min = weightTable[i][j] + g[i];
                g[j] = min;
                minimumVertex = j;
            }
        }
    }
    return minimumVertex;
}
int Graph::findMinimumWeightChilds(int* g) {
    int min = INT32_MAX;
    int minimumVertex;
    for (int i = 0; i < vertexNo; ++i) {
        for (int j = 0; j < vertexNo; ++j) {
            if (min > weightTable[i][j] + g[i] && weightTable[i][j]) {
                min = weightTable[i][j] + g[i];
                g[j] = min;
                minimumVertex = j;
            }
        }
    }
    return minimumVertex;
}
int Graph::findMinimumWeightChilds(int* h,int* g,bool* visited) {
    int min = INT32_MAX;
    int minimumVertex = 0;
    for (int i = 0; i < addNode(); ++i) {
        for (int j = 0; j < addNode(); ++j) {
                if (min > weightTable[i][j] + g[i] + h[j] && weightTable[i][j] && *(visited + i) && !*(visited + j)) {
                    min = weightTable[i][j] + g[i] + h[j];
                    g[j] = weightTable[i][j] + g[i];
                    minimumVertex = j;
            }
        }
    }
    return minimumVertex;
}
int Graph::findMinimumWeightChildsD(double* h,int* g,bool* visited) {
    double min = 100000;
    int minimumVertex = 0;
    for (int i = 0; i < vertexNo; ++i) {
        for (int j = 0; j < vertexNo; ++j) {
            if (min > weightTable[i][j] + g[i] + h[j] && weightTable[i][j] && *(visited + i) && !*(visited + j)) {
                min = weightTable[i][j] + g[i] + h[j];
                g[j] = weightTable[i][j] + g[i];
                minimumVertex = j;
            }
        }
    }
    return minimumVertex;
}
int Graph::findMinimumWeightChilds(int* h,int* g) {
    int min = INT32_MAX;
    int minimumVertex;
    for (int i = 0; i < vertexNo; ++i) {
        for (int j = 0; j < vertexNo; ++j) {
            if (min > weightTable[i][j] + g[i] + h[j] && weightTable[i][j]) {
                min = weightTable[i][j] + g[i] + h[j];
                g[j] = weightTable[i][j] + g[i];
                minimumVertex = j;
            }
        }
    }
    return minimumVertex;
}
void Graph::printStack(std::stack<int> s){
    int length = s.size();
    int arr[length] = {0};
    for (int i = 0; i < length; ++i) {
        arr[length-1-i] = s.top();
        s.pop();
    }
    printArray(arr,length);
}
void Graph::printQueue(std::queue<int> q){
    if (q.empty())
        return;
    int length = q.size();
    int arr[length] = {0};
    for (int i = 0; i < length; ++i) {
        arr[i] = q.front();
        q.pop();
    }
    printArray(arr,length);
}
void Graph::printArray(int arr[],int length){
    printf("[ ");
    for (int i = 0; i < length; ++i)
        printf("%d ",arr[i]);
//        WaterCans::printWaterStuff(i);
    printf("]\n");
}
int Graph::getVertexNo() {
    return vertexNo;
}
void Graph::calculateHeuristic(int h[],int startingVertex,int targetVertex){
//    int currentVertex = targetVertex;
//    bool visited[vertexNo] = {false};
//    while (currentVertex != startingVertex) {
//        calculateHeuristicUtil(visited,h,currentVertex);
//    }
//    h = {26,23,28,30,30,20,15,22,11,13,0,12,14};
}
int Graph::addNode() {
    int vertices = 0;
    int max = 0;
    while (!adjNodes[vertices].empty())
        vertices++;
    for (int i = 0; i < vertices ; ++i) {
        for (int j:adjNodes[i]) {
            if (j>max)
                max=j;
        }
    }
    return max+1;
}