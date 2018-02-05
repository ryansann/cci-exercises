# 4.1  
### Description:  
Given a directred graph, design an algorithm to find out whether there is a route between two nodes.  

### Assumptions:  
- Using BasicGraph implementation
- Using BFS instead of DFS (recursion seems harder for this one - practice exercise)

### Example:  
```
Graph (nodes = 5, edges = 5):
1 --> 2
2 --> 3
3 --> 4
4 --> 5
5 --> 1

result = true
______________________________

Graph (nodes = 5, edges = 5):
1 --> 2
2 --> 3
3 --> 4
4 --> 6
5 --> 1

result = false
```
