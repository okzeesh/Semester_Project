#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
#include<set>
#include <queue>
using namespace std;


class Transactions
{
public:
    long dep_amount, withdraw_amount, transfer_amount, remaining, receiver_acc_num;
    string deposit, withdraw, transfer;

    Transactions()
    {
      
    }

void Transaction(long accNum)
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

            
                  break;

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
};



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

    // Function to perform transactions and update transaction history
    void performTransaction(long acc_num, int transactionType)
    {
        Transactions transactionRecord;
        switch (transactionType)
        {
        case 1: // Fund Transfer
            cout << "Enter the account number of the receiver: ";
            cin >> transactionRecord.receiver_acc_num;
            cout << "Enter the amount you want to transfer: ";
            cin >> transactionRecord.transfer_amount;
            break;
        case 2: // Cash Deposit
            cout << "Enter the amount you want to deposit: ";
            cin >> transactionRecord.dep_amount;
            break;
        case 3: // Cash Withdrawal
            cout << "Enter the amount you want to withdraw: ";
            cin >> transactionRecord.withdraw_amount;
            break;
        }

        Node* accountNode = accountHash[acc_num];
        transactionRecord.remaining = accountNode->amount;

        // Update account balance
        switch (transactionType)
        {
        case 1:
            if (accountNode->amount >= transactionRecord.transfer_amount)
            {
                accountNode->amount -= transactionRecord.transfer_amount;
                accountHash[acc_num]->amount = accountNode->amount;
                accountHash[transactionRecord.receiver_acc_num]->amount += transactionRecord.transfer_amount;
            }
            else
            {
                cout << "Insufficient funds for the transfer!" << endl;
                return;
            }
            break;
        case 2:
            accountNode->amount += transactionRecord.dep_amount;
            accountHash[acc_num]->amount = accountNode->amount;
            break;
        case 3:
            if (accountNode->amount >= transactionRecord.withdraw_amount)
            {
                accountNode->amount -= transactionRecord.withdraw_amount;
                accountHash[acc_num]->amount = accountNode->amount;
            }
            else
            {
                cout << "Insufficient funds for the withdrawal!" << endl;
                return;
            }
            break;
        }

        // Update transaction history
        transactionHistory.push(transactionRecord);
        cout << "Transaction completed successfully!" << endl;
    }

    // Function to display transaction history
    void displayTransactionHistory()
    {
        cout << "Your transaction details are: " << endl;
        while (!transactionHistory.empty())
        {
            Transactions record = transactionHistory.front();
            transactionHistory.pop();
            cout << "Transfered Record : " << endl;
            cout << "Receiver account No. : " << record.receiver_acc_num << endl;
            cout << "Amount Transferred : " << record.transfer_amount << endl;
            cout << "Deposit Record : " << endl;
            cout << "Deposited amount : " << record.dep_amount << endl;
            cout << "Withdraw Record : " << endl;
            cout << "Withdraw amount : " << record.withdraw_amount << endl;
            cout << "Your current Balance is : " << record.remaining << endl;
        }
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

            //         int opt2;
            //         cout<<"1. Cash Deposit "<<endl;
            //         cout<<"2. Cash Withdrawl "<<endl;
            //         cout<<"3. Fund Transfer "<<endl;
            //         cout<<"4. Exit"<<endl;
            //         cout<<"Enter option : ";
            //         cin>>opt2;
            //         switch(opt2)
            //         {
            //             case 1:

            // int transactionType;
            // cin >> transactionType;
            // bankingSystem.performTransaction(acc_num, transactionType);
            // break;

            //             break;

            //             case 2 :
            //                 cout<<"";
            //             break;

            //             case 3 :
            //                 cout<<"";
            //             break;

            //             default :
            //                 cout<<"";
            //             break;
            //         }
            //         break;
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
