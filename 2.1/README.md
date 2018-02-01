# 2.1  
### Description:  
Write code to remove duplicates from an unsorted linked list.  

### Assumptions:  
- uses LinkedList class so data in each node is a single int.  

### Example:  
- `Node[0]: 10 --> Node[1]: 100 --> Node[2]: 10 --> Node[3]: 1 -->` goes to `Node[0]: 100 --> Node[1]: 10 --> Node[2]: 1 -->`  

### Improvements:  
- O(1) space can be achieved by searching for duplicates as you go and then removing them. i.e. don't build a map  