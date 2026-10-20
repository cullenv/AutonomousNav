#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>

//The data structure for intersections
struct Node {
    long long id;
    double lat;
    double lon;
};

// The data structure for a road
struct Edge {
    long long destination_id;
    double distance;
    
    //EV Feature Placeholder
    // We will initialize this to just equal the distance for now
    double energy_cost; 
};

class Graph {
public:
    // Stores the actual nodes so we can look up their coordinates later for A*
    std::unordered_map<long long, Node> nodes;
    
    // The Adjacency List: Maps a Node ID to a list of outgoing Edges
    std::unordered_map<long long, std::vector<Edge>> adjacency_list;

    void loadNodes(const std::string& filename);
    void loadEdges(const std::string& filename);
};