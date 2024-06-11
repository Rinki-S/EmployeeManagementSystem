#include <iostream>
#include <vector>
#include "Employees.h"
#include "EMS.h"

void EMS::printMenu() {
    std::cout << "1. Add a new employee" << std::endl;
    std::cout << "2. Display info" << std::endl;
    std::cout << "3. Remove an employee" << std::endl;
    std::cout << "4. Modify info" << std::endl;
    std::cout << "5. Query" << std::endl;
    std::cout << "6. Sort" << std::endl;
    std::cout << "7. Clear all data" << std::endl;
    std::cout << "8. Exit" << std::endl;
}

void EMS::printTableHead() {
    std::cout << std::left << std::setw(15) << "Name" << std::setw(15) << "Age"
              << std::setw(15) << "DeptID" << std::setw(15) << "Job Title"
              << std::endl;
}

int EMS::selectFunction(std::vector<Employee *> &employees) {
    int choice;
    std::cout << "Please select a function: ";
    while (true) {
        std::cin >> choice;
        if (choice < 1 || choice > 8 || std::cin.fail()) {
            std::cout << "Invalid input. Please try again: ";
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        } else {
            break;
        }
    }
    switch (choice) {
        case 1: addEmployee(employees); break;
        case 2: displayInfo(employees); break;
        case 3: removeEmployee(employees); break;
        case 4: modifyInfo(employees); break;
        case 5: query(employees); break;
        case 6: sort(employees); break;
        case 7: clearAllData(); break;
        case 8: exit(); break;
        default: break;
    }
    return choice;
}

bool EMS::addEmployee(std::vector<Employee *> &employees) {
    std::string name;
    int age;
    int deptID;
    std::string jobTitle;
    std::cout << "Please select the employee's type: ";
    std::cout << "1. Employee" << std::endl;
    std::cout << "2. Manager" << std::endl;
    std::cout << "3. General Manager" << std::endl;
    int type;
    while (true) {
        std::cin >> type;
        if (type < 1 || type > 3 || std::cin.fail()) {
            std::cout << "Invalid input. Please try again: ";
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        } else {
            break;
        }
    }
    std::cout << "Please enter the employee's name: ";
    std::cin >> name;
    std::cout << "Please enter the employee's age: ";
    std::cin >> age;
    std::cout << "Please enter the employee's department ID: ";
    std::cin >> deptID;
    std::cout << "Please enter the employee's job title: ";
    std::cin >> jobTitle;
    switch (type) {
        case 1:
            employees.push_back(new Employee(name, age, deptID, jobTitle));
            break;
        case 2:
            employees.push_back(new Manager(name, age, deptID, jobTitle));
            break;
        case 3:
            employees.push_back(
                new GeneralManager(name, age, deptID, jobTitle));
            break;
    }
    return true;
}

bool EMS::displayInfo(std::vector<Employee *> &employees) {
    if (employees.empty()) {
        std::cout << "No data to display." << std::endl;
        return false;
    }
    printTableHead();
    for (const auto &employee : employees) {
        employee->display();
    }
    return true;
}