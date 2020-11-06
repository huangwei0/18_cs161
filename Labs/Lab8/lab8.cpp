#include <iostream>
#include <string>

 using namespace std;

void get_string(char *input) {
cout<<"Please enter a string: ";
cin.getline(input, 256);
}

void set_replace_string(char *input, char *replace){
 // *replace =input;
  for(int i=0;i < 256;i++){
	 if((input[i] >='A')&&(input[i]<='Z')||((input[i]>='a')&&(input[i]<='z'))){
      replace[i] ='-';
    	}
	else{
	replace[i] = input[i];
	}
 	} 
     cout << " set replace string is " <<replace<< '\n';
}

  int get_search_replace(char *input, char *replace){
    char letter;
    int count =0;
    int i;
   cout << "please enter a letter in the string: ";
    cin>> letter;
    for( i=0; i<256;i++){
      if(input[i]==letter){
        replace[i] = letter;
        count++;

      }}
    

    return count;
  }

 int main(){
   char *input = new char[256];
   char *replace= new char[256];
   char letter =0;
   get_string(input);
   set_replace_string(input,replace);
  int count= get_search_replace(input, replace);
  cout<<"the string has "<<count<<"letters of you choice"<<endl;
  cout<<"now string is: "<< replace <<endl;
	delete[] input;
	delete[] replace;
  return 0;
 }

