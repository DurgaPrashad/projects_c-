#include <iostream>
#include <vector>
#include <string>

class Stock {
private:
    std::string name;
    int quantity;
    double price;

public:
    Stock(const std::string& name, int quantity, double price)
        : name(name), quantity(quantity), price(price) {}

    std::string getName() {
        return name;
    }

    int getQuantity() {
        return quantity;
    }

    double getPrice() {
        return price;
    }

    void removeQuantity(int quantityToRemove) {
        if (quantityToRemove <= quantity) {
            quantity -= quantityToRemove;
        } else {
            std::cout << "Not enough quantity to remove" << std::endl;
        }
    }

    std::string toString() {
        return name + ", quantity: " + std::to_string(quantity) + ", price: $" + std::to_string(price);
    }
};

int main() {
    std::vector<Stock> stocks;

    int choice;
    do {
        std::cout << "1. Add stock" << std::endl;
        std::cout << "2. Remove stock" << std::endl;
        std::cout << "3. View stock" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name;
                int quantity;
                double price;

                std::cout << "Enter the stock name: ";
                std::cin >> name;
                std::cout << "Enter the stock quantity: ";
                std::cin >> quantity;
                std::cout << "Enter the stock price: ";
                std::cin >> price;

                Stock newStock(name, quantity, price);
                stocks.push_back(newStock);

                std::cout << "Stock added successfully" << std::endl;
                break;
            }

            case 2: {
                std::string stockName;
                int removeQuantity;

                std::cout << "Enter the stock name: ";
                std::cin >> stockName;
                std::cout << "Enter the quantity to remove: ";
                std::cin >> removeQuantity;

                bool stockFound = false;
                for (auto it = stocks.begin(); it != stocks.end(); ++it) {
                    if (it->getName() == stockName) {
                        stockFound = true;
                        it->removeQuantity(removeQuantity);
                        std::cout << "Stock removed successfully" << std::endl;
                        break;
                    }
                }

                if (!stockFound) {
                    std::cout << "Stock not found" << std::endl;
                }
                break;
            }

            case 3:
                std::cout << "Current stocks:" << std::endl;
                for (const Stock& stock : stocks) {
                    std::cout << stock.toString() << std::endl;
                }
                break;

            case 4:
                std::cout << "Exiting the program..." << std::endl;
                break;

            default:
                std::cout << "Invalid choice, try again." << std::endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
