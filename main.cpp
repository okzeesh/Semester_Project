#include <iostream>
#include <string>
#include <list>
#include<unordered_map>
#include<set>
using namespace std;

struct Node
{
    long acc_num;
    string name;
    string address;
    long long ph_num;
    Node(long acc_num, string name, string address, long long ph_num)
    {
        this->acc_num = acc_num;
        this->name = name;
        this->address = address;
        this->ph_num = ph_num;
    }
};

void display(list<Node> singlelist)
{
    int i = 1;
    for (auto itr : singlelist)
    {
        cout << "Client " << i << " Details" << endl;
        cout << "Account Number -> " << itr.acc_num << endl;
        cout << "Account Holder's Name -> " << itr.name << endl;
        cout << "Account Holder's Address -> " << itr.address << endl;
        cout << "Account Holder's Contact Information -> " << itr.ph_num << endl;
        i++;
    }
}


int main()
{
    list<Node> AMS;
    set<Node> BST;
    string name, address;
    long acc_num;
    long long ph_num;
    int opt;

    do
    {
        cout << "WELCOME TO UMAR BANK Ltd" << endl;
        cout << "==== MENU ====" << endl;
        cout << "1. Open New Account" << endl;
        cout << "2. Show Account holder details" << endl;
        cout<<"3. Already have an account "<<endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice : ";
        cin >> opt;
        cin.ignore();
        switch (opt)
        {
        case 1:
        {
            cout << "Enter account number : ";
            cin >> acc_num;
            cin.ignore();
            cout << "Enter your name : ";
            getline(cin, name);
            cout << "Enter your address : ";
            getline(cin, address);
            cout << "Enter your Phone number : ";
            cin >> ph_num;
            Node temp(acc_num, name, address, ph_num);
            AMS.push_front(temp);
            BST.insert(temp);
            cout << "\nCongratulations!!!\nYour Account has been created! \n"
                 << endl;
            break;
        }
        case 2:
        {
            display(AMS);
            break;
        }
        case 3:
        {
            cout<<"1. Want to perform a transaction"<<endl;
        
        }
        case 4:
        {
            cout << "Exiting" << endl;
            break;
        }
        }
    } while (opt != 4);
    return 0;
}