#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// meal categories
enum MealCategory {
    BREAKFAST,
    LUNCH,
    DINNER
};

// Structures order items
struct MenuItem {
    string name;
    float price;
    int quantity;
    MealCategory mealCategory;
};

struct OrderItem {
    MenuItem item;
    int quantity;
};

// Function 
void displayMenu(const vector<MenuItem>& menu);
void takeOrder(vector<MenuItem>& menu, vector<OrderItem>& order);
void printBill(const vector<OrderItem>& order);
void addMenuItem(vector<MenuItem>& menu);
void removeMenuItem(vector<MenuItem>& menu);
void showHelp();
int login();
int logout();

int main() {
    // called "menu.txt"
    ifstream menuFile("menu.txt");
    if (!menuFile.is_open()) {
        cout << "Error opening menu file. Exiting program." << endl;
        return 1;
    }

    int menuSize;
    menuFile >> menuSize;
    vector<MenuItem> menu(menuSize);

    
    for (int i = 0; i < menuSize; i++) {
    int mealCategoryInt; 
    menuFile >> menu[i].name >> menu[i].price >> menu[i].quantity >> mealCategoryInt;
    menu[i].mealCategory = static_cast<MealCategory>(mealCategoryInt);
}


    menuFile.close();

    vector<OrderItem> order; // Initialize an empty order vector
    int choice;

    int loggedIn = login(); // Attempt to log in

    if (!loggedIn) {
        cout << "Authentication failed. Exiting program." << endl;
        return 1;
    }

    // Main program loop
    do {
        system("cls"); // Clear the console screen

        // Display the main menu options
        cout << "\t\t---------------------------------------------" << endl;
        cout << "\t\t ====== Well come Bun Talk Bakery ==========" << endl;
        cout << "\t\t---------------------------------------------\n\n\n" << endl;
        cout << "\t\t\t\t1. Display Menu\n" << endl;
        cout << "\t\t\t\t2. Take Order\n" << endl;
        cout << "\t\t\t\t3. Print Bill\n" << endl;
        cout << "\t\t\t\t4. Add Item to Menu\n" << endl;
        cout << "\t\t\t\t5. Remove Item from Menu\n" << endl;
        cout << "\t\t\t\t6. Help\n" << endl;
        cout << "\t\t\t\t7. Logout\n" << endl;
        cout << "\t\t\t\t8. Exit" << endl;
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        //  switch statement
        switch (choice) {
            case 1:
                displayMenu(menu); // Display the bakery menu
                int subChoice4;
                cout << "\n\nEnter 0 to return to the main menu: ";
                cin >> subChoice4;
                if (subChoice4 == 0) {
                    system("cls");
                }
                break;

            case 2:
                takeOrder(menu, order); // Take an order
                system("cls");
                break;

            case 3:
                printBill(order); // Print the bill
                int subChoice1;
                cout << "Enter 0 to return to the main menu: ";
                cin >> subChoice1;
                if (subChoice1 == 0) {
                    system("cls");
                }
                break;

            case 4:
                addMenuItem(menu); // Add an item to the menu
                int subChoice2;
                cout << "\n\n\t\t------------Added Successfully!-------------" << endl;
                cout << "\n\nEnter 0 to return to the main menu: ";
                cin >> subChoice2;
                if (subChoice2 == 0) {
                    system("cls");
                }
                break;

            case 5:
                removeMenuItem(menu); // Remove an item from the menu
                int subChoice3;
                cout << "\n\nEnter 0 to return to the main menu: ";
                cin >> subChoice3;
                if (subChoice3 == 0) {
                    system("cls");
                }
                break;

            case 6:
                showHelp(); // Display help information
                int subChoice;
                cout << "\nEnter 0 to return to the main menu: ";
                cin >> subChoice;
                if (subChoice == 0) {
                    system("cls");
                }
                break;

            case 7:
                loggedIn = logout(); // Log out
                if (!loggedIn) {
                    loggedIn = login(); // Attempt to log in again
                    if (!loggedIn) {
                        cout << "Authentication failed. Exiting program." << endl;
                        return 1;
                    }
                }
                break;

            case 8:
                cout << "\n\n\t\t------------Exiting Bun Talk Bakery. Goodbye!---------------------" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 8);

    return 0;
}


// Function to display the bakery menu categorized by meal
void displayMenu(const vector<MenuItem>& menu) {
    system("cls"); // Clear the console screen

    cout << "\t\t------------------------------------------------" << endl;
    cout << "\t\t=============== Bakery Menu ====================" << endl;
    cout << "\t\t------------------------------------------------\n\n\n\n" << endl;
    
    // Display breakfast items
    cout << "Breakfast Menu:\n";
    cout << "\t\tItem No. | Item Name         | Price  | In Stock" << endl;
    cout << "\t\t-----------------------------------------------" << endl;
    for (size_t i = 0; i < menu.size(); i++) {
        if (menu[i].mealCategory == BREAKFAST) {
            cout <<"\t\t"<< setw(9) << i + 1 << "| " 
                << setw(17) << menu[i].name << "| "
                << setw(6) << fixed << setprecision(2) 
                << menu[i].price << " | " << menu[i].quantity << endl;
        }
    }

    // Display lunch items
    cout << "\nLunch Menu:\n";
    cout << "\t\tItem No. | Item Name         | Price  | In Stock" << endl;
    cout << "\t\t-----------------------------------------------" << endl;
    for (size_t i = 0; i < menu.size(); i++) {
        if (menu[i].mealCategory == LUNCH) {
            cout <<"\t\t"<< setw(9) << i + 1 << "| " 
                << setw(17) << menu[i].name << "| "
                << setw(6) << fixed << setprecision(2) 
                << menu[i].price << " | " << menu[i].quantity << endl;
        }
    }

    // Display dinner items
    cout << "\nDinner Menu:\n";
    cout << "\t\tItem No. | Item Name         | Price  | In Stock" << endl;
    cout << "\t\t-----------------------------------------------" << endl;
    for (size_t i = 0; i < menu.size(); i++) {
        if (menu[i].mealCategory == DINNER) {
            cout <<"\t\t"<< setw(9) << i + 1 << "| " 
                << setw(17) << menu[i].name << "| "
                << setw(6) << fixed << setprecision(2) 
                << menu[i].price << " | " << menu[i].quantity << endl;
        }
    }
}


// Function to remove a menu item
void removeMenuItem(vector<MenuItem>& menu) {
    system("cls");
    displayMenu(menu);
    cout << "\n\t\t =========== Remove Item ===============\n\n" << endl;

    if (menu.empty()) {
        cout << "Menu is empty. Nothing to remove." << endl;
        return;
    }

    int itemToRemove;
    cout << "\n\nEnter the item number to remove (1-" << menu.size() << "): ";
    cin >> itemToRemove;

    if (itemToRemove < 1 || itemToRemove > static_cast<int>(menu.size())) {
        cout << "Invalid item number. Please enter a valid item number." << endl;
        return;
    }

    cout << "\n\n------Removing item -" << itemToRemove << ": " << menu[itemToRemove - 1].name << endl;

    menu.erase(menu.begin() + itemToRemove - 1);

    // Update the menu
    ofstream menuFile("menu.txt");
    if (!menuFile.is_open()) {
        cout << "Error opening menu file for writing." << endl;
        return;
    }

    menuFile << menu.size() << endl;
    for (size_t i = 0; i < menu.size(); i++) {
        menuFile << menu[i].name << " " << menu[i].price << " " << menu[i].quantity << " " << static_cast<int>(menu[i].mealCategory) << endl;
    }

    cout << "Item removed from the menu." << endl;
}


// Function to add a new menu item category
void addMenuItem(vector<MenuItem>& menu) {
    system("cls");

    cout << "\n\t\t =================== Add Item ====================\n\n\n" << endl;

    if (menu.size() >= 100) {
        cout << "Menu is full. Cannot add more items." << endl;
        return;
    }

    MenuItem newItem;
    cout << "Enter the name of the new item: ";
    cin.ignore(); 
    getline(cin, newItem.name);
    cout << "Enter the price of the new item: ";
    cin >> newItem.price;
    cout << "Enter the quantity of the new item: ";
    cin >> newItem.quantity;

    int mealChoice;
    cout << "Select the meal category (1. Breakfast, 2. Lunch, 3. Dinner): ";
    cin >> mealChoice;

    switch (mealChoice) {
        case 1:
            newItem.mealCategory = BREAKFAST;
            break;
        case 2:
            newItem.mealCategory = LUNCH;
            break;
        case 3:
            newItem.mealCategory = DINNER;
            break;
        default:
            cout << "Invalid meal category. Item not added to the menu." << endl;
            return;
    }

    menu.push_back(newItem);

    // Update the menu.
    ofstream menuFile("menu.txt");
    if (!menuFile.is_open()) {
        cout << "Error opening menu file for writing." << endl;
        return;
    }

    menuFile << menu.size() << endl;
    for (size_t i = 0; i < menu.size(); i++) {
        menuFile << menu[i].name << " " << menu[i].price << " " << menu[i].quantity << " " << static_cast<int>(menu[i].mealCategory) << endl;
    }
}




// Function to take an order from the user with meal category filtering
void takeOrder(vector<MenuItem>& menu, vector<OrderItem>& order) {
    system("cls");
    
    int mealChoice;
    
    cout << "\n\t\t =================== Choose a meal category ====================\n\n\n" << endl;
    cout << "\t\t\t\t1. Breakfast" << endl;
    cout << "\t\t\t\t2. Lunch" << endl;
    cout << "\t\t\t\t3. Dinner" << endl;
    cout << "\t\t\t\t0. Finish ordering" << endl;
    cout << "\n\n\nEnter your choice: ";
    cin >> mealChoice;

    if (mealChoice < 0 || mealChoice > 3) {
        cout << "Invalid meal category choice." << endl;
        return;
    }

    MealCategory selectedCategory;
    switch (mealChoice) {
        case 1:
            selectedCategory = BREAKFAST;
            break;
        case 2:
            selectedCategory = LUNCH;
            break;
        case 3:
            selectedCategory = DINNER;
            break;
        case 0:
            cout << "Finished ordering. Returning to the main menu." << endl;
            return;
    }

    system("cls");
    
    // Display only the items from the selected meal category
    cout << "Selected Meal Category: ";
    switch (selectedCategory) {
        case BREAKFAST:
            cout << "Breakfast" << endl;
            break;
        case LUNCH:
            cout << "Lunch" << endl;
            break;
        case DINNER:
            cout << "Dinner" << endl;
            break;
    }
    
    
    cout << "\n\n\n\t\t-----------------------------------------------" << endl;
    cout << "\t\tItem No. | Item Name         | Price  | In Stock" << endl;
    cout << "\t\t-----------------------------------------------" << endl;
    
    int itemNumber = 0;

    for (size_t i = 0; i < menu.size(); i++) {
        if (menu[i].mealCategory == selectedCategory) {
            itemNumber++;
            cout <<"\t\t"<< setw(9) << i + 1 << "| " 
                << setw(17) << menu[i].name << "| "
                << setw(6) << fixed << setprecision(2) 
                << menu[i].price << " | " << menu[i].quantity << endl;
        }
    }

    int choice;
    int quantity;

    cout << "\n\nEnter the item number you want to order (0 to finish ordering): ";

    while (1) {
        cin >> choice;

        if (choice == 0) {
            break;
        }

        if (choice < 1 || choice > itemNumber) {
            cout << "\n\nInvalid item number. Please try again or press 0 to finish ordering." << endl;
            continue;
        }

        // Find the selected item in the menu based on the meal category
        int selectedMenuItemIndex = 0;
        for (size_t i = 0; i < menu.size(); i++) {
            if (menu[i].mealCategory == selectedCategory) {
                selectedMenuItemIndex++;
                if (selectedMenuItemIndex == choice) {
                    if (menu[i].quantity <= 0) {
                        cout << "Sorry, this item is out of stock. Please try again or press 0 to finish ordering." << endl;
                        continue;
                    }
                    cout << "Enter the quantity: ";
                    cin >> quantity;

                    if (quantity <= 0) {
                        cout << "\nQuantity must be greater than zero. Please try again or press 0 to finish ordering." << endl;
                        continue;
                    }

                    if (quantity > menu[i].quantity) {
                        cout << "\nSorry, not enough in stock for your order. Please try again or press 0 to finish ordering." << endl;
                        continue;
                    }

                    OrderItem newItem;
                    newItem.item = menu[i];
                    newItem.quantity = quantity;
                    menu[i].quantity -= quantity;

                    order.push_back(newItem);
                    cout << "\n\t\t =========== Order added to the bill ===============\n\nEnter another item number or press 0 to finish ordering." << endl;
                    break;  
                }
            }
        }
    }

    cout << "Finished ordering. Returning to the main menu." << endl;
}



// Function to print the bill
void printBill(const vector<OrderItem>& order) {
    system("cls");

    if (order.empty()) {
        cout << "\nNo items in the bill." << endl;
        return;
    }

    cout << "\t\t---------------------------------------------" << endl;
    cout << "\t\t =================== Bill ====================" << endl;
    cout << "\t\t---------------------------------------------\n\n\n\n" << endl;
    cout << "Item Name        | Quantity | Price" << endl;
    cout << "---------------------------------" << endl;

    float totalAmount = 0;

    for (size_t i = 0; i < order.size(); i++) {
        const OrderItem& currentItem = order[i];
        float itemTotal = currentItem.item.price * currentItem.quantity;
        totalAmount += itemTotal;
        cout << setw(16) << currentItem.item.name << " | " << setw(8) << currentItem.quantity << " | RS." << fixed << setprecision(2) << itemTotal << endl;
    }

    cout << "\nTotal Amount: RS." << totalAmount << "\n\n\n";
}

// Function to display help information
void showHelp() {
    system("cls");
    cout << "\n\t\t =========== Help ===============\n\n" << endl;
    cout << "\n1. Display Menu: Shows the bakery menu with item details." << endl;
    cout << "\n2. Take Order: Allows you to place an order by specifying item number and quantity." << endl;
    cout << "\n3. Print Bill: Displays the bill with itemized details and total amount." << endl;
    cout << "\n4. Help: Shows this help message." << endl;
    cout << "\n5. Logout: Logs out of the system." << endl;
    cout << "\n6. Exit: Exits the program." << endl;
}

// Function to simulate user login
int login() {
    system("cls");
    cout << "\t\t---------------------------------------------" << endl;
    cout << "\t\t ====== Well come Bun Talk Bakery ==========" << endl;
    cout << "\t\t---------------------------------------------\n\n\n\n" << endl;

    string username;
    string password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    
    if (username == "admin" && password == "1234") {
        cout << "Logged in as admin." << endl;
        return 1; // Authentication successful
    }
    else {
        cout << "Authentication failed." << endl;
        return 0; // Authentication failed
        
    }
}

// Function to simulate user logout
int logout() {
   
    cout << "Logged out." << endl;
    return 0; 
}

