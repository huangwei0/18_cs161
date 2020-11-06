#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
int main(){
	bool quit = false;
	int number_length;
	int uppercase_length;
	int lowercase_length;
	char a;
	char l;
	int n;
	srand(time(NULL));
while(!quit){ 
	cout << "Welcome to Password Creator!"<<endl;
	cout << "How long do you want the password to be? ";
	int length;
	cin >> length;
	cout << "Do you want letters(0-no, 1-yes)? " ;
	int letters;
	cin >> letters;
	
	if (letters == 1) {
	cout << "Do you want uppercase letter(0-no,1-yes)? ";
	int uppercase;
	cin >> uppercase;

		if(uppercase==1){
		cout <<"How many characters of the password should be uppercase? ";
//		int uppercase_length;
		cin>> uppercase_length;
			for(int i=0;i<uppercase_length;i++){
//			srand(time(NULL));
			a = (rand()%26)+65;
		cout << a <<endl;
		}// repeat for uppercase_length
		}//if for uppercase
 		else if (uppercase==0){
		}
		else{
			cout<<"Sorry, without this option."<<endl;
		}

	cout <<"Do you want lowercase letter(0-no,1-yes)? ";
	int lowercase;
	cin>> lowercase;
		if(lowercase==1){
		cout << "How many characters of the password should be lowercase? ";
//		int lowercase_length;
		cin >> lowercase_length;
			for(int i=0;i<lowercase_length;i++){
	//		srand(time(NULL));
			l=(rand()%26)+97;
			cout << l<<endl;
			}//repeat for lowercase_length
		}//if for lowercase
		else if(lowercase==0){
		}//else if for lowercase
		else{
		cout<<"Sorry, without this option."<<endl;
	}//else for lowercase
	}// if for letters
	else if(letters==0){
	}// else if for letters
	else{
	
		cout<<"Sorry, without this option."<<endl;
	}//else for letters		
	cout << " Do you want numbers?(0-no, 1-yes)?" ;
	int numbers;
	cin >> numbers;
		if(numbers==1){
		cout <<"How many characters of the password should be number? ";
//		int number_length;
		cin >> number_length;
			for(int i=0;i<number_length;i++){
	//		srand(time(NULL));
			n=rand()%10;
			cout<< n<<endl ;	
		}//repeat for number_length
		}// if for numbers
		else if(numbers==0){
		}//else if for numbers
		else{
		cout<<"Sorry, without this option."<<endl;
		}//else for numbers
	
		int password_length;
		password_length = uppercase_length + lowercase_length + number_length;

		if (password_length == length){
		 
//		char password = a + n + l;
//			cout << password << endl;
		}// if for compare
		else{
		cout<<"You password is more length than or less than your set length."<<endl;
		}//else for compare	
		cout <<"Would you like to creat another password(0-yes, 1-no)? " ;
		cin>>quit;
}// for while
	return 0;
}
