///////////////////////////////////////////////////////////////////
//
//   Author:         Reiley Walther
//   Creation Date:  February 5th, 2019
//   Due Date:       February 9th, 2019
//   Course:         CSC136 019
//   Professor Name: Dr. Carelli
//   Assignment:     #1 - Saving
//   Filename:       array.cpp
//   Purpose:        This program calculates and outputs childrens
//                   piggy bank savings using data given in a file.
// 
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define ARRAYSIZE 12

// prototypes
int readDatafile(string[], int[], int[], int[], int[], int);
void calcTotAward(int[], int[], int[], int[], float[], int[], char[], int);
void dumpData(string[],int[],int[],int[],int[],int);
void dumpResults(string[], int[], int[], int[], int[], float[], char[], int[], int);

// add prototypes and functions as needed for sorting
void swap(int&, int&);

main() {
  string names[ARRAYSIZE];  // student names
  int quarters[ARRAYSIZE];  // number of quarters
  int dimes[ARRAYSIZE];     // number of dimes
  int nickels[ARRAYSIZE];   // number of nickels
  int pennies[ARRAYSIZE];   // number of pennies

  float total[ARRAYSIZE];   // total amount
  char star[ARRAYSIZE];     // award

  int index[ARRAYSIZE] = {0,1,2,3,4,5,6,7,8,9,10,11}; //index array

  int val = readDatafile(names, quarters, dimes, nickels, pennies, ARRAYSIZE);
  
  cout << endl;
  
  if(val == -1) {
    return 1;
  }

  dumpData(names,quarters,dimes,nickels,pennies,val);

  calcTotAward(quarters,dimes,nickels,pennies,total,index,star,val);

  dumpResults(names,quarters,dimes,nickels,pennies,total,star,index,val);

  return 0;
}

// open and read the datafile
// this should return the number of entries read!!!
int readDatafile(string n[], int q[], int t[], int p[], int f[], int max) {
  string fname;  // file name
  ifstream ifs;  // input file stream
  int num=0;     // number of students read

  cout << "Enter the file name: ";  //requests user input
  cin >> fname;

  ifs.open(fname.c_str());   //tests if file can open/exists
  if (ifs.fail()) {
      cout << "ERROR: File name " << fname << " was not found." << endl;
      ifs.clear();
      ifs.ignore(100,'\n');
      return -1;
    }

  while (num<max) { //reads from file until size is reached or until end of file is reached
    if (ifs.eof()) 
      break;
    ifs >> n[num];
    ifs >> q[num];
    ifs >> t[num];
    ifs >> p[num];
    ifs >> f[num];
    num++;
  } 

  return num;
}

////////////////////////////////////////////////////////////////////
//
//   Function name:     dumpData
//   Description:       Function receives arrays of names, quarters,
//                      dimes, nickels and pennies and displays what
//                      was read in the input file in a neat format.
//   Parameters:        string names - student names (input)
//                      int qs - number of quarters (input)
//                      int ds - number of dimes (input)
//                      int ns - number of nickels (input)
//                      int ps - number of pennies (input)
//   Return value:      int - number of students read in the file
//
////////////////////////////////////////////////////////////////////

// output the data that was read in
void dumpData(string names[],int qs[],int ds[],int ns[],int ps[],int max) {
  cout << "Children's data: " << endl 
       << "----------------------" << endl;
  for(int i=0;i<max;i++) {
    cout << setw(10) << left << names[i] << setw(3) << right << qs[i] 
	 << setw(3) << ds[i] << setw(3) << ns[i] 
	 << setw(3) << ps[i] << endl;
  }
}

////////////////////////////////////////////////////////////////////
//
//   Function name:     calcTotAward
//   Description:       Function calculates the total money one has 
//                      and assigns the correct star to a student
//                      as well as sort the index array to use in
//                      displaying at a later stage.
//   Parameters:        int qs - number of quarters (input)
//                      int ds - number of dimes (input)
//                      int ns - numbers of nickels (input)
//                      int ps - numbers of pennies (input)
//                      float tot - total cash
//                      int index - index of the lists (input)
//                      char star - list for stars( input)
//                      int size - number of students (input)
//   Return value:      void - none
//
////////////////////////////////////////////////////////////////////

// calculate the total and the award
void calcTotAward(int qs[], int ds[], int ns[], int ps[], float tot[], int index[], char star[], int size) {
  for(int i=0;i<size;i++) {   //adding the totals up and assigning the correct star to their totals
    tot[i] = (qs[i]*0.25) + (ds[i]*0.10) + (ns[i]*0.05) + (ps[i]*0.01);
    if(tot[i]>=10.00) 
      star[i] = 'G';
    else if(tot[i]>5.00)
      star[i] = 'S';
    else
      star[i] = 'B';
  }
  
  float tottemp[12];      //temporary array of totals that will be changed with index numbers
  for(int i=0;i<size;i++) {
    tottemp[i] = tot[i];
  }

  bool flag = true;
  
  for(int i=1; (i <= size) && flag; i++) {  //comapring the index file and total values and placing in the correct order
    flag = false;

    for(int j=0; j<(size-1); j++) {
      if(tottemp[j] < tottemp[j+1]) {
	swap(index[j+1],index[j]);
	swap(tottemp[j+1],tottemp[j]);
	flag = true;
      }
    }
  }
}

////////////////////////////////////////////////////////////////////
//
//   Function name:     dumpResults
//   Description:       Function displays the results and output in
//                      a neat and well-formatted display
//   Parameters:        string names - names of students (input)
//                      int qs - number of quarters (input)
//                      int ds - number of dimes (input)
//                      int ns - number of nickels (input)
//                      int ps - number of pennies (input)
//                      float tot - total earnings of students (input)
//                      char star - The correct star (input)
//                      int index - list of numbers in order (input)
//                      int size - size of the array (input)
//   Return value:      void - none
//
////////////////////////////////////////////////////////////////////

// dump the results
void dumpResults(string names[], int qs[], int ds[], int ns[], int ps[], float tot[], char star[], int index[], int size) {
  cout << endl;
  cout << fixed;
  cout << "Final Grades:" << endl
       << "---------------------------------" << endl;

  for(int i=0;i<size;i++) {
    cout << setw(10) << left << names[index[i]] 
	 << setw(3) << right << qs[index[i]]
	 << setw(3) << ds[index[i]]
	 << setw(3) << ns[index[i]]
	 << setw(3) << ps[index[i]]
	 << "   $" << setw(5) << setprecision(2) << right << tot[index[i]]
	 << setw(3) << right << star[index[i]] << endl;
  }
}

////////////////////////////////////////////////////////////////////
//
//   Function name:     swap
//   Description:       Function swaps two numbers in different 
//                      positions
//   Parameters:        float &one - first number (input)
//                      float &two - second number (input)
//   Return value:      void - none
//
////////////////////////////////////////////////////////////////////


//swapping values in a list
void swap(int &one, int &two) {
  int temp = one;
  one = two;
  two = temp;
}
