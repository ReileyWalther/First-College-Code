/////////////////////////////////////////////////////////////////////
//
//   Author:         Reiley Walther
//   Creation Date:  February 8th, 2019
//   Due Date:       February 9th, 2019
//   Course:         CSC 136 019
//   Professor Name: Dr. Carelli
//   Assignment:     #1
//   Filename:       struct.cpp
//   Purpose:        This program calculates and outputs children's
//                   piggy bank savings using data given in a file
//                   using structs to store the data.
//
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define ARRAYSIZE 12

// struct definition for a child object
struct child {
  string name;   // child name
  int quarters;  // number of quarters
  int dimes;     // number of dimes
  int nickels;   // number of nickels
  int pennies;   // number of pennies
  char star;     // award
  float total;   // child final average                                   
  char grade;    // child final letter grade
};                  


// prototypes
int readDatafile(child[], int);   //only include the struct and the size of the struct array
void calcTotAward(child[],int);
void dumpData(child[],int);
void dumpSorted(child[],int);

// additional prototypes for sorting
void swap(float&, float&);   //declared a swap function to switch items in struct array

main() {
  child slist[ARRAYSIZE];

  int val = readDatafile(slist,ARRAYSIZE);  //calls function to get number of students
  if(val==-1) {
    cout << endl;
    return 1;
  }
  
  dumpData(slist,val);   //calls function to display originally read data

  calcTotAward(slist,val);  //calls function to calculate and assign data

  dumpSorted(slist,val);  //calls function to display sorted structs
}

//////////////////////////////////////////////////////////////////////
//
//   Function name:  readDataFile
//   Description:    Function receives user input of file, attempts to
//                   open the file and stores values in struct array
//   Parameters:     child list - gives the storage locations for the 
//                                data of each child (input)
//                   int max - gives the number of available spaces (input)
//   Return value:   int - returns the number of students read
//
//////////////////////////////////////////////////////////////////////


// open and read the datafile
int readDatafile(child list[], int max) {
  string fname;
  ifstream ifs;
  int num=0;

  cout << "Enter the file name: ";  //asks for user input
  cin >> fname;

  ifs.open(fname.c_str());  //process for testing if file opens/exists or not
    if(ifs.fail()) {
      cout << "ERROR: File name " << fname << " was not found";
      ifs.clear();
      ifs.ignore(100,'\n');
      return -1;
    }

    while(num<max) {  //reads and stores information from input file until the end of the file or until the size is reached
    if(ifs.eof())
      break;
    ifs >> list[num].name;
    ifs >> list[num].quarters;
    ifs >> list[num].dimes;
    ifs >> list[num].nickels;
    ifs >> list[num].pennies;
    num++;
  }

  return num;
}

//////////////////////////////////////////////////////////////////////
//
//   Function name:  calcTotAward
//   Description:    Function calculates the total money value and
//                   gives the correct star for each child
//   Parameters:     child list - gives the storage locations for the
//                                data of each child (input)
//                   int max - gives the number of students (input)
//   Return value:   void - none
//
//////////////////////////////////////////////////////////////////////

void calcTotAward(child list[],int size) {
  for(int i=0;i<size;i++) {     //adding up the total values and storing in a field in each struct
    list[i].total = (list[i].quarters*0.25) + (list[i].dimes*0.1) + (list[i].nickels*0.05) + (list[i].pennies*0.01);
    if(list[i].total>=10.00)      //checks each value to see which sign it should be given (G, S, B)
      list[i].star = 'G';
    else if(list[i].total > 5.00)
      list[i].star = 'S';
    else 
      list[i].star = 'B';
  }

  bool flag = true;

  for(int i=1;(i<=size) && flag;i++) {
    flag = false;

    for(int j=0;j<(size-i);j++) {
      if(list[j+1].total>list[j].total)      //if true, values are swapped and replaced in their position in the struct array
	swap(list[j+1],list[j]);
      flag = true;
    }
  }
}

//////////////////////////////////////////////////////////////////////
//
//   Function name:  swap
//   Description:    Function swaps the values of two different structs
//   Parameters:     float one - first value being switched(input)
//                   float two - second value being switched(input)
//   Return value:   void - none
//
//////////////////////////////////////////////////////////////////////

void swap(float &one, float &two) {
  float temp = one;
  one = two;
  two = temp;
}

//////////////////////////////////////////////////////////////////////
//
//   Function name:  readDataFile
//   Description:    Function displays the data read originally from
//                   the input file
//   Parameters:     child list - gives the storage locations for the
//                                data of each child (input)
//                   int size - gives the number of available spaces (input)
//   Return value:   void - none
//
//////////////////////////////////////////////////////////////////////

void dumpData(child list[],int size) {
  cout << fixed;
  cout << endl;
  cout << "Children's data:" << endl;
  cout << "----------------------" << endl;

  for(int i=0;i<size;i++) {
    cout << setw(10) << left << list[i].name
	 << setw(3) << right << list[i].quarters
	 << setw(3) << right << list[i].dimes
	 << setw(3) << right << list[i].nickels
	 << setw(3) << right << list[i].pennies << endl;
  }
}

//////////////////////////////////////////////////////////////////////
//
//   Function name:  dumpSorted
//   Description:    Function neatly displays the sorted output
//   Parameters:     child list - gives the storage locations for the
//                                data of each child (input)
//                   int size - gives the number of available spaces (input)
//   Return value:   void - none
//
//////////////////////////////////////////////////////////////////////

void dumpSorted(child list[],int size) {
  cout << endl;
  cout << fixed;
  cout << setprecision(2);
  cout << "Final Grades:" << endl
       << "-------------------" << endl;

  for(int i=0;i<size;i++) { 
    cout << setw(10) << left << list[i].name
	 << setw(3) << right << "$ "
	 << setw(5) << right << list[i].total
	 << setw(3) << right << list[i].star << endl;
  }
}
