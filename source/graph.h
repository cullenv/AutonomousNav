#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <algorithm> // Needed for std::reverse

// The data structure for an intersection
struct Node {
    long long id;
    double lat;
    double lon;
};

// The data structure for a road
struct Edge {
    long long destination_id;
    double distance;
    
    // Week 5 EV Feature Placeholder
    double energy_cost; 
};

// Struct to hold the results of our routing algorithms
struct SearchResult {
    bool found = false;
    std::vector<long long> path; // Sequence of Node IDs from start to end
    int nodes_explored = 0;      // Number of nodes popped from the queue
    double total_distance = 0.0; // Cumulative road distance in meters
};

class Graph {
public:
    // Stores the actual nodes so we can look up their coordinates later for A*
    std::unordered_map<long long, Node> nodes;
    
    // The Adjacency List: Maps a Node ID to a list of outgoing Edges
    std::unordered_map<long long, std::vector<Edge>> adjacency_list;

    // Week 2: Functions to load the files
    void loadNodes(const std::string& filename);
    void loadEdges(const std::string& filename);

    // Week 3: Breadth-First Search
    SearchResult bfs(long long start_id, long long goal_id);

    //ai ai ai ai ai ai ai ai 
    void exportRouteToGeoJSON(const SearchResult& result, const std::string& filename);
    //ai ai ai ai ai ai ai ai 

};
