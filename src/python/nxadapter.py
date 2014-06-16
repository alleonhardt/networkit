"""
This module handles compatibility between NetworKit and NetworkX
"""

import graph

# non standard library modules
try:
	import networkx as nx
except ImportError:
	print("""WARNING: module 'networkx' not installed, which is required by some
						functions.""")
########  CONVERSION ########

def nx2nk(nxG, weightAttr=None):
	""" 
	Convert a networkx.Graph to a NetworKit.Graph
		:param weightAttr: the edge attribute which should be treated as the edge weight
	 """	

	# map networkx node ids to consecutive numerical node ids
	idmap = dict((id, u) for (id, u) in zip(nxG.nodes(), range(nxG.number_of_nodes())))
	z = max(idmap.values()) + 1
	# print("z = {0}".format(z))
	
	if weightAttr is not None:
		nkG = graph.Graph(z)
		for (u_, v_) in nxG.edges():
			u, v = idmap[u_], idmap[v_]
			w = nxG.edge[u_][v_][weightAttr]
			nkG.addEdge(u, v, w)
	else:
		nkG = graph.Graph(z)
		for (u_, v_) in nxG.edges():
			u, v = idmap[u_], idmap[v_]
			# print(u_, v_, u, v)
			assert (u < z)
			assert (v < z)
			nkG.addEdge(u, v)
	
	assert (nkG.numberOfNodes() == nxG.number_of_nodes())
	assert (nkG.numberOfEdges() == nxG.number_of_edges())
	return nkG


def nk2nx(nkG):
	""" Convert a NetworKit.Graph to a networkx.Graph """
	nxG = nx.Graph()
	if nkG.isWeighted():
		for (u, v) in nkG.edges():
			nxG.add_edge(u, v, weight=nkG.weight(u, v))
	else:
		for (u, v) in nkG.edges():
			nxG.add_edge(u, v)
	return nxG
