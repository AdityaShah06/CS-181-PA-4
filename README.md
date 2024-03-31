#include <iostream>
#include <iomanip>
#include "Manager.h"

using namespace std;

int main() {
  int numManagers;

  cout << "Enter number of managers: ";
  cin >> numManagers;

  
  Manager* managers[100];                       // Creating Array of pointers to Manager objects

  
  for (int i = 0; i < numManagers; ++i) {      // Reading information for each manager
    char* name;
    double wage, hours, bonus;

    cin.ignore();
    cout << "\nEnter manager " << i << " name: ";
    cin.getline(name, 100);

    cout << "Enter manager " << i << " hourly wage: ";
    cin >> wage;

    cout << "Enter manager " << i << " hours worked: ";
    cin >> hours;

    cout << "Enter manager " << i << " bonus: ";
    cin >> bonus;

   
    managers[i] = new Manager(name, wage, hours, bonus);           // Dynamically creating a manager object
  }

  
  double highestPay = 0.0;                                      // Find highest paid manager and total pay
  string highestPaidName;
  double totalPay = 0.0;
  for (int i = 0; i < numManagers; ++i) {
    double managerPay = managers[i]->calcPay();
    totalPay += managerPay;

    if (managerPay > highestPay) {
      highestPay = managerPay;
      highestPaidName = managers[i]->getName();
    }
  }

  
  double averagePay = totalPay / numManagers;                  // Calculating average pay

  
  cout << fixed << setprecision(2);
  cout << "\nHighest paid manager is " << highestPaidName << " who is paid $" << highestPay << endl;
  cout << "Average pay is $" << averagePay << endl;

  
  for (int i = 0; i < numManagers; ++i) {                // Deallocating memory for manager objects
    delete managers[i];
  }

  return 0;
}
