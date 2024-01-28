#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string pin;
    double balance;

public:
    BankAccount(const string& accNumber, const string& pinNumber, double initialBalance)
        : accountNumber(accNumber), pin(pinNumber), balance(initialBalance) {}

    bool validatePin(const string& enteredPin) const {
        return pin == enteredPin;
    }
	string getAccountNumber() const {
        return accountNumber;
    }
    void displayBalance() const {
        cout << "Account Balance: $" << fixed << setprecision(2) << balance << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: $" << fixed << setprecision(2) << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: $" << fixed << setprecision(2) << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
        }
    }
};

class ATM {
private:
    BankAccount* currentAccount;

public:
    ATM() : currentAccount(NULL) {}

    void displayMainMenu() const {
        cout << "\n1. Login" << endl;
        cout << "2. Exit" << endl;
    }

    void displayAccountMenu() const {
        cout << "\n1. Display Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Logout" << endl;
    }

    void processMainMenu() {
        int choice;
        do {
            displayMainMenu();
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    login();
                    break;
                case 2:
                    cout << "Exiting ATM. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 2);
    }

    void processAccountMenu() {
        int choice;
        do {
            displayAccountMenu();
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    currentAccount->displayBalance();
                    break;
                case 2:
                    deposit();
                    break;
                case 3:
                    withdraw();
                    break;
                case 4:
                    logout();
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 4);
    }

    void login() {
        string accNumber, pin;
        cout << "Enter account number: ";
        cin >> accNumber;
        cout << "Enter PIN: ";
        cin >> pin;

        // Assuming accounts are stored somewhere (e.g., in a database).
        // Here, we create a sample account for demonstration purposes.
        BankAccount* account = new BankAccount(accNumber, pin, 1000.0);

        if (account->validatePin(pin)) {
            cout << "Login successful. Welcome, " << accNumber << "!" << endl;
            currentAccount = account;
            processAccountMenu();
        } else {
            cout << "Invalid account number or PIN. Login failed." << endl;
            delete account;
        }
    }

    void deposit() {
        double amount;
        cout << "Enter deposit amount: $";
        cin >> amount;
        currentAccount->deposit(amount);
    }

    void withdraw() {
        double amount;
        cout << "Enter withdrawal amount: $";
        cin >> amount;
        currentAccount->withdraw(amount);
    }

    void logout() {
        cout << "Logging out. Goodbye, " << currentAccount->getAccountNumber() << "!" << endl;
        delete currentAccount;
        currentAccount = NULL;
    }
};

int main() {
    ATM atm;
    atm.processMainMenu();
    return 0;
}

