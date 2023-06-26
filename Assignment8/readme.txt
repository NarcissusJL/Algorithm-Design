# Description
## Max Flow Problem

An implementation of the Ford-Fulkerson algorithm for finding the maximum flow in a graph.


#The algorithm works as follows:

The algorithm works by repeatedly finding augmenting paths from the source node to the sink node in the graph. An augmenting path is a path in which every edge has available capacity for additional flow. The algorithm increases the flow along the augmenting path until no more augmenting paths can be found.