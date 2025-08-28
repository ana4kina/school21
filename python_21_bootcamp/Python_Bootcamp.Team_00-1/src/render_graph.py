import networkx as nx
import matplotlib.pyplot as plt
import json
import sys
import os
from pyvis.network import Network

file_name = os.getenv('WIKI_FILE')

if not file_name:
    print('sdfsdfsdf')
    file_name = '/'.join(sys.argv[0].split('/')[:-1] + ['wiki_graph.json'])
# Load the graph from a JSON file
with open(file_name, 'r') as file:
    data = json.load(file)

# Create a directed graph from the loaded data
graph = nx.DiGraph()

for node in data['nodes']:
    node_id = node['id']
    graph.add_node(node_id)

for edge in data['links']:
    source = edge['source']
    target = edge['target']
    graph.add_edge(source, target)

# Print some information about the graph
print("Number of nodes:", graph.number_of_nodes())
print("Number of edges:", graph.number_of_edges())

# Generate a HTML image of the graph
pyvis_graph = Network(height="500px", width="100%", notebook=True)
pyvis_graph.from_nx(graph)

# # Save the graph
pyvis_graph.save_graph('wiki_graph.html')

# Generate a visualization of the graph
plt.figure(figsize=(16, 9))
pos = nx.spring_layout(graph, scale=250)
nx.draw_networkx(graph, pos, with_labels=True, node_size=200, font_size=7)
plt.savefig('wiki_graph.png')
plt.show()
