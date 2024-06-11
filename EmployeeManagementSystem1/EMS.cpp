#include <iostream>
#include <vector>
#include<algorithm>
#include<fstream>
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
        case 6: sortData(employees); break;
        case 7: clearAllData(employees); break;
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

bool EMS::removeEmployee(std::vector<Employee*>& employees) {   //按照编号删除离职的员工
	if (employees.empty()) {
		std::cout << "No data to remove." << std::endl;
		return false;
	}
	int IDin;
	std::cout << "Please enter the ID of the employee you want to remove: ";
	std::cin >> IDin;
	for (auto it = employees.begin(); it != employees.end(); ++it) {
		if ((*it)->getDeptID() == IDin) {
			delete* it;
			employees.erase(it);
			std::cout << "Employee removed." << std::endl;
			return true;
		}
	}
	std::cout << "Cannot find the employee." << std::endl;
	return false;
}

bool EMS::modifyInfo(std::vector<Employee*>& employees) {  //按照编号修改员工信息
	if (employees.empty()) {
		std::cout << "No data to modify." << std::endl;
		return false;
	}
	int IDin;
	std::cout << "Please enter the ID of the employee you want to modify: ";
	std::cin >> IDin;
	for (auto it = employees.begin(); it != employees.end(); ++it) {
        if ((*it)->getDeptID() == IDin) {
			std::string name;
			int age;
			int deptID;
			std::string jobTitle;
			std::cout << "Please enter the employee's name: ";
			std::cin >> name;
			std::cout << "Please enter the employee's age: ";
			std::cin >> age;
			std::cout << "Please enter the employee's ID: ";
			std::cin >> deptID;
			std::cout << "Please enter the employee's job title: ";
			std::cin >> jobTitle;
			(*it) = new Employee(name, age, deptID, jobTitle);
			std::cout << "Employee modified." << std::endl;
			return true;
		}
	}
    std::cout << "Cannot find the employee." << std::endl;
	return false;
}

bool EMS::query(std::vector<Employee*>& employees) {  //按照编号或姓名查询员工信息
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
		}
		else {
			break;
		}
	}
    switch (choice) {
    case 1: {if (employees.empty()) {
        std::cout << "No data to query." << std::endl;
        return false;
    }
          int IDin;
          std::cout << "Please enter the ID of the employee you want to query: ";
          std::cin >> IDin;
          for (auto it = employees.begin(); it != employees.end(); ++it) {
              if ((*it)->getDeptID() == IDin) {
                  printTableHead();
                  (*it)->display();
                  return true;
              }
          }
          std::cout << "Cannot find the employee." << std::endl;
          return false;
    }
    case 2: {if (employees.empty()) {
        std::cout << "No data to query." << std::endl;
        return false;
    }
          std::string namein;
          std::cout << "Please enter the name of the employee you want to query: ";
          std::cin >> namein;
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
}

bool compare(Employee* a, Employee* b) {
    return a->getDeptID() > b->getDeptID();
}

bool EMS::sortData(std::vector<Employee*>& employees){        //按照编号排序
        if (employees.empty()) {
            std::cout << "No data to sort." << std::endl;
            return false;
        }
        int choice;
        std::cout << "Please select a function: " << std::endl;
        std::cout << "1.Ascending order" << std::endl;   //升序排序
        std::cout << "2.Descending order" << std::endl;  //降序排序
        while (true) {
            std::cin >> choice;
            if (choice < 1 || choice > 2 || std::cin.fail()) {
                std::cout << "Invalid input. Please try again: ";
                std::cin.clear();
                std::cin.ignore(32767, '\n');
            }
            else {
                break;
            }
        }
        switch (choice) {
        case 1: {   //升序排序
            std::sort(employees.begin(), employees.end());
            return true;
            }
        case 2: {   //降序排序
        std::sort(employees.begin(), employees.end(), compare);
        return true;
        }
        default: break;
     }
}

bool EMS::clearAllData(std::vector<Employee*>& employees) {    //清空所有数据
	std::cout << "Are you sure you want to clear all data? (y/n) ";   //再次确认防止误操作
	char choice;
	std::cin >> choice;
	if (choice == 'y') {
		for (auto it = employees.begin(); it != employees.end(); ++it) {
			delete* it;
		}
		std::cout << "All data cleared." << std::endl;
		return true;
	}
	return false;
}

bool EMS::exit() {  //////////////////////////////////////////////////////////
	return true;
};  //退出程序

bool EMS::saveData(std::vector<Employee*>& employees) {  //保存数据
	std::ofstream ofs("Employees.txt");
	if (!ofs) {
		std::cout << "Failed to save data." << std::endl;
		return false;
	}
	for (const auto& employee : employees) {
		ofs << employee->getName() << " " << employee->getAge() << " "
			<< employee->getDeptID() << " " << employee->getJobTitle() << std::endl;
	}
	ofs.close();
	std::cout << "Data saved." << std::endl;
	return true;
}