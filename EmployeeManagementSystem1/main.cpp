#include <iostream>
#include <vector>
#include "Employees.h"
#include "EMS.h"

void printMenu() {
    std::cout << "1. Add a new employee" << std::endl;
    std::cout << "2. Display info" << std::endl;
    std::cout << "3. Remove an employee" << std::endl;
    std::cout << "4. Modify info" << std::endl;
    std::cout << "5. Query" << std::endl;
    std::cout << "6. Sort" << std::endl;
    std::cout << "7. Clear all data" << std::endl;
    std::cout << "8. Exit" << std::endl;
}

int main() {
    std::cout << "Welcome to the employee management system!" << std::endl;
    printMenu();
    std::vector<Employee *> employees;
    EMS ems;
    while (ems.selectFunction(employees) != 8) {
    }
    return 0;
}