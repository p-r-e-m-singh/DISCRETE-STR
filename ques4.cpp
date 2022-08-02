#include <iostream>
using namespace std;

class Relation{
public:
    // Members of class
    bool** matrix;
    int n; // order - n

    Relation(int side){
        n = side;
        this->matrix = new bool*[side];
        for (int i = 0; i < side; i++){
            this->matrix[i] = new bool[side];
            for (int j = 0; j < n; j++){
                cin >> this->matrix[i][j];
            }
        }
    }

    bool is_reflexive(){
        for (int i = 0; i < n; i++){
            if (!matrix[i][i]){
                return false;
            }
        }
        return true;
    }

    bool is_symmetric(){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (j>i && !matrix[i][j])
                        return false;
                    else{
                        if (matrix[i][j] != matrix[j][i])
                            return false;
                    }
            }
        }
        return true;
    }

    bool is_transitive(){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j]){
                    for (int k = 0; k < n; k++){
                        if (matrix[j][k]){
                            if (matrix[i][k])continue;
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    bool is_antisymmetric(){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (j>i && matrix[i][j] == matrix[j][i]) return false;
            }
        }
        return true;
    }

    bool is_equivalence(){
        return (is_reflexive() && is_symmetric() && is_transitive());
    }

    bool is_partial_order(){
        return (is_reflexive() && is_antisymmetric() && is_transitive());
    }
};

int main(){
    int n = 3;
    Relation r(n);
    cout << "Is relation equivalence? :";if(r.is_equivalence()==1) cout<<"Yes"; else cout<<"No";
    cout << "\nIs relation Partially ordered? :";if(r.is_partial_order()==1) cout<<"Yes";else cout<<"No";
    if(r.is_equivalence()==0 && r.is_partial_order()==0 ){
        cout<<"\nNone";
    }
}