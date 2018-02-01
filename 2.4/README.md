# 2.4  
### Description:  
Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x. if x is contained within the list, the values of x only need to be after the elements less than x. The partition element x can appear anywhere in the "right partition" it does not need to appear between the left and right partitions

### Assumptions:  
- uses LinkedList class so data in each node is a single int.  

### Example:   
```
List:   3 --> 5 --> 8 --> 5 --> 10 --> 2 --> 1 -/->
Input:  x = 5
Output: 3 --> 1 --> 2 --> 10 --> 5 --> 5 --> 8 -/->
```  
