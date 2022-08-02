#include<iostream>
using namespace std;

void fibonacci(int n, int a = 0, int b = 1){
	if (n <= 0){
		return;
	}
	int c = a + b;
	cout << a << " ";
	a = b;
	b = c;
	n--;
	fibonacci(n,a,b);
}

int main(){
	int n;
	cout << "enter the number of terms in fibonacci series : ";
	cin >> n;
	fibonacci(n);
	return 0;
}