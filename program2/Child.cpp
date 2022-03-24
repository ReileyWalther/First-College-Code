////////////////////////////////////////////////////////////////////////
//
//    Author:           Reiley Walther
//    Creation Date:    February 23, 2019
//    Due Date:         March 1, 2019
//    Course:           CSC136 019
//    Professor Name:   Dr. Carelli
//    Assignment:       #2
//    Filename:         Child.cpp
//
//    Purpose:   
//
////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
using namespace std;

#include "Child.h"

// constructor
Child::Child(string na, int q, int d, int n, int p) {
  name= na; quarters= q; dimes= d; nickels= n; pennies= p;
}

//Initialize static members from 'Child.h'
const float Child::Qvalue = 0.25;
const float Child::Dvalue = 0.10;
const float Child::Nvalue = 0.05;
const float Child::Pvalue = 0.01;

////////////////////////////////////////////////////////////////////////////
//
//   Method name:     getTotal
//   Description:     Computes the cash value of the child's "holdings"
//   Member Type:     Inspector
//   Parameters:      none
//   Return Value:    float - total child's holdings/savings
//
///////////////////////////////////////////////////////////////////////////
float Child::getTotal() const{
  float Total = (quarters*Qvalue) + (dimes*Dvalue) + (nickels*Nvalue) + (pennies*Pvalue);

  return Total;
}

////////////////////////////////////////////////////////////////////////////
//
//   Method name:     getAward
//   Description:     Determines the child's "star award"
//   Member Type:     Inspector
//   Parameters:      none
//   Return Value:    char - star awarded to a child based on total
//
///////////////////////////////////////////////////////////////////////////
char Child::getAward() const {
  float tot = getTotal();

  if(tot>=10) 
    return 'G';
  else if(tot>=5)
    return 'S';
  else
    return 'B';
}

//istream operator overloads
//define the istream for the operator >
////////////////////////////////////////////////////////////////////////////
//
//   Method name:     Child::operator>
//   Description:     Compares which date is more recent(bigger)
//   Member Type:     Inspector
//   Parameters:      const int - &cash
//   Return Value:    bool - returns true/false if date is bigger or not
//
///////////////////////////////////////////////////////////////////////////
bool Child::operator>(const Child &cash) const{
  float tot = getTotal();

  if(cash.getTotal() < tot) return true;
  if(cash.getTotal() > tot) return false;
}

//define the istream for the operator <
////////////////////////////////////////////////////////////////////////////
//
//   Method name:     Child::operator<
//   Description:     Compares which date is less recent(smaller)
//   Member Type:     Inspector
//   Parameters:      const int - &cash
//   Return Value:    bool - returns true/false if date is smaller or not
//
///////////////////////////////////////////////////////////////////////////
bool Child::operator<(const Child &cash) const{
  //string name = getName();

  if(cash.getName() > name) return true;
  if(cash.getName() < name) return false;
}


//define the istream for the operator ++
////////////////////////////////////////////////////////////////////////////
//
//   Method name:     Child::operator++
//   Description:     Preincrement of quarters only
//   Member Type:     Mutator
//   Parameters:      none
//   Return Value:    Child - updates the quarters of an instance
//
///////////////////////////////////////////////////////////////////////////
Child &Child::operator++() {
  int qs = getQuarters();
  qs = qs + 1;
  setQuarters(qs);

  return *this;
}


//Honors required!
//define the istream for the operator +=
///////////////////////////////////////////////////////////////////////////
//
//    Method Name:     operator+=
//    Description:     this method increases the amount of cash using
//                     simplest change by the amount specified
//    Member type:     Mutator
//    Parameters:      float cash - cash being added
//    Return Value:    Child - updates the current associated variables
//
///////////////////////////////////////////////////////////////////////////
Child &Child::operator+=(float amount) {
  makeChange(amount,quarters,dimes,nickels,pennies);
  return *this;
}


//define the static makeChange method
///////////////////////////////////////////////////////////////////////////
//
//    Method Name:     makeChange
//    Description:     this method finds the amount of change for a person
//                     in the best change possible
//    Member type:     Mutator
//    Parameters:      float amount -
//                     int &q - reference to quarters
//                     int &d - reference to dimes
//                     int &n - reference to nickels
//                     int &p - reference to pennies
//    Return Value:    void - none
//
///////////////////////////////////////////////////////////////////////////
static void makeChange(float amount, int &q, int &d, int &n, int &p) {
  int fund = amount*100;
  int current = fund%25;
  fund = fund - current;
  q = q + fund/25;
  current = fund%10;
  fund = fund - current;
  d = d + fund/10;
  current = fund%5;
  fund = fund - current;
  n = n + fund/5;
  p = p + current;
}


// istream operator overload
istream &operator>>(istream &input, Child &s) {

   string name; int q; int d; int n; int p;

   input >> name >> q >> d >> n >> p;
   s.setName(name);
   s.setQuarters(q);
   s.setDimes(d);
   s.setNickels(n);
   s.setPennies(p);

   return input;   // enables cascading
}

//define the istream for the operator >>
//ostream operator overload
ostream &operator<<(ostream &output, const Child &s) {
  
  output << left << setw(10) << s.getName()
	 << right << setw(3) << s.getQuarters()
	 << right << setw(3) << s.getDimes()
	 << right << setw(3) << s.getNickels()
	 << right << setw(3) << s.getPennies()
	 << right << setw(7) << s.getTotal()
	 << right << setw(2) << s.getAward() << endl;

  return output;
}
