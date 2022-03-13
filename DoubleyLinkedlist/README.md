A Doubly Linked List (DLL) contains an extra pointer, typically called previous pointer.
Following are advantages/disadvantages of doubly linked list over singly linked list.
Advantages over singly linked list 
1) A DLL can be traversed in both forward and backward direction. 
2) The delete operation in DLL is more efficient if pointer to the node to be deleted is given. 
3) We can quickly insert a new node before a given node. 
In singly linked list, to delete a node, pointer to the previous node is needed. To get this previous node, sometimes the list is traversed. In DLL, we can get the previous node using previous pointer. 
 

 
Disadvantages over singly linked list 
1) Every node of DLL Require extra space for an previous pointer. It is possible to implement DLL with single pointer though (See this and this). 
2) All operations require an extra pointer previous to be maintained. For example, in insertion, we need to modify previous pointers together with next pointers. For example in following functions for insertions at different positions, we need 1 or 2 extra steps to set previous pointer.
Insertion 
A node can be added in four ways 
1) At the front of the DLL 
2) After a given node. 
3) At the end of the DLL 
4) Before a given node.
