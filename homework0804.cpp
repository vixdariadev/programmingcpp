#include <iostream> 
#include <string>
using namespace std;

class Client {

    private:
    string name;
    int clientID;

    public:

    Client (string name, int clientID) {
        this->name = name;
        this->clientID = clientID;
    }
    Client () {}

    void setterName(string name) {
        this->name = name;
    }
    void setterClientID(int clientID) {
        this->clientID = clientID;
    }
    string getName() {
        return name;
    }
    int getClientID() {
        return clientID;
    }
};

class BankAccount {

    protected:
    Client client;
    double balance;

    public:

    BankAccount(Client client, double balance) {
        this->client = client;
        this->balance = balance;
    }

    void deposit(double sum){
        balance += sum;
    }

   void withdraw(double sum) {
        if (sum <= balance) {
            balance -= sum;
        } else {
            cout << "Недостатньо коштів!" << endl;
        }
    }
      virtual string getAccountType() {
        return "Standard Account";
    }

    double getBalance() {
        return balance;
    }

    Client getClient() {
        return client;
    }
};

class SavingsAccount : public BankAccount {

    private:
    double interestRate;

    public:
    SavingsAccount(Client client, double balance, double rate): BankAccount(client, balance) {
        interestRate = rate;
    }

    string getAccountType() override {
        return "Savings Account";
    }

    double calculateInterest() {
        return balance * interestRate / 100;
    }
};

int main() {
    Client c1("Ivan", 1);
    Client c2("Maria", 2);

    BankAccount acc1(c1, 1000);
    SavingsAccount acc2(c2, 2000, 5);

    BankAccount* accounts[2];
    accounts[0] = &acc1;
    accounts[1] = &acc2;

    for (int i = 0; i < 2; i++) {
        cout << "Client: " << accounts[i]->getClient().getName() << endl;
        cout << "Type: " << accounts[i]->getAccountType() << endl;
        cout << "Balance: " << accounts[i]->getBalance() << endl;

        accounts[i]->deposit(500);
        accounts[i]->withdraw(200);

        cout << "Balance after operations: " << accounts[i]->getBalance() << endl;
    }
    return 0;
}


