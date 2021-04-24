#pragma once
#include "Graph.h"
class AdjacencyMatrixGraph :
    public Graph
{
private:
    struct Edge {
        int weight = 0; // weight of the edge
        bool exists = false; // true if exists,false otherwise
    };
    Edge** arr;
    int n;
public:
    AdjacencyMatrixGraph(const int& m){
        this->n = m;
        this->arr = new Edge*[m];
        for (int i = 0; i < m; i++) {
            arr[i] = new Edge[m];
        }
    }
    ~AdjacencyMatrixGraph(){
        for (int i = 0; i < this->n; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }

    virtual void MakeEmptyGraph(const int& n);
    virtual bool isAdjacent(const int& u, const int& v);
    virtual const AdjacencyList& GetAdjList(const int& u);
    virtual void addEdge(const int& u, const int& v, const int& c);
    virtual void removeEdge(const int& u, const int& v);
};

