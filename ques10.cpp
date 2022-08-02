#include <iostream>
#include <vector>

using namespace std;

void generate_permutation_with_repetition(vector<int> vect, int terms = 0, vector<int>solutions = {}){
    if (terms == vect.size()){
        for (int i = 0; i < solutions.size(); i++){
            cout << solutions[i] << " ";
        }
        cout << endl;
        return;
    }
    else{
        for (int pos = 0; pos < vect.size(); pos++){
            vector<int> new_sol = solutions;
            new_sol.push_back(vect[pos]);
            generate_permutation_with_repetition(vect , terms+1, new_sol);
        }
    }
}

void generate_permutation_without_repetition(vector<int> vect, int terms = 0 , vector<int> visited = {}, vector<int>solutions = {}){
    if (terms == vect.size()){
        for (int i = 0; i < solutions.size(); i++){
            cout << solutions[i] << " ";
        }
        cout << endl;
        return;
    }

    else{
        for (int pos = 0; pos < vect.size(); pos++){
            bool is_visited = false;
            for (int i = 0; i < visited.size(); i++){
                if (visited[i] == pos) is_visited = true;
            }

            if (is_visited) continue;

            vector<int> new_sol = solutions;
            visited.push_back(pos);
            new_sol.push_back(vect[pos]);
            generate_permutation_without_repetition(vect , terms+1, visited, new_sol);
            visited.pop_back();
        }
    }
}




int main(){
    vector<int> vect;
    int length, element;
    bool choice;

    cout << "Please enter the length of the set ";
    cin >> length;

    for (int i = 0; i < length; i++){
        cout << "Please enter a unique element ";
        cin >> element;
        vect.push_back(element);
    }

    cout << "Do you want digits to be repeated press 0 for no and 1 for yes ";
    cin >> choice;
    if (choice) generate_permutation_with_repetition(vect,vect.size());
    else generate_permutation_without_repetition(vect);
    return 0;
}