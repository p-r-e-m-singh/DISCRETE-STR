#include<iostream>
using namespace std;

int factorial(int n){
	if (n == 1)
		return 1;
	else
		return n * factorial(n-1);
}

float permutation(int n, int r){
	return float(factorial(n))/factorial(n-r);
}
float combination(int n, int r){
	return float(factorial(n))/(factorial(n-r) * factorial(r));
}

int main(){
	// For Example
	cout << "Selection of 2 out of 5 is possible in "<<combination(5,2)<<" ways\n";
	cout<<"Arrangement of 2 out of 5 is possible in "<<permutation(5,2)<<" ways\n";

	return 0;
}
