////////////////////////////////////////////////////////////////////////////
//     Author:           Reiley Walther
//     Creatiion Date:   November  4, 2018
//     Due Date:         November 13, 2018
//     Course:           CSC135
//     Professor Name:   Dr. Carelli
//     Assignment:       #5 - Reference Parameters & Files (Restaurant Bills)
//     Filename:         restaurant2.cpp
//     Purpose:          The purpose of this program is to receive input from  
//                       an input file and calculate the total amount owed
//                       by a customer including the subtotal, tip and tax.
////////////////////////////////////////////////////////////////////////////

#include <iostream>  //input-output library
#include <fstream>   //file stream library allowing to read and write to files
#include <string>    //string library
#include <iomanip>   //manipulator library to display output

using namespace std;

//prototypes
void instructions();
string getFile(ifstream&);
void setHeader();
int readPeople(ifstream&);
float getTotal(ifstream&,int);
void getOthers(float, float&, int, float&, float&);
void Output(float, float, float, float);

int main() {              //main function
  int counter,               //declaring integer variables
      people;
  float total,               //declaring float variables
        salestax,
        tip,
        grandtotal;
  string filename;           // declaring string variables
  
  ifstream ins;              //declaring an input file to be used

  instructions();            //calling the instructions function

  filename = getFile(ins);   //calling getFile and assigning result to filename

  if (filename == "fail")    //testing if filename is valid
    return 1;

  setHeader();               //calling the setHeader function
  
  people = readPeople(ins);  //calling readPeople and assigning result to people
  do {                       //beginning of a do-while loop. Allows for loop to occur at least once
    
    if (people==0)
      break;
    total = getTotal(ins,people);                     //getTotal function is called and result assigned to total
    
    getOthers(total,salestax,people,tip,grandtotal);  //getOthers function called to use reference variables to find the tax, tip and grand total

    Output(total,salestax,tip,grandtotal);            //Output function is called to display output with the given arguments


    people = readPeople(ins);  //readPeople is called at the end again to check if we are at the end-of-file yet. If not, the loop continues
  }while(!ins.eof());          //do-while loop end when we reach eof
  
  ins.close();                 //close the input file we  are working with
  cout << endl;
  return 0;
}

//////////////////////////////////////////////////////////////
//
//    Function Name:    instructions
//    Description:      Function displays a brief description
//                      of the program.
//    Parameters:       none
//    Return Value:     none - void type
//
//////////////////////////////////////////////////////////////

void instructions() {
  cout << endl;
  cout << "This program calculates the table charges in a restaurant using information read from a user-supplied data file.";
  cout << endl << endl;
}

/////////////////////////////////////////////////////////////
//
//    Function Name:    getFile
//    Description:      Function to prompt the user to enter
//                      in the name of the input file and
//                      return it to main
//    Parameters:       ifstream& - ins: input file - input
//    Return Value:     string - the name of the input file
//
/////////////////////////////////////////////////////////////

string getFile(ifstream& ins) {
  string filename;

  cout << "Enter the file name: ";
  cin >> filename;

  ins.open(filename.c_str());
  if (ins.fail()) { 
    cout << "ERROR opening file: " << filename << endl << endl;
    return "fail";
  }
  else 
    return filename;
}

///////////////////////////////////////////////////////////
//
//    Function Name:    setHeader
//    Description:      Function is called to set a table
//                      formatted header for the table
//    Parameters:       none
//    Return Value:     void - none
//
///////////////////////////////////////////////////////////

void setHeader() {
  cout << endl;
  cout << setw(11) << left << " " << "RESTAURANT BILLS" << endl;
  cout << setw(13) << left << " " << "(per table)" << endl << endl;

  cout << fixed << setprecision(2);
  cout << setw(9) << left << " SubTotal" 
       << setw(10) << right << "Tax"
       << setw(10) << right << "Tip"
       << setw(10) << right << "Total" << endl;
  cout << "----------------------------------------" << endl;
}

///////////////////////////////////////////////////////////
//
//    Function Name:    getPeople
//    Description:      Function receives the input file
//                      and retrieves the number of people
//                      at the current table
//    Parameters:       ifstream& ins - reference variable
//                      to the input file - input
//                      int& people - reference to the 
//                      number of people at the table
//    Return Value:     int - a line in the file representing
//                      the number of people at the table
//
///////////////////////////////////////////////////////////

int readPeople(ifstream& ins) {
  int people;

  ins >> people;   //receives input from the file

  return people;
}

///////////////////////////////////////////////////////////
//
//    Function Name:    getTotal
//    Description:      Function receives the number of
//                      people and finds the total cost
//    Parameters:       ifstream& - ins: input file - input
//                      int - people: counter for people at
//                      the table - input
//    Return Value:     float - Total price of a meal
//
///////////////////////////////////////////////////////////

float getTotal(ifstream& ins, int people) {
  float total=0, price;
  
  for(int counter=1;counter<=people;counter++) {      //for loop repeats and accumulates the total price for one table
    ins >> price;
    total = total + price;
  }
  
  return total;
}

/////////////////////////////////////////////////////////////////
//
//    Function Name:    getOthers
//    Description:      Function receives reference values and
//                      calculates and returns the sales tax at
//                      6%, tip according to 4 or more people
//                      and grand total of the meals
//    Parameters:       float - subtotal: subtotal value - input
//                      float& - tax: reference to tax variable
//                      int - people: number of people at table
//                      float& - tip: reference to tip variable
//                      float& - grandtotal: grand total 
//                      reference variable
//    Return Value:     void - none
//
/////////////////////////////////////////////////////////////////

void getOthers(float subtotal, float& tax, int people, float& tip, float& grandtotal) {
  float percent;
  
  tax = subtotal*0.06;

  if (people < 5)   //checks if the people were above, below or equal to 5
    percent = 0.18;
  else
    percent = 0.2;

  tip = subtotal * percent;

  grandtotal = subtotal + tax + tip;
}

////////////////////////////////////////////////////////////
//
//    Function Name:    Output
//    Description:      Displays the calculated information
//                      in a neat, readable report
//    Parameters:       float - subtotal: is the total of
//                      the meals of all the people
//                      float - tax: the sales tax on the
//                      meals
//                      float - tip: the required tip on the
//                      meals
//                      float - grandtotal: the end, added
//                      total of all the variables
//
////////////////////////////////////////////////////////////

void Output(float subtotal, float tax, float tip, float grandtotal) {
  cout << fixed << setprecision(2);
  cout << setw(4) << left << "  $ " << setw(5) << right << subtotal
       << setw(5) << left << "   $ " << setw(5) << right << tax
       << setw(5) << left << "   $ " << setw(5) << right << tip 
       << setw(5) << left << "   $ " << setw(5) << right << grandtotal;
  cout << endl;
}
