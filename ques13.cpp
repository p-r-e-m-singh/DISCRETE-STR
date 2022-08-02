#include<iostream>
using namespace std;

int main(){
    bool p = 0, q = 0;
    cout << "enter the value of x and y" << endl;
    cin >> p;
    cin >> q;
    cout << "Conjunction               : " << (p && q) << endl;
    cout << "Disjunction               : " << (p || q) << endl;
    cout << "XOR                       : " << ((!p && q) || (p && !q)) << endl;
    cout << "Conditional (if x then y) : " << !(p && !q) << endl;
    cout << "Conditional (if y then x) : " << !(q && !p) << endl;
    cout << "Bi-conditional            : " << ((!p && !q) || (p && q)) << endl;
    cout << "XNOR                      : " << ((!p && !q) || (p && q)) << endl;
    cout << "Negation x                : " << !p << endl;
    cout << "Negation y                : " << !q << endl;
    cout << "x NAND y                  : " << !(p && q) << endl;
    cout << "p NOR q                   : " << !(p || q) << endl; 
    return 0;
}