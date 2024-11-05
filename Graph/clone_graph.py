'''
To create a deep copy (or clone) of a connected undirected graph represented as an adjacency list, we need to carefully traverse the graph, ensuring that we create new nodes that reflect the original graph's structure without duplicating any references. Let's break this down in detail.

Understanding the Graph Structure
Graph Representation:
The graph is represented using an adjacency list, where each node contains a value (val) and a list of its neighbors.
For example, if we have the following adjacency list:
csharp
Copy code
adjList = [
  [2, 4],  // Node 1s neighbors are Node 2 and Node 4
  [1, 3],  // Node 2s neighbors are Node 1 and Node 3
  [2, 4],  // Node 3s neighbors are Node 2 and Node 4
  [1, 3]   // Node 4s neighbors are Node 1 and Node 3
]
This means:
Node 1 (val = 1) connects to Node 2 (val = 2) and Node 4 (val = 4).
Node 2 (val = 2) connects to Node 1 (val = 1) and Node 3 (val = 3).
Node 3 (val = 3) connects to Node 2 (val = 2) and Node 4 (val = 4).
Node 4 (val = 4) connects to Node 1 (val = 1) and Node 3 (val = 3).
'''




# Definition for a Node.
class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

from typing import Optional

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        
        # Dictionary to save cloned nodes
        cloned_nodes = {}
        
        # Function for DFS
        def dfs(original_node):
            # If the node is already cloned, return the cloned node
            if original_node in cloned_nodes:
                return cloned_nodes[original_node]
            
            # Clone the node
            cloned_node = Node(original_node.val)
            # Save the cloned node in the dictionary
            cloned_nodes[original_node] = cloned_node
            
            # Recursively clone neighbors
            for neighbor in original_node.neighbors:
                cloned_node.neighbors.append(dfs(neighbor))
            
            return cloned_node
        
        # Start cloning from the given node
        return dfs(node)