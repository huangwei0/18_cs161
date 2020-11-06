#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

/*****************************************************
**program:is_int(string str)
**descriptio: check the user input the number of player
**pre-condition: string str
**post-condition: bool true or false
******************************************************/

bool is_int(string str){
	if (str.length() == 0)
		return false;
	for (int i = 0 ; i < str.length(); i++){
		if (!(str[i] >= '0' && str[i] <='9'))
			return false;
	}


	return true;
}

/*****************************************************
**program:user_input(string member)
**descriptio: user input the number of player
**pre-condition: string number
**post-condition: atoi(member.c_str())
******************************************************/
int user_input(string member){
  //int i, check=0;
  do{
    cout<<"How many people play the Farkle: ";
    getline(cin, member);
    //for( i=0;i<member.length();i++){
      //if(member[i]<'0' || (member[i]>='a' && member[i]<='z')) check=1;
      //else check=0;
   }while(!is_int(member) || atoi(member.c_str()) < 2);
  return atoi(member.c_str());
}

// bool check_user_input(string member){
//     int people;
//     do{
//        people = user_input(member);
//     }while(people < 2);
//     return true;
// }

/*****************************************************
**program:get_dice(int *dice, int &size)
**descriptio: get dice nuber
**pre-condition:int *dice, int &size
**post-condition: dice
******************************************************/
 int* get_dice(int *dice, int &size){
 	dice = new int[size];
  	srand(time(NULL));
  	for(int i = 0; i < size;i++){
    	dice[i] = (rand() % 6) + 1;
  		//cout<<dice[i]<<endl;
    }

    // dice[0] = 3;
    // dice[1] = 3;
    // dice[2] = 3;
    // dice[3] = 3;
    // dice[4] = 3;
    // dice[5] = 3;

    return dice;
}

/*****************************************************
**program:check_single_number(int* dice, int &size, int number)
**descriptio:check the single number(1 or 5) from the score table
**pre-condition:int* dice, int &size, int number
**post-condition: 0
******************************************************/

int check_single_number(int* dice, int &size, int number){
  	int i;
  //cout<< "number given to check single num "<<number<<endl;
  	if (size == 0) {
//  	cout << " in first false" << endl;
  	return 0;}
  	for(i=0; i < size; i++){
    if(dice[i]==number) {return 1;}
  }

  //  	cout << " in first false" << endl;
    	return 0;
}


/*****************************************************
**program:remove_single_number(int* dice, int &size, int num)
**descriptio:remove one dice
**pre-condition:int* dice, int &size, int num)
**post-condition: size--
******************************************************/
void remove_single_number(int* dice, int &size, int num){
	int re;
	for(int i=0; i<size;i++){
		if(dice[i]==num){
			re = dice[i];
			dice[i] = dice[size-1];
			dice[size-1]= re;
			size--;
			break;
		}
	}

}


/*****************************************************
**program:check_same_number(int* dice, int &size, int a,int number)
**descriptio: check the same dices in the output dices
**pre-condition:int* dice, int &size, int a,int number
**post-condition:bool true or fasle
******************************************************/
bool check_same_number(int* dice, int &size, int a,int number){
  int i,count=0;
  if(size < a) {
  	//cout << "size less than a" << endl;
  	return false;
  }
  for(i=0; i<size;i++){
    if(dice[i]==number)
      count++;
    if(count== a){
      	return true;}
  }
      //	cout << " count not equal to a" << endl;
      	return false;
}

/*****************************************************
**program:remove_same_number(int* dice, int &size, int a, int num)
**description:remove the same dice that user choose in the output dice
**pre-condition:int* dice, int &size, int a, int num
**post-condition: size
******************************************************/

void remove_same_number(int* dice, int &size, int a, int num){
	for(int i = 0; i < a; i++){
		remove_single_number(dice, size, num);
	}
		//return size = size - a;
}

/*****************************************************
**program:check_different_number(int* dice, int &size)
**description: check continue dices in the output dices
**pre-condition:int* dice, int &size
**post-condition:bool true or false
******************************************************/

bool check_different_number(int* dice, int &size){
	int test = 0;
    if(size < 6) return false;
    for(int i = 1;i<=6;i++){
      test = test + (check_single_number(dice, size, i));
      }
    if(test == 6)
    	return true;
	else
     	return false;
}

/*****************************************************
**program:remove_different_number(int* dice, int &size)
**descriptio:rmove the all dice from output dice
**pre-condition:int* dice, int &size
**post-condition: size
******************************************************/

void remove_different_number(int* dice, int &size){
	size = 0;
	//return size;
}

/*****************************************************
**program:check_one_pair(int* dice, int &size, int number)
**descriptio: check the one pair dice from the output dices
**pre-condition:int* dice, int &size, int number
**post-condition:bool true or false
******************************************************/

bool check_one_pair(int* dice, int &size, int number){
    if(size < 2) return false;
    int count = 2;
    for(int i = 0;i < size; i++){
        if(dice[i]==number){
          count --;
          if(count == 0)
            return true;
        }
    }
    return false;

}

/*****************************************************
**program:check_three_pairs(int* dice, int size)
**descriptio: check the three pair from the output dices
**pre-condition:int* dice, int size
**post-condition: bool true or false
******************************************************/

bool check_three_pairs(int* dice, int size){

  if(size < 6) return false;

  int count = 0;

  for (int i = 1; i <= 6; i++){
    if(check_one_pair(dice, size, i))
      count ++;
    if (count == 3) return true;
  }

  return false;
}

/*****************************************************
**program:check_four_one_pair(int* dice, int size)
**descriptio:check four any same dice and one pair from the output dices
**pre-condition:int* dice, int size
**post-condition:bool true or false
******************************************************/

bool check_four_one_pair(int* dice, int size){
  if(size<6) {
	//cout<<"first false"<<endl;
  	return false;
  }

  for(int i=1; i<=6; i++){
	if(check_same_number(dice, size, 4, i)){
	//	cout << "recogize 4 same num"<<endl;
		for(int j=1; j <i;j++)
			if(check_one_pair(dice, size, j)) return true;
		for(int k = i+1; k<=6;k++)
			if(check_one_pair(dice, size, k)) return true;
	}

  }
	//else {
	//	cout<<"second false"<<endl;
	//	return false;}

  return false;
}

/*****************************************************
**program:check_triple(int* dice, int &size, int number)
**descriptio:check two triple from the output dices
**pre-condition:int* dice, int &size, int number
**post-condition:bool true or false
******************************************************/

bool check_triple(int* dice, int &size, int number){
  if(size < 6) return false;
  for(int i=1; i <=6; i++){
  if(check_same_number(dice, size,3,i)){
    for(int j=1; j<i; j++)
    if(check_same_number(dice, size,3,j)) return true;
    for(int k = i+1; k<=6; k++)
    if(check_same_number(dice, size,3,k)) return true;
  }
}
 /* if(size < 3) return false;
  int count = 0, add = 0;
  for(int i = 0;i < size; i++){
    if(dice[i] == num){
      count++;
      if(count==3){
        add++;
        if(add==2) return true
        }
    }
  }*/
  return false;
}


/*****************************************************
**program:check_farkle(int* dice, int &size)
**descriptio: check all dice cannot get score from the score table
**pre-condition:int* dice, int &size
**post-condition:bool true or false
******************************************************/

bool check_farkle(int* dice, int &size){
	int i,c7,j;
	int c3 = 0;
	int c1 = check_single_number(dice, size, 1);
	 //cout << "c1 is :" << c1 <<endl;
	int c2 = check_single_number(dice, size, 5);
//cout<<"c2"<<c2<<endl;


  	for(i=1; i <= 6; i++){
  		for( j=3;j<=6;j++){
  			 //c3 =
  			 if ((check_same_number(dice, size,j, i)) == true){
  			 	c3 = true;
  			 	break;
  			// cout<<"c3"<<c3<<endl;
  			 }
  		}


	//int c_test = check_same_number(dice, size,j, i);
  	//	cout << "c_test is :" << c_test <<endl;
	}


 	int c4 = check_different_number(dice,size);
	//cout<<"c4"<<c4<<end;
 	int c5 = check_three_pairs(dice, size);
	//cout<<"c5"<<c5<<endl;
 	int c6 = check_four_one_pair(dice, size);
	//cout<<"c6"<<c6<<endl;
 	for(int k=1; k<=6;k++){
		 c7 = check_triple(dice, size, k);

	}
	//cout<<"c7:"<<c7<<endl;
	int totall = c1 + c2 + c3 + c4 + c5 + c6 + c7;

	// cout<<"c1"<<c1<<endl;cout<<"c1"<<c1<<endl;cout<<"c1"<<c1<<endl;
	if(totall == 0){
		return true;
		//cout<<"Farkle"<<endl;
	}
	return false;
}

/*****************************************************
**program:point_table()
**descriptio:score table that player can know what choose get what score
**pre-condition:none
**post-condition:none
******************************************************/

void point_table(){
    cout<<"single1 = 100          four of any number = 1000"<<endl;
    cout<<"single5 = 50           five of any number = 2000"<<endl;
    cout<<"three 1's = 300        six of any number = 3000"<<endl;
    cout<<"three 2's = 200        1-6 straight = 1500"<<endl;
    cout<<"three 3's = 300        three pairs = 1500"<<endl;
    cout<<"three 4's = 400        four of any number with pair = 1500"<< '\n';
    cout<<"three 5's = 500        two triples = 2500"<<endl;
    cout<<"three 6's = 600"<<endl;
}

// bool check_choose(string choose){
// 	for(int i=0;i<choose.length();i++){
// 		if(!(choose[i]>='1')&&(choose[i]<='15'))
// 			return false;
// 	}
// 	return true;
// }


// int get_choose(string choose){
// 	do{
// 		cout<<"which option you want to choose? 1--single 1; 2--single 5; 3--three 1's; 4--three 2's; 5--three 3's; 6--three 4's; 7--three 5's; 8-- three's 6; 9--four of any number; 10--five of any number; 11--six of any number;
// 			12--1-6 straight; 13--three pairs; 14--four of any number with pair; 15--two triples"<<endl;
// 	getline(cin,choose);}while(!check_choose(choose))
// 	return atoi(choose.c_str());
// }

/*****************************************************
**program:check_option(int* dice, int &size, int* user_array, int user_array_size, int a, int num, int* point)
**descriptio: check player choose dice and get point
**pre-condition:int* dice, int &size, int* user_array, int user_array_size, int a, int num, int* point
**post-condition: reurn point
******************************************************/

void check_option(int* dice, int &size, int* user_array, int user_array_size, int &point){
	//get_choose(choose);
do{



	for(int i = 1; i<=6;i++){
		if(check_same_number(dice, size, 6, i) && check_same_number(user_array, user_array_size, 6, i)){
			remove_different_number(dice, size);
			remove_different_number(user_array, user_array_size);
			point += 3000;
		}
	}

	for(int i=1; i <= 6; i++){
		if(check_triple(dice, size, i) && check_triple(user_array, user_array_size, i)){
			remove_different_number(dice,size);
			remove_different_number(user_array, user_array_size);
			point += 2500;
		}
	}
				//cout<<point<<endl;

	for(int i = 1; i<=6;i++){
		if(check_same_number(dice, size, 5, i) && check_same_number(user_array, user_array_size, 5, i)){
			remove_same_number(dice, size, 5, i);
			remove_same_number(user_array, user_array_size, 5, i);
			point += 2000;
		}
	}

	if(check_three_pairs(dice, size)&&check_three_pairs(user_array, user_array_size)){
		remove_different_number(dice, size);
		remove_different_number(user_array, user_array_size);
		point += 1500;
				//cout<<point<<endl;
	}

	if(check_four_one_pair(dice, size) && check_four_one_pair(user_array, user_array_size)){
		remove_different_number(dice, size);
		remove_different_number(user_array, user_array_size);
		point += 1500;
				//cout<<point<<endl;
	}



	// if(check_four_one_pair(dice, size) && check_four_one_pair(user_array, user_array_size)){
	// 	remove_different_number(dice, size);
	// 	remove_different_number(user_array, user_array_size);
	// 	point += 1500;
	// 			//cout<<point<<endl;
	// }

	// if(check_four_one_pair(dice, size) && check_four_one_pair(user_array, user_array_size)){
	// 	remove_different_number(dice, size);
	// 	remove_different_number(user_array, user_array_size);
	// 	point += 1500;
	// 			//cout<<point<<endl;
	// }

	if(check_four_one_pair(dice, size) && check_four_one_pair(user_array, user_array_size)){
		remove_different_number(dice, size);
		remove_different_number(user_array, user_array_size);
		point += 1500;
				//cout<<point<<endl;
	}


	// if(check_different_number(dice, size) && check_different_number(user_array, user_array_size)){
	// 	remove_different_number(dice, size);
	// 	remove_different_number(user_array, user_array_size);
	// 	point += 1500;
				//cout<<point<<endl;
	//}

	if(check_different_number(dice, size) && check_different_number(user_array, user_array_size)){
		remove_different_number(dice, size);
		remove_different_number(user_array, user_array_size);
		point += 1500;
				//cout<<point<<endl;
	}



				//cout<<point<<endl;


	for(int i = 1; i<=6;i++){
		if(check_same_number(dice, size, 4, i) && check_same_number(user_array, user_array_size, 4, i)){
			remove_same_number(dice, size, 4, i);
			remove_same_number(user_array, user_array_size, 4, i);
			point += 1000;
		}
	}

				//cout<<point<<endl;

	if(check_same_number(dice, size, 3, 6) && check_same_number(user_array, user_array_size, 3, 6)){
		//cout << "san ge 6" << endl;
		remove_same_number(dice, size, 3, 6);
		remove_same_number(user_array, user_array_size, 3, 6);
		point += 600;
				//cout<<point<<endl;
	}

	if(check_same_number(dice, size, 3, 5) && check_same_number(user_array, user_array_size, 3, 5)){
		remove_same_number(dice, size, 3, 5);
		remove_same_number(user_array, user_array_size, 3, 5);
		point += 500;
				//cout<<point<<endl;
	}


	if(check_same_number(dice, size, 3, 4) && check_same_number(user_array, user_array_size, 3, 4)){
		remove_same_number(dice, size, 3, 4);
		remove_same_number(user_array, user_array_size, 3, 4);
		point += 400;
				//cout<<point<<endl;
	}

	// if(check_same_number(dice, size, 3, 3) && check_same_number(user_array, user_array_size, 3, 3)){
	// 	remove_same_number(dice, size, 3, 3);
	// 	remove_same_number(user_array, user_array_size, 3, 3);
	// 	point += 300;
	// 			//cout<<point<<endl;
	// }

	// if(check_same_number(dice, size, 3, 3) && check_same_number(user_array, user_array_size, 3, 3)){
	// 	remove_same_number(dice, size, 3, 3);
	// 	remove_same_number(user_array, user_array_size, 3, 3);
	// 	point += 300;
	// 			//cout<<point<<endl;
	// }


	if(check_same_number(dice, size, 3, 3) && check_same_number(user_array, user_array_size, 3, 3)){
		remove_same_number(dice, size, 3, 3);
		remove_same_number(user_array, user_array_size, 3, 3);
		point += 300;
				//cout<<point<<endl;
	}

	if(check_same_number(dice, size, 3, 2) && check_same_number(user_array, user_array_size, 3, 2)){
		remove_same_number(dice, size, 3, 2);
		remove_same_number(user_array, user_array_size, 3, 2);
		point += 200;
				//cout<<point<<endl;
	}


	if(check_same_number(dice, size, 3, 1) && check_same_number(user_array, user_array_size, 3, 1)){
			remove_same_number(dice, size, 3,1);
			remove_same_number(user_array, user_array_size, 3,1);
			point += 300;
					//cout<<point<<endl;
	}

	if(check_single_number(dice, size, 1) && check_single_number(user_array, user_array_size, 1)){
		remove_single_number(dice, size, 1);
		remove_single_number(user_array, user_array_size, 1);
		point += 100;
		//cout<<point<<endl;
	}

	if(check_single_number(dice, size, 5) && check_single_number(user_array, user_array_size, 5)){
		remove_single_number(dice, size, 5);
		remove_single_number(user_array, user_array_size, 5);
		point += 50;
				//cout<<point<<endl;
	}
	// cout << "In check option function --- user_array_size: " << user_array_size << endl;
}while(user_array_size != 0);


		//cout<<point<<endl;

	//return point;

}

/*****************************************************
**program:check_num(string num)
**descriptio: check player choose dice the number
**pre-condition:string num
**post-condition:bool true or false
******************************************************/

bool check_num(string num){
	for(int i=0;i<num.length();i++){
		if((num[i]>='1')&&(num[i]<='6')){
		}else{
			return false;
		}
	}
	return true;
}

/*****************************************************
**program:get_input(int *dice, int &size)
**descriptio:get player choose dices
**pre-condition:int *dice, int &size
**post-condition: return num
******************************************************/

string get_input(int *dice, int &size){
	// for(int i=0; i<size;i++){
	// 	cout << dice[i]<< "\t"<< endl;
	// }
		int number = 0;
		string num = "";

		do{
			cout << "which dice that you want to pick(for example: 123)?" << endl;
			getline(cin, num);
		//cout<<dice[0]<<endl;
		}while(!check_num(num));

		return num;

		//else{
		//	cout<<"please enter again?"<<endl;
		//	get_input(dice, size);
			//return 0;
		//}
}

/*****************************************************
**program:convert_arr(string str, int &user_array_size)
**descriptio:make player choose become an array
**pre-condition:string str, int &user_array_size
**post-condition:user_array
******************************************************/

int* convert_arr(string str, int &user_array_size){
	int* user_array = new int [str.length()];
	for (int i = 0; i < str.length(); i++){
		user_array[i] = str[i] - '0';
	}

	user_array_size = str.length();
	//delete user_array;
	return user_array;

}

/*****************************************************
**program:print_user_arry(int* user_array, int user_array_size){
**descriptio: print the player choose of array
**pre-condition:int* user_array, int user_array_size
**post-condition:none
******************************************************/

void print_user_arry(int* user_array, int user_array_size){
	for (int i = 0 ; i < user_array_size; i++)
		cout << user_array[i] << endl;
}

/*****************************************************
**program:print_dice_arr(int* dice, int size)
**descriptio:print the dice array
**pre-condition:int* dice, int size
**post-condition:none
******************************************************/

void print_dice_arr(int* dice, int size){
	for(int i = 0 ; i < size; i++){
		cout << dice[i] << endl;
	}

}


/*****************************************************
**program:creat_score_board(int* point)
**descriptio: caculate the players' score
**pre-condition:int* point
**post-condition:
******************************************************/

int*  creat_score_board(int player){
	int* score = new int [player];
	for (int i = 0; i < player; i++)
	{
		score[i]=0;
	}
		//delete score;
	return score;
}

/*****************************************************
**program:check_winner(int score, player)
**descriptio: check winner who get 10000 score
**pre-condition:int score, player
**post-condition: bool true or false
******************************************************/

bool check_winner(int* score, int player){
	for(int i=0; i<player;i++){
		if (score [i] >= 10000)
			return true;
	}
	return false;
}

/*****************************************************
**program:check_collect(int *score, int player)
**descriptio: check player reach 500
**pre-condition:int score, int player)
**post-condition: bool true or false
******************************************************/

bool check_collect(int *score, int player){
	for(int i=0; i<player;i++){
		if(score[i]>=500)
			return true;
	}
	return false;
}

// int help_function(){
// int a,
// string x;

// do{

// 	cout<<"Do you want to collect the score or not?(1--collect, 2--continue roll)： ";
// 	getline(cin, x);

// }while((x!="1")||(x!="2"));

// 	int a = atoi(x.c_str());

/*****************************************************
**program:check_500(int* score, int player)
**descriptio: check 500 score to check roll continue or break
**pre-condition:int* score, int player
**post-condition: bool true or false
******************************************************/

int check_500(int* score, int player, int * dice, int &size ){
int check =0;
string x;
do{

	cout<<"Do you want to collect the score or not?(1--collect, 2--continue roll)： ";
	getline(cin, x);
	cout << x << endl;
}while((x!="1\0")&&(x!="2\0"));

int a = atoi(x.c_str());

	if(a==1){
		if(check_collect(score, player)){				check= 1;
		}
				//return false;

		else if (!(check_collect(score, player))){
			cout<<"you did not reach 500 score, you cannot save the score"<<endl;
					check= 0;
					// if(check_farkle(dice, size)) check =1;
				// if(check_farkle(dice, size)) return 0;
				// else {						return 1;
				// }

		}

	}

	else if(a==2){
		return 0;
			//if(check_collect(score, player)){
			//  if(!(check_farkle(dice, size))) check = 0;
			// else if(check_farkle(dice, size)){
			// 		cout<< "Farkle"<<endl;
			// 		check =1;
			// 	}
			// if(!(check_farkle(dice, size))) check = 0;

				return check;
			//else if(!(check_collect(score, player))) return 0;

	//}

	// false;
}
}
/*****************************************************
**program:void print_Score(int* score, int player)
**descriptio: print out the player got the point
**pre-condition:int* score, int player
**post-condition: none
******************************************************/
void print_Score(int* score, int player){
	for (int i = 0; i < player; i ++)
		cout << "Player " << i+1 << ": " << score[i] << endl;
}

int main(){

	//help_function();
	srand(time(NULL));
	string member="";
	int player =user_input(member);
	// cout<<player<<endl;
	int *score =creat_score_board(player);
	// for(int i=0;i<player;i++)
	// {
	// 	cout<<score[i]<<endl;
	// }
	int size = 6, point = 0,check =0;

	int *dice= new int [size];
	string str;

	int  user_array_size =0;
		do {
				for(int i=0; i<player; i++){
					point = 0;
					print_Score(score, player);

				 	cout<<"\n\nplayer " << i+1 << "\n\n" <<endl;

				 	point_table();
				 	size = 6;
					dice = get_dice(dice, size);
					 //print_dice_arr(dice, size);
					if(check_farkle(dice,size)){
						cout << "Farkle!!!" << endl;
					}
					else{
							do{
								dice = get_dice(dice, size);
									print_dice_arr(dice, size);
									if(check_farkle(dice,size)){
										cout << "Farkle!!!" << endl;
										break;
									}
									else{
								//cout << "Your current size " << size << endl;
											string str = get_input(dice, size);
											int* user_array = convert_arr(str, user_array_size);
											cout << "user array is: " << endl;
											print_user_arry(user_array, user_array_size);
											//cout << "hahaha" << endl;
											check_option(dice, size, user_array, user_array_size, point);
											cout << "current point is: " << point << endl;
											//check_500(score, player);
											check = check_500(&point, player, dice, size);
											cout << "check: " << check << endl;





											delete [] user_array;
						}
						}while(check == 0);
					}

					score[i] += point;


				}

			}while(!(check_winner(score, player)));

			print_Score(score, player);

			delete [] score;
			delete [] dice;


		//delete dice；
	//cout<<check_dice_arr( dice, size);
 return 0;


}
