#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"
#include<string>

class Manager : public Employee {
private:
  double bonus;

public:
  // Create a new manager with a bonus
  Manager(string theName, double theWage, double theHours, double theBonus);

  // Redefined calcPay to include bonus
  double calcPay() const;
};

#endif // MANAGER_H
