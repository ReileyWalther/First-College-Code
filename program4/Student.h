#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

// A class for storing student information
class Student {
public:
  
  // constructor
  Student(string N= "", float G= 0.0 ) :
      name(N), gpa(G) {}; 

  // get info
  string getName() const { return name; }
  float getGPA() const { return gpa; }

  // set the name
  void setName(string N) { name= N; }
  void setGPA(float G) { gpa= G; }

  // compare two Students 
  bool operator==(const Student &);
  // compare two Students by gpa 
  bool operator>=(const Student &);

private:
  string name;  
  float gpa;  
};

// print out a student
ostream& operator<<(ostream &, const Student &);
// input a student
istream& operator>>(istream &, Student &);

#endif
