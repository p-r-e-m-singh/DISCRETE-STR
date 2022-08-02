#include<iostream>
using namespace std;
int *U;
int U_Length;
class SET{
	private:
		int *arr;
		int n;
		bool isMember(int element){
			for (int i = 0; i < n; i++){
				if (arr[i] == element)
					return true;
			}
			return false;
		}
	public:
		SET(){
			n = 0;
			arr = new int[0];
		}
		SET(int arr[], int n){
			this->arr = new int[n];
			this->n = n;
			for (int i = 0; i < n; i++){
				this->arr[i] = arr[i]; 
			}
		}
		// part (a)
		void isSubset(SET other){
			if (other.n > n){
				cout << "no! it is not a subset.\n";
				return;
			}
			for (int i = 0; i < other.n; i++){
				if (!(isMember(other.arr[i]))){
					cout << "no! it is not a subset.\n";
					return;
				}
			}
			cout << "yes! it is a subset.\n";
			return;
		}
		// part (b) - Union
		void getUnion(SET other){
			cout << "union - ";
			for (int i = 0 ; i < n; i ++){
				cout << arr[i] << " ";
			}
			for (int i = 0; i < other.n; i++){
				if (!(isMember(other.arr[i])))
					cout << other.arr[i] << " ";
			}
		}
		// part (b) - intersection
		void getIntersection(SET other){
			cout << "intersection - ";
			for (int i = 0; i < other.n; i++){
				if (isMember(other.arr[i]))
					cout << other.arr[i] << " ";
			}
			cout << endl;
		}
		// part (c)
		void complement(){
			cout << "Complement - ";
			for (int i = 0; i < U_Length ; i ++){
				if (!(isMember(U[i])))
					cout << U[i] << " ";
			}
		}
		// part (d) - set difference
		void setDifference(SET other){
			cout << "set diiference - ";
			for (int i = 0; i < n; i++){
				if (!(other.isMember(arr[i])))
					cout << arr[i] << " ";
			}
		}
		// part (d) - symmetric difference
		void symmetricDifference(SET other){
			cout << "symmetric difference - ";
			for (int i = 0 ; i < n; i++){
				if (!(other.isMember(arr[i])))
					cout << arr[i] << " ";
			}
			for (int i = 0 ; i < other.n; i++){
				if (!(isMember(other.arr[i])))
					cout << other.arr[i] << " ";
			}
		}
		// part (e)
		void cartesianProduct(SET other){
			cout << "cartesian product - \n";
			for (int i = 0; i < n; i++){
				for (int j = 0; j < other.n; j ++){
					cout << "(" << arr[i] << ", " << other.arr[j] << ")" << endl;
				}
			}
		}
};

int main(){
	int nouni;
	cout<<"Enter length of Union Set: ";
	cin>>U_Length;
	U = new int[U_Length];
	for (int i = 0; i < U_Length; i ++){
		cout<<"Enter "<<i+1<<"th element";
		cin>>U[i];
	}

	//Taking 1st array in input
	int n1;
	cout<<"ENter the number of elements in first array";
	cin>>n1;
	int a[n1];
	for(int i=0;i<n1;i++){
		cout<<"Enter "<<i+1<<"th element :";
		cin>>a[i];
	}
	int n2;
	cout<<"Enter size of second set : ";
	cin>>n2;
	int b[n2];
	for(int i=0;i<n2;i++){
		cout<<"ENter "<<i+1<<"th element : ";
		cin>>b[i];
	}
	// int a[] = {0,1,2,3,4,5,6,7,8,9};
	// int b[] = {6,7,8,9,10,11};
	SET s1(a,n1), s2(b,n2);
	cout<<"Is s2 subset of s1 : ";s2.isSubset(s1);
	cout<<endl;
	cout<<"Union of both sets: ";s1.getUnion(s2);
	cout<<endl;
	cout<<"Intersection of both sets:";s1.getIntersection(s2);
	cout<<endl;
	cout<<"Complement of set 1 is : ";s1.complement();
	cout<<endl;
	cout<<"Set Difference of set1 and set2 : ";s1.setDifference(s2);
	cout<<"\nSymmetric DIfference of set1 and set2 : ";s1.symmetricDifference(s2);
	cout<<"\nCartesian Products of both sets: "; s1.cartesianProduct(s2);
	return 0;
}
