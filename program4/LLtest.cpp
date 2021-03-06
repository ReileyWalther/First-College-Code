////////////////////////////////////////////////////////////////////////
//
//   Author:           Reiley Walther
//   Creation Date:    April 23, 2019 
//   Due Date:         April 27, 2019
//   Course:           CSC136 019
//   Professor Name:   Dr. Carelli 
//   Assignment:       #4
//   Filename:         LLtest.cpp 
//
//   Purpose:        
//      This program will provide output and make use of header files to
//      manipulate data and linked lists easier.
//
////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <stdlib.h>
#include "LinkedList.h"
#include "Student.h"

int main()
{
  // create an integer list
  LinkedList<int> ilist;

  //create a string list (part 2)
  LinkedList<string> slist;
 
  ///////////////////////
  ////// Section A //////
  ///////////////////////
  cout << "----------------------" << endl;
  cout << "Linkedlist of integers" << endl;
  // add some values (out of order)
  for(int i=0; i<=5; i++) {
    if(i % 2) ilist.add(i);
    else ilist.add(-i);
  }

  // output the list
  cout << "integer List:" << endl;
  cout << ilist << endl;
  cout << endl;

  // add some items
  ilist.add(-1); ilist.add(6); 
  // output the list
  cout << "after adding items:" << endl;
  cout << ilist << endl;
  cout << endl;

  // this is a repeat - it should not get added!!!
  ilist.add(5); 
  // output again
  cout << "after attempting to add a duplicate:" << endl;
  cout << ilist << endl;
  cout << endl;

  ilist.sortAscend(); 
  cout << "Sort:" << endl;
  cout << ilist << endl;
  cout << endl;

  ilist.reverse(); 
  cout << "Reverse:" << endl;
  cout << ilist << endl;
  cout << endl;

  ///////////////////////
  ////// Section B //////
  ///////////////////////
  // test LinkedList using strings
  cout << "---------------------" << endl;
  cout << "Linkedlist of strings" << endl;
  cout << endl;
  // WRITE THIS SECTION YOURSELF

  // add some letters and strings
   slist.add("A");
   slist.add("HIJ");
   slist.add("XY");
   slist.add("Z");
   slist.add("NAME");
   slist.add("DOG");
  

  // output the list
  cout << "String List:" << endl;
  cout << slist << endl;
  cout << endl;


  // add some items
  slist.add("HELLO"); slist.add("ABC");
  // output the list
  cout << "after adding string items:" << endl;
  cout << slist << endl;
  cout << endl;


  // this is a repeated string - it should not get added to the list
  slist.add("A");
  // output again
  cout << "after attempting to add a duplicate:" << endl;
  cout << slist << endl;
  cout << endl;

  slist.sortAscend();
  cout << "Sort strings:" << endl;
  cout << slist << endl;
  cout << endl;

  slist.reverse();
  cout << "Reverse list:" << endl;
  cout << slist << endl;
  cout << endl;


  ///////////////////////
  ////// Section C //////
  ///////////////////////
  cout << "-----------------------------" << endl;
  cout << "Linkedlist of Student objects" << endl;
  cout << endl;

  // Here is a list of students in unsorted order
  // together with their total medal and gold medal counts
  //   Name      GPA
  // ------------------
  //  Mary       3.2
  //  Noah       2.3
  //  James      3.88
  //  Olivia     2.7
  //  Sophia     3.6

  // Create Student objects for each student
  // like this:
  // Student S1("Mary", 3.2); 

  // 1) create an empty Student list 
  // 2) add the Studenst in the unsorted order as given in the table above
  //    using the list add() method
  // 3) output the contents of the Linked list

  // 4) try to add "Noah" to the list again with GPA=2.0
  //    - He should NOT get added if add() was correctly coded
  // 5) output the contents of the Linked list after the attempted addition
  //    - the list should be unchanged
  //
  // 6) try to add "Noah" once more with GPA=3.0
  //    - The new item should replace the old one
  // 7) output the contents of the Linked list after the attempted addition
  //    - Noah should be updated
  //
  // 8) sort the list 
  // 9) output the contents of the sorted Linked List 
  //
  // 10) reverse the list
  // 11) output the contents of the reversed Linked List 

  Student S1("Mary", 3.2);
  
  // Create an empty Student list 
  LinkedList<string> Student;

  // add some students in random order
  Student S2("Noah", 2.3);
  Student S3("James", 3.88);
  Student S4("Olivia", 2.7);
  Student S5("Sophia", 3.6);


  // output the Student(s)
  cout << "Linkedlist of Student objects" << endl;
  cout << Student << endl;
  cout << endl;

  // try to add someone a second time using the add method
  // with value < existing - it should not happen
  Student.add("Noah", 2.0);

  // output the Student(s) after add
  cout << "Student (try to add a smaller value)" << endl;
  cout << Student << endl;
  cout << endl;
  
  // do it again with a larger value
  // output the Student(s) after add
  Student.add("Noah", 3.0);
  cout << "Student (try to add a larger value)" << endl;
  cout << Student << endl;
  cout << endl;
  
  // sort them by number

  
  // output the sorted list
  cout << "Student (sorted)" << endl;
  cout << Student << endl;
  cout << endl;

  // reverse the list
  Student.reverse();

  // output the reversed list
  cout << "Student (reversed)" << endl;
  cout << Student << endl;
  cout << endl;
  
  /////////////////////////
  ////// Honors Only //////
  /////////////////////////
  // create a float list
  LinkedList<float> flist;
 
  cout << "----------------------" << endl;
  cout << "Linkedlist of floats" << endl;
  // add some values (out of order)
  for(int i=0; i<=12; i++) {
    if(i % 2) flist.add(i);
    else flist.add(-i);
  }

  // output the list
  cout << "float List:" << endl;
  cout << flist << endl;
  cout << endl;

  // run prunedList with args: 0 & 2
  // output the list
  cout << "pruned (0,2):" << endl;
  prunedList(0,2);
  cout << flist << endl;
  cout << endl;

  // run prunedList with args: 1 & 3
  // output the list
  cout << "pruned (1,3):" << endl;
  prunedList(1,3);
  cout << flist << endl << endl;
}
