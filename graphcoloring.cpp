#include<bits/stdc++.h>
using namespace std;

class Graph{

    int vertices;
    int graph[10][10];

public:

    Graph(int v){

        vertices = v;

        // Initialize adjacency matrix with 0
        for(int i = 0; i < vertices; i++){
            for(int j = 0; j < vertices; j++){
                graph[i][j] = 0;
            }
        }
    }

    // Add edge between vertices
    void addEdge(int source, int destination){

        graph[source][destination] = 1;
        graph[destination][source] = 1;
    }

    // Check if color assignment is safe
    bool isSafe(int vertex, int color[], int currentColor){

        for(int i = 0; i < vertices; i++){

            // Adjacent vertex has same color
            if(graph[vertex][i] == 1 && color[i] == currentColor){
                return false;
            }
        }

        return true;
    }

    // Recursive backtracking function
    bool graphColoring(int vertex, int totalColors, int color[]){

        // Base condition
        if(vertex == vertices){
            return true;
        }

        // Try all colors
        for(int currentColor = 1; currentColor <= totalColors; currentColor++){

            // Check safety
            if(isSafe(vertex, color, currentColor)){

                // Assign color
                color[vertex] = currentColor;

                // Recursive call for next vertex
                if(graphColoring(vertex + 1, totalColors, color)){
                    return true;
                }

                // Backtracking
                color[vertex] = 0;
            }
        }

        return false;
    }

    // Print solution
    void printSolution(int color[]){

        cout << "Assigned Colors:" << endl;

        for(int i = 0; i < vertices; i++){
            cout << "Vertex " << i << " ---> Color " << color[i] << endl;
        }
    }
};

int main(){

    int vertices = 4;

    Graph g(vertices);

    // Create graph
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);

    int totalColors = 3;

    int color[10] = {0};

    // Solve graph coloring problem
    if(g.graphColoring(0, totalColors, color)){

        g.printSolution(color);
    }
    else{
        cout << "Solution does not exist";
    }

    return 0;
}
