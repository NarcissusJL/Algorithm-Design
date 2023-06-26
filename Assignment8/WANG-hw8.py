# Define a class to represent edges
class Edge:
    def __init__(self, from_node, to_node, capacity):
        self.from_node = from_node  # Starting node
        self.to_node = to_node      # Ending node
        self.capacity = capacity    # Capacity
        self.flow = 0               # Current flow
        self.rev_index = 0          # the index of the reverse edge

# Use DFS to find an augmenting path
def dfs(u, t, a, visited, graph):
    # If the current node is the sink node or the current flow is 0, return the current flow
    if u == t or a == 0:
        return a
    visited.add(u)
    for e in graph[u]:
        if e.to_node not in visited and e.flow < e.capacity:
            # Find the minimum flow in the augmenting path
            f = dfs(e.to_node, t, min(a, e.capacity - e.flow), visited, graph)
            if f > 0:
                e.flow += f
                graph[e.to_node][e.rev_index].flow -= f
                return f
    return 0

# Compute the maximum flow
def max_flow(s, t, graph):
    flow = 0
    while True:
        visited = set()
        f = dfs(s, t, float('inf'), visited, graph)
        # If there is no augmenting path, the algorithm terminates
        if f == 0:
            break
        flow += f
    return flow

if __name__ == '__main__':
    # Input n
    n = int(input())
    # Input the capacity matrix
    capacity_matrix = [list(map(int, input().split())) for i in range(n)]
    # Initialize the adjacency list of the graph
    graph = [[] for i in range(n)]
    # Build the adjacency list of the graph
    for i in range(n):
        for j in range(n):
            if capacity_matrix[i][j] > 0:
                # Add forward and backward edges
                e1 = Edge(i, j, capacity_matrix[i][j])
                # Add backward edges
                e2 = Edge(j, i, 0)
                # Record the index of the reverse edge
                e1.rev_index = len(graph[j])
                e2.rev_index = len(graph[i])
                graph[i].append(e1)
                graph[j].append(e2)
    
    # Compute the maximum flow
    ans = max_flow(0, n - 1, graph)
    print(ans)
