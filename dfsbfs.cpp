#include<iostream>
#include<list>
#include<map>
#include<queue>

using namespace std;

class Graph{

public:

    map<int, list<int>> adjList;
    map<int, bool> visited;
    queue<int> q;

    // Add edge
    void addEdge(int source, int destination){

        adjList[source].push_back(destination);
        adjList[destination].push_back(source);
    }

    // DFS Recursive Function
    void DFS(int node){

        // Mark visited
        visited[node] = true;

        // Print node
        cout << node << " ";

        // Visit neighbours recursively
        for(int neighbour : adjList[node]){

            if(!visited[neighbour]){
                DFS(neighbour);
            }
        }
    }

    // BFS Recursive Function
    void BFS(){

        // Base condition
        if(q.empty()){
            return;
        }

        // Take front node
        int node = q.front();
        q.pop();

        // Print node
        cout << node << " ";

        // Visit neighbours
        for(int neighbour : adjList[node]){

            if(!visited[neighbour]){

                visited[neighbour] = true;

                q.push(neighbour);
            }
        }

        // Recursive call
        BFS();
    }
};

int main(){

    Graph g;

    // Create graph
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,6);

    int choice;

    cout << "Enter 0 for DFS and 1 for BFS: ";
    cin >> choice;

    if(choice == 0){

        cout << "DFS Traversal: ";

        g.DFS(0);
    }
    else{

        cout << "BFS Traversal: ";

        g.q.push(0);

        g.visited[0] = true;

        g.BFS();
    }

    return 0;
}
