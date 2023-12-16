//Rishikesh Chaudhari
//E11 23304

//Represent a graph of city using adjacency matrix adjacency list. Nodes should represent the various landmarks and links should represent the distance between them. Find the shortest path using Dijkstra's algorithm from single source to all destination

#include<iostream>
#include <climits>
using namespace std;

class Graph
{
    private: int weightGraphMatrix[20][20];
             bool visitedArray[20];
             int vertices, edges;
             int key[20];
             int parent[20];
             int arr[20];

    public: Graph();
            void addGraph(bool );
            void Dijkstras(bool,int);
            void printShortestPath(int);
};

Graph::Graph()
{
    for (int i=0; i<20; i++)
    {
        visitedArray[i] = false;
        vertices = 0;
        edges = 0;
        key[i] = INT_MAX;
        parent[i] = -1;
        for (int j=0; j<20; j++)
        {
            weightGraphMatrix[i][j] = 0;
        }
    }
}

void Graph :: addGraph(bool direction)
{
    int vertex1,vertex2,weight;
    cout<<"Enter number of vertices : ";
    cin>>vertices;
    while (vertices<0 || vertices>20)
    {
        cout<<"Vertices cannot be negative and more than 20"<<endl;
        cout<<"Enter again"<<endl;
        cin>>vertices;
    }
    for (int i=0; i<vertices; i++)
    {
        cout<<"Enter Node "<<(i+1)<<" : ";
        cin>>arr[i];
    }
    cout<<"Enter number of edges : ";
    cin>>edges;
    while (edges<0 || edges>(vertices*vertices))
    {
        cout<<"Enter valid number of edges ";
        cin>>edges;
    }
    for (int i=0; i<edges; i++)
    {
        cout<<"Enter vertex 1 ";
        cin>>vertex1;
        cout<<"Enter vertex 2 ";
        cin>>vertex2;
        cout<<"Enter weight of edge ";
        cin>>weight;
        while (weight<0)
        {
            cout<<"Enter valid weight ";
            cin>>weight;
        }
        if (direction)
        {
            weightGraphMatrix[vertex1][vertex2] = weight;
        }
        else{
            weightGraphMatrix[vertex1][vertex2] = weight;
            weightGraphMatrix[vertex2][vertex1] = weight;
        }
    }
    cout<<endl;
    cout<<"Matrix is "<<endl;
    for (int i=0; i<vertices; i++)
    {
        for (int j=0; j<vertices; j++)
        {
            cout<<weightGraphMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Graph :: Dijkstras(bool direction, int source)
{
    for (int i=0; i<vertices; i++)
    {
        parent[arr[i]] = -1;
        if (weightGraphMatrix[source][i] != 0)
        {
            key[i] = weightGraphMatrix[source][i];
        }
        else{
            key[i] = INT_MAX;
        }
    }
    key[source] = 0;
    for (int i=0; i<vertices; i++)
    {
        int minDist = INT_MAX;
        int curr = -1;
        for (int j=0; j<vertices; j++)
        {
            if (!visitedArray[arr[j]] && key[arr[j]]<minDist)
            {
                minDist = key[arr[j]];
                curr = arr[j];
            }
        }
        if (curr == -1)
        {
            break;      //All remaining verticws are unreachable
        }
        visitedArray[curr] = true;
        for (int j=0; j<vertices; j++)
        {
            if (!visitedArray[j] && weightGraphMatrix[curr][arr[j]] != 0)
            {
                int newDistance = key[curr] + weightGraphMatrix[curr][arr[j]];
                if (newDistance < key[arr[j]])
                {
                    key[arr[j]] = newDistance;
                    parent[arr[j]] = curr;
                }
            }
        }
    }
    
}

void Graph :: printShortestPath(int s)
{
    cout<<"Shortest path from verex "<<s<<" to other vertices"<<endl;
    for (int i=0; i<vertices; i++)
    {
        if (arr[i] != s)
        {
            cout<<"Vertex "<<arr[i]<<" : Distance = "<<key[arr[i]]<<", Path = ";
            int currentVertex = arr[i];
            while (currentVertex != -1)
            {
                cout<<currentVertex<<"->";
                currentVertex = parent[currentVertex];
            }
            cout<<s;
            cout<<endl;
        }
    }
}

int main()
{
    Graph g;
    bool isDirected;
    cout<<"Is Graph Directed(1 for Yes and 0 for No)"<<endl;
    cin>>isDirected;
    cout<<"Enter source : "<<endl;
    int source;
    cin>>source;
    g.addGraph(isDirected);
    g.Dijkstras(isDirected,source);
    g.printShortestPath(source);
}