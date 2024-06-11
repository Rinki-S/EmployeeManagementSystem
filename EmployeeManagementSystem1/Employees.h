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
    int m_age;
    int m_deptID;
    std::string m_jobTitle;

public:
    Employee(std::string name, int age, int deptID, std::string jobTitle)
        : m_name(name), m_age(age), m_deptID(deptID), m_jobTitle(jobTitle) {}
    ~Employee() = default;
    virtual void display() const {
        std::cout << std::left << std::setw(15) << "Employee" << std::setw(15)
                  << m_name << std::setw(15) << m_age << std::setw(15)
                  << m_deptID << std::setw(15) << m_jobTitle << std::endl;
    }
	int getDeptID(){ return m_deptID; }     //获取编号
	std::string getName() { return m_name; } //获取姓名
	int getAge() { return m_age; }           //获取年龄
	std::string getJobTitle() { return m_jobTitle; } //获取职位
};

class Manager : public Employee
{
public:
    Manager(std::string name, int age, int deptID, std::string jobTitle)
        : Employee(name, age, deptID, jobTitle) {}
    ~Manager() = default;
    void display() const override {
        std::cout << std::left << std::setw(15) << "Manager";
        Employee::display();
    }
};

class GeneralManager : public Manager
{
public:
    GeneralManager(std::string name, int age, int deptID, std::string jobTitle)
        : Manager(name, age, deptID, jobTitle) {}
    ~GeneralManager() = default;
    void display() const override {
        std::cout << std::left << std::setw(15) << "GeneralManager";
        Manager::display();
    }
};

#endif  // EMPLOYEES_H