/*******************************************************************************************************
**Fucntion: four type calculator
**Desciption:the user enters an equation, and the computer according to the equation to calculate the correct
 answer. It should have a space between each operand and operator. There must be sure that each operand only has
  one point, and the input should be string. the user input the binary, and the calculator program to convert from
   binary to decimal. All input should be unsign number. If user input wrong continue let him input until correct.
   the user input the decimal, and the calculator program to convert from decimal to binary. All input should be 
   unsign number. If user input wrong continue let him input until correct.The user input each grade, and add the all
    grade then calculate the average point. Ask for the user about weight that user can chose yes or no to calculate 
    the grade.  If the user input wrong continue let him input until correct.There must also be error handling for 
    all parts of this program. The functions must contain 15 lines or less of code. 
**Parameters: decimal. binary, equation, garde, wight
**pre-Conditions: string decimal, string binary, string equation, string grade, string wight 
**post-Conditions: return true or fasle, return bin, return res,return atoi(num.c_str()),return average,
********************************************************************************************************/



#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>

using namespace std;
/*void user_input(string calcultor){
cout<<"Please choose a calcultor, standard, binarytodecimal,decimaltobinary or garde: ";
getline(cin, calcultor);
if(calcultor='standard') 	
}*/
/****************************************************************************
**program: binary to decimal
**name:Shannon
**decribe: the user input the binary, and the calculator program to convert from 
binary to decimal. All input should be unsign number. If user input wrong continue
 let him input until correct. There must also be error handling for all parts of 
 this program. The functions must contain 15 lines or less of code.  
 **Parameters:string binary
 **pre-Conditions: string bin, string str
 **post-Conditions:return bool, return res
******************************************************************************/
bool check_bin(string bin){
	for(int i=0;i<bin.length();i++){
		if((bin[i]!='0')&&(bin[i]!='1')) {
			return false;
		} 
	}
	return true;
}

string get_bin(){
	string bin;
	do{
		cout<<"please provide a binary number: ";
		getline(cin, bin);
	}while(check_bin(bin) == false);
	return bin;
}

int convert_to_decimal(string bin){
	int len=bin.length();
	int res =0;
	for(int i=0; i<len;i++){
		if (bin[i] =='1'){
			res += pow (2,(len-i-1));
		}
	}
	return res;
}

bool check_equation(string str){
	
	string bin =get_bin();
	int res = convert_to_decimal (bin);
	cout<<res<<endl;
	//string str = " ";
	//getline(cin,str);
	if((str[0] >='0' && str[0] <='9')  && (str[str.length()-1] >='0'&& str[str.length()-1] <='9'))
		return true;	
} 
/****************************************************************************
**program: decimal to binary
**decribe: the user input the decimal, and the calculator program to convert 
from decimal to binary. All input should be unsign number. If user input wrong 
continue let him input until correct. There must also be error handling for all 
parts of this program. The functions must contain 15 lines or less of code
 **pre-Conditions: string deci
 **post-Conditions: return arr[j]
******************************************************************************/

void get_deci(){
	string deci;
	int arr[100],i=0,j,check=0;
	do {cout<<"Please enter decimal number(unsign): ";
		getline(cin,deci);
		for(int a=0;a<deci.length();a++){
			if(deci[a]<'0'||(deci[a]>='a'&&deci[a]<='z')) check =1;
			else {check = 0;}
		}}while(check == 1);
	int val = atoi(deci.c_str());	
	while(val>0){
		arr[i]=val%2;
		i++;
		val=val/2;}
	for(j=i;j>=0;j--)	cout<<arr[j];cout<<endl;
}

/****************************************************************************
**program: grade calcultor
**decribe: The user input each grade, and add the all grade then calculate the 
average point. Ask for the user about weight that user can chose yes or no to 
calculate the grade.  If the user input wrong continue let him input until 
correct. There must also be error handling for all parts of this program. 
The functions must contain 15 lines or less of code.  
 **Parameters: string grade 
 **pre-Conditions: sstring grade, int times, 
 **post-Conditions: return ato(num.c_str()), return average,return grad_ave
******************************************************************************/

int accouting(){
	string num;
	int check=0;
	do{
	cout<<"How many grade you want to calculate: "<<endl;
	cin>>num;
	for(int i=0;i<num.length();i++){
		if((num[i]<'0') || (num[i] >='a'&&num[i]<='z')) check=1;
		else check=0;
	}
	}while(check==1);
	return atoi(num.c_str());
}


float yes(string grade,int times){
	float result=0, average;
	int check =0;
	//int times=accouting(times);
	  for(int i=0; i<times;i++) {
	    do{cout<<"Enter a grade: ";
	    cin >> grade;
	    for(int i=0;i<grade.length();i++){
	    	if((grade[i]<'0') || (grade[i] >='a'&& grade[i]<='z')) check=1; 
	    	else check=0; }}while(check==1);
	    result += atof(grade.c_str());
		}
	cout<< result <<endl;
	average = result/times;
	cout<<"total grade: "<<result<<endl;
	cout<<"average is: "<<average<<endl;
	return average;
		//return result;
}


float get_weight(string grade,int times){
	string percentage;
	float grade_ave; 
	int check =0;
	float average=yes(grade,times);
	for(int j=0;j<times;j++){
	do{do{cout<<"Enter wegiht: ";
	cin>>percentage;
	for(int i=0;i<percentage.length();i++){
		if((percentage[i]<'0') || (percentage[i] >='a'&&percentage[i]<='z')) check=1;
		else check=0;
	}
	}while(check==1);}while(percentage>"1");
	 grade_ave = average* atof(percentage.c_str());
	cout<<"grade is: "<<grade_ave<<endl;
	}
		return grade_ave;
}


void grade_equation(){
	string chose,points;
	int check=0;
	int times = accouting();
	do{cout<<"Do you want calculate the wegiht of each grade(y-yes, n-no): ";
	cin>> chose;
	for(int i=0;i<chose.length();i++){
		if(chose[i] !='n' &&chose[i] !='y') check=1;
		else check=0;}
	}while(check==1||chose=="ny"||chose=="yn");
	if(chose=="n")
	  	cout<<yes(points,times);
	else if(chose=="y")
		cout<<get_weight(points,times);
}

/****************************************************************************
**program: grade calcultor
**decribe: the user enters an equation, and the computer according to the 
equation to calculate the correct answer. It should have a space between 
each operand and operator. There must be sure that each operand only has 
one point, and the input should be string. There must also be error handling 
for all parts of this program. The functions must contain 15 lines or less of code.  
 **Parameters: string equation
 **pre-Conditions: string str, string temp1, string temp2, char op
 **post-Conditions: return bool
******************************************************************************/

float get_answer(string, string ,char);

bool check_equation1(string str){
	int i;
  if (str.length()==0) return false;//check no string
	if(!(str[0] >='0' && str[0] <='9')  || !(str[str.length()-1] >='0'&& str[str.length()-1] <='9'))	return false;//the first integer and last integer

	for(i=0;i<=str.length();i++){
	 	  if (str[i]==' '){ //check around space
    		if(str[i+1]==' ') return false;
    		if (((str[i-1]>='0' && str[i-1] <='9') && (str[i+1]>='0' && str[i+1] <='9')) || ((str[i-1]=='-' || str[i-1]=='+' || str[i-1]=='*'||str[i-1]=='/')&&(str[i+1]=='-'||str[i+1]=='+'||str[i+1]=='*'||str[i+1]=='/'))) return false;    
     	
    }
    if (str[i]=='-' || str[i]=='+' || str[i]=='*' || str[i]=='/'){ 
      if (str[i+1]!=' ' || str[i-1]!=' ') 
        return false;
      }
  }
  return true;
}

void found_operand(string str){
 
  string temp1 = "";
  string temp2 = "";
  float r = 0.0;
  int i = 0;

  for(i= 0;i<str.length();i++){
    if(str[i]!=' '){
      temp1 += str[i];
    }
    else
      break; 
  }
    cout << temp1 << endl;
   


  char op = str[i+1];

  for(int j = i+3; j < str.length(); j++){
    if (str[j]!=' ')
      temp2 += str[j];
    else break;
  }

    cout << op << endl;
    cout << temp2 << endl;

    r = get_answer(temp1, temp2, op);
   cout << r << endl;
}

void get_equation(string str){
   do{
    cout<<"Please enter a equation: ";
    getline(cin,str);
    }while(check_equation1(str)==false);

    if(check_equation1(str))
      found_operand(str);
    
}

float get_answer(string temp1, string temp2, char op){

   switch(op){
    case'+': return atof(temp1.c_str()) + atof(temp2.c_str()); 
      break;
    case'-': return atof(temp1.c_str()) - atof(temp2.c_str());
      break;
    case'*': return atof(temp1.c_str()) * atof(temp2.c_str());
     break;
    case'/': return (float) atof(temp1.c_str()) / atof(temp2.c_str());
      break;

  
  }
}

int main(){
	int n;
	do{string str = " ";
	int check=0;
	string x;
	do{cout<<"What type calcultor do you want to chose 1.binary to decimal,2decimal to binary, 3grade, 4standard calculate: ";
	getline(cin,x);
	}while(x!="1" && x!="2" && x!="3" && x!="4");
	int y =atoi(x.c_str());
	if(y==1) check_equation(str);	
	else if(y==2)get_deci();
	else if(y==3) grade_equation();
	else if(y==4)get_equation(str);
	cout<<"Do you want play again? 1-yes 0-exit: ";
	cin>>n; 
	}while(n == 1);

	return 0;
}