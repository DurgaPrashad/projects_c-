#include <iostream>
#include <vector>

struct Transaction {
    std::string description;
    double amount;
    bool isExpense;

    Transaction(const std::string& desc, double amt, bool isExp) : description(desc), amount(amt), isExpense(isExp) {}
};

class FinanceTracker {
private:
    double balance;
    double spendingLimit;
    std::vector<Transaction> transactions;

public:
    FinanceTracker() : balance(0.0), spendingLimit(0.0) {}

    void addTransaction(const std::string& description, double amount, bool isExpense) {
        Transaction transaction(description, amount, isExpense);
        transactions.push_back(transaction);

        if (isExpense) {
            balance -= amount;
        } else {
            balance += amount;
        }
    }

    void setSpendingLimit(double limit) {
        spendingLimit = limit;
    }

    double calculateDebtRecoveryGoal() {
        return -balance;
    }

    void viewTransactions() {
        std::cout << "Transactions:" << std::endl;
        for (const Transaction& transaction : transactions) {
            std::string type = (transaction.isExpense) ? "Expense" : "Income";
            std::cout << type << ": " << transaction.description << " - $" << transaction.amount << std::endl;
        }
    }

    void viewBalance() {
        std::cout << "Current Balance: $" << balance << std::endl;
        std::cout << "Spending Limit: $" << spendingLimit << std::endl;
    }
};

int main() {
    FinanceTracker tracker;

    int choice;
    do {
        std::cout << "1. Add Expense" << std::endl;
        std::cout << "2. Add Income" << std::endl;
        std::cout << "3. Set Spending Limit" << std::endl;
        std::cout << "4. View Transactions" << std::endl;
        std::cout << "5. View Balance" << std::endl;
        std::cout << "6. Calculate Debt Recovery Goal" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string description;
                double amount;

                std::cout << "Enter the expense description: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                std::cout << "Enter the expense amount: $";
                std::cin >> amount;

                tracker.addTransaction(description, amount, true);
                std::cout << "Expense added successfully" << std::endl;
                break;
            }

            case 2: {
                std::string description;
                double amount;

                std::cout << "Enter the income description: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                std::cout << "Enter the income amount: $";
                std::cin >> amount;

                tracker.addTransaction(description, amount, false);
                std::cout << "Income added successfully" << std::endl;
                break;
            }

            case 3: {
                double limit;
                std::cout << "Enter your spending limit: $";
                std::cin >> limit;
                tracker.setSpendingLimit(limit);
                std::cout << "Spending limit set successfully" << std::endl;
                break;
            }

            case 4:
                tracker.viewTransactions();
                break;

            case 5:
                tracker.viewBalance();
                break;

            case 6:
                std::cout << "Debt Recovery Goal: $" << tracker.calculateDebtRecoveryGoal() << std::endl;
                break;

            case 7:
                std::cout << "Exiting the program..." << std::endl;
                break;

            default:
                std::cout << "Invalid choice, try again." << std::endl;
                break;
        }
    } while (choice != 7);

    return 0;
}
