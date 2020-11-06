#include <iostream>
#include <sys/time.h>
#include <cstdlib>
using namespace std;

int fib_iter(int n){
	int a=1;
	int b=1;
	int c=1;
	for(int i=3;i<=n;i++){
		c=a+b;
		a=b;
		b=c;
	}
	return c;
}

int fib_recurs(int m){
	if(m<=0) return 0;
	if (m==1) return 1;
	 return fib_recurs(m-1)+fib_recurs(m-2);
}
int fun(int n){
	if(n==0) return 0;
	else if(n==1)return 1;
	else if (n==2) return 2;
	else if(n>2) return fun(n-1)+fun(n-2);
}
int main(){
	typedef struct timeval time;
	time stop, start;

	gettimeofday(&start, NULL);
	int x; 
	cout<<"fib_recurs: ";
	cin >> x;
	cout<<fib_recurs(x)<<endl;
	gettimeofday(&stop, NULL);
	
	if(stop.tv_sec > start.tv_sec)
		cout<<"Seconds:"<<stop.tv_sec - start.tv_sec<<endl;
	else
		cout<<"Micro:"<<stop.tv_usec - start.tv_usec<<endl;  
	
	

	gettimeofday(&start, NULL);
	int n;
		cout<<"fib_iter: ";
		cin>>n;
		cout<<fib_iter(n)<<endl;
	gettimeofday(&stop, NULL);
	
	if(stop.tv_sec > start.tv_sec)
		cout<<"Seconds:"<<stop.tv_sec - start.tv_sec<<endl;
	else
		cout<<"Micro:"<<stop.tv_usec - start.tv_usec<<endl; 

	
	int b;
	cin>>b;
	cout<<fun(b)<<endl; 
	return 0;


}
