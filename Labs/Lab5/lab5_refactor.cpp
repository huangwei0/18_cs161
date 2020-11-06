#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool is_int(string input){
	bool flag = false;
		int count = 0;
		for(int i=0; i<input.length(); i++){
			if (input[i] < '0' || input[i] > '9') {
				if (input[i] == '.') {
					count++;
					if (count > 1) {
						flag = true;
					}
				}
				else {
					flag = true;
				}
			}
		}
		return flag;
}

float get_float(string input){
	int i =0;
	for(i = 0; i < input.length(); i++) {
		if (input[i] == '.')
			break;
	}
	float res = 0;
	float val = 0;
	for(int j = i-1; j >= 0; j--) {
		val = ((int) input[j]) -48;
		res += val * pow(10, (i - 1 - j));
	}
	float decimal = 0;
	int count = 1;
	for(int k = i+1; k < input.length(); k++) {
		val = ((int) input[k]) - 48;
		decimal += val * pow(10, (-count));
		count++;
	}
	return res + decimal;
}

int get_int(string input){
	float res;
	for(int i = (input.length()-1); i >= 0; i--) {
		float val = ((int) input[i]) - 48;
		 res +=  val * pow(10,(input.length() - i -1));
	}
	return res;
}

void user_enter(string input){
	bool flag;
	do{
		cout << "Please provide the amount of time in years between the current offer and future offer: ";
		getline(cin, input);
		flag = false;
		int count = 0;
		for(int i=0; i<input.length(); i++){
			if (input[i] < '0' || input[i] > '9') {
				flag = true;
			}
		}
	} while (flag);
}



int main() {
	float current_offer = 0, future_offer = 0, ir = 0, m = 1, n = 0, res, val, decimal;
	string input = "";
	int i, count;
	bool flag;
	cout << "It looks like you have two offers. Let's calculate which one is worth more." << endl;
	do{
		cout << "Please provide the current offer amount: ";
		getline(cin, input);
		 is_int(input);
	} while (flag);
	current_offer =get_float(input);
	do{
		cout << "Please provide the future offer amount: ";
		getline(cin, input);
		is_int(input);
	} while (flag);
	future_offer = get_float(input);
	do{
		cout << "Please provide the interest rate: ";
		getline(cin, input);
		is_int(input);
	} while (flag);
	ir = is_int(input);
	cout << "Please provide the amount of time in years between the current offer and future offer: ";
	cin >> n;
	user_enter( input);
	n = get_int(input);

	 float val_current_offer = current_offer*(pow((1+(ir/m)),(n*m)));
	 float val_future_offer = future_offer/(pow((1+(ir/m)), (n*m)));

	 if (val_current_offer > val_future_offer) {
	 	cout << "Take the current offer" << endl;
	 }
	 else if (val_current_offer < val_future_offer) {
	 	cout << "Take the future offer" << endl;
	 }
	 else {
	 	cout << "Choose which ever" << endl;
	 }
	return 0;
}
