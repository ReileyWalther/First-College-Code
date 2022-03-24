////////////////////////////////////////////////////////////////////////
//
//   Author:           Reiley Walther
//   Creation Date:    April 23, 2019 
//   Due Date:         April 27, 2019
//   Course:           CSC136 019
//   Professor Name:   Dr. Carelli 
//   Assignment:       #4
//   Filename:         Student.cpp 
//
//   Purpose:        
//      This program will define and overload operators.
//
////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <iomanip>
#include "Student.h"

using namespace std;

// Output a Student
ostream& operator<<(ostream &os, const Student &S) {
   os << fixed << setprecision(2)
     << left << setw(12) << S.getName() << "  " << right
     << setw(4) << S.getGPA() << endl;
  return os;
}

// input a Student
istream& operator>>(istream &is, Student &S) {
  string name; float gpa;
  is >> name >> gpa;
  S.setName(name);
  S.setGPA(gpa);
  return is;
}

//////////////////////////////////////////
// Complete the following operators:
//   operator==
//   operator>=
//////////////////////////////////////////



////////////////////////////////////////////////////////////////////////
//
//   Method name:      operator==
//   Description:      Comparison operator of student names 
//   Member Type:      Inspector
//   Parameters:       const Student &s
//   Return Value:     bool - if names are same or not 
//
////////////////////////////////////////////////////////////////////////

// operator== should compare Student names
bool Student::operator==(const Student &s) {
  if(this.getName() == s.getName())
    return true;
  else
    return false;
}


////////////////////////////////////////////////////////////////////////
//
//   Method name:      operator>=
//   Description:      Comparison operator of student GPA scores 
//   Member Type:      Inspector
//   Parameters:       const Student &s
//   Return Value:     bool - if GPA is greater or equal, or less than
//                            another GPA
//
////////////////////////////////////////////////////////////////////////

// operator>= should compare Student gpa's
bool Student::operator>=(const Student &s) {
  if(this.getGPA() > s.getGPA() || this.GPA() == s.getGPA())
    return true;
  else
    return false;
}
