#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Meal {
    string name;
    string type; 
};

class MealManagementSystem {
private:
    vector<Meal> meals;

public:
    void addMeal(const Meal& meal) {
        meals.push_back(meal);
        cout << "Meal added successfully!" << endl;
    }

    void viewMeals() const {
        if (meals.empty()) {
            cout << "No meals available." << endl;
            return;
        }

        cout << "Meal Schedule for today:" << endl;
        for (const Meal& meal : meals) {
            cout << meal.type << ": " << meal.name << endl;
        }
    }
};

int main() {
    MealManagementSystem mealSystem;

    while (true) {
        cout << "Meal Management System" << endl;
        cout << "1. Add Meal" << endl;
        cout << "2. View Meals" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            {
                Meal meal;
                cout << "Enter your name: ";
                cin.ignore(); 
                getline(cin, meal.name);
                cout << "Enter the meal type (Breakfast, Lunch, Dinner): ";
                getline(cin, meal.type);
                mealSystem.addMeal(meal);
                break;
            }
        case 2:
            mealSystem.viewMeals();
            break;
        case 3:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}