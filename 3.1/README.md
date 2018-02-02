# 3.1  
### Description:  
Describe how you would use a single array to implement three stacks.  

This can be achieved by changing the array indexing scheme.
That is:
- the first stack gets indicies 0, 3, 6, 9, ... , 3 * s1_size
- the second stack gets indicies 1, 4, 7, 10, ... , 3 * s2_size + 1
- the third stack gets indicies 2, 5, 8, 11, ... , 3 * s3_size + 2  

