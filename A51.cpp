#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int maj(int x, int y,int z){
	if ((x+y+z) >= 2) return 1; //If there are two ones, return one, else return zero
	else return 0;
};

void shift(int keyBits[], int size) {
	int newInput = 0;
	int i = 0;
	if (size == 19) { //If we want to shift the X array
		newInput = keyBits[13] ^ keyBits[16] ^ keyBits[17] ^ keyBits[18];
		
		for (i = 18; i >= 0; i--) {
			if (i == 0) {
				keyBits[i] = newInput;
			} else {
				keyBits[i] = keyBits[i-1];
			}
		}
	}
	
	if (size == 22) { //If we want to shift the Y array
		newInput = keyBits[20] ^ keyBits[21];
		
		for (i = 21; i >= 0; i--) {
			if (i == 0) {
				keyBits[i] = newInput;
			} else {
				keyBits[i] = keyBits[i-1];
			}
		}
	}
	
	if (size == 23) { //If we want to shift the Z array
		newInput = keyBits[7] ^ keyBits[20] ^ keyBits[21] ^ keyBits[22];
		
		for (i = 22; i >= 0; i--) {
			if (i == 0) {
				keyBits[i] = newInput;
			} else {
				keyBits[i] = keyBits[i-1];
			}
		}
	}
	

}

int main(int argc, char** argv) {
	
	int x [19] = {1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
	int y [22] = {1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1};
	int z [23] = {1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0};
	int result[10];
	
	int i = 0;
	
	for (i = 0; i < 10; i++) {
		int m = maj(x[8],y[10],z[10]);
		if (x[8] == m) {
			shift(x,19);
		}
		
		if (y[10] == m) {
			shift(y,22);
		}
		
		if (z[10] == m) {
			shift(z,23);
		}
		
		result[i] = x[18] ^ y[21] ^ z[22];
	}
	for (i = 9; i >=0; i--) {
		cout << result[i];
	}
	return 0;
}
