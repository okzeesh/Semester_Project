#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
#include<set>
#include <queue>
using namespace std;


struct Transactions
{
public:
    string type;
    int amount;

    Transactions() : type(""), amount(0) {}

    Transactions(string type, int amount)
    {
        this->type = type;
        this->amount = amount;
    }

                
};
class Node
{
public:
    long acc_num;
    string name;
    string address;
    long long ph_num;
    long amount;
    int pin;

    queue < Transactions > T1;

    Node() 
       :  acc_num(0), name(""), address(""), ph_num(0), amount(0), pin(0) {};

    // Parameterized constructor

    Node(long acc_num, string name, string address,
    long long ph_num, long amount, int pin) 
    {
        this->acc_num = acc_num;
        this->name = name;
        this->address = address;
        this->ph_num = ph_num;
        this->amount = amount;
        this->pin = pin;
    }

    void Transaction(set<Node>& BST)
    {
    int opt2;
                    cout<<"1. Cash Deposit "<<endl;
                    cout<<"2. Cash Withdrawl "<<endl;
                    cout<<"3. Fund Transfer "<<endl;
                    cout<<"4. Exit"<<endl;
                    cout<<"Enter option : ";
                    cin>>opt2;

                    Transactions temp;

                    switch(opt2)
                    {
                        case 1:
                        // Cash Deposit
                        cout << "Enter the amount you want to deposit: ";
                        int deposit;
                        cin >> deposit;
                        amount += deposit;
                        cout << "Amount $"<<deposit<<" deposited Succssfully!!\nYour current balance is: $" << amount << endl;
                        temp = Transactions("DEPOSIT",deposit);
                        T1.push(temp);
                        break;

                        case 2 : // Cash Withdrawal
                        cout << "Enter the amount you want to withdraw: ";
                        int withdraw;
                        cin >> withdraw;
                        if (amount >= withdraw)
                        {
                        amount -= withdraw;
                        cout << "Amount $"<<withdraw<<" Withdrawed Succssfully!!\nYour current balance is: $" << amount << endl;
                        temp = Transactions("WITHDRAW",withdraw);
                        T1.push(temp);
                            }
                         else
                        {
                         cout << "Insufficient Balance for the withdrawal!" << endl;
                            return;
                                 }
                        
                        break;

                        case 3 : // Fund Transfer
                        
                        
                        break;

                        default :
                            cout<<"";
                        break;
                    }
                   

}
};

void Transfer(Node sender)
{
    cout << "receiver's Account number : ";
    long acc_NUM;
    cin >> acc_NUM;

     int attempts = 3;

    do{
        for (auto& itr : BST)
        {
            if (itr.acc_num == acc_number)
            {

                cout << "Enter the amount you want to transfer: ";
                int trans;
                cin >> trans;
                if (amount >= trans)
                {
                    amount -= trans;
                cout << "Amount $"<<trans<<" Transfered Succssfully!!\nYour current balance is: $" << amount << endl;
                temp = Transactions("Transfer",trans);
                T1.push(temp);
                    accountNode->amount -= transactionRecord.transfer_amount;
                    accountHash[acc_num]->amount = accountNode->amount;
                    accountHash[transactionRecord.receiver_acc_num]->amount += transactionRecord.transfer_amount;
                }
                else
                {
                    cout << "Insufficient Balance for the transfer!" << endl;
                    return;
                }
    
            }
        }

        cout << "Account does not exist." << endl;
        attempts--;
        cout << "Attempts left: " << attempts << endl;

        if (attempts == 0) {
            cout << "Too many incorrect attempts. Exiting." << endl;
            return;
        }
        cout << "Enter Account Number Again: ";
        cin >> acc_NUM;

    } while (attempts>=1);


    





}


class BankingSystem
{
private:
    list<Node> accountList;
    unordered_map<long, Node*> accountHash;
    queue<Transactions> transactionHistory;
    Node* rootBST;

public:
    BankingSystem()
    {
        rootBST = nullptr;
    }

    // Function to display account holder details
    void displayCustomers()
    {
        int i = 1;
        for (const auto& itr : accountList)
        {
            cout << "Client " << i << " Details" << endl;
            cout << "Account Number -> " << itr.acc_num << endl;
            cout << "Account Holder's Name -> " << itr.name << endl;
            cout << "Account Holder's Address -> " << itr.address << endl;
            cout << "Account Holder's Contact Information -> " << itr.ph_num << endl;
            i++;
        }
    }

    // Function to display transaction history
  

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


int main()
{
    BankingSystem bankingSystem;
    list<Node> AMS;
    set<Node> BST;

    int pin,pin1;
    long acc_num;
    string name, address;
    long long ph_num;
    long amount;

    int opt;

    do
    {
        cout << "WELCOME TO SIMULATED BANKING SYSTEM" << endl;
        cout << "==== MENU ====" << endl;
        cout << "1. Open New Account" << endl;
        cout << "2. Show Account Holder Details" << endl;
        cout<<"3. Already have an account "<<endl;
        cout << "4. Display Transaction History" << endl;
        cout << "5. Verify Account" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice : ";
        cin >> opt;

        Node temp;

        switch (opt)
        {
        case 1:
            cout << "Enter account number: ";
            cin >> acc_num;
            cout << "Enter your name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter your address: ";
            getline(cin, address);
            cout << "Enter your phone number: ";
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

            cout << "Enter initial amount: ";
            cin >> amount;

           temp= Node(acc_num, name, address, ph_num,amount,pin);
            AMS.push_front(temp);
            BST.insert(temp);
            cout << "\nCongratulations!!!\nYour Account has been created! \n"
                 << endl;

            break;

        case 2:
            bankingSystem.displayCustomers();
            break;

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
                    for (auto& itr : BST)
                    {
                        if (itr.acc_num == acc_number)
                        {
                           itr.Transaction();
                        }
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
            bankingSystem.displayTransactionHistory();
            break;

        case 5:
           
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid option! Please try again." << endl;
            break;
        }

    } while (opt != 6);

    return 0;
}
