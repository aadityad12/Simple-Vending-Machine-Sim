/*
Date: Feb 13
*/
#include <iostream>
#include <iomanip>
#include <ctime>
#pragma warning (disable:4996)

using namespace std;

class Snack {
    private: 
        string name;
        double price;
        int qty;
        int numSold;
        string* transactionTimes;
        int transactionCount;
        string getCurrentTime() { 
            time_t t = time(0); 
            struct tm ts; 
            char buff[10]; 
            ts = *localtime(&t); 
            strftime(buff, sizeof(buff), "%X", &ts); 
            return buff; 
        }
    public:
        string getName() const {
            return name; 
        }
        void setName(const string & newName) {
            name = newName;
        }
        double getPrice() const { 
            return price; 
        }
        void setPrice(double newPrice) {
            price = newPrice;
        }
        int getQty() const { 
            return qty; 
        }
        void setQty(int newQty) { 
            qty = newQty;
            if (transactionTimes == nullptr && qty > 0) { 
                transactionTimes = new string[qty]; 
            }
        }
        int getNumSold() const { 
            return numSold; 
        }
        void setNumSold(int newNumSold) {
            numSold = newNumSold;
        }
        
        bool buyItem(double&);
        Snack();
        Snack(string, double, int);
        ~Snack();
};

/*
RECIVES: nothing
DOES: default constructor
RETURNS: nothing
*/
Snack::Snack () {   
    name = "";
    price = 0;
    qty = 0;
    numSold = 0;
    transactionTimes = nullptr; 
    transactionCount = 0;
}

/*
RECIVES: nothing
DOES: overloaded constructor
RETURNS: nothing
*/
Snack::Snack (string inputName, double inputPrice, int inputQty) {
    name = inputName;
    price = inputPrice;
    qty = inputQty;
    numSold = 0;
    transactionCount = 0;
    transactionTimes = new string[qty];
}

/*
RECIVES: nothing
DOES: destructor
RETURNS: nothing
*/
Snack::~Snack() {
    cout << "Closing info for " << name << endl;
    cout << qty << " in stock" << endl;
    cout << numSold << " sold for a profit of $" << price * numSold << endl;

    if (transactionCount > 0) {
        cout << "\nTransactions occurred at:" << endl;
        for (int i = 0; i < transactionCount; i++) {
            cout << "        " << transactionTimes[i] << endl;
        }
    }

    delete[] transactionTimes;
}

/*
RECIVES: by refrence the amount of money entered as a double
DOES: registers when someone buys something, stores the transaction time
updates the stock, numsold and money entered
RETURNS: bool
*/
bool Snack::buyItem(double& moneyEntered) {
    if (moneyEntered >= price && qty > 0) {
        moneyEntered -= price;
        qty--;
        numSold++;
        if (transactionCount < numSold) {
            transactionTimes[transactionCount] = getCurrentTime();
            transactionCount++;
        }
        cout << "Item has been dispensed below" << endl;
        return true;
    }
    else if (qty == 0) {
        cout << "Error: item is sold-out!" << endl;
        return false;
    }
    else {
        cout << "Error: insufficient funds!" << endl;
        return false;
    }
}

void displayVendingMachine(const Snack[], int); 
int getQuarters();
void userBuyItem(Snack [], int);
bool promptToContinue();

int main() {
    const int SIZE = 3;
    
    // Snack snack1;
    // snack1.setName("Chips");
    // snack1.setPrice(1.75);
    // snack1.setQty(3);
    // Snack snack2("Candy", 1.25, 5);
    // Snack snack3("Soda", 1.00, 2);
    // Snack snacks[SIZE] = {snack1, snack2, snack3};
    cout << "Welcome to the vending machine!" << endl;
    cout << endl;
    // Snack snacks[3] = {
    //     Snack("Chips", 1.75, 3),
    //     Snack("Candy", 1.25, 5),
    //     Snack("Soda", 1.00, 2)
    // };
    // Snack snacks[SIZE];
    // snacks[0].setName("Chips");
    // snacks[0].setPrice(1.75);
    // snacks[0].setQty(3);
    // snacks[1] = Snack("Candy", 1.25, 5);
    // snacks[2] = Snack("Soda", 1.00, 2);
    Snack snacks[SIZE] = { 
        Snack(),                     
        Snack("Candy", 1.25, 5),      
        Snack("Soda", 1.00, 2)        
    };
    snacks[0].setName("Chips");
    snacks[0].setPrice(1.75);
    snacks[0].setQty(3);

    bool state = true;
    do {
        userBuyItem(snacks, SIZE);
        state = promptToContinue();
        cout << endl;
    } while(state);
    
}

/*
RECIVES: array of the snacks, and its size
DOES: displays the current state of the vending machine
RETURNS: nothing
*/
void displayVendingMachine(const Snack snacks[], int size) {
    cout << setw(10) << left << "Item #" << setw(10) << left << "ItemName" 
         << setw(10) << left << "Price"<< setw(10) << left << "# in-stock" 
         << endl;
    cout << setw(40) << setfill('-') << "" << endl;
    cout << setfill(' ');

    for (int i = 0; i < size; i++) {
        cout << setw(10) << left << i + 1 << setw(10) << left 
             << snacks[i].getName() << setw(10) << snacks[i].getPrice() 
             << setw(10) << left << snacks[i].getQty()<< endl;
    }
}

/*
RECIVES: nothing
DOES: accepts the number of quarters the user enters 
RETURNS: int
*/
int getQuarter() {
    int input;
    do {
        cout << "Enter the number of quarters: ";
        cin >> input;
        if (input < 1) {
            cout << "Please enter a number greater than 0" << endl;
            cout << endl;
        }
    } while(input < 1);
    return input;
}

/*
RECIVES: array of snacks, and it's size
DOES: calls the displayVendingMachine and calls getQuarter,
converts to amount of money and asks user what they want to buy, and displays
change amount if any
RETURNS: nothing
*/
void userBuyItem(Snack snacks[], int size) {
    displayVendingMachine(snacks, size);
    int input = getQuarter();
    double amount = ((double)input * 25)/100;
    cout << "Amount Entered: $" << fixed << setprecision(2) << amount << endl;
    int productNum;
    do {
        cout << "\nEnter a number between 1 and 3 to make your selection: ";
        cin >> productNum;
        if (productNum < 1 || productNum > 3) {
            cout << "Error: invalid input. Try again" << endl;
        }
    } while (productNum < 1 || productNum > 3);
    bool dum = snacks[productNum - 1].buyItem(amount);
    if(amount > 0) {
        cout << "$" << amount << " dispensed below" << endl;
    }
}

/*
RECIVES: nothing
DOES: asks user if they want to continue, is case insensitive,
RETURNS: bool
*/
bool promptToContinue() {
    cout << "\nContinue? (Y / N): ";
    char input;
    cin >> input;
    input = toupper(input);
    if (input == 'Y') {
        return true;
    }
    else {
        return false;
    }
}
