//Author:            Reiley Walther
//Creation Date:     September 26, 2018
//Due Date:          October 2, 2018
//Course:            CSC 135
//Professor Name:    Dr. Carelli
//Assignment:        #2 (Selection - Internet Service Provider)
//File Name:         internet.cpp
//Description:       The program asks for a specific type of internet package a user has purchased and displays the users' monthly bill including the package type, hours used, if applicable, and the total charge.

//****************************************************

#include <iostream>  //class for input/output
#include <string>    //class for strings
#include <iomanip>   //class for input/output manipulation

using namespace std; //use for standard namespace

int main()
{
  //declaring variables
  char package;
  int hours,
      addhours;
  float charge;
  bool valid = false;

  //getting input of package
  cout << "Enter package (A, B, or C): ";
  cin >> package;

  switch (package) {  //Validating the package entered
    case 'A':
    case 'a':
    case 'B':
    case 'b':
      cout << "Enter the number of hours used: ";
      cin >> hours;
      valid = true;
      break;
    case 'C':
    case 'c':
      valid = true;
      hours = -1;
      charge = 19.99;
      break;
  }

  if (!valid) {  
    cout << endl << "ERROR: Invalid package - must be A, B or C!" << endl << endl;
      return 1;
  }
  
  
  //Validating number of hours
  if (package == 'A' || package == 'a') {
    if (hours > 10)
      addhours = hours - 10;
    else
      addhours = 0;
    charge = 9.95 + (addhours*2.00);
  }

  if (package == 'B' || package == 'b') {
    if (hours > 20)
      addhours = hours - 20;
    else
      addhours = 0;
    charge = 14.95 + (addhours*1.00);
  }

  //Formatting and displaying output
  cout << fixed << setprecision(2);
  cout << endl << "Your Monthly Bill" << endl;
  cout << "-----------------" << endl;
  cout << setw(15) << left << "Package: " << setw(7) << right << package << endl;

  if (package != 'c' && package != 'C') //validating and displaying package 'c'
    cout << setw(15) << left << "Hours Used: " << setw(7) << right << hours << endl;

  cout << setw(15) << left << "Total charge: " << "$" << setw(6) << right << charge << endl << endl;
    

  return 0;
}
