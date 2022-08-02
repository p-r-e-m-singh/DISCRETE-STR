#include<iostream>
using namespace std;
bool check_euler_circuit(bool *arr, int n){
    for (int i = 0; i < n; i++){
        int degree = 0;
        for (int j = 0; j < n; j++){
            if (arr[i*n + j]) degree++;
        }
        if (degree % 2 != 0) return false;
    }
    return true;
}

bool check_euler_path(bool *arr, int n){
    int odd_degree_count = 0;
    for (int i = 0; i < n; i++){
        int degree = 0;
        for (int j = 0; j < n; j++){
            if (arr[i*n + j]) degree++;
        }
        if (degree % 2 == 1) odd_degree_count++;
    }
    if (odd_degree_count != 2) return false;
    return true;
}

int main(){
    int n = 5;
    //Taking this matrix as an exemplary
    bool matrix[n*n] = {
        0,1,0,0,0,
        1,0,1,0,0,
        0,1,0,1,1,
        0,0,1,0,1,
        0,0,1,1,0
    };

    cout <<"Is there an Euler Path? :";if(check_euler_path(matrix, n)) cout<<"Yes!";else cout<<"No";
    cout<<"\nIs there an Euler Circuit? : ";if(check_euler_circuit(matrix,n)) cout<<"Yes";else cout<<"No";
    return 0;
}
