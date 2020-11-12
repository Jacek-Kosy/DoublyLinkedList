# DoublyLinkedList
My implementation of Doubly Linked List in C++

This implementation relies on a special node called sentinel with irrelevant data
whose member 'next' points to the first "true" node and 'prev' to the last one.

An empty list is represented by a sentinel whose both member pointers ('prev' and 'last')
point to itself.

I prepared the following functions to simplify operations on the list:
  constructor for creating an empty list;
  empty - returns true if the list is empty;
  push_front - adds an element at the beginning of the list;
  push_back - adds an element at the end of the list;
  print_fwd - prints to a given stream (by default is cout) all elements of the list (data from the nodes in one line, separated by space)
  print_rev = works as print_fwd but elements are printed in reverse order
  find_first - finds the first node with data equal to a given value and returns the pointer to this node or nullptr if there is no such node;
  insert_after - gets the pointer to a node and inserts a new node with a given data after it
  insert_before - works as insert_after, but inserts the new node before the node it has got as an argument
  delete_node - gets the pointer to a node and deletes it, afterwards it prints data from the deleted node
  reverse - reverses the order of all nodes
  clear - deletes all nodes (except sentinel) so the resulting object represents an empty list, afterwards it prints data from all the deleted nodes
  destructor for deleting all the nodes including sentinel
 
The main function contains code created for testing purposes.
