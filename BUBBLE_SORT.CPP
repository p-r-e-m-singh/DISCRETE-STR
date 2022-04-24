#include<iostream>
using namespace std;

class bub_sort{
    int length;
    int *arr;
    public:
        bub_sort(){
            length=0;
            arr = new int[0] ;
        }
        bub_sort(int a[],int n){
            length =n;
            arr = new int[n];
            arr=a;

        }
        void input(){
            cout<<"Enter the length of array  : ";
            cin>>length;
            arr = new int[length];
            for (int i = 0; i < length; i++)
            {
                cin>>arr[i];
            }
        }

        void sort(){
            for (int i = 0; i < length; i++)
            {   int temp;
                int iter =1;
                for(int j=length-1;j>i;j--){

                    if(arr[j]<arr[j-1]){
                        temp = arr[j];
                        arr[j]=arr[j-1];
                        arr[j-1]=temp;
                    }
                    cout<<"Array after "<<iter<<"th iteration is : \n"<<endl;
                    for (int i = 0; i < length; i++)
                    {
                        cout<<arr[i]<<" ";
                    }
                    cout<<"\n";
                    iter++;
                    
                }
                cout<<"Next Loop \n";
                
            }
            
            
        }
        void display()
        {
            for(int i=0;i<length;i++){
                cout<<arr[i]<<" ";
            }
        }
        ~bub_sort(){
            cout<<"\nSorting Done\n";
        }
};
int main()
{
    int n=4;
    int a[n]={8,4,6,3};
    bub_sort ob(a,n);
    ob.sort();
    return 0;
}