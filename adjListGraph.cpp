#include <iostream>
#include <unordered_map>
#include <vector>

class Graph {
private:
    std::unordered_map<int, std::vector<int>> adjList;

public:
    void addEdge(int u, int v, bool isDirected = false) {
        adjList[u].push_back(v);
        if (!isDirected) {
            adjList[v].push_back(u);
        }
    }

    void printGraph() const {
        for (const auto& pair : adjList) {
            std::cout << pair.first << " -> ";
            for (const int& neighbor : pair.second) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }

    bool hasEdge(int u, int v) const {
        if (adjList.find(u) == adjList.end()) return false;
        for (const int& neighbor : adjList.at(u)) {
            if (neighbor == v) return true;
        }
        return false;
    }

    std::vector<int> getNeighbors(int node) const {
        if (adjList.find(node) != adjList.end()) {
            return adjList.at(node);
        }
        return {};
    }
};

int main() {
    Graph graph;

    graph.addEdge(1, 2, true);
    graph.addEdge(1, 3, true);
    graph.addEdge(2, 4, true);
    graph.addEdge(3, 4, true);
    graph.addEdge(4, 5, true);

    std::cout << "graph adj list:" << std::endl;
    graph.printGraph();

    std::cout << "edge between 1 and 3: " << (graph.hasEdge(1, 3) ? "y" : "n") << std::endl;
    std::cout << "edge between 2 and 5: " << (graph.hasEdge(2, 5) ? "y" : "n") << std::endl;

    std::vector<int> neighbors = graph.getNeighbors(4);
    for (const int& neighbor : neighbors) {
        std::cout << neighbor << " ";
    }
    std::cout << std::endl;

    return 0;
}