#include <iostream>
#include <cmath>
using namespace std;

int main () {
	cout << "cos(2/3) = " << cos(2.0/3) << endl;
	
        cout << "2sin(2/3) = " << 2*sin(2.0/3) << endl;

	cout << "tan(-3/4) = " << tan(-3.0/4) << endl;

	cout << "log10(55) = " << log10(55) << endl;

	cout << "ln60 = " << log(60) << endl;
	
	cout << "Find the log base 2 of 15." << endl; /* ln(x) uses log function*/
	cout << "ln(15) = " << log(15) << endl;
	cout << "ln(2) = " << log(2) << endl;
	cout << "ln(15)/ln(2) = " << log(15)/log(2) << endl;  

	cout << "Find the log base 4 of 40." << endl;
	cout << "ln(40) = " << log(40) << endl;
	cout << "ln(4) = " << log(4) << endl;
	cout << "ln(40)/ln(4) = " << log(40)/log(4) <<endl;

	cout << "Find the sin(x) power of 3." << endl;
	cout << "When x=1." << endl;
	cout << "3^(sin(1)) = " << pow(3.0,sin(1)) << endl; /*here have to use power function*/
	cout << "When x=10." << endl;
	cout << "3^(sin(10)) = " << pow(3, sin(10)) << endl;
	cout << "When x=100." << endl;
	cout << "3^(sin(100) =" << pow(3,sin(100)) << endl;

	cout << "Find the log base 2 of ((x^2)+1)." << endl;  /*there is a log function and power function*/
	cout << "When x=1." << endl;
	cout << "log2((1^2)+1) = " << log2(pow(1,2)+1) << endl;
	cout << "When x=10." << endl;
	cout << "log2((10^2)+1)= " << log2(pow(10,2)+1) << endl;
	cout << "When x=100." << endl;
	cout << "log2((100^2)+1)= " << log2(pow(100,2)+1) << endl;

       return 0;

} 

/****************************************************************************************************************************************************
** Program Filename: assignment1
** Author: Wei Huang
** Date: 1/13/18
** Decription: According to the requirements of the homework requires, and calculator the math function. Then the program shows the math answers.
** Input: There is no input
** Output: Each output is math function's answers. 
****************************************************************************************************************************************************/
