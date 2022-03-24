///////////////////////////////////////////////////////////
//
//   Author:            Reiley Walther
//   Creation Date:     November 25, 2018
//   Due Date:          November 29, 2018
//   Course:            CSC 135
//   Professor Name:    Dr. Carelli
//   Assignment:        #6 - Arrays (drivers exam scorer)
//   Filename:          driving.cpp
//   Purpose:           This program reads information from
//                      a data file and compares the answers
//                      of drivers for a test to the correct
//                      answers in a stored array. It also
//                      displays if a person passed/failed
//                      and what they got correct and wrong.
//
///////////////////////////////////////////////////////////

#include <iostream>                      //iostream library
#include <fstream>                       //fastream library
#include <iomanip>                       //iomanip library
#include <string>                        //string library

using namespace std;

//Prototypes
bool openfile(ifstream&,string&);
void loader(ifstream&,char[]);
void compareanswers(char[],char[],bool[]);
void determine(bool[],int&);
void output(bool[],int);

int main() {
  //declaring three arrays for answers, correct answers and true/false
  char correct[20] = {'B','D','A','A','C','A','B','A','C','D','B','C','D','A','D','C','C','B','D','A'};
  char current[20];
  bool result[20];

  //declaring variables in int main
  int right,
      counter=1;
  string filename;
  ifstream info;
  
  //calling a function to test if the file is valid and will open
  //if unsuccessful, error message displayed and program stopped
  if(!openfile(info,filename)){
    cout << "ERROR: Unable to open file " << filename << endl << endl;
    return 1;
  }

  //header output for driver results
  cout << endl << endl;
  cout << setw(10) << "Pass/Fail " 
       << setw(9) << "#Correct " 
       << setw(11) << "#Incorrect "  << "Wrong Answers"
       << endl;
  cout << "-------------------------------------------" << endl;

  //calling loader function to load first set of results into current array
  loader(info,current);

  //loop for entire file and stops if at end of file or 25 records are reached
  while(!info.eof() || counter > 25) {
    right=0;
    counter++;

    compareanswers(correct,current,result);          //compares answers to correct answers
    determine(result,right);                         //determines how many answers are correct

    output(result,right);                            //displays output
    cout << endl;

    loader(info,current);                    //loads next line into the current array
  }
  cout << endl;

  info.close();                        //closes the file

  return 0;
}

/////////////////////////////////////////////////////////////////
//
//    Function Name:    openfile
//    description:      Function attempts to open the data file
//                      and returns a true/false value according
//                      to if it's successful or not
//    Parameters:       ifstream - info: input file - input
//                      string - file: the name of the data file
//                      - input
//    Return Value:     bool - if file is opened successfully
//
/////////////////////////////////////////////////////////////////

bool openfile(ifstream& info,string& file) {

  //requests and stores user input
  cout << "Enter the file name: ";
  cin >> file;

  info.open(file.c_str());           //attempts to open the input file

  if(info.fail())                    //tests if the input file was opened successfully and returns an appropriate response
    return false;
  else
    return true;
}

///////////////////////////////////////////////////////////////////
//
//    Function Name:    loader
//    Description:      Function reads data from a file and stores
//                      the input in its own array
//    Parameters:       ifstream& - info: Input file - input
//                      char[] - answers: values are put into this 
//                      array for storage
//    Return Value:     void - none
//
///////////////////////////////////////////////////////////////////

void loader(ifstream& info, char answers[]) {
  //for loop loops the line into an array
  for(int i=0;i<20;i++) {
    info >> answers[i];
  }
}

///////////////////////////////////////////////////////////////////
//
//    Function Name:    compareanswers
//    Description:      Function compares values in different arrays
//                      and stores the result of the comparison in a
//                      bool array.
//    Parameters:       char array - correct: correct answers -input
//                      char array - current: Drivers answers -input
//                      bool array - result: true/false storage
//    Return Value:     void - none
//
///////////////////////////////////////////////////////////////////

void compareanswers(char correct[],char current[],bool result[]) {
  //for loop compares answers to correct answers and sets an appropriate response in result array
  for(int i=0;i<20;i++) {
    if(current[i] == correct[i])
      result[i] = true;
    else
      result[i] = false;
  }
}

///////////////////////////////////////////////////////////////////
//
//    Function Name:    determine
//    Description:      Function receives a int variable and if an
//                      array item is 'true' it increases integer
//    Parameters:       bool array - result: contains true/false
//                      int& - right: increases if array is true
//    Return Value:     void - none
//
///////////////////////////////////////////////////////////////////

void determine(bool result[],int& right) {
  //for loop determines if the value in result index is true/false and increases counter if true
  for(int i=0;i<20;i++)
    if(result[i])
      right++;
}

///////////////////////////////////////////////////////////////////
//
//    Function Name:    output
//    Description:      Function receives an array and an integer
//                      and determines pass/fail, right wrong and
//                      which answers were wrong
//    Parameters:       bool array - result: contains true/false
//                      int& right: number of correct asnwers
//    Return Value:     void - none
//
///////////////////////////////////////////////////////////////////

void output(bool result[],int correct) {
  //tests if correct answers are greater than 14 and shows pass if it is and fail if not
  if(correct>14)
    cout << setw(6) << right << "pass";
  else
    cout << setw(6) << right << "fail";

  //displays number of correct and incorrect answers
  cout << setw(9) << right << correct;
  cout << setw(10) << right << (20-correct);
  cout << "     ";

  //for loop checks if result index is false and if so, displays which questions were incorrect
  for(int i=0;i<20;i++)
    if(!result[i])
      cout << (i+1) << " ";
}
