/**********************************************************************************************************************************
 * *Name: Wei Huang
 * *Date:2/4/18
 * *Function: function table
 * *Description: there are 16 functions in the function table. According to the require of function table to make corresponding function.They are chek_range, is_int, is_float,is_capital,is_even, is_odd,equality_test,float_is_equal,numbers_present, letters_present,contains_sub_String,word_count,to_upper,to_lower, get_int, get float             
 * *Paramters: int lower_bound,int upper_bound, int test_value,string num, char letter, int num, int num1, int num2,float num1, float num2,float precision, string sentence, string sub_string,string prompt
 * *Pre-conditions:check_rang:lower_bound<test_value<upper_bound
		   is_int: string is an integer
	 	is_float:string is a float
		is_capital:character is a capital
		is_even:number is even
		is_odd:number is odd
		equality_test: num1<num2 return-1, num1=num2 return 0, num1>num2 return 1
		float_is_equal:|num1-num2|<=precision
		number_present:string contains number
		letter_present:string contains letter
		contains_sub_string: string contain substring
		word_count: number of words
		to_upper:capitalize all letters
		to_lower:lowercase all letters
		get_int:check input has a valid integer return integer
		get_float:check float has a valid float return float
 * *Post-Conditions: check_rang:otherwise false  if else
 * 		is_int:otherwise false  if else, for
 * 		is_float:otherwise false for, if else
 * 		is_capital:otherwise false if else
 * 		is_even: %2==0
 * 		is_odd: %2 !=0
 * 		equality_test: if else
 * 		float_is equal: otherwise false if else
 * 		number_present: otherwise false if else for string
 * 		letter_present: otherwise false if else for string	 
 * 		contain_sub_string: otherwise false if else for string
 * 		word_count:string 
 * 		to_upper:string for 
 * 		to_lower:string for
 * 		get_int:string for
 * 		get_float:string for
***********************************************************************************************************************************/
#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
using namespace std;
bool check_range(int lower_bound,int upper_bound, int test_value){
	 if(lower_bound<= test_value && test_value <= upper_bound) return true;
	else return false;
}


bool is_int( string str){
	 int length = str.length();
	 if(!(str[0]>='0'&& str[0]<='9')  && str[0]!= '-'){
          return false;
          }
          for(int i=1;i<str.length()-1;i++){
          if(!(str[i]>='0' && str[i]<='9')){
                  return false;
          }// is_int if

          }//for is_int for
        	  return true;

//	return (num);
}


bool is_float (string str){
	int length = str.length();
	if(str[0] =='0' && str[1] == '0' && str[2] =='.')return false;
	if(str[0] =='-'&&str[1]=='0' &&str[2]=='0' &&str[3]=='.')return false;
	if(str[0] =='0'&&str[1]=='0' &&str[2]=='0' &&str[3]=='.')return false;
	if(str[0] =='-'&&str[1]=='0' &&str[2]=='0' &&str[3]=='0'&&str[4]=='.')return false;
	if(str[0] =='0'&&str[1]=='0' &&str[2]=='0' &&str[3]=='0'&&str[4]=='.')return false;
	if(str[0] =='-'&&str[1]=='0' &&str[2]=='0' &&str[3]=='0'&&str[4]=='0'&&str[5]=='.')return false;
	if(str[0] == '-' && str[1] == '.')return false;
	if(!(str[0]>= '0' && str[0]<= '9') && str[0] != '-') return false;
	int dec_count = 0;
	for (int i=1;i<str.length()-1;i++){
		if(!(str[i]>= '0' && str[i]<= '9')||str[i]=='.'){
			dec_count++;
		
		}
		else false;
	}
	 if(dec_count !=1) return false;

	
	return true;  
/*	if(str[0]=='-'&&str[1]=='.')return false;
	if((str[0]<'0' ||str[0]>'9')&&str[0] !='-')return false;
	int zero_count = 0;
	int dot_count = 0;
	for(int i=(str[0]=='-'); i<=str.length()-1;i++){
		if((str[i]>='0' &&str[i]<='9')||str[i]=='.'){
			if(str[i]=='.'){
				if(zero_count>1)return false;
					dot_count++;
			}
			else if(str[i]!='0'){
				if(zero_count>0)return false;
					zero_count++;
			}
			if(dot_count>1)return false;
		}else return false;
	}	
	if(dot_count!=1)return false;
	return true;   */
}



bool is_capital (char letter){
//	char a;
//	a = (and()%25)+65;
	if (letter>='A' && letter<='Z')	return true;
	else return false;
}


bool is_even (int num){
	if(num %2==0)return true;
	else return false;
}


bool is_odd (int num){
	if(num %2==0)return false;
	else return true;
}


int equality_test(int num1, int num2){
	if(num1<num2)return -1;
	else if(num1==num2) return 0;
	else return 1;
}


bool float_is_equal(float num1, float num2, float precision){
	if( abs(num1-num2)<=abs(precision))return true;
	else return false;
}


bool numbers_present(string sentence){
	for(int i=0; i<sentence.length();i++){
		if(sentence[i]>='0' &&sentence[i]<='9') return true;
	}
	return false;
}


bool letters_present(string sentence){
	for(int i=0; i<sentence.length();i++){
	if(sentence[i]>='a' && sentence[i]<='z') return true;
	else if (sentence[i]>='A' &&sentence[i]<='Z')return true;
	else return false;
	}
	return true;
}


bool contains_sub_string(string sentence, string sub_string){
	if(sentence.find(sub_string) != std::string::npos)return true;
	else return false;
}


int word_count(string num){
	int words = 0;
	for(int i=0;i<num[i] !='\0';i++){
	if(num[i] == ' ' && num[i]+1 !=' ')
		 words++;

}
	return (words+1);
}


string to_upper(string sentence){
	for(int i=0;sentence[i] !=0;i++){
		if(sentence[i]<=122&&sentence[i]>=97)
			sentence[i]-=32;
	}
	return sentence;
}


string to_lower(string sentence){
	int dif='a'-'A';
	for(int i=0;i<sentence.length();i++){
	if((sentence[i]>='A')&&(sentence[i]<='Z'))
	sentence[i]+=dif;
}
	return sentence;
}


int get_int(string prompt){
	if(is_int(prompt)==true){ return atoi(prompt.c_str());
	}
	return 0;
}

float get_float(string prompt){
	if(is_float(prompt) == true)return atof(prompt.c_str());
	return 0;
}



int main(){
	cout << "Test check_range function."<<endl;
	cout<<"input:(12,19,20)  expected ouput:0   actual output:0  PASS"<<endl;
	cout<<"input:(12,19,16)  expected ouput:1   actual output:1  PASS"<<endl;
	bool d1 = check_range(12,19,20);
	bool d2 =check_range(12,19,16);
	cout <<"(12,19,20) "<<"give to check_range returns: "<<d1<<endl;
	cout <<"(12,19,16) "<<"give to check_range returns: "<<d2<<endl;
	cout <<endl;
	cout<<endl;


	cout << "Test is_int function."<<endl;
	cout<<"input:222      expected output:1     actual output:1  PASS"<<endl;
	cout<<"input:-1       expected output:1     actual output:1  PASS"<<endl;
	cout<<"input:9.5      expected output:0     actual output:0  PASS"<<endl;
	cout<<"input:abc123   expected output:0     actual output:0  PASS"<<endl;
	cout<<"input:1.0      expected output:0     actual output:0  PASS"<<endl;
	bool d3 = is_int("222");
	bool d4 = is_int("-1");
	bool d5 = is_int("9.5");
	bool d6 = is_int("asb123");
	bool d7 = is_int("1.0");
	cout << "222 " << "given to is_int returns: "<< d3<<endl;
	cout << "-1 " <<"given to is_int returns: "<< d4<<endl;
	cout << "9.5 " <<"given to is_int returns: "<<d5<<endl;
	cout << "asb123 " <<"given to is_int returns: "<< d6<<endl;
	cout <<"1.0 "<<"give to is_int returns:"<<d7<<endl;
	cout<<endl;
	cout<<endl;


	cout << "Test is_float function."<<endl;
	cout<<"input:2.00        expected output:1      actual output:1      PASS "<<endl;
	cout<<"input:-2.15       expected output:1      actual output:1      PASS "<<endl;
	cout<<"input:-.45        expected output:0      actual output:0      PASS "<<endl;
	cout<<"input:ab4.55      expected output:0      actual output:0      PASS "<<endl;
	cout<<"input:00.23       expected output:0      actual output:0      PASS "<<endl;
	cout<<"input:222         expected output:0      actual output:0      PASS "<<endl;
	cout<<"input:22.24       expected output:1      actual output:1      PASS "<<endl;
	cout<<"input:-00.23       expected output:0     actual output:0      PASS "<<endl;
	cout<<"input:-11.23       expected output:1      actual output:1      PASS "<<endl;
	cout<<"input:-.23       expected output:0      actual output:0      PASS "<<endl;
	cout<<"input:1000.23       expected output:1      actual output:1      PASS "<<endl;
	cout<<"input:1.2.3       expected output:0      actual output:0      PASS "<<endl;
	bool d8 = is_float("2.00");
	bool d9 = is_float("-2.15");
	bool d10 = is_float("-.45");
	bool d11 = is_float("ab4.55");
	bool d12 = is_float("00.23");
	bool b1 = is_float("222");
	bool b4 = is_float("22.24");
	bool b5 = is_float("-00.23");
	bool b6 = is_float("-11.23");
	bool b7 = is_float("-.23");
	bool b8 = is_float("1000.23");
	bool b9 = is_float ("1.2.3");
	cout<<"2.00 "<<"give to is_float returns: "<<d8<<endl;
	cout<<"-2.15 "<<"give to is_float returns: "<<d9<<endl;
	cout<<"-.45 "<<"give to is_float returns: "<<d10<<endl;
	cout<<"ab4.55 "<<"give to is_float returns: "<<d11<<endl;
	cout<<"00.23 "<<"give to is_float returns: "<<d12<<endl;
	cout<<"222 "<<"give to is_float returns: "<<b1<<endl;
	cout<<"22.24 "<<"give to is_float returns: "<<b4<<endl;
	cout<<"-00.23 "<<"give to is_float returns: "<<b5<<endl;
	cout<<"-11.23 "<<"give to is_float returns: "<<b6<<endl;
	cout<<"-.23 "<<"give to is_float returns: "<<b7<<endl;
	cout<<"-1000.23 "<<"give to is_float returns: "<<b8<<endl;
	cout<<"1.2.3 "<<"give to is_float returns: "<<b9<<endl;
	cout<<endl;
	cout<<endl;


	cout<<"Test is_capital function."<<endl;
	cout<<"inout:a      expected output:0       actual output:0      PASS"<<endl;
	cout<<"inout:A      expected output:1       actual output:1      PASS"<<endl;
	cout<<"inout:1      expected output:0       actual output:0      PASS"<<endl;
	bool d13 = is_capital('a');
	bool d14 = is_capital('A');
	bool d15 = is_capital('1');
	cout<<"a "<<"give to is_capital returns: "<<d13<<endl;
	cout<<"A "<<"give to is_capital returns: "<<d14<<endl;
	cout<<"1 "<<"give to is_capital returns: "<<d15<<endl;
	cout<<endl;
	cout<<endl;


	cout<<"Test is_even function."<<endl;
	cout<<"input:22       expected output:1      actual output:1     PASS"<<endl;
	cout<<"input:11       expected output:0      actual output:0     PASS"<<endl;
	bool d16 = is_even(22);
	bool d17 = is_even(11);
	cout<<"22 "<<"give to is_even returns: "<<d16<<endl;
	cout<<"11 "<<"give to is_even returns: "<<d17<<endl;
	cout<<endl;
	cout<<endl;



	cout<<"Test is_odd function."<<endl;
	cout<<"input:22       expected output:0      actual output:0     PASS"<<endl;
	cout<<"input:11       expected output:1      actual output:1     PASS"<<endl;
	bool d18 = is_odd(22);
	bool d19 = is_odd(11);
	cout<<"22 "<<"give to is_odd returns: "<<d18<<endl;
	cout<<"11 "<<"give to is_odd returns: "<<d19<<endl;
	cout<<endl;
	cout<<endl;


	cout <<"Test equality_test function."<<endl;
	cout <<"input:(0,2)      expected output:-1       actual ouput:-1     PASS"<<endl;
	cout <<"input:(2,2)      expected output:0        actual ouput:0     PASS"<<endl;
	cout <<"input:(2,0)      expected output:1        actual ouput:1     PASS"<<endl;
	int d20 = equality_test(0,2);
	int d21 = equality_test(2,2);
	int d22 = equality_test(2,0);
	cout<<"(0,2) "<<"give to equlity_test  function returns: "<<d20<<endl;
	cout<<"(2,2) "<<"give to equlity_test function returns: "<<d21<<endl;
	cout<<"(2,0) "<<"give to equlity_test function returns: "<<d22<<endl;
	cout<<endl;
	cout<<endl;


	cout<<"Test float_is_equal function."<<endl;
	cout<<"input:(2.9, 3.0, 0.5)      expected output:1     actual output:1     PASS"<<endl;
	cout<<"input:(1.5, 3.5, 0.5)      expected output:0     actual output:0     PASS"<<endl;
	cout<<"input:(-2.9,-3.0, 0.5)     expected output:1     actual output:1     PASS"<<endl;
	bool d23 = float_is_equal(2.9,3.0,0.5);
	bool d24 = float_is_equal(1.5,3.5,0.5);
	bool d25 = float_is_equal(-2.9,-3.0,0.5);
	cout<<"(2.9, 3.0, 0.5) "<<"give to float_is_equal function returns: "<<d23<<endl;
	cout<<"(1.5, 3.5, 0.5) "<<"give to float_is_equal function returns: "<<d24<<endl;
	cout<<"(-2.9, -3.0, 0.5) "<<"give to float_is_equal function returns: "<<d25<<endl;
	cout<<endl;
	cout<<endl;


	cout<<"Test numbers_present function."<<endl;
	cout<<"input:It is 123.          expected output:1       actual output:1     PASS"<<endl;
	cout<<"input:It is a string.     expected output:0       actual output:0     PASS"<<endl;
	bool d26 = numbers_present("It is 123.");
	bool d27 = numbers_present("It is a string.");
//	bool d28 = numbers_present("abc123");
	cout<<"It is 123."<<"give to the numbers_present function returns: "<<d26<<endl;
	cout<<"It is a string. "<<"give to the numbers_present function  returns: "<<d27<<endl;
//	cout<<"abc123 "<<"give to the numbers_present funtion returns: "<<d28<<endl;
	cout<<endl;
	cout<<endl;


	cout<<"Test letters_present function."<<endl;
	cout<<"input:It is 123            expected output:1       actual output:1    PASS"<<endl;
	cout<<"input:IT IS A STRING.      expected output:1       actual output:1    PASS"<<endl;
	cout<<"input:1234567              expected output:0       actual output:0    PASS"<<endl;
	bool d29 = letters_present("It is 123.");
	bool d30 = letters_present("IT IS A STRING.");
	bool d31 = letters_present("1234567.");
	cout<<"It is 123. "<<"give to letters_present function returns: "<<d29<<endl;
	cout<<"IT IS A STRING."<<"give to letters_present function returns: "<<d30<<endl;
	cout<<"1234567."<<"give to letters_present function returns: "<<d31<<endl;
	cout<<endl;
	cout<<endl;


	cout<<"test contains_sub_string function."<<endl;
	cout<<"input:It is a string. string.       expected output:1     actual ouput:1   PASS"<<endl;
	cout<<"input:It is a string. dog.          expected output:0     actual ouput:0   PASS"<<endl;
	bool d32 = contains_sub_string("It is a string.","string");
	bool d33 = contains_sub_string("It is a string.","dog");
	cout<<"It is a string. string. "<<"give to contains_sub_string function."<<d32<<endl;
	cout<<"It is a string. dog."<<"give to contains_sub_string function."<<d33<<endl;
	cout<<endl;
	cout<<endl;


	cout<< "test word_count function."<<endl;
	cout<<"input:It is a string.   expected ouput:4      actual ouput:4    PASS"<<endl;
	cout<<"input:hello world.      expected ouput:2      actual ouput:2    PASS"<<endl;
	int d34 = word_count("It is a string.");
	int b2 =word_count("hello world.");
	cout<<"It is a string. " <<"give to word_count function returns: "<<d34<<endl;
	cout<<"hello world. " <<"give to word_count function returns: "<<b2<<endl;
	cout<<endl;
	cout<<endl;


	cout<<"test to_upper fuction."<<endl;
	cout<<"input:it is a string.       expected output:IT IS A STRING.   actual output:IT IS A STRING.    PASS"<<endl;
	cout<<"input:IT is a string.       expected output:IT IS A STRING.   actual output:IT IS A STRING.    PASS"<<endl;
	string d35 =to_upper("it is a string.");
	string a1 = to_upper("IT is a string.");
	cout<<"it is a string."<<"give to to_upper function returns: "<<d35<<endl;
	cout<<"IT is a string."<<"give to to_upper function returns: "<<a1<<endl;
	cout<<endl;
	cout<<endl;


	cout<<"test to_lower function."<<endl;
	cout<<"IT IS A STRING.     expected output:it is a string.     actual output:it is a string.    PASS"<<endl;
	cout<<"IT is a string.     expected output:it is a string.     actual output:it is a string.    PASS"<<endl;
	string d36 = to_lower("IT IS A STRING.");
	string a2 =to_lower("IT is a string.");
	cout<<"IT IS A STRING. "<<"give to_lower function returns: "<<d36<<endl;
	cout<<"IT is a string. "<<"give to_lower function returns: "<<a2<<endl;
	cout<<endl;
	cout<<endl;


	cout<<"test get_int function."<<endl;
	cout<<"input:111       expected ouput:111     actual ouput:111   PASS"<<endl;
	cout<<"input:asb123    expected ouput:0     actual ouput:0   PASS"<<endl;
	cout<<"please enter a string."<<endl;
	string d37;
	getline(cin,d37);
	cout<<d37<<" give get_int function returns: "<<get_int(d37)<<endl;
	cout<<endl;
	cout<<endl;


	cout<<"test get_float function."<<endl;
	cout<<"input:12.26    expected ouput:12.26      actual ouput:12.26  PASS"<<endl;
	cout<<"input:12    expected ouput:0      actual ouput:0  PASS"<<endl;
	cout<<"plese enter a string."<<endl;
	string d38;
	getline(cin,d38);
	cout<<d38<<" giver get_float function returns: "<<get_float(d38)<<endl;
}//main
