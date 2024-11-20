#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

// BFS implementation for an unweighted graph
void bfs(int startNode, vector<vector<int>>& adjList, int numNodes) {
    // Create a visited array to track visited nodes
    vector<bool> visited(numNodes, false);

    // Create a queue for BFS
    queue<int> q;

    // Mark the start node as visited and enqueue it
    visited[startNode] = true;
    q.push(startNode);

    // While the queue is not empty, explore the graph
    while (!q.empty()) {
        // Dequeue a node and process it
        int currentNode = q.front();
        cout << currentNode << " ";  // Process the node
        q.pop();

        // Visit all the neighbors of the current node
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                // If neighbor has not been visited, mark it as visited and enqueue it
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int numNodes = 6; // Number of nodes in the graph
    vector<vector<int>> adjList(numNodes);

    // Building the graph (undirected graph)
    adjList[0] = {1, 2};
    adjList[1] = {0, 3, 4};
    adjList[2] = {0, 5};
    adjList[3] = {1};
    adjList[4] = {1};
    adjList[5] = {2};

    cout << "BFS Traversal starting from node 0:" << endl;
    bfs(0, adjList, numNodes);

    return 0;
}
