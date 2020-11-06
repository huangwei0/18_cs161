#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int a_to_i(char num);
char i_to_a(int ch); 
int main(){
	char c;
	int a;	
  	cout << "Please insert a character."<<endl;
        cin >>  c;
//	int a_to_i;
	a = a_to_i(c);
	cout << a << endl;
//         num =(rand()%94)+33;
//	cout << num << endl;	
//	return 0;  
	int d;
	char b;
	cout << "please insert a number." <<endl;
	cin >> d;
	b = i_to_a(d);
	cout << b << endl;
}
int a_to_i( char num){
			
	return int (num);
}

char  i_to_a(int ch){
	return char (ch);
}
