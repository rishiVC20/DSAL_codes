//Rishikesh Chaudhari
//E11 23304

/*Represent a graph of your college campus using adjacency list /adjacency matrix. Nodes should represent the various departments/institutes and links should represent the distance between them.Find minimum spanning tree using
a) Using Kruskal’s algorithm.
b) Using Prim’s algorithm. */

#include<iostream>
using namespace std;

struct Edge
{
    int point1, point2, weight;
};

class Graph
{
    private: int weightGraphMatrix[20][20];
             string nodeName[20];
             int visitedArray[20],path[20],distance[20];
             int vertices, edges;
             Edge edge[20];

    public:  Graph();
            void createGraph();
            void prims();
            void kruskals();
            void sortEdges();            
};

Graph :: Graph()
{
    vertices = 0;
    edges = 0;
    for (int i=0; i<20; i++)
    {
        for (int j=0; j<20; j++)
        {
            weightGraphMatrix[i][j] = 0;
        }
    }
}

void Graph :: createGraph()
{
    int vertex1, vertex2, weightOfEdge;
    cout<<"Enter number of vertices "<<endl;
    cin>>vertices;
    while (vertices < 0 || vertices > 20)
    {
        cout<<"Vertices cannot be negative or greater than 20 "<<endl;
        cout<<"Re enter the vertices "<<endl;
        cin>>vertices;
    }

    for (int i=0; i<vertices; i++)
    {
        cout<<"Enter department "<<(i+1)<<endl;
        cin>>nodeName[i];
    }

    cout<<"Enter number of edges "<<endl;
    cin>>edges;

    while (edges <=0 || edges>(vertices*vertices))
    {
        cout<<"Invalid number of edges "<<endl;
        cout<<"Re enter number of edges "<<endl;
        cin>>edges;
    }

    for (int i=0; i<edges; i++)
    {
        cout<<"Edge "<<(i+1)<<": "<<endl;
        cout<<"Enter vertex 1 ";
        cin>>vertex1;
        cout<<"Enter vertex 2 ";
        cin>>vertex2;
        cout<<"Enter weight of edge ";
        cin>>weightOfEdge;
        while (weightOfEdge <= 0)
        {
            cout<<"Weight of edge cannot be negative "<<endl;
            cout<<"Re enter the weight of edge"<<endl;
            cin>>weightOfEdge;
        }
        weightGraphMatrix[vertex1][vertex2] = weightOfEdge;
        weightGraphMatrix[vertex2][vertex1] = weightOfEdge;
        edge[i].point1 = vertex1;
        edge[i].point2 = vertex2;
        edge[i].weight = weightOfEdge;
    }
    cout<<"Matrix is "<<endl;
    for(int i=0; i<vertices; i++)
    {
        for (int j=0; j<vertices; j++)
        {
            cout<<weightGraphMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
void Graph :: prims()
{
    int visitedArray[20], minimumCost = 0, a = 0, b = 0, c = 0;
    int rowArr[20];
    int columnArr[20];
    int weightArr[20];
    for (int i=0; i<20; i++)
    {
        visitedArray[i] = 0;
        path[i] = 0;
    }

    visitedArray[0] = 1;

    cout<<"Visited and path status"<<endl;
    cout<<"Destinations"<<"\t|\t"<<"visited"<<"\t|\t"<<"Path"<<endl;
    for (int i=0; i<vertices; i++)
    {
        cout<<nodeName[i]<<"\t|\t"<<visitedArray[i]<<"\t|\t"<<nodeName[path[i]]<<endl;
    }
    int numberOfEdges = 0;
    while (numberOfEdges < (vertices-1))
    {
        int min = 99999;
        int column = 0, row = 0;
        for (int i=0; i<vertices; i++)
        {
            if (visitedArray[i])
            {
                for (int j=0; j<vertices; j++)
                {
                    if (min > weightGraphMatrix[i][j])
                    {
                        if (!visitedArray[j] && weightGraphMatrix[i][j])
                        {
                            min = weightGraphMatrix[i][j];
                            row = i;
                            column = j;
                            path[i] = row;
                        }
                    }
                }
            }
        }
        minimumCost += weightGraphMatrix[row][column];
        rowArr[a++] = row;
        columnArr[b++] = column;
        weightArr[c++] = weightGraphMatrix[row][column];
        visitedArray[column] = 1;
         cout<<"Visited and path status"<<endl;
        cout<<"Destinations"<<"\t|\t"<<"visited"<<"\t|\t"<<"Path"<<endl;
        for (int i=0; i<vertices; i++)
        {
            cout<<nodeName[i]<<"\t|\t"<<visitedArray[i]<<"\t|\t"<<nodeName[path[i]]<<endl;
        }
        numberOfEdges++;
        cout<<"Total visited "<<numberOfEdges<<endl;
    }

    cout<<"Minimum Spanning Tree(MST)"<<endl;
    cout<<"Destinations\t|\tCost"<<endl;
    for (int i=0; i<vertices; i++)
    {
        int tempRow = rowArr[i];
        int tempColumn = columnArr[i];
        cout<<nodeName[tempRow]<<"->"<<nodeName[tempColumn]<<weightArr[i]<<endl;
    }
    cout<<"Minimum cost of Spanning Tree "<<minimumCost<<endl;
}

void Graph :: sortEdges()
{
    bool swapped = false;
    do{
        swapped = false;
        for (int i=0; i<edges; i++)
        {
            if (edge[i].weight > edge[i+1].weight)
            {
                Edge temp = edge[i];
                edge[i] = edge[i+1];
                edge[i+1] = temp;
                swapped = true;
            }
        }
    }
    while (swapped);
}

void Graph :: kruskals()
{
    cout<<"Destinations path array"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"Destinations\t|\tWeight"<<endl;
    cout<<"------------------------------"<<endl;
    for (int i=0; i<edges; i++)
    {
        cout<<nodeName[edge[i].point1]<<" - "<<nodeName[edge[i].point2]<<"\t|\t"<<edge[i].weight;
        cout<<endl;
    }
    sortEdges();
    cout<<"Sorted Destinations"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"Destinations\t|\tWeight"<<endl;
    cout<<"------------------------------"<<endl;
    for (int i=0; i<edges; i++)
    {
        cout<<nodeName[edge[i].point1]<<" - "<<nodeName[edge[i].point2]<<"\t|\t"<<edge[i].weight;
        cout<<endl;
    }
    cout<<endl;

    Edge temp[20];
    int visitedvertices[20],r,p;
    for (int i=0; i<edges; i++)
    {
        visitedvertices[i] = 0;
    }

    int val = 1;
    int count = 0;
    int j = 0;
    while (count<vertices-1 && j<edges)
    {
        if (visitedvertices[edge[j].point1]==0 && visitedvertices[edge[j].point2]==0)
        {
            cout<<"Destinations path selected"<<endl;
            cout<<"-------------------------------"<<endl;
            cout<<"Destinations\t|\tWeight"<<endl;
            cout<<nodeName[edge[j].point1]<<" - "<<nodeName[edge[j].point2]<<"\t|\t"<<edge[j].weight;
            cout<<endl;
            temp[count] = edge[j];
            visitedvertices[edge[j].point1] = val;  
            visitedvertices[edge[j].point2] = val;
            val++;
            count++;  
        }
        else if (visitedvertices[edge[j].point1] != visitedvertices[edge[j].point2])
        {
            cout<<"Destination path selected: "<<endl;
			cout<<"-------------------------------------------------------"<<endl;
			cout<<"Destinations\t|\tWeight"<<endl;
			cout<<"-------------------------------------------------------"<<endl;
			cout<<nodeName[edge[j].point1]<<" - "<<nodeName[edge[j].point2]<<"\t|\t"<<edge[j].weight;
			cout<<endl;

            if (visitedvertices[edge[j].point1]!=0 && visitedvertices[edge[j].point2]!=0)
            {
                temp[count] = edge[j];
                if (visitedvertices[edge[j].point1] < visitedvertices[edge[j].point2])
                {
                    r = visitedvertices[edge[j].point1];
                    p = visitedvertices[edge[j].point2];
                }
                else{
                    r = visitedvertices[edge[j].point2];
                    p = visitedvertices[edge[j].point1];
                }
                for (int k=0; k<edges; k++)
                {
                    if (visitedvertices[k] == p)
                    {
                        visitedvertices[k] = r;
                    }
                }
                count++;
            }
            else if (visitedvertices[edge[j].point1]==0 && visitedvertices[edge[j].point2]!=0)
            {
                temp[count] = edge[j];
                visitedvertices[edge[j].point1] = visitedvertices[edge[j].point2];
                count++;
            }
            else{
                temp[count] = edge[j];
                visitedvertices[edge[j].point2] = visitedvertices[edge[j].point1];
                count++;
            }
        }
        else{
            cout<<"Destinations path rejected"<<endl;
            cout<<"------------------------------------"<<endl;
            cout<<"Destinations"<<"\t|\t"<<"Weight"<<endl;
            cout<<"------------------------------------"<<endl;
            cout<<nodeName[edge[j].point1]<<" - "<<nodeName[edge[j].point2]<<"\t|\t"<<edge[j].weight;
            cout<<endl;
        }
        j++;
    }
    cout<<endl;
    cout<<"Kruskals Minimum Spanning Tree"<<endl;
    cout<<endl;
    int minCost = 0;
    cout<<"-------------------------------------------------------"<<endl;
	cout<<"Destinations"<<"\t|\t"<<"Weight"<<endl;
	cout<<"-------------------------------------------------------"<<endl;
	for (int i=0; i<count; i++)
    {
        cout<<nodeName[temp[i].point1]<<" -> "<<nodeName[temp[i].point2]<<"\t|\t"<<temp[i].weight;
        cout<<endl;
        minCost += temp[i].weight;
    }
    cout<<"Total cost of MST is = "<<minCost<<endl;
}
int main()
{
    int ch;
    Graph g;
    do{
        cout<<"1. Create Graph\n2. Prims\3.Kruskals\4.exit"<<endl;
        cout<<"Enter choice "<<endl;
        cin>>ch;
        switch(ch){
            case 1: 
                    g.createGraph();
                    break;
            
            case 2: g.prims();
                    break;

            case 3: g.kruskals();
                    break;        
        }
    }
    while (ch != 0);    
}