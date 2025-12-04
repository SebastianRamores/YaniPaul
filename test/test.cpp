#include <iostream>
#include <cstdlib>

int main() {
    int choice;

    while (true) {
        std::cout << "\n=== System App Launcher ===\n";
        std::cout << "1. Calculator\n";
        std::cout << "2. Notepad\n";
        std::cout << "3. Paint\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                system("calc");
                break;
            case 2:
                system("notepad");
                break;
            case 3:
                system("mspaint");
                break;
            case 4:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
