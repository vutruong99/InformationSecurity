#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int mod(int x, int n, int p) {
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

void encryption(int p, int q, int e, int m) {
    int n = (p-1)*(q-1);
    int d = 0;
	int N = p*q;
	
    for (int i = 0; i < n; i++) {
        if ((e*i)%n == 1) {
            d=i;
            break;
        }
    }
    
    cout << "Public key is (" << N << "," << e << ") / Private key is " << d <<"\n";
    cout << "Cypher text is " << mod(m,e,N) << "\n";  
       
}

void decryption(int p, int q, int d, int c) {
    int n = (p-1)*(q-1);
    int e = 0;
	int N = p*q;
	
    for (int i = 0; i < n; i++) {
        if ((d*i)%n == 1) {
            e=i;
            break;
        }
    }
    
    cout << "Public key is (" << N << "," << e << ") / Private key is " << d <<"\n";
    cout << "Cypher text is " << mod(c,d,N) << "\n";  
       
}
int main(int argc, char** argv) {
	encryption(5,11,3,9);
 	decryption(5,11,27,14);
	return 0;
}
