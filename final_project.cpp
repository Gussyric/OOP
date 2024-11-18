#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <limits> // For numeric_limits

using namespace std;

// Struct to hold transaction details
struct Transaction {
    string type;    // "Income" or "Expense"
    string category;
    double amount;
};

// Class to manage the family budget
class FamilyBudget {
private:
    vector<Transaction> transactions;
    double balance;

public:
    // Constructor to initialize balance
    FamilyBudget() : balance(0.0) {}

    // Add an income transaction
    void addIncome(const string& category, double amount) {
        if (amount <= 0) {
            cout << "Income amount must be greater than zero.\n";
            return;
        }
        transactions.push_back({"Income", category, amount});
        balance += amount;
        cout << "Income added successfully.\n";
    }

    // Add an expense transaction
    void addExpense(const string& category, double amount) {
        if (amount <= 0) {
            cout << "Expense amount must be greater than zero.\n";
            return;
        }
        transactions.push_back({"Expense", category, amount});
        balance -= amount;
        cout << "Expense added successfully.\n";
    }

    // Display the current balance
    void viewBalance() const {
        cout << fixed << setprecision(2);
        cout << "Current balance: $" << balance << endl;
    }

    // Display a summary of all transactions
    void viewTransactions() const {
        cout << "\n--- Transaction Summary ---\n";
        cout << left << setw(10) << "Type" 
             << setw(15) << "Category" 
             << setw(10) << "Amount" << endl;
        cout << string(35, '-') << endl;

        for (const auto& t : transactions) {
            cout << left << setw(10) << t.type 
                 << setw(15) << t.category 
                 << "$" << setw(10) << fixed << setprecision(2) << t.amount << endl;
        }

        cout << "\nTotal balance: $" << fixed << setprecision(2) << balance << endl;
    }
};

// Main function
int main() {
    FamilyBudget budget;
    int choice;

    do {
        // Display menu
        cout << "\n--- Family Budget Manager ---\n";
        cout << "1. Add Income\n";
        cout << "2. Add Expense\n";
        cout << "3. View Balance\n";
        cout << "4. View Transactions\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        // Input validation
        if (!(cin >> choice)) { // If input is not a valid integer
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            continue; // Restart the loop
        }

        switch (choice) {
            case 1: {
                string category;
                double amount;
                cout << "Enter income category: ";
                cin >> ws; // Clear whitespace
                getline(cin, category);
                cout << "Enter income amount: ";
                cin >> amount;

                if (cin.fail()) { // Validate numeric input for amount
                    cout << "Invalid amount. Please enter a valid number.\n";
                    cin.clear(); // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    break;
                }

                budget.addIncome(category, amount);
                break;
            }
            case 2: {
                string category;
                double amount;
                cout << "Enter expense category: ";
                cin >> ws; // Clear whitespace
                getline(cin, category);
                cout << "Enter expense amount: ";
                cin >> amount;

                if (cin.fail()) { // Validate numeric input for amount
                    cout << "Invalid amount. Please enter a valid number.\n";
                    cin.clear(); // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    break;
                }

                budget.addExpense(category, amount);
                break;
            }
            case 3:
                budget.viewBalance();
                break;
            case 4:
                budget.viewTransactions();
                break;
            case 5:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}