#include <iostream>
#include <vector>
using namespace std;

void solutions(int terms , int sum , vector<int> vect = {}){
    if (terms == 1){
        for (int i = 0; i < vect.size(); i++){
            cout << vect[i] << " ";
        }
        cout << sum;
        cout << endl;
    }
    else {
        for (int i = 0; i <= sum; i++){
            vector<int> new_sol = vect;
            new_sol.push_back(i);
            solutions(terms-1, sum-i, new_sol);
        }
    }
}

int main(){
    int n, C;
    cout << "Please enter the number of terms ";
    cin >> n;
    cout << "Please enter the target sum ";
    cin >> C;
    cout<<"No of distinct pairs possible to get sum ="<<C<<endl ;
    solutions(n , C);
    return 0;
}