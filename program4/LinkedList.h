///////////////////////////////////////////////////////////////////////
//
//   Author:           Reiley Walther
//   Creation Date:    April 23, 2019 
//   Due Date:         April 27, 2019 
//   Course:           CSC136 019
//   Professor Name:   Dr. Carelli 
//   Assignment:       #5
//   Filename:         LinkedList.h 
//
//   Purpose:        
//      This program provides the classes, definitions and declarations
//      for the linked lists used in the main program.
//
////////////////////////////////////////////////////////////////////////

#ifndef LINKEDLIST
#define LINKEDLIST
#include <iostream>
using namespace std;

#include "LListIter.h"

// Need to prototype template classes 
// since they are referenced as friends below
template <typename T> class LListIter;

/////////////////////////////////////////////////////
// define a class to contain one linked list Node
template <typename T> 
class Node {  
  private:
    Node(T value=T(), Node* ptr=NULL) {
      data= value; next= ptr;
    }

    T getData() { return data; }
    void setData(const T& d) { data= d; }
    Node *getNext() { return next; }

    T data;
    Node *next;

    // must make LinkedList and LListIter friends to Node
    // otherwise, Node pointers will need to be passed around
    // allowing visiblity into LL elements
    friend class LinkedList<T>;
    friend class LListIter<T>;
};

/////////////////////////////////////////////////////
// the linked list class
template <typename T> 
class LinkedList {
  public:
    // Default constructor
    LinkedList();
    // destructor
    ~LinkedList();

    // add an item to the end
    void add(T); 
    // erase item with specified value
    bool erase(T);
    // delete everything
    void deleteAll();

    // Is the LinkedList empty?
    bool isEmpty();
    // find the max value in the list
    T findMax();
    // sort the list in ascending order
    void sortAscend();
    // reverse the order of items in the list 
    void reverse();

    // create a pruned list from the linked list
    LinkedList<T> &prunedList(int start, int step);

  private:
    // is the item already in the list?
    Node<T>* findItem(T);

    // linked list pointer
    Node<T>* first;

    // remove item with specified value
    // return the removed node              //removes an item BUT DOESN'T DELETE IT
    Node<T>* remove(T);

    // make iterator a friend
    friend class LListIter<T>;
};
 
// Output a linked list, using a list iterator
template <typename T> 
ostream& operator<<(ostream &os,const LinkedList<T> &llist) {  
  LListIter<T>  iter(llist);
  if(!iter.end()) { 
    do {
      os << " " << iter.getValue();
    } while(iter.next());
  }
  return os;
}

/////////////////////////////////////////////////////
// Linked List Implementations
/////////////////////////////////////////////////////

// Construct empty LinkedList
template <typename T> 
LinkedList<T>::LinkedList() {
  first= NULL;
}

// Free all Nodes
template <typename T> 
LinkedList<T>::~LinkedList() {
  deleteAll();
}

// is list empty?
// Note: inline !!!!!!!!!!!!
template <typename T> inline 
bool LinkedList<T>::isEmpty() {
  return (first == NULL);
}

// erase an item from the llist 
// return true if successful (false if not found)
template <typename T> 
bool LinkedList<T>::erase(T val) {  
  Node<T> *current= first;
  if(!isEmpty()) {
    // val is first item, erase it
    if(val == current->data) {
      first= current->next; delete current;
      return true;
    }
    // not the first, check the rest
    while(current->next != NULL) {
      if(val == current->next->data) {
        Node<T> *temp= current->next->next;
        delete current->next; current->next= temp;
        return true;
      }
      // not found, go on to the next one
      current= current->next;
    }
  }
  return false;
}

// Delete all Nodes in the linked list
template <typename T> 
void LinkedList<T>::deleteAll() {  
  Node<T> *ptr= first;
  while (ptr != NULL) {  
    Node<T> *doomed = ptr;
    ptr = ptr->next;
    delete doomed;
  }
}

// sort the linked list in ascending order
template <class T>
void LinkedList<T>::sortAscend() {
  Node<T> *nptr= NULL;
  Node<T> *lptr= nptr;

  while(!isEmpty()) {
    T data= findMax();
    lptr= nptr;
    nptr= remove(data);
    nptr->next= lptr;
  }
  first= nptr;
}

/////////////////////////////////////////////////////
//
// COMPLETE THE FOLLOWING METHODS !!!
//
/////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////
//
//   Method name:      findItem
//   Description:      Finds an item in a linked list 
//   Member Type:      Inspector
//   Parameters:       T val - value that may be in the link list to be
//                             removed
//   Return Value:     pointer value ptr/NULL 
//
////////////////////////////////////////////////////////////////////////
// Is this item in the linked list?
template <typename T> 
Node<T> *LinkedList<T>::findItem(T val) {  
  Node<T> *ptr = first;
  while(ptr != NULL) {
    if(ptr->data == val)
      return *ptr;
    ptr = ptr->next;
  }
  return NULL;
}

////////////////////////////////////////////////////////////////////////
//
//   Method name:      add
//   Description:      Adds an item onto the end of the linked list 
//   Member Type:      Mutator
//   Parameters:       T val - value to be added onto the linked list
//   Return Value:     void - none
//
////////////////////////////////////////////////////////////////////////

// Add an item to the end of the list
// replace the item if the new value is > the existing value
template <typename T> 
void LinkedList<T>::add(T val) {
  bool duplicate = false;
  if(isEmpty()) {
    first = new Node<T>(val,first);
  }
  else {
    Node<T> *current = first;
    while(current->next != NULL && duplicate == false) {
      if(val == current->data){
	duplicate = true;
      }
      current = current->next;
    }
    if(!duplicate) {
      current->next = new Node<T>(val,current->next);
    }
  }
}

////////////////////////////////////////////////////////////////////////
//
//   Method name:      remove
//   Description:      Removes an item from the link list, returns a 
//                     pointer value of removed item but does not delete
//                     the item 
//   Member Type:      inspector
//   Parameters:       T val - the value to be removed from linked list
//   Return Value:     pointer value - ptr/NULL
//
////////////////////////////////////////////////////////////////////////

// remove an item from the llist 
// return pointer to the removed item if successful 
// do NOT delete the removed item!!!
// return NULL if not found
template <typename T> 
Node<T> *LinkedList<T>::remove(T val) {
  Node<T> *current=first;
  bool found = false;
  if(isEmpty()) {
    return NULL;
  }

  //  Node<T> *current=first;
  while((current->next != NULL) && (found == false)) {
    if(val == current->next->data) {
      found = true;
      break;
    }
    current = current->next;
  }
  if(found)
    return current;//->next;
  else
    return NULL;
  
}

////////////////////////////////////////////////////////////////////////
//
//   Method name:      findMax
//   Description:      Seeks out the biggest number on linked list 
//   Member Type:      Inspector
//   Parameters:       none
//   Return Value:     pointer value - max/NULL
//
////////////////////////////////////////////////////////////////////////

// get the max value in the list
// assumes the list is not empty
// if it is, return the default value for T
template <typename T>
T LinkedList<T>::findMax() {
  T max= T();
  Node<T> *ptr = first;
  if(first != NULL) {
    while(ptr != NULL) {
      if(ptr->data > max)
	max = ptr->data;
      ptr = ptr->next;
    }
    return max;
  }
  return NULL;
}

////////////////////////////////////////////////////////////////////////
//
//   Method name:      reverse
//   Description:      Switches the order of the linked list around 
//   Member Type:      Mutator
//   Parameters:       none
//   Return Value:     void - none 
//
////////////////////////////////////////////////////////////////////////

// reverse the item order
template <class T>
void LinkedList<T>::reverse() {
  Node<T> *current = first;
  Node<T> *prev = NULL;
  Node<T> *next;
 
  while(current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  first = prev;  
}

////////////////////////////////////////////////////////////////////////
//
//   Method name:      prunedList
//   Description:      Selects the starting point and step for new list 
//   Member Type:      Mutator
//   Parameters:       int start - beginning point of new list (input)
//                     int step - the step for the list (input)
//   Return Value:     reference to new list
//
////////////////////////////////////////////////////////////////////////

// prune this list
template <class T>
LinkedList<T> &LinkedList<T>::prunedList(int start, int step) {
  Node<T> *start = new Node<T>(start->getData(),start);
  Node<T> *current = start;
  while(current->next != NULL) {
    current->next = new Node<T>(step->getData(),step);
    current = current->next;
  }
  return start;
}
#endif
