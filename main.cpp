#include <iostream>
#include <string>
#include <list>
#include<unordered_map>
#include<set>
#include<queue>
using namespace std;

struct Node
{
    long acc_num;
    string name;
    string address;
    long long ph_num;
    int pin;

    Node(long acc_num, string name, string address,
     long long ph_num,int pin)
    {
        this->acc_num = acc_num;
        this->name = name;
        this->address = address;
        this->ph_num = ph_num;
        this->pin = pin;
    }
};



bool findAccountHolder(long acc_number, set<Node>& BST) {
    int attempts = 3;

    do{
       

        for (auto& itr : BST)
        {
            if (itr.acc_num == acc_number) 
            {
                attempts = 3;
                int ppin;
                do {
                    cout << "Enter PIN: ";
                    cin >> ppin;

                    if (itr.pin == ppin) {
                        return true;
                    } else {
                        cout << "Incorrect PIN. ";
                        attempts--;
                        cout << "Attempts left: " << attempts << endl;

                        if (attempts == 0) {
                            cout << "Too many incorrect attempts. Exiting." << endl;
                            return false;
                        }
                    }
                } while (true);
            }
        }

        cout << "Account does not exist." << endl;
        attempts--;
        cout << "Attempts left: " << attempts << endl;

        if (attempts == 0) {
            cout << "Too many incorrect attempts. Exiting." << endl;
            return false;
        }
        cout << "Enter Account Number Again: ";
        cin >> acc_number;

    } while (true);

    return false;
}



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

    int pin,pin1;
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
            
            cout << "Enter Pin : ";
            cin >> pin;
            cout << "Re-Enter Pin : ";
            cin >> pin1;

            while (pin!=pin1)
            {
                cout << "Pin does not match" << endl;
                cout << "Enter Pin : ";
                cin >> pin;
                cout << "Re-Enter Pin : ";
                cin >> pin1;
            }
               
            Node temp(acc_num, name, address, ph_num,pin);
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
             long acc_number;
    
    cout << "Enter Account Number : ";
    cin >> acc_number;

        if (findAccountHolder(acc_number,BST))
        {
            int opt1;
            cout<<"1. Want to perform a transaction"<<endl;
            cout<<"2. Exit"<<endl;
            cout<<"Enter option : ";
            cin>>opt1;
            switch(opt1)
            {
                case 1:
                {
                    
                    int opt2;
                    cout<<"1. Cash Deposit "<<endl;
                    cout<<"2. Cash Withdrawl "<<endl;
                    cout<<"3. Fund Transfer "<<endl;
                    cout<<"4. Exit"<<endl;
                    cout<<"Enter option : ";
                    cin>>opt2;
                    switch(opt2)
                    {
                        case 1:
                        
                            cout<<"";
                        break;

                        case 2 :
                            cout<<"";
                        break;

                        case 3 :
                            cout<<"";
                        break;

                        default :
                            cout<<"";
                        break;
                    }
                    break;
                }
                case 2:
                       
                    cout<<"Exitng"<<endl;
                    break;
                
                default :
                            cout<<"";
                        break;
            }
        }
       

        break;
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
