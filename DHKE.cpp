#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int expModulus(int x, int n, int p) {
	int result = 1;

    x = x % p;
    while (n > 0) {
        if (n % 2  != 0) {
            result = (result * x) %  p;
        }
        n=n/2;
        x= (x*x) % p;
    }

    return result;
}
int main(int argc, char** argv) {
	//Standard DHKE
	int alpha = 2; //Generator g or alpha
	int prime = 467; //Prime p
	
	int a = 400; //Alice chooses 400 as small a and send Bob A = g^a mod p
	int b = 57; //Bob chooses 57 as small b and send Alice B = g^b mod p
	
	int A = expModulus(alpha,a,prime);
	int B = expModulus(alpha,b,prime);
	
	int commonKeyA = expModulus(B,a,prime);
	int commonKeyB = expModulus(A,b,prime);
	
	cout << "Two common keys are " << commonKeyA << " and " << commonKeyB;
	cout << "\n\n";
	
	//Man in the middle
	
	int middleValue = 23;
	
	int middleB = expModulus(alpha,middleValue,prime);
	int middleA = expModulus(alpha,middleValue,prime);
	
	int fakeKeyB = expModulus(middleA,b,prime);
	int fakeKeyA = expModulus(middleB,a,prime);

	cout << "Fake keys are " << fakeKeyA << " and " << fakeKeyB;
	return 0;
}
