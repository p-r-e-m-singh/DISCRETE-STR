#include<iostream>
using namespace std;

template<class X> class node{
    public:
        X value;
        node<X> *next;
        node<X> *prev;
};
template<class X> class DLL{
    node<X> *first,*last,*temp;
    public:
        DLL(){
            first =last = temp=nullptr;

        }
        void addtotail(){
            int nov;
            cout<<"Enter number of values you wanna enter";
            cin>>nov;

            for(int i=1;i<=nov;i++){
                X value;
                cin>>value;
                if(first==nullptr){
                    
                    temp=new node<X>;
                    temp->value=value;
                    temp->next=temp->prev=nullptr;
                    last=first=temp; 
                
                }
                else{

                    temp = new node<X>;
                    temp->value=value;
                    temp->next=nullptr;
                    temp->prev=last;
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
                X value;
                cin>>value;
                if(first==nullptr){
                    
                    temp=new node<X>;
                    temp->value=value;
                    temp->next=temp->prev=nullptr;
                    last=first=temp; 
                
                }
                else{

                    temp = new node<X>;
                    temp->value=value;
                    temp->prev=nullptr;
                    temp->next=first;
                    first=temp;

                }
            }

        }

        void insert_at_i(){
            int i,pos = 1;
            X value;
            cout<<"Enter the value of i: ";
            cin>>i;
            cout<<"Enter the value to be inserted : ";
            cin>>value;
            temp = new node<X>;
            node<X> *temp1,*temp2 = new node<X>;
            temp1->value=value;

            if(first==nullptr){
                cout<<"Array Is Empty\n + Addding at 1st Position\n";
                first = temp1;
                first->next=first->prev=nullptr;
                

            }
            else{
                 temp = first;
                 while (i!=pos)
                {
                    temp2 = temp;
                    temp = temp->next;
                    pos++;
                
                }
                if(temp==last){

                    temp2->next=temp1;
                    temp1->prev=temp2;
                    temp1->next=temp;
                    last=temp;

                }
                else if (temp==first)
                {
                    temp1->next=temp;
                    temp->prev=nullptr;
                }
                
                temp2->next=temp1;
                temp1->next=temp;

            }
            
        }

        void remove_from_i()
        {
            int i;
            cout<<"Enter the value of i: ";
            cin>>i;
            int pos = 1;
            temp = new node<X>;
            if(first == nullptr){
                cout<<"List Empty can't delete";

            }

            else
            {
                node<X> *temp1 = new node<X>;
                temp = first;
                while(pos!=i){
                    temp1 = temp;
                    temp = temp->next;
                    pos++;
                }
                temp1->next=temp->next;
                temp->next->prev=temp1;
                delete temp;

            }
            
        }
        
        
        void addinbw(){
            if(first==nullptr){
                cout<<"No Linked List exist to make addition in between";
            }
            else{
                X bwelem,prelem;
                temp = new node<X>;
                node<X>* temp1 = new node<X>;
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
                first->prev=nullptr;
                delete temp;
            }
        }
        void deletefromend(){
            if(first==nullptr){
                cout<<"Array empty! nothng to delete";
            }

            else{
               temp = first;
               node<X> *temp1;
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
                X delem;
                cout<<"Enter the element to be deleted in b/w the linked list : ";
                cin>>delem;
                temp = new node<X>();
                temp = first;
                node<X> *temp1 = new node<X>;
                while (temp->value!=delem)
                {
                    temp1=temp;
                    temp = temp->next;
                }

                temp1->next = temp->next;
                temp->next->prev=temp1;
                delete temp;



                

            }
        }

        void operator +(DLL l2){
            if(first=nullptr){
                first = l2.first;
                last = l2.last;
            }
            else
            {
                last->next = l2.first;
                l2.first->prev=last;
                
                last = l2.last;
            }
            
            


        }


        void reverse(){
            
            node<X>* templast = new node<X>;
            temp = new node<X>;
            templast=last;
            
            while (templast!=first)
            {
                temp = templast;
                templast = templast->prev;
                swap(temp->next,temp->prev);

            }
            swap(templast->next,templast->prev);
            swap(first,last);
            
        }



        void search_elem(){
            int pos=1;
            X elem;
            cout<<"Enter the element you want to search : ";
            cin>>elem;
            temp = new node<X>;
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
                node<X> *temp1 = first;
                while (temp1!=nullptr)
                {
                    cout<<temp1->value<<" ";
                    temp1 = temp1->next;

                }
                cout<<endl;return;
                
            }
            
        }

        ~DLL(){
            node<X> *temp1 = new node<X>;
            temp = first;
            while(temp!=nullptr){
                temp1 = temp;
                temp->next;
                delete temp1;
            }
        }
};

int main(){
    
    
    int type;
    cout<<"Ënter the dataype you want to continue with \n1.Integer \n2.Character \n3.String \n4.Float \n5.Boolean\n";
    cin>>type;
    switch (type)
    {
    case 1:{
        DLL <int>list1,list2;
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
            list1+list2;
            cout<<"After Concatenation, new List obtained is :";
            list1.display();
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
        break;
    }
    case 2:{
        DLL <char>list1,list2;
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
            list1+list2;
            cout<<"After Concatenation, new List obtained is :";
            list1.display();
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
        break;
    }
    case 3:{
        DLL <string>list1,list2;
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
            list1+list2;
            cout<<"After Concatenation, new List obtained is :";
            list1.display();
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
        break;
    }
    case 4:{
        DLL <float>list1;
        DLL<float>list2;
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
            list1+list2;
            cout<<"After Concatenation, new List obtained is :";
            list1.display();
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
        break;
    }
    case 5:{
        DLL <bool>list1,list2;
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
        list1+list2;
        cout<<"After Concatenation, new List obtained is :";
        list1.display();
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
    break;
    }

    
    default:
        cout<<"Enter correct option! --fatal error";
        return 0;
        break;
    }
    

    
    
    
    return 0;
}