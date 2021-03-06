/***************************************************************
Author:         
Assignment:     #3
Filename:       atest.cpp 

Other stuff

Purpose:        
***************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include "Array.h"

using namespace std;

template <typename eltType> 
void printArray(const Array<eltType> &MyArray);

int main()
{ 
  ///////////////////////////////////
  // create an empty Array object 
  cout << "Default Constructor" << endl;
  Array<int> iList1(3);
  printArray(iList1);

  // test += on object that is not at capacity
  cout << "Add an item (under capacity)" << endl;
  iList1 += 2;
  printArray(iList1);

  // change the last value
  cout << "Change last value" << endl;


  // test += on object that is not at capacity
  cout << "Add item (at capacity)" << endl;


  ///////////////////////////////////////////////////
  // new object using array initialization
  cout << "Constructor from standard array:" << endl;
  float farray[]= { 10.1, 20.2, 30.3, 40.4 , 50.5 };


  cout << "Constructor from standard array, (under capacity) :" << endl;


  // Copy Constructor
  cout << "Copy Constructor:" << endl;


  cout << "Copy Constructor (under capacity):" << endl;

  
  // test assignment operator
  cout << "Assignment:" << endl;


  cout << "Assignment (under capacity):" << endl;


  ///////////////////////////////////////////////////
  // Honors only:
  // change an existing value
  // cout << "-------------- Honors Only ---------------" << endl;
  // cout << "Change value beyond capacity" << endl;
  // cout << "Array before" << endl;
  //
  // cout << "Array after adding element at position 5" << endl;


  return(0);
}

template <typename dataType> 
void printArray(const Array<dataType> &MyArray) { 
  cout << "  Capacity: " << MyArray.getCapacity() 
       << ", Elements in Use: " << MyArray.getNumUsed() << endl;
  cout << "  Contents: " << MyArray << endl;
  cout << endl;
}

