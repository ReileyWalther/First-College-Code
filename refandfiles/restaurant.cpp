////////////////////////////////////////////////////////////////////////////
//     Author:           Reiley Walther
//     Creatiion Date:   November  4, 2018
//     Due Date:         November 12, 2018
//     Course:           CSC135
//     Professor Name:   Dr. Carelli
//     Assignment:       #5 - Reference Parameters & Files (Restaurant Bills)
//     Filename:         restaurant2.cpp
//     Purpose:          The purpose of this program is to receive input from  
//                       an input file and calculate the total amount owed
//                       by a customer including the subtotal, tip and tax.
////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//prototypes
void instructions();
int getPeople();
float getTotal(int);
float getPrice(int);
float getSalestax(float);
float getTip(int, float);
float getGrandtotal(float, float, float);
void Output(float, float, float, float);

int main() {
  int people= -1,
      counter;
  float total,
        salestax,
        tip;

  instructions();

  people = getPeople();
  
  while(!people == 0) {
    /*if (people == 0) {
      cout << "No people were recorded at the table" << endl << endl;
      return 0;
    }*/
    total = 0;

    total = getTotal(people);

    salestax = getSalestax(total);

    tip = getTip(people,total);

    float grandtotal = getGrandtotal(total, salestax, tip);

    Output(total,salestax,tip,grandtotal);
    people = getPeople();
  }
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
  cout << "This program calculates the table charges in a restaurant.";
  cout << endl << endl;
}

/////////////////////////////////////////////////////////////
//
//    Function Name:    getPeople
//    Description:      Function to prompt the user for and 
//                      to get the input for the number of 
//                      people at a table
//    Parameters:       none
//    Return Value:     int - number of people at a table
//
/////////////////////////////////////////////////////////////

int getPeople() {
  int num;

  do {
    cout << "Enter the number of people at the table: ";
    cin >> num;
  
    if (cin.fail()) {
      cout << endl;
      cout << "Error: Enter an integer!" << endl << endl;
      cin.clear();
      cin.ignore(50,'\n');
    }
  } while(num < 0);
  return num;
}

///////////////////////////////////////////////////////////
//
//    Function Name:    getTotal
//    Description:      Function receives the number of
//                      people and finds the total cost
//    Parameters:       int - people: counter for people at
//                      the table - input
//    Return Value:     float - Total price of a meal
//
///////////////////////////////////////////////////////////

float getTotal(int people) {
  float total = 0;
  
  for(int counter=1;counter<=people;counter++)
    total = total + getPrice(counter);
  
  return total;
}

///////////////////////////////////////////////////////////
//
//    Function Name:    getPrice
//    Description:      Function asks the user for and
//                      returns the price of a meal
//    Parameters:       int - num: counter for people at
//                      the table - input
//    Return Value:     int - Price of a meal
//
///////////////////////////////////////////////////////////

float getPrice(int num) {
  float price;

  cout << "Enter the charge for customer #" << num << ": ";
  cin >> price;

  return price;
}

///////////////////////////////////////////////////////////
//
//    Fuunction Name:   getSalestax
//    Description:      Function receives a value and 
//                      calculates and returns the sales
//                      tax of 6% on subtotal value
//    Parameters:       int - sub: subtotal value - input
//    Return Value:     float - returns sales tax
//
///////////////////////////////////////////////////////////

float getSalestax(float subtotal) {
  return (subtotal * 0.06);
}

///////////////////////////////////////////////////////////
//
//    Function Name:    getTip
//    Description:      Function receives the number of 
//                      people and the subtotal value and 
//                      determines the tip percentage and 
//                      the tip amount
//    Parameters:       int - people: number of people at
//                      a table - input
//                      float - total: subtotal value of
//                      table
//    Return Value:     float - returns the tip value
//
///////////////////////////////////////////////////////////

float getTip(int people, float total) {
  float tip;

  if (people < 5)
    tip = 0.18;
  else 
    tip = 0.2;

  return (total * tip);
  
}

/////////////////////////////////////////////////////////////
//
//    Function Name:    getGrandtotal
//    Description:      Function receives values of subtotal,
//                      sales tax and tip and calculates and 
//                      returns the total added value of
//                      these values
//    Parameters:       float - subtotal: the subtotal of 
//                      peoples meals
//                      float - tax: the sales tax on the 
//                      meals
//                      float - tip: the tip on the meal
//    Return Value:     float - returns the grand total owed
//                      by the specified number of people
//
/////////////////////////////////////////////////////////////

float getGrandtotal(float subtotal, float tax, float tip) {
  return (subtotal + tax + tip);
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
  cout << endl << endl;
  cout << "Restaurant Bill" << endl;
  cout << "---------------" << endl;
  cout << fixed << setprecision(2);
  cout << setw(17) << left << "Subtotal" << ": $ "
       << setw(7) << right << subtotal << endl;
  cout << setw(17) << left << "Tax" << ": $ "
       << setw(7) << right << tax << endl;
  cout << setw(17) << left << "Tip" << ": $ "
       << setw(7) << right << tip << endl;
  cout << setw(17) << left << "Total Cost" << ": $ "
       << setw(7) << right << grandtotal << endl;
  cout << endl;
}
