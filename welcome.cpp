#include "Welcome.h"

void printMessageCenter(const char* message) {
    int len = 0;
    int pos = 0;

    len = (78 - strlen(message)) / 2;

    std::cout << "\t\t\t";

    for(pos = 0; pos < len; pos++) {
        std::cout << " ";
    }

    std::cout << message;
}

void headMessage(const char* message) {
    system("cls");
    std::cout << "\t\t\t#######################################################################\n";
    std::cout << "\t\t\t##                                                                   ##\n";
    std::cout << "\t\t\t##              LIBRARY MANAGEMENT SYSTEM - Omar Khan                ##\n";
    std::cout << "\t\t\t##                                                                   ##\n";
    std::cout << "\t\t\t#######################################################################\n";
    std::cout << "\t\t\t---------------------------------------------------------------------------\n";
    printMessageCenter(message);
    std::cout << "\n\t\t\t---------------------------------------------------------------------------";
}
