#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Coffee {
public:
    Coffee(int water, int milk, int coffee) : water_(water), milk_(milk), coffee_(coffee) {}

    virtual string getName() const = 0;
    virtual bool isResourceSufficient(int water, int milk, int coffee) const {
        return water_ >= water && milk_ >= milk && coffee_ >= coffee;
    }
    virtual double getCost() const {
        return 0.0;  
    }
    virtual void brew(int& water, int& milk, int& coffee) {
        water -= waterNeeded();
        milk -= milkNeeded();
        coffee -= coffeeNeeded();
        cout << "Here is your " << getName() << ". Enjoy!" << endl;
    }

    int waterNeeded() const { return water_; }
    int milkNeeded() const { return milk_; }
    int coffeeNeeded() const { return coffee_; }

private:
    int water_;
    int milk_;
    int coffee_;
};

class Espresso : public Coffee {
public:
    Espresso() : Coffee(50, 0, 18) {}

    string getName() const override {
        return "Espresso";
    }
    double getCost() const override {
        return 3.20;  
    }
};

class Cappuccino : public Coffee {
public:
    Cappuccino() : Coffee(100, 50, 15) {}

    string getName() const override {
        return "Cappuccino";
    }
    double getCost() const override {
        return 5.25;  
    }
};

class Latte : public Coffee {
public:
    Latte() : Coffee(100, 100, 10) {}

    string getName() const override {
        return "Latte";
    }
    double getCost() const override {
        return 6.90; 
    }
};

class Americano : public Coffee {
public:
    Americano() : Coffee(100, 0, 10) {}

    string getName() const override {
        return "Americano";
    }
    double getCost() const override {
        return 4.00; 
    }
};

class CoffeeMaker {
public:
    CoffeeMaker() : water(300), milk(200), coffee(100) {}

    void report() const {
        cout << "Resources:" << endl;
        cout << "Water: " << water << "ml" << endl;
        cout << "Milk: " << milk << "ml" << endl;
        cout << "Coffee: " << coffee << "g" << endl;
    }

    void makeCoffee(const string& coffeeType) {
        Coffee* selectedCoffee = nullptr;
        if (coffeeType == "Espresso") {
            selectedCoffee = new Espresso();
        } else if (coffeeType == "Cappuccino") {
            selectedCoffee = new Cappuccino();
        } else if (coffeeType == "Latte") {
            selectedCoffee = new Latte();
        } else if (coffeeType == "Americano") {
            selectedCoffee = new Americano();
        } else {
            cout << "Invalid coffee selection." << endl;
            return;
        }

        int coffeeAmount = selectedCoffee->coffeeNeeded();
        int waterAmount = selectedCoffee->waterNeeded();
        int milkAmount = selectedCoffee->milkNeeded();

        if (selectedCoffee->isResourceSufficient(waterAmount, milkAmount, coffeeAmount)) {
            // Ask for money in dollars and cents
            double cost = selectedCoffee->getCost();
            double money;
            cout << "Please insert $" << fixed << setprecision(2) << cost << ": ";
            cin >> money;

            if (money >= cost) {
                selectedCoffee->brew(water, milk, coffee);
                coffee -= coffeeAmount;
                // Return change if any
                double change = money - cost;
                if (change > 0) {
                    cout << "Change: $" << fixed << setprecision(2) << change << endl;
                }
            } else {
                cout << "Insufficient funds." << endl;
            }
        } else {
            cout << "Insufficient resources." << endl;
        }

        delete selectedCoffee;
    }

    void addResources(int addedWater, int addedMilk, int addedCoffee) {
        water += addedWater;
        milk += addedMilk;
        coffee += addedCoffee;
    }

private:
    int water;
    int milk;
    int coffee;
};

int main() {
    CoffeeMaker coffeeMaker;

    cout << "Coffee Maker Menu:" << endl;
    cout << "1. Make Espresso" << endl;
    cout << "2. Make Cappuccino" << endl;
    cout << "3. Make Latte" << endl;
    cout << "4. Make Americano" << endl;
    cout << "5. Add Resources" << endl;
    cout << "6. Report Resources" << endl;
    cout << "7. Exit" << endl;

    int choice;
    while (true) {
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        switch (choice) {
            case 1:
                coffeeMaker.makeCoffee("Espresso");
                break;
            case 2:
                coffeeMaker.makeCoffee("Cappuccino");
                break;
            case 3:
                coffeeMaker.makeCoffee("Latte");
                break;
            case 4:
                coffeeMaker.makeCoffee("Americano");
                break;
            case 5:
                int addedWater, addedMilk, addedCoffee;
                cout << "Enter the amount of water (ml): ";
                cin >> addedWater;
                cout << "Enter the amount of milk (ml): ";
                cin >> addedMilk;
                cout << "Enter the amount of coffee (g): ";
                cin >> addedCoffee;
                coffeeMaker.addResources(addedWater, addedMilk, addedCoffee);
                break;
            case 6:
                coffeeMaker.report();
                break;
            case 7:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option (1-7)." << endl;
                break;
        }
    }

    return 0;
}

