#include "graph.h"
#include <stdio.h>

int main() {
    Graph city_map;
    
    city_map.loadNodes("nodes.txt");
    city_map.loadEdges("edges.txt");

    if (city_map.nodes.size() < 2) {
        std::cout << "Not enough nodes to run search. Pick a larger area to Search.\n";
        return 1;
    }

    // Pick two nodes from the loaded map
    auto it = city_map.nodes.begin();
    long long start = it->first;
    std::advance(it, 140); // 100 nodes away in the map hash
    long long goal = it->first;

    std::cout << "\nRunning BFS from " << start << " to " << goal << "...\n";
    SearchResult res = city_map.bfs(start, goal);

    if (res.found) {
        std::cout << "Path found!\n";
        std::cout << "Total hops: " << res.path.size() - 1 << "\n";
        std::cout << "Nodes explored: " << res.nodes_explored << "\n";
        std::cout << "Total distance: " << res.total_distance << " meters\n";
//ai ai ai ai ai ai ai ai 
        city_map.exportRouteToGeoJSON(res, "route.geojson");
//ai ai ai ai ai ai ai ai         
    } else {
        std::cout << "No path exists between the selected nodes.\n";
    }

    return 0;
}

