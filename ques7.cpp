#include<iostream>
using namespace std;

int BinarySearch(int *Array, int lower, int upper, int element){
	if (lower <= upper){
		int mid = (lower + upper)/2;
		// case 1: mid 
		if (element == Array[mid]){
			return mid;
		}
		// case 2: left half
		else if (element < Array[mid]){
			return BinarySearch(Array, lower, mid - 1, element);
		}
		// case 3: right half
		else{
			return BinarySearch(Array, mid + 1, upper, element);
		}
	}
	return -1;
}

int main(){
	// Taking random list and element to be searched thereof
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int element = 3;
	int index = BinarySearch(arr, 0, sizeof(arr)/sizeof(arr[0]), element);
	if (index != -1)
		cout << "the element " << element << " is present at index " << BinarySearch(arr, 0, sizeof(arr)/sizeof(arr[0]), element);
	else
		cout << "the element " << element << " is not preset in the array.";
	return 0;
}