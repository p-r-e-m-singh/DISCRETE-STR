#include <iostream>
using namespace std;

class Relation{
public:
    // Members of class
    bool** matrix;
    int n; // order - n

    Relation(int side)
    {
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
            for (int j = 0; j < n; j++)
            {
                if (j>i && !matrix[i][j])
                        return false;
                else
                {
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
                            if (matrix[i][k]) continue;
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
};

int main(){
    int n = 3;
    Relation r(n);
    
    cout <<"IS relation reflexive ?"; if(r.is_reflexive()==1){ cout<<"true";} else{cout<<"false";};
    cout << "\nIs relation symmetric?";if(r.is_symmetric()==1) cout<<"true"; else cout<<"false";
    cout << "\nIs relation transitive ?";if(r.is_transitive()==1) cout<<"true"; else cout<<"false";
}