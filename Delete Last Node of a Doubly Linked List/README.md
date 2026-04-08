Algorithm
To delete the tail of a doubly linked list, we update the linkage between its last node and its second last node. Since a doubly linked list is bidirectional, we set the second last node's next pointer and the last node's back pointer to null. Then, we can return the head of the doubly linked list as the result.

Some edge cases to consider is when the list is empty or when there is only one node in the entire list.
If the list is empty, return immediately as there is nothing to delete.
If list has only one node, delete the node and return an empty list.
Traverse the doubly linked list to the last node and keep track of it using the tail pointer.
Access the second last node using the tail's back pointer
Set the next pointer of the second last node to null. This step effectively disconnects the initial tail node from the list in the forward direction, making second last node as the new tail node.
Set the back pointer of the tail node to null. This ensures that the tail node no longer points back to the second last node.
Return the head of the doubly linked list as the result.
