/***************************************************************
Author:         Reiley Walther
Creation Date:  April 3, 2019
Due Date:       April 6, 2019
Course:         CSC136
Professor Name: Dr. Carelli
Assignment:     #3
Filename:       atest.cpp 

Purpose:        This program makes use of a header file to 
                manipulate arrays by showing partial additions
                and changes
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
  Array<int> iList1(3);  //creating an array and printing it out
  printArray(iList1);

  // test += on object that is not at capacity
  cout << "Add an item (under capacity)" << endl;
  iList1 += 2; //adding to the array at the beginning and printing it out
  printArray(iList1);

  // change the last value
  cout << "Change last value" << endl;
  iList1[iList1.getCapacity()] = 6;   //gets the last index of the array and chnges the value to the assigned number and prints it out
  printArray(iList1);

  // test += on object that is at capacity
  cout << "Add item (at capacity)" << endl; //adds a number onto a full capacity array and prints it out
  iList1 += 8;
  printArray(iList1);

  ///////////////////////////////////////////////////
  // new object using array initialization
  cout << "Constructor from standard array:" << endl;
  float farray[]= { 10.1, 20.2, 30.3, 40.4 , 50.5 };
  Array<float> iList2(farray,5); //calls a different array and provides a size for it to be printed out 
  printArray(iList2);

  cout << "Constructor from standard array, (under capacity) :" << endl;
  Array<float> iList3(farray,2); //same array as above is called but with less than 3 elements to be printed out
  printArray(iList3);

  // Copy Constructor
  cout << "Copy Constructor:" << endl;
  Array<float> iList4(iList2);  //copying an array to a new array
  printArray(iList4);

  cout << "Copy Constructor (under capacity):" << endl;
  Array<float> iList5(iList3);  //copying an array not to capacity to a new array
  printArray(iList5);
  
  // test assignment operator
  cout << "Assignment:" << endl;  //assigning an array to a new array
  Array<float> iList6 = iList4;
  printArray(iList6);

  cout << "Assignment (under capacity):" << endl;
  Array<float> iList7 = iList5;  //assigning an array not full capacity to a new array
  printArray(iList7);

  ///////////////////////////////////////////////////
  // Honors only:
  // change an existing value
  cout << "-------------- Honors Only ---------------" << endl;
  cout << "Change value beyond capacity" << endl;
  cout << "Array before" << endl;
  printArray(iList1); //print out initial array

  cout << "Array after adding element at position 5" << endl;
  iList1[iList1.getCapacity()+1] = 10; //increase last index and sets it to a given number and prints it out
  printArray(iList1);

  return(0);
}

/***************************************************************

Function Name:    printArray
Description:      Displays the output of the array in neat and
                  a well-formatted display
Parameters:       const Array<datatype> &MyArray - array (input)
Return value:     void - none

***************************************************************/
template <typename dataType> 
void printArray(const Array<dataType> &MyArray) { 
  cout << "  Capacity: " << MyArray.getCapacity() 
       << ", Elements in Use: " << MyArray.getNumUsed() << endl;
  cout << "  Contents: " << MyArray << endl;
  cout << endl;
}

