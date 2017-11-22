//
// Created by arya11 on 11/17/17.
//

#include "Graph.h"
#include <iostream>
#include <string.h>
#include <queue>
#include <cstring>
#include <fstream>
#include <stack>

void Graph::breadthFirstSearch(int startingVertex,int targetVertex){
    printf("Breadth First Search Route:\t");
    bool visited[vertexNo] = {false};
    std::queue<int> q;
    q.push(startingVertex);
    visited[startingVertex] = true;
//    doSearchStuff(0);
    while (!q.empty()) {
        for (int i: adjNodes[q.front()]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
        doSearchStuff(q.front());
        if(q.front() == targetVertex)
            break;
        q.pop();
    }
    printf("\n");
}
void Graph::depthFirstSearch(int startingVertex,int targetVertex){
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
void Graph::depthFirstSearch(int startingVertex,int targetVertex,int limit){
    printf("Depth First Search (Limit: %d) Route:\t",limit);
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
            if (!visited[i] && limit > depth) {
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
void Graph::uniformCostSearch(int startingVertex,int targetVertex){
    printf("Uniform Cost Route:\t");
    bool visited[vertexNo] = {false};
    int g[vertexNo] = {0};
    visited[startingVertex] = true;
    int v = startingVertex;
    while (v != targetVertex) {
        doSearchStuff(v);
        v = findMinimumWeightChilds(g,visited);
        visited[v] = true;
    }
    printf("\ng(n) Completed Array: ");
    printArray(g,vertexNo);
    printf("target vertex: %d with %d cost.\n",targetVertex,g[targetVertex]);

}
void Graph::twoDirectionalSearch(int startingVertex,int targetVertex){
    printf("two directional Depth First Search Route:\t");
    bool visited1[vertexNo] = {false};
    bool visited2[vertexNo] = {false};
    bool allChildNodesVisited1;
    bool allChildNodesVisited2;
    std::stack<int> s1,s2;
    s1.push(startingVertex);
    visited1[startingVertex] = true;
    printf("\nStarting Route1 With: ");
    doSearchStuff(startingVertex);
    s2.push(targetVertex);
    visited2[targetVertex] = true;
    printf("\tStarting Route2 With: ");
    doSearchStuff(targetVertex);
    while (!s1.empty() || !s2.empty()) {
        allChildNodesVisited1 = true;
        allChildNodesVisited2 = true;
        for (int i: adjNodes[s1.top()]) {
            if (!visited1[i]) {
                s1.push(i);
                visited1[i] = true;
                printf("\nSearching Route1: ");
                doSearchStuff(i);
                allChildNodesVisited1 = false;
                break;
            }
        }
        for (int i: adjNodes[s2.top()]) {
            if (!visited2[i]) {
                s2.push(i);
                visited2[i] = true;
                printf("\tSearching Route2: ");
                doSearchStuff(i);
                allChildNodesVisited2 = false;
                break;
            }
        }
        if(allChildNodesVisited1)
            s1.pop();
        if(allChildNodesVisited2)
            s2.pop();
        if (overlappingVisited(visited1,visited2)) {
            s1.pop();
            s2.pop();
            printf("\nFirst Route: ");
            printStack(s1);
            printf("Second Route: ");
            printStack(s2);
            break;
        }
    }
}
void Graph::AStar(int startingVertex,int targetVertex){
    printf("A* Algorithm: ");
    bool visited[vertexNo] = {false};
    int g[vertexNo] = {0};
    int* h = heuristic;
//    calculateHeuristic(h,startingVertex,targetVertex);
    visited[startingVertex] = true;
    int v = startingVertex;
    while (v != targetVertex) {
        doSearchStuff(v);
        v = findMinimumWeightChilds(h,g,visited);
        visited[v] = true;
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
    printf("%d ",vertex);
}
Graph::Graph(std::string fileName) {
    readFromFile(fileName);
}
Graph::Graph(int vertexNo){
    heuristic = new int[vertexNo];
    this->vertexNo = vertexNo;
    adjNodes = new std::list<int>[vertexNo];
    weightTable = new int*[vertexNo];
    for (int i = 0; i < vertexNo; ++i) {
        weightTable[i] = new int[vertexNo];
        for (int j = 0; j < vertexNo; ++j)
            weightTable[i][j] = 0;
    }
}
void Graph::addEdge(int n1, int n2,bool twoWays) {
    adjNodes[n1].push_back(n2);
    if(twoWays)
        adjNodes[n2].push_back(n1);
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
void Graph::readFromFile(std::string fileName) {
//    std::ifstream file(fileName);
//    std::string line;
//    if (file.is_open())
//    {
//        while ( getline (file,line) )
//        {
//            char* cline = &line[0u];
//            char *token = std::strtok(cline, " ->");
//            Node pre = 0;
//            while (token != NULL) {
//                Node n = addNode(token);
//                if(&pre)
//                    edges.push_back(Edge(pre,n, false));
//                token = std::strtok(NULL, " ->");
//                pre = n;
//            }
//        }
//        file.close();
//    }
//    else std::cout << "error in file" << '\n';
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

int Graph::findMinimumWeightChilds(int* h,int* g,bool* visited) {
    int min = INT32_MAX;
    int minimumVertex;
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
void Graph::printStack(std::stack<int> s){
    int length = s.size();
    int arr[length] = {0};
    for (int i = 0; i < length; ++i) {
        arr[length-1-i] = s.top();
        s.pop();
    }
    printArray(arr,length);
}
void Graph::printArray(int arr[],int length){
    printf("[ ");
    for (int i = 0; i < length; ++i)
        printf("%d ",arr[i]);
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
