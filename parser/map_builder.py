import osmnx as ox

def build_map_files():
    print("Downloading street data from OpenStreetMap...")
    
    # 1. Fetch the map graph
    # Coordinates are for Midtown Detroit. dist=2000 means a 2km radius.
    # network_type='drive' ensures we only get roads cars can drive on (no walking trails)
    G = ox.graph_from_point((42.358, -83.066), dist=2000, network_type='drive')
    
    print(f"Map downloaded! Found {len(G.nodes)} intersections and {len(G.edges)} roads.")

    # 2. Write the Intersections (Nodes) to nodes.txt
    print("Writing nodes.txt...")
    with open("nodes.txt", "w") as f:
        # Loop through every node in the graph
        for node_id, data in G.nodes(data=True):
            lat = data['y']
            lon = data['x']
            # Format: NodeID Latitude Longitude
            f.write(f"{node_id} {lat} {lon}\n")

    # 3. Write the Roads (Edges) to edges.txt
    print("Writing edges.txt...")
    with open("edges.txt", "w") as f:
        # Loop through every edge in the graph
        for u, v, data in G.edges(data=True):
            # u = Start Node ID
            # v = End Node ID
            # length = Distance in meters
            distance = data['length']
            f.write(f"{u} {v} {distance}\n")

    print("Success! nodes.txt and edges.txt have been generated.")

if __name__ == "__main__":
    build_map_files()