#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>           // Tool for printing text to the screen
#include <fstream>            // Tool for reading our txt files
#include <unordered_map>      // Tool for our "lookup cabinets" (dictionaries) to assign ID to our Long at LAt
#include <vector>             // Tool for making a dynamic sized list 
#include <string>             // Tool for handling text (like filenames)

//using stucts just to hold our passive data
struct Node { 
    long long id;  //id 
    double lat;  //latitude
    double long; //longitude

};

struct Edge {
    long long destination_id; // id of the intercection this road leads to
    double distance; //length of the road (meters)
    double energy_cost; //battery needed to drive that distance (future plans to add this)
}

// using class to hold our active operations and such
class Graph {
public:
    std::unordered_map<long long, Node> nodes; // this is our list of nodes
    std::unordered_map<long long, std::vector<Edge>> adjacency_list; // list of roads (edges) that lead off from a particular intersection (node)

    void loadNodes(const std::string& filename);
    void loadEdges(const std::string& filename);
};

#endif // GRAPH_H