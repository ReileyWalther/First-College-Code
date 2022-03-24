#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

// struct definition for a child object
class Child {
public:

  // constructor
  Child(string name="", int q=0, int d=0, int n=0, int p=0);

  // Mutators (modifiers)
  void setName(string n) { name= n; }
  void setQuarters(int v) { quarters= v; }
  void setDimes(int v) { dimes= v; }
  void setNickels(int v) { nickels= v; }
  void setPennies(int v) { pennies= v; }

  // inspectors (accessors)
  string getName() const { return name; }
  int getQuarters() const { return quarters; }
  int getDimes() const { return dimes; }
  int getNickels() const { return nickels; }
  int getPennies() const { return pennies; }

  // methods for computing total cash and award "star"
  float getTotal() const;
  char getAward() const;

  // overloads
  // greater than - compares total
  bool operator>(const Child &) const; // greater than
  // less than - compares child names
  bool operator<(const Child &) const; // less than
  // pre-increment operator 
  Child &operator++();                 // add a quarter

  //////////////////////////////////////////////////////
  // The following 2 methods are required for Honors only!!!
  // given a cash amount, return the change in the reference variables
  static void makeChange(float amount, int &q, int &d, int &n, int &p);
  // += operator
  Child &operator+=(float);             // add cash

private:
  string name;   // child name
  int quarters;  // number of quarters
  int dimes;     // number of dimes
  int nickels;   // number of nickels
  int pennies;   // number of pennies

  // static members
  static const float Qvalue; // Value of a quarter
  static const float Dvalue; // Value of a dime
  static const float Nvalue; // Value of a nickel
  static const float Pvalue; // Value of a penny
};                  

// overload of external stream operators
ostream &operator<<(ostream &, const Child &);
istream &operator>>(istream &, Child &);

#endif
