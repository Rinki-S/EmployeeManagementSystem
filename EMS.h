#ifndef EMS_H
#define EMS_H

#include <string>
#include <vector>
#include "Employees.h"
class EMS
{
public:
    EMS(){};
    ~EMS(){};
    void printMenu();
    void printTableHead();
    int selectFunction(std::vector<Employee *> &employees);
    bool addEmployee(std::vector<Employee *> &employees);
    bool displayInfo(std::vector<Employee *> &employees);
    bool removeEmployee(std::vector<Employee *> &employees);
    bool modifyInfo(std::vector<Employee *> &employees);
    bool query(std::vector<Employee *> &employees);
    bool sortData(std::vector<Employee *> &employees);
    bool clearAllData(std::vector<Employee *> &employees);
    bool exit(std::vector<Employee *> &employees);
    bool saveData(std::vector<Employee *> &employees);
    bool readData(std::vector<Employee *> &employees);
    std::string inputName();
    int inputID();
    int inputDeptID();
    std::string inputJobTitle();
};

#endif  // EMS_H