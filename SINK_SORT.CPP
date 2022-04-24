#include<iostream>
using namespace std;

class sink_sort
{
    int n;
    int *arr;
    public:
        sink_sort(int a[],int num){
            n = num;
            arr = new int[num];
            arr=a;
        }
        sink_sort(){
            n = 0;
            arr=new int[0];
        }

        void input(){
            cout<<"Enter the number of elements : ";
            int i;
            cin>>i;
            n=i;
            arr = new int[i];
            for (int j = 0; j < n; j++)
            {
                cin>>arr[j];
            }
            
        }

        void sortit(){
            int i=n;
            while(i){
                int iter=1;
                int temp;
                for(int j=0;j<i-1;j++){
                    if(arr[j]>arr[j+1]){
                        temp = arr[j];
                        arr[j]=arr[j+1];
                        arr[j+1]=temp;

                    }
                    cout<<"Array after "<<iter<<"th iteration is : \n"<<endl;
                    for (int i = 0; i < n; i++)
                    {
                        cout<<arr[i]<<" ";
                    }
                    cout<<"\n";
                    iter++;
                    
                } cout<<"\t Next Loop \t \n";
                i--;
            }
        }
        void display()
        {
            for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
        }

        ~sink_sort()
        {
            cout<<" \nSorting Done \n";
        }
};

// MAIN PROGRAM
int main(){
    int a[] = {2,4,3,5};
    sink_sort ob(a,4);
    // ob.input();
    ob.sortit();
    // ob.display();
    return 0;
}