#include <iostream>

#include<string>  

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

void rightBlock(int x) 
{ 
    int binaryNum[32]; 
  
    int i = 0; 
    while (x >= 1) { 
        binaryNum[i] = x % 2; 
        x = x / 2; 
        i++; 
    } 
  
  	cout << "Right foremost = ";
    for (int j = i - 1; j >= 0; j--) 
        cout << binaryNum[j]; 
    
    cout << " and to the left of it is " << 64-i << " zeros";
} 
	
void middleBlock(int l, int pL) {
	cout << "\nThe middle block contains " << pL - 65 - l << " zeros";
}
int main(int argc, char** argv) {
	int l;
	
	cout << "Enter the lenth of the message in bits ";
	cin >> l;
	
	int padLength = 512;
	
	while (padLength < l+65) {
		padLength += 512;
	}
	
    rightBlock(l);
	middleBlock(l,padLength);
	
	return 0;
}
