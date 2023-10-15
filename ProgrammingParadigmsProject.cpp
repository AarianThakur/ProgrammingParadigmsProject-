#include <iostream>
#include <string>

class Coffee {
public:
    Coffee(int water, int milk, int coffee) : water_(water), milk_(milk), coffee_(coffee) {}

    virtual std::string getName() const = 0;
    virtual bool isResourceSufficient(int water, int milk, int coffee) const {
        return water_ >= water && milk_ >= milk && coffee_ >= coffee;
    }
    virtual void brew() {
        water_ -= waterNeeded();
        milk_ -= milkNeeded();
        coffee_ -= coffeeNeeded();
        std::cout << "Here is your " << getName() << " ??. Enjoy!" << std::endl;
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

    std::string getName() const override {
        return "Espresso";
    }
};

class Cappuccino : public Coffee {
public:
    Cappuccino() : Coffee(100, 50, 15) {}

    std::string getName() const override {
        return "Cappuccino";
    }
};

class CoffeeMaker {
public:
    CoffeeMaker() : water(300), milk(200), coffee(100) {}

    void report() const {
        std::cout << "Resources:" << std::endl;
        std::cout << "Water: " << water << "ml" << std::endl;
        std::cout << "Milk: " << milk << "ml" << std::endl;
        std::cout << "Coffee: " << coffee << "g" << std::endl;
    }

    void makeCoffee(const std::string& coffeeType) {
        Coffee* coffee = nullptr;
        if (coffeeType == "Espresso") {
            coffee = new Espresso();
        } else if (coffeeType == "Cappuccino") {
            coffee = new Cappuccino();
        } else {
            std::cout << "Invalid coffee selection." << std::endl;
            return;
        }

        if (coffee->isResourceSufficient(coffee->waterNeeded(), coffee->milkNeeded(), coffee->coffeeNeeded())) {
            coffee->brew();
            water -= coffee->waterNeeded();
            milk -= coffee->milkNeeded();
            coffee -= coffee->coffeeNeeded();
        } else {
            std::cout << "Insufficient resources." << std::endl;
        }

        delete coffee;
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

    std::cout << "Coffee Maker Menu:" << std::endl;
    std::cout << "1. Make Espresso" << std::endl;
    std::cout << "2. Make Cappuccino" << std::endl;
    std::cout << "3. Add Resources" << std::endl;
    std::cout << "4. Report Resources" << std::endl;
    std::cout << "5. Exit" << std::endl;

    int choice;
    while (true) {
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                coffeeMaker.makeCoffee("Espresso");
                break;
            case 2:
                coffeeMaker.makeCoffee("Cappuccino");
                break;
            case 3:
                int addedWater, addedMilk, addedCoffee;
                std::cout << "Enter the amount of water (ml): ";
                std::cin >> addedWater;
                std::cout << "Enter the amount of milk (ml): ";
                std::cin >> addedMilk;
                std::cout << "Enter the amount of coffee (g): ";
                std::cin >> addedCoffee;
                coffeeMaker.addResources(addedWater, addedMilk, addedCoffee);
                break;
            case 4:
                coffeeMaker.report();
                break;
            case 5:
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a valid option (1-5)." << std::endl;
                break;
        }
    }

 return 0;
}


