#include<iostream>
using namespace std;

class Vertex{
	public:
		char name;
		Vertex(){ // default constructor
		}
		Vertex(char name){
			this->name = name;
		}
		void operator = (Vertex oth){
			this->name = oth.name;
		}
		bool operator == (Vertex oth){
			return this->name == oth.name;
		}
};

class Graph{
	public:
		Vertex *V;
		int *arr;
		int n;
		Graph(Vertex *V, int *arr, int n){
			this->n = n;
			this->V = new Vertex[n];
			this->arr = new int[n*n];
			for (int i = 0; i < n; i++){
				this->V[i] = V[i];
				for (int j = 0; j < n; j ++){
					this->arr[(i * n) + j] = arr[(i * n) + j];
				}
			}
		}
		void computeDegree(){
			cout << "In-degree\n";
			for (int j = 0; j < n; j ++){
				int in_degree = 0;
				for (int i = 0; i < n; i ++){
					in_degree += arr[(i * n) + j];
				}
				cout << "deg-(" << V[j].name << ") is : " << in_degree << endl;
			}
			cout << "\n\nOut-degree\n";
			for (int i = 0; i < n; i ++){
				int out_degree = 0;
				for (int j = 0; j < n; j ++){
					out_degree += arr[(i * n) + j];
				}
				cout << "deg+(" << V[i].name << ") is : " << out_degree << endl;
			}
		}
};

int main(){
	Vertex V[] = {Vertex('a'), Vertex('b'), Vertex('c')};
	int n = sizeof(V)/sizeof(V[0]);
	int matrix[n*n] = {0};
	cout << "enter the elements of the matrix : \n";
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j ++){
			cin >> matrix[(i * n) + j];
		}
	}
	Graph graph(V, matrix, n);
	graph.computeDegree();
	return 0;
}
