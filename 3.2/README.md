# 3.2  
### Description:  
How would you design a stack which in addition to `push` and `pop`, has a function `min` which returns the minimum element? `Push`, `pop`, and `min` should all operate in O(1) time.  

My implementation in `../Stack/` can be slightly modified to achieve this functionality. Steps:
1. Create a new private member variable to point to the min element.
2. Update the enqueue method to check if the iterm to be enqueued is smaller than the current min. if it is, then change the min to point to item to be enqueued, otherwise leave it. If there is no min at the time of enqueueing, it implies the list is empty so the item to be enqueued automatically has the min ptr assigned to it.
3. Add a method `getMin()` which returns the ptr to the current minimum item.  
