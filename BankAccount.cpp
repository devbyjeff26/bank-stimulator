#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cctype>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    string accountNumber;
    double balance;

public:
    BankAccount(const string& name, const string& number, double initialBalance = 0.0)
        : accountHolder(name), accountNumber(number),
          balance(initialBalance >= 0 ? initialBalance : 0.0) {}

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Error: Deposit must be greater than zero.\n";
        } else {
            balance += amount;
            cout << "Deposit successful! Amount deposited: Ksh "
                 << amount << '\n';
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Error: Withdrawal must be greater than zero.\n";
        } else if (amount > balance) {
            cout << "Error: Insufficient balance!\n";
        } else {
            balance -= amount;
            cout << "Withdrawal successful! Amount withdrawn: Ksh "
                 << amount << '\n';
        }
    }

    void checkBalance() const {
        cout << "\nCurrent Balance: Ksh " << balance << '\n';
    }

    void displayDetails() const {
        cout << "\n===== ACCOUNT DETAILS =====\n"
             << "Account Holder: " << accountHolder << '\n'
             << "Account Number: " << accountNumber << '\n'
             << "Balance: Ksh " << balance << '\n';
    }
};

double getAmount() {
    double amount;

    while (true) {
        cout << "Enter amount: Ksh ";
        if (cin >> amount && amount > 0) {
            return amount;
        }

        cout << "Invalid amount. Enter a number greater than zero.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    string name, accountNumber;
    int choice = 0;

    cout << fixed << setprecision(2);
    cout << "================================\n"
         << "       BANK ACCOUNT SYSTEM\n"
         << "================================\n";

    cout << "Enter account holder name: ";
    getline(cin, name);
    while (name.empty()) {
        cout << "Name cannot be empty. Enter name: ";
        getline(cin, name);
    }

    cout << "Enter account number: ";
    getline(cin, accountNumber);
    while (accountNumber.empty()) {
        cout << "Account number cannot be empty. Enter again: ";
        getline(cin, accountNumber);
    }

    BankAccount account(name, accountNumber);
    cout << "\nAccount created successfully!\n";

    do {
        cout << "\n========== MAIN MENU ==========\n"
             << "1. Deposit Money\n"
             << "2. Withdraw Money\n"
             << "3. Check Balance\n"
             << "4. Account Details\n"
             << "5. Exit\n"
             << "================================\n"
             << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid choice. Enter a number from 1 to 5.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                account.deposit(getAmount());
                break;
            case 2:
                account.withdraw(getAmount());
                break;
            case 3:
                account.checkBalance();
                break;
            case 4:
                account.displayDetails();
                break;
            case 5:
                cout << "\nThank you for using the Bank Account System!\n";
                break;
            default:
                cout << "Invalid option. Choose between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
