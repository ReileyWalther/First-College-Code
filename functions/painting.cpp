/*********************************************************/
//  Author:             Reiley Walther
//  Creation Date:      October  4, 2018
//  Due Date:           October 12, 2018
//  Course:             CSC135
//  Professor Name:     Dr. Carelli
//  Assignment:         #3 - Functions (Painting Costs)
//  Filename:           painting.cpp
//  Purpose:            
/*********************************************************/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//prototypes
void instructions();
int getsquarefeet();
float pricepergallon();
float costofpaint(int,float); //pricepergallon times 3 hours times $24 per hour
float costoflabor(int);
float calculatetotal(float,float);
void displayoutput(int,float,float,float,float);

int main() {

  //declaring variables 
  int squarefeet,
      laborhours;
  float gallonprice,
        paintcost,
        laborcost,
        total;

  instructions(); //displays instructions to the user

  squarefeet = getsquarefeet();       //getting square feet from user
  gallonprice = pricepergallon();  //getting price per gallon from user

  if (squarefeet < 0) {   //validating square feet
    cout << endl << "ERROR: Square feet must be positive" << endl << endl;
    return 1;
  }

  if (gallonprice < 10) {   //validating price per gallon
    cout << endl << "ERROR: Gallon price must be >= $10.00" << endl << endl;
    return 1;
  }

  paintcost = costofpaint(squarefeet,gallonprice); //computes and returns the cost of paint
  laborcost = costoflabor(squarefeet); //computes and returns the cost of labor

  total = calculatetotal(paintcost,laborcost); // adds the cost of paint and cost of labor

  displayoutput(squarefeet,gallonprice,paintcost,laborcost,total); //displays the output of the paint bill

  return 0;
}

///////////////////////////////////////////////////////////
//
//    Function Name:  instructions
//    Description:    Display the instructions to the user
//                    about the program.
//    Parameters:     None
//    Return value:   void type - none
//
///////////////////////////////////////////////////////////

void instructions() {  //Function displaying instructions for the user
  cout << endl << "Compute the cost to paint given the area to be painted (in square feet) and the price per gallon of paint." << endl << endl;
}

//////////////////////////////////////////////////////////
//
//    Function Name:  getsquarefeet
//    Description:    Function to get square feet from the
//                    user and return the value
//    Parameters:     None
//    return value:   int - area in square feet
//
//////////////////////////////////////////////////////////

int getsquarefeet() {  //function to get square feet from the user
  int area;

  cout << "Enter area (in square feet): ";
  cin >> area;
  return area;
}

//////////////////////////////////////////////////////////
//
//    Function Name:  pricepergallon
//    Description:    Function to get the price per gallon
//                    from the user and return the value
//    Parameters:     None
//    Return value:   float - price per gallon of paint
//
//////////////////////////////////////////////////////////

float pricepergallon() {  //function to get price per gallon from the user
  float price;

  cout << "Enter paint cost (per gallon): ";
  cin >> price;
  return price;
}

////////////////////////////////////////////////////////////
//
//    Function Name:   costofpaint
//    Description:     Function to calculate and return
//                     the paint cost
//    Parameters:      int sqfeet: area - input
//                     float price: price per gallon - input
//    Return value:    float - paint cost
//
////////////////////////////////////////////////////////////

float costofpaint(int sqfeet, float price) {  //function to calculate paint cost
  if (sqfeet < 116)
    return price;
  else if (sqfeet % 115 != 0) 
    sqfeet = sqfeet + 115;
    return (sqfeet/115) * price;
}

////////////////////////////////////////////////////////////
//
//    Function Name:   costoflabor
//    Description:     Function to calculate and return
//                     labor cost
//    Parameters:      int sqfeet: area in square feet
//    Return value:    float - labor cost
//
////////////////////////////////////////////////////////////

float costoflabor(int sqfeet) {  //function to calculate labor cost
  if (sqfeet < 39)
    return 1 * 24;
  else if (sqfeet >=39 && sqfeet < 77)
    return 2 * 24;
  else if (sqfeet < 116)
    return 3 * 24;
  else if (sqfeet % 115 != 0)
    sqfeet = sqfeet + 115;
  return (sqfeet/115) * 72;


  /*if (sqfeet < 39)
    return 1 * 24;
  else if (sqfeet >=39 && sqfeet < 77)
    return 2 * 24;
  else if (sqfeet < 116)
    return 3 * 24;
  else if (sqfeet % 115 < 39)
    return (((sqfeet/115) *  3)+ 1) * 24;
  else if (sqfeet % 115 >= 39 && sqfeet < 77)
    return (((sqfeet/115) *  3)+ 2) * 24;
  else if (sqfeet % 115 > 77)
    return (((sqfeet/115) *  3)+ 3) * 24;
  else if (sqfeet % 115 == 0)
    return ((sqfeet/115) *  3) * 24;*/
}

////////////////////////////////////////////////////////////
//
//    Function Name:   calculatetotal
//    Description:     Function to add cost of paint and
//                     labor together
//    Parameters:      float x: cost of paint - input
//                     float y: cost of labor - input
//    Reuturn value:   float - total costs
//
////////////////////////////////////////////////////////////

float calculatetotal(float x, float y) {   //function to add cost of paint and cost of labor
  return x + y;
}

////////////////////////////////////////////////////////////
//
//    Function Name:   displayoutput
//    Description:     Function to display output neatly
//    Parameters:      int sqfeet: area - input
//                     float gallonprice: price per gallon
//                                        - input
//                     float paint: paint cost - input
//                     float labor: labor cost - input
//                     float total: total cost - input
//    Return value:    void type - none
//
////////////////////////////////////////////////////////////

void displayoutput(int sqfeet, float gallonprice, float paint, float labor, float total) {  //function to display output in a neat format
  cout << fixed << setprecision(2);
  cout << endl;
  cout << "Painting Bill" << endl;
  cout << "-------------" << endl;
  cout << setw(12) << left << "Square Feet" << ":" 
       << setw(12) << right << sqfeet << endl;
  cout << setw(12) << left << "Price/Gallon" << ": $ " 
       << setw(9) << right << gallonprice << endl;
  cout << setw(12) << left << "Paint Cost" << ": $ " 
       << setw(9) << right << paint << endl;
  cout << setw(12) << left << "Labor Cost" << ": $ "
       << setw(9) << right << labor << endl;
  cout << setw(12) << left << "Total cost" << ": $ "
       << setw(9) << right << total << endl << endl;
}
