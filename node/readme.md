A node is made up of two parts:

1. Value: Data we're storing in our data structure
2. Pointer: Pointer to another node

Traversal:
Traversal in linked list can be done using the head pointer, i.e., the starting point of linked list.

1. We can take a temporary pointer and keep it moving further until it reaches NULL, i.e., the last Node of the list.
   You can do it by using, temp = temp -> next

Insertion:

1. Insert a node at the start:
   1. Create the new node
   2. Make the next pointer of the new node point to the next node (i.e., where the head was pointing previously)
   3. Make the head pointer point to the new node
