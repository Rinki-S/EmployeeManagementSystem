#include "Employees.h"

bool compare(Employee *a, Employee *b) {
    return a->getDeptID() > b->getDeptID();
}