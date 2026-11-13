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

SearchResult Graph::bfs(long long start_id, long long goal_id) {
    SearchResult result;

    // Boundary check: ensure endpoints exist
    if (nodes.find(start_id) == nodes.end() || nodes.find(goal_id) == nodes.end()) {
        std::cerr << "Start or Goal ID does not exist in graph.\n";
        return result;
    }

    if (start_id == goal_id) {
        result.found = true;
        result.path.push_back(start_id);
        return result;
    }

    std::queue<long long> q;
    std::unordered_map<long long, bool> visited;
    
    // Parent map: key = child_id, value = parent_id
    // Crucial for backwards route reconstruction
    std::unordered_map<long long, long long> parent;

    q.push(start_id);
    visited[start_id] = true;

    while (!q.empty()) {
        long long current = q.front();
        q.pop();
        result.nodes_explored++;

        // Destination reached
        if (current == goal_id) {
            result.found = true;
            break;
        }

        // Expand neighbors
        auto it = adjacency_list.find(current);
        if (it != adjacency_list.end()) {
            for (const Edge& edge : it->second) {
                long long neighbor = edge.destination_id;

                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    parent[neighbor] = current;
                    q.push(neighbor);
                }
            }
        }
    }

    // Route Reconstruction
    if (result.found) {
        long long curr = goal_id;
        while (curr != start_id) {
            result.path.push_back(curr);
            curr = parent[curr];
        }
        result.path.push_back(start_id);
        std::reverse(result.path.begin(), result.path.end());

        // Calculate actual cumulative distance across the traversed hops
        for (size_t i = 0; i < result.path.size() - 1; ++i) {
            long long u = result.path[i];
            long long v = result.path[i + 1];
            for (const Edge& edge : adjacency_list[u]) {
                if (edge.destination_id == v) {
                    result.total_distance += edge.distance;
                    break;
                }
            }
        }
    }

    return result;
}
/*
//ai ai ai ai ai ai ai ai 

void Graph::exportRouteToGeoJSON(const SearchResult& result, const std::string& filename) {
    if (!result.found || result.path.empty()) {
        std::cerr << "No route to export.\n";
        return;
    }

    std::ofstream file(filename);
    file << "{\n";
    file << "  \"type\": \"FeatureCollection\",\n";
    file << "  \"features\": [\n";
    file << "    {\n";
    file << "      \"type\": \"Feature\",\n";
    file << "      \"geometry\": {\n";
    file << "        \"type\": \"LineString\",\n";
    file << "        \"coordinates\": [\n";
    
    // Loop through our hops and print the coordinates
    for (size_t i = 0; i < result.path.size(); ++i) {
        long long node_id = result.path[i];
        Node n = nodes[node_id];
        
        // GeoJSON requires [Longitude, Latitude]
        file << "          [" << n.lon << ", " << n.lat << "]";
        
        // Add a comma after every coordinate EXCEPT the very last one
        if (i < result.path.size() - 1) {
            file << ",\n";
        } else {
            file << "\n";
        }
    }
    
    file << "        ]\n";
    file << "      },\n";
    // This styling makes the line thick and red on the map
    file << "      \"properties\": {\"stroke\": \"#ff0000\", \"stroke-width\": 5}\n";
    file << "    }\n";
    file << "  ]\n";
    file << "}\n";
    
    std::cout << "Successfully exported route to " << filename << "\n";
}

//ai ai ai ai ai ai ai ai
*/