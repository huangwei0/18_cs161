#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
int main(){
        int n,max,min,umax,umin,max1,min1,umax1,umin1;
        cin >> n;
        cout << "Please enter the number \"n\" between 0~8 "  << endl;
        if (n <= 8 && n>=0){
        max = pow(2,8*(n-1))-1;
        min = pow(2,8*n-1);
        umax = pow(2,8*n)-1;
        umin = 0;
	
	max1 = max+1;
	min1 = min-1;
	umax1 = umax+1;
	umin1 = umin1-1;
        cout <<  "The sign max number value of " << n << "bytes is: " << max1<< endl;
        cout << "The sign min number value of " << n << "bytes is: " << min1 << endl;
        cout <<" The unsign max number value of " << n << "bytes is: " << umax1 <<endl;
        cout << "The unsign min number value of " << n << "bytes is: " << umin1 << endl;
        }
        else{
                cout <<"The number you typed is out of range."<< endl;
        }
        return 0;
}

