#include <iostream>
#include <string>
#include <cstdlib>
#include <string.h>

using namespace std;

bool jump_chess(char**, int, int, int, int, int);
void compare_x1_x2(char** ,int, int, int, int,int);
/*****************************************************
 **program:print
 **descriptio:print the board with whit and balck
 **pre-condition: char **board,int num
 **post-condition: none
 ******************************************************/
void print (char **board,int num){
	cout<<"    ";
	for(int a=0; a<num; a++){
		cout<<a<<"   ";
	}
	cout<<endl;

	for(int i =0;i<num;i++){
		cout<<i<<" ";
		for(int j=0; j<num; j++){
			if (i%2 == 0 && j%2 == 0)
				cout << "|\033[30;47m "  << board[i][j] << " ";
			else if (i%2 == 1 && j%2 == 1)
				cout << "|\033[30;47m "  << board[i][j] << " ";
			else
				cout << "|\033[0m " << board[i][j] << " ";
			cout << "\033[0m";
		}
		cout << endl;
	}
	cout << endl;

	}

	/*****************************************************
	 **program:allocate
	 **descriptio: build the board and put chesses
	 **pre-condition: int num
	 **post-condition: return arr
	 ******************************************************/
	char **allocate(int num){


		char **arr=new char *[num];
		for(int i=0;i<num;i++){
			arr[i]=new char[num];
		}

		for(int i=0;i<num;i++){
			for(int j=0;j<num;j++){
				arr[i][j]=' ';
			}
		}

		for(int i=0;i<(num/2)-1;i++){
			for(int j=1-(i%2);j<num;j+=2){
				arr[i][j]='x';
			}
		}

		for(int i=num-((num/2)-1);i<num;i++){
			for(int j=1-(i%2);j<num;j+=2){
				arr[i][j]='o';
			}
		}
		return arr;
	}

	/*****************************************************
	 **program:reprompt
	 **descriptio: get user input size
	 **pre-condition: none
	 **post-condition: atoi(str.c_str())
	 ******************************************************/
	int reprompt(){
		string str = "";
		do{
			cout << "enter size: ";
			cin >> str;
		}while(str!="8" && str!="10" && str!="12");

		return atoi(str.c_str());
	}
	/*****************************************************
	 **program:get_size
	 **descriptio: chek the size and get size
	 **pre-condition: int argc, char *argv[]
	 **post-condition: size
	 ******************************************************/
	int get_size(int argc, char *argv[]){
		int size = -1;
		if (argc != 2){
			size = reprompt();
		}
		else{
			if (!strcmp(argv[1], "8") && !strcmp(argv[1], "10") && !strcmp(argv[1],"12"))
				size = reprompt();
			else{
				size = atoi(argv[1]);
			}
		}
		return size;
	}
	/*****************************************************
	 **program:check_chess
	 **descriptio: check the chess of the user pick
	 **pre-condition: char *pick
	 **post-condition: bool true or false
	 ******************************************************/
	bool check_chess(char *pick){
		int count=0;
		if(!((pick[0] >='0' && pick[0] <='9')||pick[0]=='@'||pick[0]=='J'))
			return false;

		for(int i=0; i<256;i++){
			if(pick[i]==' '){

				if(pick[i+1]==' ')
					return false;

				if (((pick[i-1]>='0' && pick[i-1] <='9')||pick[i-1]=='@'||pick[i-1]=='J') && (pick[i+1]>='0' && pick[i+1] <='9')||(pick[i+1]=='@'||pick[i+1]=='J'))
					count++;

				else{
					return false;
				}
			}
		}

		int len = count+1;
		int a = len%2;
		if(len<4) return false;

		if(a==0) {
			return true;
				}


		 return false;
	}

	/*****************************************************
	 **program:check
	 **descriptio: check the user inuput is his own chess and choose correctly
	 **pre-condition:char**board, int num,int x1, int y1, int x2, int y2, char a
	 **post-condition: bool true false
	 ******************************************************/
	bool check(char**board, int num,int x1, int y1, int x2, int y2, char a){
		if ((board[x1][y1]==a)&&(board[x2][y2]==' ')){
			return false;

		}
		else{
			cout<<"Please choose your own chess, and with space."<<endl;
			return true;
		}

	}

	/*****************************************************
	 **program:charge
	 **descriptio: check the chess move.
	 **pre-condition: char** board, int x1,int y1, int x2, int y2
	 **post-condition: bool true or false
	 ******************************************************/
	bool charge(char** board, int num,int x1,int y1, int x2, int y2){
		if(board[x1][y1]=='x'&&((x2==x1+1 && y2==y1-1)||(x2==x1+2 && y2==y1-2)||(x2==x1+2 && y2==y1+2)||(x2==x1+1 && y2==y1+1))){
			return true;
		}else if(board[x1][y1]=='o'&&((x2==x1-1 && y2==y1+1)||(x2==x1-2 && y2==y1+2)||(x2==x1-2 && y2==y1-2)||(x2==x1-1 && y2==y1-1))){
			return true;
		}
		else if((board[x1][y1]=='X'||board[x1][y2]=='O')&&((x2==x1-1 && y2==y1+1)||(x2==x1-2 && y2==y1+2)||(x2==x1-2 && y2==y1-2)||(x2==x1-1 && y2==y1-1)||(x2==x1+1 && y2==y1-1)||(x2==x1+2 && y2==y1-2)||(x2==x1+2 && y2==y1+2)||(x2==x1+1 && y2==y1+1))){
			return true;
		}
		return false;
	}

	/*****************************************************
	 **program:king_x
	 **descriptio: change x to X
	 **pre-condition: char** board, int num
	 **post-condition: none
	 ******************************************************/
	void king_x(char** board, int num,int x2, int y2){
		for(int i=0;i<num; i++){
			for(int j=0;j<num;j++){
				if(board[x2][y2]=='x'&&board[x2][y2]==board[7][y2]){
					int a = board[x2][y2];
					board[x2][y2] = 'X';
				}


			}
		}
	}

	/*****************************************************
	 **program:king_y
	 **descriptio: change o to O
	 **pre-condition: char** board, int num
	 **post-condition: none
	 ******************************************************/
	void king_o(char** board, int num,int x2, int y2){
		for(int i=0;i<num; i++){
			for(int j=0;j<num;j++){
				if(board[x2][y2]==board[0][y2]&&board[x2][y2]=='o'){
					int a = board[x2][y2];
					board[x2][y2] = 'O';
				}


			}
		}
	}




	/*****************************************************
	 **program: give
	 **descriptio:check for x1, y1, x2,y2
	 **pre-condition: char* pick, int i
	 **post-condition: 10, 11 or pick[i]-'0'
	 ******************************************************/
	int give(char* pick ,int  i){
		if(pick[i]=='@'){
			return 10;
		}else if(pick[i]=='J'){
			return 11;
		}else {
			return pick[i]-'0';
		}
	}
	/*****************************************************
	 **program:move1
	 **descriptio: check chess moving for player 1
	 **pre-condition: char** board, int num
	 **post-condition:  0 or 1
	 ******************************************************/
	int move1(char** board, int num){
		cout<<"you are player 1: "<<endl;
		char* pick = new char[256];
		do{cout<<"choose original chess position and new position: ";
			cin.getline(pick,256);
		}while(!(check_chess(pick)));

		int len=strlen(pick);
		int n = (len+1)/4-1;

		for(int i=0;i<n;i++){
			int x1 = give(pick,0);
			int y1 = give(pick,2);
			int x2 = give(pick,4);
			int y2 = give(pick,6);
			cout<<"x1, y1, x2,y2 "<<x1<<y1<<x2<<y2<<endl;
			if(check(board,num ,x1,y1,x2,y2,'x')){
					move1(board, num);
					return 0;
			}
			if(!charge(board,num,x1,y1,x2,y2)||jump_chess(board, num,x1,x2, y1,  y2))
			{
				move1(board, num);
				return 0;
			}
			king_x(board, num,x2,y2);
			cout<<"yes"<<endl;
			if(i!=n-1){
				len-=4;
				for(int i =0;i<len;i++){
				pick[i] = pick[i+4];
				}
				cout<<"pick: "<<pick<<endl;
			}
	}
	print(board, num);
	delete [] pick;
	}

	/*****************************************************
	 **program:move2
	 **descriptio: check chess moving for player 2
	 **pre-condition: char** board, int num
	 **post-condition: 0 or 1
	 ******************************************************/
	int move2(char** board, int num){
		cout<<" you are player 2: "<<endl;

		char* pick = new char[256];
		do{cout<<"choose original chess position and new position: ";
			cin.getline(pick,256);
		}while(!(check_chess(pick)));
		int len=strlen(pick);

		int n = (len+1)/4-1;

		for(int i=0;i<n;i++){
		int x1 = pick[0]-'0';
		int y1 = pick[2]-'0';
		int x2 = pick[4]-'0';
		int y2 = pick[6]-'0';
		if(check(board,num ,x1,y1,x2,y2,'o')){
			move2(board, num);
			return 0;
		}
		if(!charge(board,num,x1,y1,x2,y2)||jump_chess(board, num,x1,x2, y1,  y2))
		{
			move2(board, num);
			return 0;
		}
		king_o(board, num,x2,y2);
		if(i!=n-1){
				len-=4;
				for(int i =0;i<len;i++){
				pick[i] = pick[i+4];
				}
				cout<<"pick: "<<pick<<endl;
			}

		}

		print(board, num);
		delete [] pick;
	}

	/*****************************************************
	 **program:jump_chess
	 **descriptio: check the chess jump for player1
	 **pre-condition: char **board, char *pick, int x1,int y1, int x2, int y2
	 **post-condition: bool true or false
	 ******************************************************/
	bool jump_chess(char **board, int num,int x1,int x2,int y1, int y2){


		int c;
		if(x1<x2){
			c=x2-x1;
		}
		else{
			c=x1-x2;
		}
		if(c==1){
			char a;
			a = board[x1][y1];
			board[x1][y1]=board[x2][y2];
			board[x2][y2] = a;
			return false;
		}
		else {
			if(board[(x1+x2)/2][(y1+y2)/2] ==' '){
				return true;
			}
			if(((board[x1][y1]=='x'||board[x1][y1]=='X')||(board[(x1+x2)/2][(y1+y2)/2]=='o'||board[(x1+x2)/2][(y1+y2)/2]=='O'))||((board[x1][y1]=='o'||board[x1][y1]=='O')||(board[(x1+x2)/2][(y1+y2)/2]=='x'||board[(x1+x2)/2][(y1+y2)/2]=='X'))){
				char a;
				a = board[x1][y1];
				board[x1][y1]=board[x2][y2];
				board[x2][y2] = a;
				board[(x1+x2)/2][(y1+y2)/2]	=' ';
				return false;
			}
		}
	}




	/*****************************************************
	 **program:check_winner
	 **descriptio: check the checker's winner
	 **pre-condition: char**board, int num
	 **post-condition: none
	 ******************************************************/

	bool check_winner(char ** board,int size){
		int p1=0;
		int p2=0;
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				if(board[i][j]=='x'||board[i][j]=='X'){
					p1++;
				}else if(board[i][j]=='o'||board[i][j]=='O'){
					p2++;
				}
			}
		}
		if(p1==0){
			cout<<"Player 1 run out of his chesses,player2 is winner!"<<endl;
			return true;
		}
		else if(p2==0){
			cout<<"Player 2 run out of his chesses,player1 is winner!"<<endl;
			return true;
		}
		return false;
	}

	/*****************************************************
	 **program:stcuk1
	 **descriptio: check winner for no one can move for 'O' and 'o'
	 **pre-condition: char** board  int size
	 **post-condition:  exit(0) exit the game
	 ******************************************************/
bool  stuck1(char** board, int size){
			for(int i=0;i<size;i++){
				for(int j=0;j<size;j++){
					if(board[i][j]=='o'){
						if(charge(board,size,i,j,i-1,j-1)||charge(board,size,i,j,i-1,j+1)||charge(board,size,i,j,i-2,j-2)||charge(board,size,i,j,i-2,j+2))
							return true;
					}
					else if(board[i][j]=='O'){
						if(charge(board,size,i,j,i-1,j-1)||charge(board,size,i,j,i-1,j+1)||charge(board,size,i,j,i+1,j-1)||charge(board,size,i,j,i+1,j+1)||charge(board,size,i,j,i-2,j-2)||charge(board,size,i,j,i-2,j+2)||charge(board,size,i,j,i+2,j-2)||charge(board,size,i,j,i+2,j+2))
							return true;

					}
				}
			}
			cout<<"player2 can not move. The winner is player1"<<endl;
			exit(0);
}

/*****************************************************
 **program:stcuk2
 **descriptio: check winner for no one can move for 'x' and 'X'
 **pre-condition: char** board  int size
 **post-condition:  exit(0) exit the game
 ******************************************************/
bool  stuck2(char** board, int size){
			for(int i=0;i<size;i++){
				for(int j=0;j<size;j++){
					if(board[i][j]=='x'){
						if(charge(board,size,i,j,i+1,j-1)||charge(board,size,i,j,i+1,j+1)||charge(board,size,i,j,i+2,j-2)||charge(board,size,i,j,i+2,j+2))
							return true;
					}
					else if(board[i][j]=='X'){
						if(charge(board,size,i,j,i-1,j-1)||charge(board,size,i,j,i-1,j+1)||charge(board,size,i,j,i+1,j-1)||charge(board,size,i,j,i+1,j+1)||charge(board,size,i,j,i-2,j-2)||charge(board,size,i,j,i-2,j+2)||charge(board,size,i,j,i+2,j-2)||charge(board,size,i,j,i+2,j+2))
							return true;

					}
				}
			}
			cout<<"player1 can not move. The winner is player2"<<endl;
			exit(0);
}

	int main(int argc,char *argv[]){
		int x1,y1,x2,y2;
		int size = get_size(argc, argv);
		char **board = allocate(size);
		print (board,size);
		while(!check_winner(board, size)){

			move1(board,size);
			stuck1(board, size);
			move2(board,size);
			stuck2(board, size);

		}


		for(int i=0;i<size;i++){
			delete[] board[i];
		}
		delete []board;

	}
