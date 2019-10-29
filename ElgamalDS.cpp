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

int CAfunction(int key, int id) {
	return 4*key+id; //Function is 4*b(i) + ID(i)
}

int mod(int a, int b) { 
	return (a % b + b) % b; 
}

int modInverse(int a, int m) 
{ 
    a = a%m; 
    for (int x=1; x<m; x++) 
       if ((a*x) % m == 1) 
          return x; 
} 

int main(int argc, char** argv) {
	
	int p = 467; //Large prime
	int d = 127; //Random integer
	int alpha = 2; //Primitive element
	int beta = expModulus(alpha,d,p); //Beta = alpha^d mod p
	int kE = 213; //Random empheral key;
	
	//Compute signature parameters
	int r = expModulus(alpha,kE,p); 
	int s = mod(mod((CAfunction(400,1)- d*r),p-1) * modInverse(kE,p-1),p-1);  // (x-d*r)*kE mod p 
	int t = expModulus((expModulus(beta,r,p) * expModulus(r,s,p)),1,p) ;
	
	int tPrime = expModulus(alpha,CAfunction(400,1),p);
	
	cout << "\n" << t << " " << tPrime;
	return 0;
}
