#include <iostream>

using namespace std;

class Matrix{
private:
    int** matrix;
    int degree;

public:
    Matrix(int degree){
        this->degree = degree;
        this->matrix = new int*[degree];
        for (int i = 0; i < degree; i++){
            this->matrix[i] = new int[degree];
        }

        for (int i = 0; i < degree; i++){
            for (int j = 0; j < degree; j++){
                cout << "Please enter the element at position " << i + 1 << " " << j+1 << " ";
                cin >> this->matrix[i][j];
            }
        }
    }

    Matrix(int degree, int** matrix){
        this->degree = degree;
        this->matrix = new int*[degree];
        for (int i = 0; i < degree; i++){
            this->matrix[i] = new int[degree];
        }
        for (int i = 0; i < degree; i++){
            for (int j = 0; j < degree; j++){
                this->matrix[i][j] = matrix[i][j];
            }
        }
    }

    // Matrix(Matrix& copier, bool copy){
    //     this->degree = copier.degree;
    //     this->matrix = copier.matrix;
    // }

    Matrix operator * (Matrix other){
        int** result;
        result = new int*[degree];
        for (int i = 0; i < degree; i++){
            result[i] = new int[degree];
        }

        for (int i = 0; i < degree; i++){
            for (int j = 0; j < degree; j++){
                result[i][j] = 0;
                for (int x = 0; x < degree; x++){
                    result[i][j] += matrix[i][x] * other.matrix[x][j];
                }
            }
        }

        return Matrix(degree, result);
    }


    void print_matrix(){
        for (int i = 0; i < degree; i++){
            for (int j = 0; j < degree; j++){
                cout << this->matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    int get_element(int i, int j){
        return this->matrix[i][j];
    }
};

int main(){
    Matrix A(4);
    A.print_matrix();
    // Matrix C = A * A;
    // cout << "Printing done" << endl;
    // C.print_matrix();
    int start, end, length;
    cout << "Please enter starting point and ending point ";
    cin >> start;
    cin >> end;
    cout << "Please enter the length ";
    cin >> length;

    Matrix result = Matrix(A);
    for (int i = 1; i < length; i++){
        result = result * A;
    }

    cout << "Number of possble paths = " << result.get_element(start, end) << endl;
    return 0;
}
