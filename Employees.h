#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include <ios>
#include <iostream>
#include <ostream>
#include <string>
#include <iomanip>

class Employee
{
private:
    std::string m_name;
    int m_id;
    int m_deptID;
    std::string m_jobTitle;

public:
    Employee(std::string name, int id, int deptID, std::string jobTitle)
        : m_name(name), m_id(id), m_deptID(deptID), m_jobTitle(jobTitle) {}
    ~Employee() = default;
    virtual void display() const {
        std::cout << std::left << std::setw(15) << "Employee" << std::setw(15)
                  << m_name << std::setw(15) << m_id << std::setw(15)
                  << m_deptID << std::setw(15) << m_jobTitle << std::endl;
    }
    int getDeptID() {
        return m_deptID;
    }
    std::string getName() {
        return m_name;
    }
    int getId() {
        return m_id;
    }
    std::string getJobTitle() {
        return m_jobTitle;
    }
};

class Manager : public Employee
{
public:
    Manager(std::string name, int id, int deptID, std::string jobTitle)
        : Employee(name, id, deptID, jobTitle) {}
    ~Manager() = default;
    void display() const override {
        std::cout << std::left << std::setw(15) << "Manager";
        Employee::display();
    }
};

class GeneralManager : public Manager
{
public:
    GeneralManager(std::string name, int id, int deptID, std::string jobTitle)
        : Manager(name, id, deptID, jobTitle) {}
    ~GeneralManager() = default;
    void display() const override {
        std::cout << std::left << std::setw(15) << "GeneralManager";
        Manager::display();
    }
};

#endif  // EMPLOYEES_H