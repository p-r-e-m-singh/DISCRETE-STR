#include <iostream>
using namespace std;

int calc_answer(int n, int default_value){ //T(0) = 1
    if (n==0) return default_value;
    else return calc_answer(n-1 , default_value) + n; //T(n) = T(n-1) + n
}   

int calc_answer_two(int n, int default_value){
    if (n==0) return default_value;
    else return calc_answer_two(n-1, default_value) + n*n;
}  

int calc_answer_three(int n, int default_value){
    if (n==1) return default_value;
    else return calc_answer_three(n/2 , default_value) + n;
}

int main(){
    int n, def_value, choice;

    cout << "Which expression do you want the calculation for " << endl;
    cout << "1. T(n) = T(n-1) + n" << endl;
    cout << "2. T(n) = T(n-1) + n^2" << endl;
    cout << "3. T(n) = 2 T(n/2) + n" << endl;
    cout << "Please enter you choice ";
    cin >> choice;

    cout << "Please enter the default value ";
    cin >> def_value;

    cout << "Please enter the number of terms ";
    cin >> n;
    
    if (choice == 1) cout << calc_answer(n , def_value) << endl;
    else if(choice == 2) cout << calc_answer_two(n , def_value) << endl;
    else if (choice == 3) cout << calc_answer_three(n , def_value) << endl;
    else cout << "Please enter a value choice." << endl;
    return 0;
}
