#include <iostream>
#include <vector>
#include <typeinfo>
#include <stdexcept>


using namespace std;

class DepositeOnlyAccount {
    public:
        virtual void deposite(double amount) = 0;

};

class WithdrawableAccount : public DepositeOnlyAccount {
    public:
        virtual void withdraw(double amount) = 0;
};

class SavingAccount : public WithdrawableAccount {
    private:
        double balance;

    public:
        SavingAccount() {
            balance = 0;
        }

        void deposite(double amount) {
            balance += amount;
            cout << "Deposited: " << amount " in Saving account. New Balance: " << balance << endl;
        }

        void withdraw(double amount) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Withdraw: " << amount << " from Saving Account. New Balance: " << balance << endl;
            } else {
            cout << "Insufficient funds in Savings Account!\n";
           }
        }
};

class CurrentAccount : public WithdrawableAccount {
    private:
        double balance;

    public: 
        CurrentAccount() {
            balance = 0;
        }

        void deposite(double amount) {
            balance += amount;
            cout << "Deposited: " << amount << " in current Account. New Balnce: " << balance << endl;
        }

        void withdraw(double amount) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Withdrawn: " << amount << " from Current Account. New Balance: " << balance << endl;
            } else {
                cout << "Insufficient funds in Current Account!\n";
            }
        }

;

class FixedTermAccount : public DepositOnlyAccount {
private:
    double balance;

public:
    FixedTermAccount() { 
        balance = 0; 
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Fixed Term Account. New Balance: " << balance << endl;
    }
};}

