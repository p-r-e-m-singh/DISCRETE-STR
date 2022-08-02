#include <iostream> 
using namespace std;

void swapping_in_bubble_sort(int* arr , int length){
    int number_comparisons = 0;
    for (int i = length - 1; i >= 0; i--){
        for (int j = 0; j < i; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            number_comparisons++;
        }
    }
    cout << "The number of comparison is : " << number_comparisons;
    cout<<"\nSorted Array: ";
    for(int i=0;i<length;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int length = 0;
    cout << "enter the length of the array : ";
    cin >> length;
    int* arr = new int[length];
    cout << "enter elements of the array\n";
    for (int i = 0; i < length; i ++){
        cin >> arr[i];
    }
    swapping_in_bubble_sort(arr, length);
    return 0;
}