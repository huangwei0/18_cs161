#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
	cout << "\033[33m Welcome to the school trip"; 
	cout <<"\033[0m";
	cout<< endl;
	cout << "Tomorrow you have a class at 8:00AM." <<endl;
	cout << "Enter 1 to set an alarm, enter 2 to set 2 alarms:\n" ;
	int x;
	cin >> x;
	cout << endl;
	if (x==1) {   /*choose 111 or 112*/
		cout << "You attempt to set an alarm at 7:00AM. Now the alarm is ringing." <<endl;
  		cout << "Enter 1 to wake up, enter 2 to set ignore the alarm:\n" ;
		cin >> x;/*this is the first path of teh first decision for 1 */   	
		cout << endl;
		if(x==1){
			cout << "You spends 10 minutes to wake up. Do you want to eat breakfast?" <<endl; 
  			cout << "Enter 1 to wake up, enter 2 to set ignore the alarm:\n" ;
			cin >> x;
			cout << endl;
			if(x==1){
				cout << "You spends 10 minutes to eat breakfaster, and spends 10 mintues arrive at school. It is 7:30AM, you arrive at school too early."<<endl;
				}/*this brac for the third if */
			else if(x==2){
				cout << "Because you don't eat breakfast for long time that lead to illness, so you cannot go to take calss today."<<endl;
				}/*this brace for third else if*/
			else{
				cout << "The information you entered is invalid." << endl;
				}/*this brace for the third else*/
	}  /* this brace for the second "if" */
		else if(x==2){ /* choose 121 or 122*/
			cout << "You ignore the alarm at 7:00AM. Do you want set a new alarm?"<< endl;				
  	  		cout << "Enter 1 to set a new alarm at 7:30AM, enter 2 to sleep:\n" ;
			cin >>x;
			cout << endl;
			if(x==1){
				cout << "You set a new alarm, and you arrive at school on time." <<endl;
			}/*121*/
			else if(x==2){
				int z;
				srand(time(NULL));
				z = rand()%3;
				if(z==0){
					cout << "You wake up at 7:40AM, and late 10 minutes for class."<<endl;
				}/*rand  */
				else{
					cout <<"You overslept and missed the class."<<endl;
				}
			}/*122*/
			else{

			cout << "The information you entered is invalid." << endl;
			}
		}/*this brace for the second else if"*/
  	  	
		
		else{
			cout << "The information you entered is invalid." << endl;
			}/*this brac is 121 path*/
	}  /* this brace for the first "if" */
	else if(x==2) {/*2*/
		cout <<"You set two alarms,one set at 7:00AM, another set at 7:30AM. Now the first alarm is ringing."<<endl;
  	  	cout << "Enter 1 to wake up, enter 2 to ignore and wait for the second alarm:\n" ;
		cin >>x;
		cout << endl;
		if(x==1){/*211*/
                  	 cout << "You spends 10 minutes to wake up. Do you want to eat breakfast?" <<endl;
        		 cout << "Enter 1 to wake up, enter 2 to set ignore the alarm:\n" ;
                    	 cin >> x;
			cout << endl;
                       	 if(x==1){
                                cout << "You spends 10 minutes to eat breakfaster, and spends 10 mintues arrive at school. It is 7:30AM, you arrive at school too early."<<endl;
                                }/*this brac for the third if */
                        else if(x==2){
                                cout << "Because you don't eat breakfast for long time that lead to illness, so you cannot go to take calss today."<<endl;
                                }/*this brace for third else if*/
                        else{
                                cout << "The information you entered is invalid." << endl;
                             }							
				}
		
		else if(x==2){/*22*/
			cout << "You ignored the first alarm, now the second alarm is ringing." <<endl;
			cout << "Enter 1 to wake up, enter 2 to ignore alarm again:\n";
			cin >>x;
			cout << endl;
			if(x==1){/*221*/
				cout << "You spend 10 minutes to wake up, 10 minutes to eat breakfast, and 10 minutes to arrive school. You arrive at school on time. Congratulation!" <<endl;
			}/*221*/
			else if(x==2){/*222*/
				cout << "You ignored both alarms, and overslept. You miss the class." <<endl;
			}/*222*/
			else{			
			cout << "The information you entered is invalid." << endl;
			}
		}
		else{
			cout << "The information you entered is invalid." << endl;
		}
	}/* this brace for the first else if */  
	else {
		cout << "The information you entered is invalid." << endl;
	}/*this brace for the first else*/	
	return 0;
}
/******************************************************************
 **Program:assignment2.cpp
 **Author: Wei Huang
 **Date:1/21/2018
 **Description:It is a world game. It at least has 5 paths and 
		5 different paths, and the user has 3 time input.
		Each input number will show the different the path.
 **Input: the user input the number to choose the path 
 **Output: According to the user's input, print the path
*******************************************************************/
