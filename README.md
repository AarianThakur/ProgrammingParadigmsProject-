# Coffee Maker System

The Coffee Maker System is a console-based application that simulates the operation of a coffee maker machine. It allows users to make various types of coffee, manage resources, handle monetary transactions, and get reports on resource levels. Whether you're a coffee enthusiast or a developer looking to learn about object-oriented programming, this system provides an interactive and engaging experience.

## Features

- **Coffee Selection:** Users can choose from a menu of coffee options, including Espresso, Cappuccino, Latte, and Americano.

- **Resource Management:** The system manages resources such as water, milk, and coffee grounds. It checks resource availability before brewing a coffee.

- **Monetary Transactions:** Users are required to insert the correct amount of money, with the system calculating the cost of the selected coffee and providing change if necessary.

- **Resource Refilling:** Users can add resources (water, milk, and coffee grounds) to replenish the coffee maker's supplies.

- **Reporting:** The system provides resource reports to keep users informed about the current levels of each resource.

- **User Interaction:** The application features an interactive menu that allows users to make selections and interact with the system.

## Getting Started

1. **Clone the Repository:**

    ```bash
    git clone https://github.com/your-username/coffee-maker-system.git
    cd coffee-maker-system
    ```

2. **Compile and Run:**

    Compile the source code and run the application:

    ```bash
    g++ -o coffee_maker main.cpp
    ./coffee_maker
    ```

3. **Usage:**

    - Choose from the menu options to make coffee, add resources, or get resource reports.
    - Follow the on-screen instructions to insert money when prompted.

## Classes and Code Structure

The Coffee Maker System is built using object-oriented programming (OOP) principles. Key classes and functions include:

- `Coffee`: Base class with attributes representing the resources required to make coffee and methods for brewing and cost calculation. Derived classes include Espresso, Cappuccino, Latte, and Americano.

- `CoffeeMaker`: Manages resources, coffee making, and provides options to add resources and get reports. It also contains a friend function for calculating total cost and an operator overloading function to combine two coffee objects.

## Future Enhancements

The Coffee Maker System can be further improved by implementing features like user accounts, inventory management, a wider variety of coffee drinks, and a mobile application for coffee orders on-the-go.



