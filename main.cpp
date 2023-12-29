#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

class Transactions
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
    queue<Transactions> transactionHistory;

    Node() : acc_num(0), name(""), address(""), ph_num(0), amount(0), pin(0) {}

    Node(long acc_num, string name, string address, long long ph_num, long amount, int pin)
    {
        this->acc_num = acc_num;
        this->name = name;
        this->address = address;
        this->ph_num = ph_num;
        this->amount = amount;
        this->pin = pin;
    }

    long getBalance() const
    {
        return amount;
    }

 void performTransaction(unordered_map<long, Node *> &accountHash, set<long> &bst)
{
    int maxAttempts = 3;
    int enteredPin;

    for (int attempt = 1; attempt <= maxAttempts; ++attempt)
    {
        cout << "Enter your PIN (Attempt " << attempt << "/" << maxAttempts << "): ";
        cin >> enteredPin;

        // Check if entered PIN is correct
        if (enteredPin == pin)
        {
            cout << "PIN verification successful. Proceeding with the transaction." << endl;
            break;
        }
        else
        {
            cout << "Incorrect PIN. ";

            if (attempt < maxAttempts)
            {
                cout << "Please try again." << endl;
            }
            else
            {
                cout << "Maximum attempts reached. Exiting program." << endl;
                return;
            }
        }
    }

    int opt2;
    cout << "1. Cash Deposit " << endl;
    cout << "2. Cash Withdrawal " << endl;
    cout << "3. Fund Transfer " << endl;
    cout << "4. Exit" << endl;
    cout << "Enter option : ";
    cin >> opt2;

    Transactions temp;

    switch (opt2)
    {
    case 1:
        // Cash Deposit
        cout << "Enter the amount you want to deposit: ";
        int deposit;
        cin >> deposit;
        amount += deposit;
        cout << "Amount $" << deposit << " deposited successfully!\nYour current balance is: $" << amount << endl;
        temp = Transactions("DEPOSIT", deposit);
        transactionHistory.push(temp);
        break;

    case 2:
        // Cash Withdrawal
        cout << "Enter the amount you want to withdraw: ";
        int withdraw;
        cin >> withdraw;
        if (amount >= withdraw)
        {
            amount -= withdraw;
            cout << "Amount $" << withdraw << " withdrawn successfully!\nYour current balance is: $" << amount << endl;
            temp = Transactions("WITHDRAW", withdraw);
            transactionHistory.push(temp);
        }
        else
        {
            cout << "Insufficient Balance for the withdrawal!" << endl;
            return;
        }
        break;

    case 3:
    {
        // Fund Transfer
        cout << "Enter the account number of the receiver: ";
        long receiver_acc_num;
        cin >> receiver_acc_num;

        // Check if the receiver account exists
        if (bst.find(receiver_acc_num) == bst.end())
        {
            cout << "Receiver account not found!" << endl;
            return;
        }

        // Check if the receiver account is the same as the sender account
        if (receiver_acc_num == acc_num)
        {
            cout << "Cannot transfer funds to the same account!" << endl;
            return;
        }

        // Check if the sender has sufficient balance for the transfer
        cout << "Enter the amount you want to transfer: ";
        int transfer_amount;
        cin >> transfer_amount;

        if (transfer_amount > 0 && amount >= transfer_amount) // Ensure transfer_amount is positive
        {
            amount -= transfer_amount;
            cout << "Amount $" << transfer_amount << " transferred successfully!\nYour current balance is: $" << amount << endl;
            temp = Transactions("TRANSFER", transfer_amount);
            transactionHistory.push(temp);

            // Update the receiver's account balance
            Node *receiverNode = accountHash[receiver_acc_num];
            receiverNode->amount += transfer_amount;

            cout << "Funds received from account number " << acc_num << ". \nReceiver's new balance is: $" << receiverNode->amount << endl;
        }
        else
        {
            cout << "Invalid amount or insufficient balance for the transfer!" << endl;
            return;
        }
        break;
    }

    default:
        cout << "Invalid option" << endl;
        break;
    }
}
};

class BankingSystem
{
private:
    list<Node> accountList;
    unordered_map<long, Node *> accountHash;
    set<long> bst;

public:
    // Function to add a new customer and open a new account
    void addCustomer(long acc_num, string name, string address, long long ph_num, long amount, int pin)
    {
        Node *newNode = new Node(acc_num, name, address, ph_num, amount, pin);
        accountList.push_front(*newNode);
        accountHash[acc_num] = newNode;
        bst.insert(acc_num);
        cout << "\nCongratulations!!!\nYour Account has been created! \n"
             << endl;
    }

    // Function to display account holder details
    void displayCustomers()
    {
        int i = 1;
        for (const auto &itr : accountList)
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
    void performTransaction(long acc_num)
    {
        Node *accountNode = accountHash[acc_num];
        accountNode->performTransaction(accountHash, bst);
    }

    // Function to display transaction history
    void displayTransactionHistory(long acc_num)
    {
        Node *accountNode = accountHash[acc_num];
        cout << "Transaction history for Account Number " << acc_num << " is:" << endl;
        while (!accountNode->transactionHistory.empty())
        {
            Transactions record = accountNode->transactionHistory.front();
            accountNode->transactionHistory.pop();
            cout << "Transaction Type: " << record.type << ", Amount: $" << record.amount << endl;
        }
    }

    // Function to display account holder details with balance
    void displayCustomersWithBalance()
    {
        int i = 1;
        for (const auto &itr : accountList)
        {
            cout << "Client " << i << " Details" << endl;
            cout << "Account Number -> " << itr.acc_num << endl;
            cout << "Account Holder's Name -> " << itr.name << endl;
            cout << "Account Holder's Address -> " << itr.address << endl;
            cout << "Account Holder's Contact Information -> " << itr.ph_num << endl;
            cout << "Account Balance -> $" << itr.getBalance() << endl; // Display the balance
            i++;
        }
    }

    // Function to verify account details using Binary Search Tree (BST)
    bool verifyAccount(long acc_num)
    {
        return bst.find(acc_num) != bst.end();
    }

    // Additional method to get the account node based on the account number
    Node *getAccountNode(long acc_num)
    {
        return accountHash[acc_num];
    }
};

int main()
{
    BankingSystem bankingSystem;

    long acc_num;
    string name, address;
    long long ph_num;
    long amount;
    int pin;

    int opt;

    do
    {
        cout << "WELCOME TO SIMULATED BANKING SYSTEM" << endl;
        cout << "==== MENU ====" << endl;
        cout << "1. Open New Account" << endl;
        cout << "2. Show Account Holder Details" << endl;
        cout << "3. Perform Transaction" << endl;
        cout << "4. Display Transaction History" << endl;
        cout << "5. Show Current Balance" << endl;
        cout << "6. Verify Account" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter choice : ";
        cin >> opt;

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
            cout << "Enter initial amount: ";
            cin >> amount;
            cout << "Enter Pin : ";
            cin >> pin;

            bankingSystem.addCustomer(acc_num, name, address, ph_num, amount, pin);
            break;

        case 2:
            bankingSystem.displayCustomers();
            break;

        case 3:
            cout << "Enter your account number: ";
            cin >> acc_num;
            bankingSystem.performTransaction(acc_num);
            break;

        case 4:
            cout << "Enter your account number: ";
            cin >> acc_num;
            bankingSystem.displayTransactionHistory(acc_num);
            break;

        case 5:
            // Show Current Balance
            cout << "Enter your account number: ";
            cin >> acc_num;
            if (bankingSystem.verifyAccount(acc_num))
            {
                Node *accountNode = bankingSystem.getAccountNode(acc_num);
                cout << "Your current balance is: $" << accountNode->getBalance() << endl;
            }
            else
            {
                cout << "Account not found!" << endl;
            }
            break;

        case 6:
            cout << "Enter account number to verify: ";
            cin >> acc_num;
            if (bankingSystem.verifyAccount(acc_num))
            {
                cout << "Account verified successfully!" << endl;
            }
            else
            {
                cout << "Account not found!" << endl;
            }
            break;

        case 7:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid option! Please try again." << endl;
            break;
        }

    } while (opt != 7);

    return 0;
}
