#include "graph.h"

int main() {
    Graph city_map;
    //loader
    city_map.loadNodes("nodes.txt");
    city_map.loadEdges("edges.txt");
    
    //quick test for our edges list grabbing first node
    if (!city_map.nodes.empty()) {
        long long test_id = city_map.nodes.begin()->first;
        
        std::cout << "\n Testing Node ID:" << test_id << " \n";
        std::cout << "Latitude:" << city_map.nodes[test_id].lat << "\n";
        std::cout << "Connected to" << city_map.adjacency_list[test_id].size() << " roads.\n";
        
        //Print out where those roads go
        for (const Edge& edge : city_map.adjacency_list[test_id]) {
            std::cout << " -> Road to Node " << edge.destination_id 
                      << " (Distance: " << edge.distance << "m)\n";
        }
    }

    return 0;
}