import networkx as nx
import json
import argparse
import logging
import sys
import copy

logging.basicConfig(level=logging.INFO, format='%(message)s')

lst_paths = []

def get_path(edges, prev, begin, end, lst, mode):

    for edge in edges:
        if begin == edge[mode[0]]:
            lst_copy = copy.copy(lst)
            lst_copy.append(begin)
            # print(lst_copy, edge['target'])
            if edge[mode[1]] == end:
                lst_copy.append(edge[mode[1]])
                lst_paths.append(lst_copy)
            elif prev != edge[mode[1]]:
                get_path(edges, begin, edge[mode[1]], end, lst_copy, mode)
    return


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='wiki graph')
    parser.add_argument('-f', '--from', required=False, help='Give me start point', default='42 (school)')
    parser.add_argument('-t', '--to', required=False, help='Give me end poin', default="Moscow")
    parser.add_argument('-n', '--non_directed', action='store_true',required=False, help='')
    parser.add_argument('-v', '--visualize', action='store_true', required=False, help='Visualization')
    args_from_shell = parser.parse_args()
    args = dict(args_from_shell._get_kwargs())
    # logging.info(args['from'] + ' ---> ' + str(args['to']))

    with open('/'.join(sys.argv[0].split('/')[:-1] + ['wiki_graph.json'])) as f:
        data = json.load(f)

    if args_from_shell.non_directed:
        get_path(data['links'], None, args['from'], args['to'], [], ('target', "source"))
    get_path(data['links'], None, args['from'], args['to'], [], ('source', "target"))
    
    if lst_paths:
        shortest = min(lst_paths, key=len)
    else:
        shortest = []
        print('There are no any paths')

    if args_from_shell.visualize:
        print(*shortest, sep=' --> ')
    print(len(shortest) - 1)
    # G = nx.Graph()

    # for node in data['nodes']:
    #     node_id = node['id']
    #     G.add_node(node_id)

    # for edge in data['links']:
    #     source = edge['source']
    #     target = edge['target']
    #     G.add_edge(source, target)
    
    # # Print some information about the graph
    # print("Number of nodes:", G.number_of_nodes())
    # print("Number of edges:", G.number_of_edges())

    # shortest_path = nx.shortest_path(G, source=args['from'], target=args['to'])
    # print(shortest_path, ' ----> ', len(shortest_path))
    # shortest_path = nx.shortest_path(G, source=args['to'], target=args['from'])
    # print(shortest_path, ' ----> ', len(shortest_path))