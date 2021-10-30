#include <bits/stdc++.h>
using namespace std;

// add edge in undirected graph
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// print adjacency list - representation of graph
void printGraph(vector<int> adj[], int V)
{
    for(int v = 0; v < V; v++)
    {
        cout << "\n Adjacency List of Vertex " << v  << "\n head ";
        for(auto x: adj[v])
            cout << "-> " << x;
        cout << "\n";
    }
}

int main()
{
    int V = 5; 
    vector<int> adj[V]; 
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    printGraph(adj, V); 
    return 0; 
}   

/* DFS & BFS */
#include <bits/stdc++.h>
using namespace std;


template<typename T>    // graph to be of generic type
class Graph
{
    map<T, list<T> > l;

public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    // Breadth First Search
    void bfs(T src)
    {
        map<T, bool> visited;
        queue<T> q;

        q.push(src);  // add source node in queue
        visited[src] = true;  // make source note visited

        while(!q.empty())   //  while the queue is not empty
        {
            T node = q.front();  // remove one node from queue
            q.pop();
            cout << node << " ";

            for(T nbr:l[node])  // nbr for neighbour
            {
                if(!visited[nbr])  // check if not visited
                {
                    q.push(nbr);  // push that nbr in queue
                    visited[nbr] = true;  // mark nbr visited 
                }
            }     
        }
    }

    // Depth First Search
    void dfs_helper(T src, map<T, bool> &visited)  // pass by reference so that it remains same in all the function calls
    {
        // Recursive function that will traverse the graph
        cout << src << " ";
        visited[src] = true;

        // go to all of that node that are not visited
        for(T nbr:l[src])
        {
            if(!visited[nbr])
            {
                dfs_helper(nbr, visited);
            }
        }
    }
    void dfs(T src)
    {
        map<T, bool> visited;

        // mark all the nodes as not visited in the beginning
        for(auto p:l)
        {
            T node  = p.first;
            visited[node] = false;
        }
        dfs_helper(src, visited);   
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.bfs(0);
    g.dfs(0);

    return 0;
}