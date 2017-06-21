#include "Test.h"
#include <iostream>
#include "Edge.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct subset
{
    int parent;
    int rank;
};

int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;

    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int** initGraph(int size)
{
    int **answer = new int* [size];
    for(int i=0;i<size;i++)
    {
        answer[i]=new int[size];
        for(int j=0;j<size;j++)
        {
            answer[i][j]=-1;
        }
    }
    return answer;
}

int** getKruskalMST(int** graph, int size, vector<Edge*> edges)
{
    int** result = initGraph(size);
    struct subset *subsets = new subset[size];

    for (int v = 0; v < size; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

     int i = 0;
     while (i < size)
    {
        int x = find(subsets, edges[i]->source);
        int y = find(subsets, edges[i]->destination);

        if (x != y)
        {\
            result[edges[i]->source][edges[i]->destination] = edges[i]->weight;
            result[edges[i]->destination][edges[i]->source] = edges[i]->weight;
            Union(subsets, x, y);
        }

        i++;
    }

    delete[] subsets;

    return result;
}

int main ()
{
    test();
    return 0;
}
