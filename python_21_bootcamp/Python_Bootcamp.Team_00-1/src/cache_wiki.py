import wikipediaapi
import networkx as nx
import json
from tqdm import tqdm
import argparse
import logging
import sys

# Create a Wikipedia API object
wiki = wikipediaapi.Wikipedia('en')
# logging.basicConfig(level=logging.INFO, format='%(message)s')

# Specify the page you want to start from
start_page_name = 'Python (programming language)'

# Create a directed graph
graph = nx.DiGraph()

# Function to recursively add links to the graph
def add_links_to_graph(page, cur_depth, depth, lenght):
    # Check if the page exists
    if cur_depth < depth:
        # Retrieve the links from the page
        links = page.links
        # Add the links as edges to the graph
        for link in tqdm(links, desc=page.title):
            linked_page = wiki.page(link)
            if linked_page.exists():
                lenght += 1
                if lenght > 1000:
                    raise Exception(f'Wrong lenght of links {lenght}')
                graph.add_edge(page.title, link)
                add_links_to_graph(linked_page, cur_depth + 1, depth, lenght)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='wiki graph')
    parser.add_argument('-p', '--page', required=False, help='Give me wikipedia page', default='42 (school)')
    parser.add_argument('-d', '--deep', required=False, help='Give deep of recoursion', default=3)
    args = parser.parse_args()
    args = dict(args._get_kwargs())
    logging.info(args['page'] + ' ' + str(args['deep']))
    # Get the start page object
    start_page = wiki.page(args['page'])

    # Check if the start page exists
    if start_page.exists():
        # Add links to the graph starting from the start page
        add_links_to_graph(start_page, 0, int(args['deep']), 0)

        # Convert the graph to a JSON format
        graph_json = nx.node_link_data(graph)

        # Save the graph as a JSON file
        with open('/'.join(sys.argv[0].split('/')[:-1] + ['wiki_graph.json']), 'w') as file:
            json.dump(graph_json, file)
    else:
        print(f"The page '{start_page_name}' does not exist.")
