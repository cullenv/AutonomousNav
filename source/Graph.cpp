#include "graph.h"

void Graph::loadNodes(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open " << filename << "\n";
        return;
    }

    long long id;
    double lat;
    double lon;

    while (file >> id >> lat >> lon) {
        nodes[id] = {id, lat, lon};
    }
    
    std::cout << "Successfully loaded " << nodes.size() << " nodes.\n";
}

void Graph::loadEdges(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open " << filename << "\n";
        return;
    }

    long long u;
    long long v;
    double distance;
    int edge_count = 0;
    
    while (file >> u >> v >> distance) {

        Edge new_edge = {v, distance, distance};
        
        adjacency_list[u].push_back(new_edge); //.push_back(new_edge) way to append an element to the end of a dynamic array
        edge_count++;
    }
    
    std::cout << "Successfully loaded " << edge_count << " edges.\n";
}