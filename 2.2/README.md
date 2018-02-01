# 2.2  
### Description:  
Implement an algorithm to find the kth to last element in a singly linked list.  

### Assumptions:  
- uses LinkedList class so data in each node is a single int.  

### Example:  
- find 2nd to last in: `Node[0]: 10 --> Node[1]: 100 --> Node[2]: 10 --> Node[3]: 1 -->` yields pointer to `Node[2]`  

### Improvements:  
- added length to LinkedList class (this means we don't have to iterate the list twice - worst case is one full iteration over list)