////////////////////////////////////////////////////////////////////////
//
//   Author:           Reiley Walther
//   Creation Date:    April 3, 2019
//   Due Date:         April 6, 2019 
//   Course:           CSC136
//   Professor Name:   Dr. Carelli 
//   Assignment:       #3 
//   Filename:         Array.h 
//
//   Purpose:         This program is the header file for atest.cpp and
//                    computes methods like constructors, destructors,
//                    operator overloading and inspector methods.
//
////////////////////////////////////////////////////////////////////////

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cassert>
using namespace std;

template <class dataType> 
class Array {

public:
  Array(int arraySize= 3);       // default constructor
  Array(const dataType[], int);  // init from array - specify # to copy
  Array(const Array&);           // copy constructor
  ~Array();                      // destructor

  ////////////////////////////////////////////////////////////////////////
  //
  //   Method name:      getCapacity 
  //   Description:      Provides the full length of the array 
  //   Member Type:      Inspector
  //   Parameters:       none
  //   Return Value:     int - the length of the array 
  //
  ////////////////////////////////////////////////////////////////////////

  int getCapacity() const { return capacity; }

  ////////////////////////////////////////////////////////////////////////
  //
  //   Method name:      getNumUsed
  //   Description:      Provides the actual number of units used in the 
  //                     array 
  //   Member Type:      Inspector
  //   Parameters:       none
  //   Return Value:     int - the number of actual used items in array 
  //
  ////////////////////////////////////////////////////////////////////////

  int getNumUsed() const { return numUsed; }

  const Array<dataType> &operator=(const Array &); // assignment
  Array<dataType> &operator+=(dataType); // append element to array
  dataType &operator[](int);             // l-value subscript operator
  const dataType &operator[](int) const; // r-value subscript operator

private:
  int capacity,              // capacity of the array
      numUsed;               // number of elements in use
  dataType *ptr;             // pointer to first element of array
};

// Default constructor for class Array 
template <class dataType> 
Array<dataType>::Array(int arraySize) {
  capacity= (arraySize > 0 ? arraySize : 3);
  numUsed= 0;
  
  ptr = new dataType[capacity]; // create space for array
  assert( ptr != 0 );    // terminate if memory not allocated
  for (int i = 0; i < capacity; ++i) {
    ptr[i] = dataType();
  }
}

// constructor initializes from a standard array
// designate the number of elements to copy (must be at least 3)
template <class dataType>
Array<dataType>::Array(const dataType A[], int arraySize) {
  assert(arraySize > 0); 
  capacity = (arraySize > 3 ? arraySize : 3);
  numUsed = arraySize;  //changed to assign like this instead of numUsed = Capacity

  ptr = new dataType[capacity]; // create space for array
  assert( ptr != 0 );    // terminate if memory not allocated
  for (int i = 0; i < capacity; ++i) {
    ptr[ i ] = A[i];
  }
}

// Copy constructor for class Array
template <class dataType> 
Array<dataType>::Array(const Array &A) {  
  // no need to check if > 5
  // an existing array will be
  capacity = A.capacity;
  numUsed = A.numUsed;  //changed to this from numUsed = capacity
    
  ptr = new dataType[capacity]; // create space for array
  assert( ptr != 0 );    // terminate if memory not allocated

  for ( int i = 0; i < A.capacity; i++ )
     ptr[ i ] = A.ptr[ i ];  // copy init into object
}

// Destructor for class Array
template <class dataType> 
Array<dataType>::~Array() {
  delete [] ptr;            // reclaim space for array
}

// Overloaded assignment operator
template <class dataType> 
const Array<dataType> &Array<dataType>::operator=( const Array &right ) {

  if ( &right != this ) {  // check for self-assignment
    // for arrays of different sizes, deallocate original
    // left side array, then allocate new left side array.
    if ( capacity != right.capacity ) {
       delete [] ptr;         // reclaim space
       capacity=right.capacity; // resize this object
       ptr = new dataType[capacity+1]; // create space for array copy
       assert( ptr != 0 );    // terminate if not allocated
    }
    
    numUsed = right.numUsed;  //added the definition of numUsed for overloading operator


    for ( int i = 0; i < right.capacity; i++ )
       ptr[ i ] = right[ i ];  // copy array into object
  }

  return *this;   // enables x = y = z;
}

// Append element to array
template <class dataType> 
Array<dataType> &Array<dataType>::operator+=(dataType elt) {
  dataType *temp=new dataType[capacity+1];
    for (int i = 0; i < capacity; ++i) temp[i]=ptr[i];
    if(numUsed >= capacity)  //compares numUsed and capacity and increases capacity
      capacity++;
    temp[numUsed++]=elt;
  delete[] ptr;
  ptr=temp;
  
  return(*this);
}

// Overloaded subscript operator for non-const Arrays
template <class dataType> 
dataType &Array<dataType>::operator[](int subscript) {
  if(subscript == (capacity+1)) //compares subscript to capacity and automatically expands the capacity FOR HONORS!
    capacity++;
  // check for subscript out of range error
  assert( subscript >= 0 && subscript <= capacity ); //adjusted the < to a <=
  if(subscript > numUsed) //compares numUsed and subscript and sets numUsed to subscript if subscript is larger to get to the index being used
    numUsed = subscript;

  return ptr[numUsed]; // reference return
}

// Overloaded subscript operator for const Arrays
template <class dataType> 
const dataType &Array<dataType>::operator[](int subscript) const {
  // check for subscript out of range error
  assert( subscript >= 0 && subscript <= capacity );

  return ptr[ subscript ]; // const reference return
}

// Overloaded output operator for class Array 
template <class dataType> 
ostream &operator<<(ostream &output, const Array<dataType> &A) {
  int i;
  output << "[ ";
  for ( i = 0; i < A.getNumUsed(); i++ ) {
     if (i != 0) { output << ", "; }
     output << A[ i ]; 
  }
  output << " ]" << endl;;

  return output;   // enables cout << x << y;
}

#endif
