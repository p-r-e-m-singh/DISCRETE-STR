#include <iostream> 
using namespace std;

void swapping_in_insertion_sort(int* arr , int length){
    int number_comparisons = 0;
    for (int i = 1; i < length; i++){
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            number_comparisons++;
            j = j-1;
        }
        arr[j+1] = temp;
    }
    cout << "The number of comparison is : " << number_comparisons;
    cout<<"\nSorted Array";
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
    swapping_in_insertion_sort(arr, length);
    return 0;
}
