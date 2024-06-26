#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
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

int EMS::selectFunction(std::vector<Employee*>& employees) {
    int choice;
    std::cout << "Please select a function: ";
    while (true) {
        // Get user input
        std::cin >> choice;
        if (choice < 1 || choice > 8 || std::cin.fail()) {
            // If the input is invalid,
            // clear the error state and ignore the input
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
        case 6: sortData(employees); break;
        case 7: clearAllData(employees); break;
        case 8: exit(employees); break;
        default: break;
    }
    return choice;
}

bool EMS::addEmployee(std::vector<Employee*>& employees) {
    std::string name;
    int id;
    int deptID;
    std::string jobTitle;
    std::cout << "Please select the employee's type: ";
    std::cout << "1. Employee" << std::endl;
    std::cout << "2. Manager" << std::endl;
    std::cout << "3. General Manager" << std::endl;
    int type;
    while (true) {
        // Get user input and standarlize it
        std::cin >> type;
        if (type < 1 || type > 3 || std::cin.fail()) {
            std::cout << "Invalid input. Please try again: ";
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        } else {
            break;
        }
    }
    // Get user input and standarlize them
    std::cout << "Please enter the employee's name: ";
    name = inputName();
    std::cout << "Please enter the employee's ID: ";
    id = inputID();
    std::cout << "Please enter the employee's department ID: ";
    deptID = inputDeptID();
    std::cout << "Please enter the employee's job title: ";
    jobTitle = inputJobTitle();
    switch (type) {
        // Create a new employee object based on the user's choice
        case 1:
            employees.push_back(new Employee(name, id, deptID, jobTitle));
            break;
        case 2:
            employees.push_back(new Manager(name, id, deptID, jobTitle));
            break;
        case 3:
            employees.push_back(new GeneralManager(name, id, deptID, jobTitle));
            break;
    }
    return true;
}

bool EMS::displayInfo(std::vector<Employee*>& employees) {
    if (employees.empty()) {
        std::cout << "No data to display." << std::endl;
        return false;
    }
    // Format display
    printTableHead();
    for (const auto& employee : employees) {
        employee->display();
    }
    return true;
}

bool EMS::removeEmployee(std::vector<Employee*>& employees) {
    // Detect if there is any data to remove
    if (employees.empty()) {
        std::cout << "No data to remove." << std::endl;
        return false;
    }
    int IDin;
    std::cout << "Please enter the ID of the employee you want to remove: ";
    IDin = inputID();
    // Search for the employee with the given ID
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if ((*it)->getId() == IDin) {
            delete *it;
            employees.erase(it);
            std::cout << "Employee removed." << std::endl;
            return true;
        }
    }
    std::cout << "Cannot find the employee." << std::endl;
    return false;
}

bool EMS::modifyInfo(std::vector<Employee*>& employees) {
    // Detect if threre is any data to modify
    if (employees.empty()) {
        std::cout << "No data to modify." << std::endl;
        return false;
    }
    int IDin;
    std::cout << "Please enter the ID of the employee you want to modify: ";
    IDin = inputID();
    // Search for the employee with the given ID
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if ((*it)->getId() == IDin) {
            std::string name;
            int id;
            int deptID;
            std::string jobTitle;
            std::cout << "Please enter the employee's name: ";
            name = inputName();
            std::cout << "Please enter the employee's ID: ";
            id = inputID();
            std::cout << "Please enter the employee's Department ID: ";
            deptID = inputDeptID();
            std::cout << "Please enter the employee's job title: ";
            std::cin >> jobTitle;
            // Modify the employee's information by
            // creating a new employee object
            (*it) = new Employee(name, id, deptID, jobTitle);
            std::cout << "Employee modified." << std::endl;
            return true;
        }
    }
    std::cout << "Cannot find the employee." << std::endl;
    return false;
}

bool EMS::query(std::vector<Employee*>& employees) {
    int choice;
    std::cout << "Please select a function: " << std::endl;
    std::cout << "1. Query by ID" << std::endl;
    std::cout << "2. Query by name" << std::endl;
    while (true) {
        std::cin >> choice;
        if (choice < 1 || choice > 2 || std::cin.fail()) {
            std::cout << "Invalid input. Please try again: ";
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        } else {
            break;
        }
    }
    switch (choice) {
        case 1: {
            // Detect if there is any data to query
            if (employees.empty()) {
                std::cout << "No data to query." << std::endl;
                return false;
            }
            int IDin;
            std::cout
                << "Please enter the ID of the employee you want to query: ";
            IDin = inputID();
            for (auto it = employees.begin(); it != employees.end(); ++it) {
                if ((*it)->getId() == IDin) {
                    printTableHead();
                    (*it)->display();
                    return true;
                }
            }
            std::cout << "Cannot find the employee." << std::endl;
            return false;
        }
        case 2: {
            if (employees.empty()) {
                std::cout << "No data to query." << std::endl;
                return false;
            }
            std::string namein;
            std::cout
                << "Please enter the name of the employee you want to query: ";
            namein = inputName();
            for (auto it = employees.begin(); it != employees.end(); ++it) {
                if ((*it)->getName() == namein) {
                    printTableHead();
                    (*it)->display();
                    return true;
                }
            }
            std::cout << "Cannot find the employee." << std::endl;
            return false;
        }
    }
    return false;
}

bool compare(Employee* a, Employee* b) {
    return a->getId() > b->getId();
}

bool EMS::sortData(std::vector<Employee*>& employees) {
    // Detect if there is any data to sort
    if (employees.empty()) {
        std::cout << "No data to sort." << std::endl;
        return false;
    }
    int choice;
    std::cout << "Please select a function: " << std::endl;
    std::cout << "1.Ascending order" << std::endl;
    std::cout << "2.Descending order" << std::endl;
    while (true) {
        std::cin >> choice;
        if (choice < 1 || choice > 2 || std::cin.fail()) {
            std::cout << "Invalid input. Please try again: ";
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        } else {
            break;
        }
    }
    switch (choice) {
        case 1: {
            // Ascending order
            std::sort(employees.begin(), employees.end());
            return true;
        }
        case 2: {
            // Descending order
            std::sort(employees.begin(), employees.end(), compare);
            return true;
        }
        default: break;
    }
    return false;
}

bool EMS::clearAllData(std::vector<Employee*>& employees) {
    // Confirm the user's choice
    std::cout << "Are you sure you want to clear all data? (y/n) ";
    char choice;
    std::cin >> choice;
    if (choice == 'y') {
        for (auto it = employees.begin(); it != employees.end(); ++it) {
            delete *it;
        }
        std::cout << "All data cleared." << std::endl;
        return true;
    }
    return false;
}

bool EMS::exit(std::vector<Employee*>& employees) {
    saveData(employees);
    return true;
};

bool EMS::readData(std::vector<Employee*>& employees) {
    std::ifstream ifs("Employees.txt");
    // If the file cannot be opened, return false
    if (!ifs) {
        std::cout << "Failed to read data." << std::endl;
        return false;
    }
    // Read the data from the file
    std::string name;
    int id;
    int deptID;
    std::string jobTitle;
    while (ifs >> name >> id >> deptID >> jobTitle) {
        employees.push_back(new Employee(name, id, deptID, jobTitle));
    }
    ifs.close();
    std::cout << "Data read." << std::endl;
    return true;
}

bool EMS::saveData(std::vector<Employee*>& employees) {
    std::ofstream ofs("Employees.txt");
    // If the file cannot be opened, return false
    if (!ofs) {
        std::cout << "Failed to save data." << std::endl;
        return false;
    }
    // Save the data to the file
    for (const auto& employee : employees) {
        ofs << employee->getName() << " " << employee->getId() << " "
            << employee->getDeptID() << " " << employee->getJobTitle()
            << std::endl;
    }
    ofs.close();
    std::cout << "Data saved." << std::endl;
    return true;
}

std::string EMS::inputName() {
    std::string name;
    while (true) {
        std::getline(std::cin, name);
        if (name.length() > 15) {
            std::cout << "Name too long. Please try again: ";
        } else if (name.length() == 0) {
            std::cout << "Name cannot be empty. Please try again: ";
        } else if (name.find(" ") != std::string::npos) {
            std::cout << "Name cannot contain spaces. Try substituting it with "
                         "short dash('-'). Please try again: ";
        } else {
            break;
        }
    }
    return name;
}

int EMS::inputID() {
    int id;
    while (true) {
        std::cin >> id;
        if (id > 10E16) {
            std::cout << "Invalid input. Please try again: ";
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        } else {
            break;
        }
    }
    return id;
}

int EMS::inputDeptID() {
    int deptID;
    while (true) {
        std::cin >> deptID;
        if (deptID < 0 || deptID > 100 || std::cin.fail()) {
            std::cout << "Invalid input. Please try again: ";
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        } else {
            break;
        }
    }
    return deptID;
}

std::string EMS::inputJobTitle() {
    std::string jobTitle;
    while (true) {
        std::getline(std::cin, jobTitle);
        if (jobTitle.length() > 15) {
            std::cout << "Job title too long. Please try again: ";
        } else if (jobTitle.length() == 0) {
            std::cout << "Job title cannot be empty. Please try again: ";
        } else if (jobTitle.find(" ") != std::string::npos) {
            std::cout << "Job title cannot contain spaces. Try substituting it "
                         "with short dash('-'). Please try again:";
        } else {
            break;
        }
    }
    return jobTitle;
}
