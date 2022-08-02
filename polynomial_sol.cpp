#include <iostream>
using namespace std;

class Polynomial{
	private:
		int max_power;
		int* coeffecients;
		
	public:
		Polynomial(int max_power){
			this->max_power = max_power;
			this->coeffecients = new int[max_power+1];
			
			for (int i = 0; i <= max_power; i++){
				cout << "Please enter the coeffecient of x^" << i << " ";
				cin >> coeffecients[i];
			}
		}
		
		int compute(int term){
			int result = 0;
			
			for (int i = 0; i <= max_power; i++){
				int product = 1;
				for (int j = 1; j <= i; j++){
					product = product * term;
				}
				result += product * coeffecients[i];
			
			}
			
			return result;
		}
};

int main(){
	int max_power,n;
	cout << "Please enter the maximum power in the polynomial ";
	cin >> max_power;
	Polynomial A(max_power);
	cout << "Please enter the value of n ";
	cin >> n;
	cout<<"Value of f(n) ="<<A.compute(n)<<endl;
	// for (int i = 0; i < n; i++){
	// 	cout << A.compute(i) << endl;
	// }
	return 0;
}
