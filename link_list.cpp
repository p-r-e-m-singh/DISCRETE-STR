#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;

class node{
    public:
        int value;
        node *next;
};

class LL{
    node *first=nullptr , *last=nullptr, *temp=nullptr;
    public:
        void addtotail(){
            int nov;
            cout<<"Enter number of values you wanna enter";
            cin>>nov;

            for(int i=1;i<=nov;i++){
                int value;
                cin>>value;
                if(first==nullptr){
                    
                    temp=new node;
                    temp->value=value;
                    temp->next=nullptr;
                    last=first=temp; 
                
                }
                else{

                    temp = new node;
                    temp->value=value;
                    temp->next=nullptr;
                    last->next = temp;
            
                    last = temp;

                }
            }
        }

        void addtohead(){
            int nov;
            cout<<"Enter number of values you wanna enter";
            cin>>nov;

            for(int i=1;i<=nov;i++){
                int value;
                cin>>value;
                if(first==nullptr){
                    
                    temp=new node;
                    temp->value=value;
                    temp->next=nullptr;
                    last=first=temp; 
                
                }
                else{

                    temp = new node;
                    temp->value=value;
                    temp->next=first;
                    first=temp;

                }
            }

        }

        void insert_at_i(){
            int i,value,pos = 1;
            cout<<"Enter the value of i: ";
            cin>>i;
            cout<<"Enter the value to be inserted : ";
            cin>>value;
            temp = new node();
            node *temp1,*temp2 = new node;
            temp1->value=value;

            if(first==nullptr){
                cout<<"Array Is Empty\n + Addding at 1st Position\n";
                first = temp1;
                first->next=nullptr;
                

            }
            else{
                temp = first;
                 while (i!=pos && temp!=nullptr)
                {
                    temp2 = temp;
                    temp = temp->next;
                    pos++;
                
                }
                temp2->next=temp1;
                temp1->next=temp;
            }
            
        }

        void remove_from_i(){
            int i;
            cout<<"Enter the value of i: ";
            cin>>i;
            int pos = 1;
            temp = new node;
            if(first == nullptr){
                cout<<"List Empty can't delete";

            }

            else
            {
                node *temp1 = new node;
                temp = first;
                while(pos!=i){
                    temp1 = temp;
                    temp = temp->next;
                    pos++;
                }
                temp1->next=temp->next;
                delete temp;

            }
            
        }
        
        
        void addinbw(){
            if(first==nullptr){
                cout<<"No Linked List exist to make addition in between";
            }
            else{
                int bwelem,prelem;
                temp = new node;
                node* temp1 = new node;
                cout<<"Enter the element to be inserted";
                cin>>bwelem;
                temp1->value=bwelem;
                cout<<"Enter the value of the element after which "<<bwelem<<" is to be inserted";
                cin>>prelem;
                temp = first;
                while(temp->value!=prelem){
                    temp = temp->next;
                }
                temp1->next=temp->next;
                temp->next = temp1;
                

                    
    
                

            }
        }

        void deletefromstart(){
            if(first==nullptr){
                cout<<"Array empty! nothng to delete";
            }

            else{
                temp = first;
                first = first->next;
                delete temp;
            }
        }
        void deletefromend(){
            if(first==nullptr){
                cout<<"Array empty! nothng to delete";
            }

            else{
               temp = first;
               node *temp1;
               while (temp!=last)
               {
                
                temp1=temp;
                temp=temp->next;
               }
               temp1->next=nullptr;
               last= temp1;
               delete temp;

               
            }
        }

        void deleteinbw(){
            if(first==nullptr) cout<<"List Empty";
            else{
                int delem;
                cout<<"Enter the element to be deleted in b/w the linked list : ";
                cin>>delem;
                temp = new node();
                temp = first;
                node *temp1 = new node;
                while (temp->value!=delem)
                {
                    temp1=temp;
                    temp = temp->next;
                }

                temp1->next = temp->next;
                delete temp;



                

            }
        }

        LL operator +(LL l2){
            LL temp;
            if(first=nullptr){
                return l2;
            }
            else
            {
                last->next = l2.first;
                last = l2.last;
                return *this;
            }
            
            


        }

        void reverse(){
            int len=1;
            temp = first;
            while(temp!=nullptr){
                
                temp = temp->next;
                len++;
            }
            node* a[len] ;
            int i=0;
            while(temp!=nullptr){
                
                a[i]=temp;
                i++;
            }
            temp=new node;
            node *temp1 = new node;

            for(int j = len-1;j>=0;j++){
                temp = first;
                temp1 = a[j];
                temp1->value= temp->value;
                temp = temp->next;
                    
                    
            }


        }



        void search_elem(){
            int elem ,pos=1;
            cout<<"Enter the element you want to search : ";
            cin>>elem;
            temp = new node;
            temp = first;
            while(temp->value!=elem){
                temp = temp->next;
                pos++;
            }
            cout<<"Element is at "<<pos<<"th position\n";


        }

        void display(){

            if(first==nullptr){
                cout<<"List Empty\n";
            }
            else{
                node *temp1 = first;
                while (temp1!=nullptr)
                {
                    cout<<temp1->value<<" ";
                    temp1 = temp1->next;

                }
                cout<<endl;return;
                
            }
        }

        ~LL(){
            node *temp1 = new node;
            temp = first;
            while(temp!=nullptr){
                temp1 = temp;
                temp->next;
                delete temp1;
            }
        }
};

int main(){
    LL list1,list2,list3;
    

    
    int choice;
    do
    {   
        cout<<"1. add to Tail\n";
        cout<<"2. Add to Head\n";
        cout<<"3. Add in between\n";
        cout<<"4. Delete from Beginiing\n";
        cout<<"5. Delete from end\n";
        cout<<"6.Delete in between\n";
        cout<<"7.Display the list\n";
        cout<<"8. Insert in at ith pos\n";
        cout<<"9.Delete from ith pos\n";
        cout<<"10. Search in the list\n";
        cout<<"11. Concatenate two lists\n";

        cout<<"12. Reverse the list\n";
        cout<<"0 to exit\n";
        
        cout<<"Enter your choice : ";
        cin>>choice;

        switch (choice)
        {
        case 1:
        list1.addtotail();            
        break;

        case 2:
        list1.addtohead();break;

        case 3:
        list1.addinbw();break;


        case 4:
        list1.deletefromstart();break;

        case 5:
        list1.deletefromend();break;

        case 6:
        list1.deleteinbw();break;


        case 7:
        list1.display();break;

        case 8:
        list1.insert_at_i();break;

        case 9:
        list1.remove_from_i();break;

        case 10:
        list1.search_elem();
        
        break;

        case 11:
        list2.addtotail();
        list3 = list1+list2;
        cout<<"After Concatenation, new List obtained is :";
        list3.display();
        break;

        case 12:
        list1.reverse();
        break;

        case 0:
        return 0;

        
        default:
            break;
        }

    } while (choice!=0);
    
    return 0;
}