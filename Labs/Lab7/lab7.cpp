#include <iostream>
#include <string>

 using namespace std;

void get_string(string *input) {
cout<<"Please enter a string: ";
getline(cin, *input);
}

void set_replace_string(string input, string *replace){
  *replace =input;
  for(int i=0;i < (*replace).length();i++){
    if((*replace)[i] != ' '){
      (*replace)[i] ='-';
    }
  }
     cout << " set replace string is " <<*replace<< '\n';
}

  int get_search_replace(char letter, string input, string &replace){
    int count =0;
    int i;
   cout << "please enter a letter in the string: ";
    cin>> letter;
    for( i=0; i<input.length();i++){
      if(input[i]==letter){
        replace[i] = letter;
        count++;

      }}
    

    return count;
  }

 int main(){
   string input="";
   string replace=" ";
   char letter =0;
   get_string(&input);
   set_replace_string(input,&replace);
  int count= get_search_replace(letter, input, replace);
  cout<<"the string has "<<count<<"letters of you choice"<<endl;
  cout<<"now string is: "<< replace <<endl;
  return 0;
 }
