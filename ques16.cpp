#include<iostream>
using namespace std;

void computeCompleteGraph(int *arr, int n){
	int zero_count = 0, one_count = 0;
	for (int i = 0; i < n; i ++){
		for (int j = 0; j < n; j ++){
			// check for diagonal
			if (i == j && arr[(i * n) + j] == 0){
				zero_count ++;
			}
			else if (arr[(i * n) + j] == 1){
				one_count ++;
			}
		}
	}
	if (zero_count == n && one_count == n*(n-1)){
		cout << "Complete graph";
	}
	else{
		cout << "In-complete graph";
	}
}
int main(){
	int n;
	cout << "enter the matrix order : ";
	cin >> n;
	int matrix[n*n] = {0};
	cout<<"\nEnter the adjacency Matrix with each element alongwith a space : ";
	for (int i = 0; i < n; i ++){
		for (int j = 0; j < n; j ++){
			cin >> matrix[(i * n) + j];
		}
	}
	computeCompleteGraph(matrix, n);
	return 0;
}
