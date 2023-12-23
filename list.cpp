#include <iostream>
#include <list>
#include <stack>
using namespace std;

struct Customer {
    long Acc_Num;
    string name ,address;
    long long contact;

    Customer (long Acc_Num, string name,string address,long long contact) {
        this->Acc_Num = Acc_Num;
        this->name = name;
        this->address = address;
        this->contact = contact;
    }
};

int main()
{
    list<Customer> AMS;
    long Acc_Num;
    string name ,address;
    long long contact;

    int option;
    cout<<"---------WELCOME TO THE BANK---------"<<endl<<endl;
    do
    {
        cout<<"1. Add a new customer"<<endl;
        cout<<"2. Delete a customer"<<endl;
        cout<<"3. Update customer details"<<endl;
        cout<<"4. Display all customer details"<<endl;
        cout<<"5. Display customer details by account number"<<endl;
        cout<<"6. Display customer details by name"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>option;
        Customer temp(0,"","",0);
        switch(option)
        {
            case 1:
                cout<<"Enter the account number: ";
                cin>>Acc_Num;
                cout<<"Enter the name: ";
                getline(cin,name);
                cout<<"Enter the address: ";
                 getline(cin,address);
                cout<<"Enter the contact number: ";
                cin>>contact;
                temp= Customer(Acc_Num, name,address,contact);
                AMS.push_back(temp);
                break;
            case 2:
                cout<<"Enter the account number: ";
                cin>>Acc_Num;
                for (auto it = AMS.begin(); it != AMS.end(); it++) {
                    if (it->Acc_Num == Acc_Num) {
                        AMS.erase(it);
                        break;
                    }
                }
                break;
            case 3:
                cout<<"Enter the account number: ";
                cin>>Acc_Num;
                for (auto it = AMS.begin(); it != AMS.end(); it++) {
                    if (it->Acc_Num == Acc_Num) {
                        cout<<"Enter the name: ";
                        cin>>name;
                        cout<<"Enter the address: ";
                        cin>>address;
                        cout<<"Enter the contact number: ";
                        cin>>contact;
                        it->name = name;
                        it->address = address;
                        it->contact = contact;
                        break;
                    }
                }
                break;
            case 4:
                cout<<"The customer details are: "<<endl;
                for (auto it : AMS) {
                    cout<<"Account number: "<<it.Acc_Num<<endl;
                    cout<<"Name: "<<it.name<<endl;
                    cout<<"Address: "<<it.address<<endl;
                    cout<<"Contact number: "<<it.contact<<endl;
                }
                break;
            case 5:
                cout<<"Enter the account number: ";
                cin>>Acc_Num;
                for (auto it : AMS) {
                    if (it.Acc_Num == Acc_Num) {
                        cout<<"Account number: "<<it.Acc_Num<<endl;
                        cout<<"Name: "<<it.name<<endl;
                        cout<<"Address: "<<it.address<<endl;
                        cout<<"Contact number: "<<it.contact<<endl; }
                        }
 }
     } while (option!=7);
    return 0;
}
