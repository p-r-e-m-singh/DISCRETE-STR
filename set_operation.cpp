#include<iostream>
#include<cmath>

using namespace std;

bool isMember(int *arr, int n, int element){
	for (int i = 0; i < n; i++){
		if (arr[i] == element)
			return 1;
	}
	return 0;
}
void powerset(int *arr, int n){
	for (int i = 0; i < pow(2,n); i++){
		cout << "{ ";
		for (int j = 0; j < n; j++){
			if (i & (1 << j)){
				cout << arr[j] << " ";
			}
		}
		cout << "}" << endl;
	}
}

int main(){
	int cardinality;
	cout << "enter the length of set : ";
	cin >> cardinality;
	int Set[cardinality] = {0};
	cout << "enter the elements of the array : \n";
	for (int i = 0; i < cardinality; i ++){
		cin >> Set[i];
	}
	// is member function
	int member;
	cout << "enter the element that you want to check in set : ";
	cin >> member;
	if (isMember(Set, cardinality, member))
		cout << member << " exists in Set.\n";
	else
		cout << member << " does not exists in Set";
	powerset(Set,cardinality);
	
	return 0;
}
