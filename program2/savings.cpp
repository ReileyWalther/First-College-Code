////////////////////////////////////////////////////////////////////
//
//    Author:           Reiley Walther
//    Creation Date:    February 23, 2019
//    Due Date:         March 1, 2019
//    Course:           CSC136 019
//    Professor Name:   Dr. Carelli
//    Assignment:       #2
//    Filename:         savings.cpp
//
//    Purpose:      This program reads data from a file and outputs
//                  the data in a neat format using functions and
//                  classes.
//
////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#include "Child.h"

// read the data file, store in arrays
int readDatafile(Child[], int);
// output the list of Children
void outputList(Child[], int);

// sorting routines - use a bubble sort
void sortAscend(Child[], int);  // set this up to sort by name
void sortDescend(Child[], int); // set this up to sort by average
void swap(Child&, Child&);        // used by the bubble sort

main() {
  int arraysize= 12;  // size of Child array
  int numC=0;         // the number of children read
  Child clist[arraysize];
  float more;

  numC = readDatafile(clist,arraysize);       //call function to read and store variables

  outputList(clist,numC);                    //calls function to display output

  sortAscend(clist,numC);                    //calls function to sort and display names in ascending order
  cout << "Sorted Alphabetically:" << endl;
  outputList(clist,numC);                    //calls function to display output

  sortDescend(clist,numC);                   //calls function to sort and display totals in descending order
  cout << "Sorted by Total:" << endl;
  outputList(clist,numC);                    //calls function to display output
  
  cout << endl;
  cout << "Pre-increment test:" << endl;
  outputList(clist,1);                       //calls function to display output

  ++clist[0];                                //uses overloaded pre-increment operator
  outputList(clist,1);                       //calls function to display output
  cout << endl << endl;

  cout << "Enter cash amount: ";
  cin >> more;                                
  clist[numC] += more;                       //uses overloaded += operator

  cout << endl << "Change is:" << endl                                          //displays the change from the operator
       << right << setw(3) << clist[numC].getQuarters() << " quarters" << endl
       << right << setw(3) << clist[numC].getDimes() << " dimes" << endl
       << right << setw(3) << clist[numC].getNickels() << " nickels" << endl
       << right << setw(3) << clist[numC].getPennies() << " pennies" << endl
       <<endl;

  //for loop
  for(int i=0;i<numC;i++) {    //for loop used to display the last person in the lsit with their updated total
  cout << "Updated:" << endl;
  cout << setw(10) << clist[i].getName()
       << setw(3) << right << clist[i].getQuarters()
       << setw(3) << right << clist[i].getDimes()
       << setw(3) << right << clist[i].getNickels()
       << setw(3) << right << clist[i].getPennies()
       << setw(7) << right << clist[i].getTotal()
       << setw(2) << setprecision(2) << right << clist[i].getAward() << endl;
  }

  return 0;
}

////////////////////////////////////////////////////////////////////
//
//    Function Name:    readDatafile
//    Description:      Reads data from file and stores it in
//                      necessary variables.
//    Parameters:       Child list[] - array of childrens info
//                      int size - the number of children in array
//    return Value:     int - a successful/failure number for reading
//                      the data into the variables
//
////////////////////////////////////////////////////////////////////
int readDatafile(Child list[], int size) {
  string fname , name;
  ifstream ins;
  int num = 0,
    quarters, dimes, nickels, pennies;
  
  cout << "Enter the file name: ";
  cin >> fname;

  ins.open(fname.c_str());                //attempts to open the file
  
  if(ins.fail()) {                 //tests if the file fails to open and displays a message if it fails
    cout << "ERROR opening file: " << fname << endl << endl;
    ins.clear();
    ins.ignore(100,'\n');
    return -1;
  }

  ins >> name >> quarters >> dimes >> nickels >> pennies;    //reads from input file

  list[num].setName(name);               //stores read data into the necessary variables
  list[num].setQuarters(quarters); 
  list[num].setDimes(dimes);
  list[num].setNickels(nickels); 
  list[num].setPennies(pennies);
  num++;

  while(!ins.eof() && (num<size)) {             //while loop tests for end of file and only goes to the appropriate size
    ins >> name >> quarters >> dimes >> nickels >> pennies;

    list[num].setName(name);
    list[num].setQuarters(quarters);
    list[num].setDimes(dimes);
    list[num].setNickels(nickels);
    list[num].setPennies(pennies);
    num++;
    }

  return num;
}

////////////////////////////////////////////////////////////////////
//
//    Function Name:    outputList
//    Description:      Outputs a well formatted list of results.
//    Parameters:       Child list[] - array of childrens info
//                      int size - the number of children in array
//    return Value:     void - none
//
////////////////////////////////////////////////////////////////////
void outputList(Child list[], int size) {
  cout << fixed;

  cout << "Children data:" << endl
       << "--------------" << endl;

  for(int i=0;i<size;i++) {
    cout << setw(10) << list[i].getName()
	 << setw(3) << right << list[i].getQuarters()
	 << setw(3) << right << list[i].getDimes()
	 << setw(3) << right << list[i].getNickels()
	 << setw(3) << right << list[i].getPennies()
	 << setw(7) << right << list[i].getTotal()
	 << setw(2) << setprecision(2) << right << list[i].getAward() << endl;
  }

  cout << endl;
}

////////////////////////////////////////////////////////////////////
//
//    Function Name:    swap
//    Description:      Swaps appropriate values with each other
//    Parameters:       Child &A - first child comapred
//                      Child &B - second child compared
//    return Value:     void - none
//
////////////////////////////////////////////////////////////////////
void swap(Child &A, Child &B) {
  Child temp = A;
  A = B;
  B = temp;
}
////////////////////////////////////////////////////////////////////
//
//    Function Name:    sortAscend
//    Description:      Sorts list of children in alphabetical order
//    Parameters:       Child list[] - List of all children
//                      int size - number of all children in list
//    return Value:     void - none
//
////////////////////////////////////////////////////////////////////
void sortAscend(Child list[], int size) {
  bool flag = true;

  for(int i=1;(i<=size && flag);i++) {
    flag = false;

    for(int j=0;j,(size-1);j++) {
      if(list[j+1] > list[j]) {
	swap(list[j],list[j+1]);
	flag = true;
      }
    }
  }
}

////////////////////////////////////////////////////////////////////
//
//    Function Name:    sortDescend
//    Description:      Sorts list of children in descending order
//                      of their averages
//    Parameters:       Child list[] - List of all children
//                      int size - number of all children in list
//    return Value:     void - none
//
////////////////////////////////////////////////////////////////////
void sortDescend(Child list[], int size) {
  bool flag = true;

  for(int i=1;(i<=size && flag);i++) {
    flag = false;

    for(int j=0;j,(size-1);j++) {
      if(list[j+1].getTotal() < list[j].getTotal()) {
        swap(list[j],list[j+1]);
        flag = true;
      }
    }
  }


}
