#include <bits/stdc++.h>
using namespace std;

class atm {
private:
    long int account_num;
    string name;
    int pin;
    double balance;
    string mobile_num;

public:
    void setData(long int Account_num, string Name, int Pin, double Balance, string Mobile_num) {
        account_num = Account_num;
        name = Name;
        pin = Pin;
        balance = Balance;
        mobile_num = Mobile_num;
    }

    long int getaccountnum()
    {
        return account_num;
    }
    string getname()
    {
        return name;
    }
    int getpin()
    {
        return pin;
    }
    double getbalance()
    {
        return balance;
    }
    string getmobile()
    {
        return mobile_num;
    }

    void setmobile_num(string mob_prev, string mob_new)
    {
        if (mobile_num == mob_prev)
        {
            mobile_num = mob_new;
            cout << "The new mobile number has been updated successfully.\n";
        } else {
            cout << "You are entering the wrong mobile number.\n";
        }
    }

    void cashWithDraw(int amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Take your cash.\n";
            cout << "Current balance is: " << balance << endl;
        }
        else
        {
            cout << "Insufficient balance!\n";
        }
    }
};

int main()
{
    int choice = 0, enterPin;
    long int enterAccountnum;

    atm user1;
    user1.setData(1234567, "Tim", 1111, 4500.9, "9087654321");

    do
    {
        cout << "\n******** Welcome To ATM ********\n";
        cout << "Enter Account Number: ";
        cin >> enterAccountnum;
        cout << "Enter PIN: ";
        cin >> enterPin;

        if ((enterAccountnum == user1.getaccountnum()) && (enterPin == user1.getpin())) {
            do
            {
                int amount = 0;
                string oldMobileNo, newMobileNo;

                cout << "\n******** ATM Main Menu ********\n";
                cout << "1. Check Balance\n";
                cout << "2. Cash Withdraw\n";
                cout << "3. Show User Details\n";
                cout << "4. Update Mobile Number\n";
                cout << "5. Exit\n";
                cout << "Enter choice: ";
                cin >> choice;

                switch (choice)
                {
                    case 1:
                        cout << "Your current balance is: " << user1.getbalance() << endl;
                        cin.get(); cin.get();
                        break;

                    case 2:
                        cout << "Enter the amount to withdraw: ";
                        cin >> amount;
                        user1.cashWithDraw(amount);
                        cin.get(); cin.get();
                        break;

                    case 3:
                        cout << "\nUser Details:\n";
                        cout << "Account Number: " << user1.getaccountnum() << endl;
                        cout << "Name: " << user1.getname() << endl;
                        cout << "PIN: " << user1.getpin() << endl;
                        cout << "Balance: " << user1.getbalance() << endl;
                        cout << "Mobile Number: " << user1.getmobile() << endl;
                        cin.get(); cin.get();
                        break;

                    case 4:
                        cout << "Enter old mobile number: ";
                        cin >> oldMobileNo;
                        cout << "Enter new mobile number: ";
                        cin >> newMobileNo;
                        user1.setmobile_num(oldMobileNo, newMobileNo);
                        cin.get(); cin.get();
                        break;

                    case 5:
                        exit(0);

                    default:
                        cout << "Please enter a valid choice.\n";
                        cin.get(); cin.get();
                }
            } while (true);
        }
        else
        {
            cout << "Invalid account number or PIN!\n";
        }

    } while (true);

    return 0;
}
