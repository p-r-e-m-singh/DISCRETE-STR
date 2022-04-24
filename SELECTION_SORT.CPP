#include<iostream>
using namespace std;

class selection_sort
{
private:
    int length;
    int *arr;

public:
    selection_sort(){
        length=0;
        arr= new int[0];
    };
    selection_sort(int a[],int n)
    {
        length=n;
        arr = new int[length];
        arr=a;
    };
    
    void display()
    {
        for (int i = 0; i < length; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void sorting()
    {
            int i, j, min_idx; 

        // One by one move boundary of unsorted subarray 
        for (i = 0; i < length-1; i++) 
        { 
            // Find the minimum element in unsorted array 
            min_idx = i; 
            int temp;
            for (j = i+1; j < length; j++){
                
                if (arr[j] < arr[min_idx])
                {
                    min_idx = j;
                    temp = arr[min_idx];
                    arr[min_idx]=arr[i];
                    arr[i]=temp;

                } 
                
            }
            cout<<"array after "<<i+1<<"th iteration : \n";
            display();
             
        } 
    }
    ~selection_sort()
    {
        "Sorting Done";
    };
};

// MAIN PROGRAM
int main()
{
    int ar[]={6,3,8,1};
    int n=4;
    selection_sort ob(ar,n);
    ob.sorting();
    return 0;
}