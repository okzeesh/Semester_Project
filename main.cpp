#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

class Node
{
public:
    long acc_num;
    string name;
    string address;
    long long ph_num;
    long amount;
    Node* left;
    Node* right;

    Node(long acc_num, string name, string address, long long ph_num, long amount)
    {
        this->acc_num = acc_num;
        this->name = name;
        this->address = address;
        this->ph_num = ph_num;
        this->amount = amount;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Transactions
{
public:
    long dep_amount, withdraw_amount, transfer_amount, remaining;
    string deposit, withdraw, transfer, receiver_acc_num;

    Transactions()
    {
        transfer = "Transfer";
        withdraw = "Withdraw";
        deposit = "Deposit";
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

    // Function to add a new customer and open a new account
    void addCustomer(long acc_num, string name, string address, long long ph_num, long amount)
    {
        Node* newNode = new Node(acc_num, name, address, ph_num, amount);
        accountList.push_front(*newNode);
        accountHash[acc_num] = newNode;
        rootBST = insertBST(rootBST, newNode);
        cout << "\nCongratulations!!!\nYour Account has been created! \n"
             << endl;
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
                accountHash[stol(transactionRecord.receiver_acc_num)]->amount += transactionRecord.transfer_amount;
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

    // Function to verify account details using Binary Search Tree (BST)
    bool verifyAccount(long acc_num)
    {
        return searchBST(rootBST, acc_num) != nullptr;
    }

private:
    // Binary Search Tree (BST) functions
    Node* insertBST(Node* root, Node* newNode)
    {
        if (root == nullptr)
        {
            return newNode;
        }

        if (newNode->acc_num < root->acc_num)
        {
            root->left = insertBST(root->left, newNode);
        }
        else if (newNode->acc_num > root->acc_num)
        {
            root->right = insertBST(root->right, newNode);
        }

        return root;
    }

    Node* searchBST(Node* root, long acc_num)
    {
        if (root == nullptr || root->acc_num == acc_num)
        {
            return root;
        }

        if (acc_num < root->acc_num)
        {
            return searchBST(root->left, acc_num);
        }

        return searchBST(root->right, acc_num);
    }
};

int main()
{
    BankingSystem bankingSystem;

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
        cout << "3. Perform Transaction" << endl;
        cout << "4. Display Transaction History" << endl;
        cout << "5. Verify Account" << endl;
        cout << "6. Exit" << endl;
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

            bankingSystem.addCustomer(acc_num, name, address, ph_num, amount);
            break;

        case 2:
            bankingSystem.displayCustomers();
            break;

        case 3:
            cout << "Enter your account number: ";
            cin >> acc_num;
            cout << "1. Fund Transfer" << endl;
            cout << "2. Cash Deposit" << endl;
            cout << "3. Cash Withdrawal" << endl;
            cout << "Enter transaction type: ";
            int transactionType;
            cin >> transactionType;
            bankingSystem.performTransaction(acc_num, transactionType);
            break;

        case 4:
            bankingSystem.displayTransactionHistory();
            break;

        case 5:
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

        case 6:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid option! Please try again." << endl;
            break;
        }

    } while (opt != 6);

    return 0;
}
