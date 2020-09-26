#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>

using String = std::string;
class Employee {
private:
	String  m_FirstName, m_LastName, m_SocialSecurityNumber;
public:
	Employee() : m_FirstName(""), m_LastName(""), m_SocialSecurityNumber("")
	{ }
	Employee(String f, String l, String ssn) : m_FirstName(f), m_LastName(f), m_SocialSecurityNumber(ssn)
	{ }
	virtual double  earnings() = 0;
	virtual void print() const {
		std::cout << "OKE" << std::endl;
	}
};
class SalariedEmployee : public Employee {
private:
	double m_WeeklySalary;
public:
	SalariedEmployee() : m_WeeklySalary(0) { }
	SalariedEmployee(String f, String l, String ssn, double sws) 
		: Employee(f, l, ssn), m_WeeklySalary(0)
	{ }
	void setWeeklySalary( int sws) { m_WeeklySalary = sws;  }
	int getWeeklySalary() { return m_WeeklySalary; }
	double  earnings() { return m_WeeklySalary; }
};
class CommissionEmployee : public Employee {
private:
	double m_GrossSales, m_CommissionRate;
public:
	CommissionEmployee() 
		: m_GrossSales(0), m_CommissionRate(0)
	{ }
	CommissionEmployee(String f, String l, String ssn, double gross, double commission)
		: Employee(f, l, ssn), m_GrossSales(gross), m_CommissionRate(commission)
	{ }
	void setGrossSales(double w) { m_GrossSales = w; }
	void setCommissionRate(double c) { m_CommissionRate = c; }
	double getGrossSales() { return m_GrossSales; }
	double getCommissionRate() { return m_CommissionRate; }
	double  earnings() { return m_GrossSales; }
};
class HourlyEmployee : public Employee {
private:
	double  m_Wage, m_Hours;
public:
	HourlyEmployee() 
		: m_Wage(0), m_Hours(0)
	{ }
	HourlyEmployee(String f, String l, String ssn, double wage , double hours )
		: Employee(f, l, ssn), m_Wage(wage), m_Hours(hours)
	{ }
	void setWage(double w) { m_Wage = w;  }
	void setHours(double h) { m_Hours = h; }
	double getWage() { return m_Wage; }
	double getHours() { return m_Hours; }
	double  earnings() { return m_Wage; }
};
class BasePlusCommissionEmployee : public CommissionEmployee {
private:
	double m_BaseSalary;
public:
	BasePlusCommissionEmployee() : m_BaseSalary(0){ }
	BasePlusCommissionEmployee(String f, String l, String ssn, double gross, double commission, double bs) 
		: CommissionEmployee(f, l, ssn, gross, commission), m_BaseSalary(bs) { }
	void setBaseSalary(double base) {
		m_BaseSalary = base;
	}
	double getBaseSalary() { return m_BaseSalary;  }
};


int main() {
	std::vector < Employee* > employees(4);
	employees[0] = new SalariedEmployee("John", "Smith", "111-11-1111", 800.00);
	employees[1] = new CommissionEmployee("Sue", "Jones", "222-22-2222", 10000, 0.06);
	employees[2] = new BasePlusCommissionEmployee("Bob", "Lewis", "333-33-3333", 300, 5000, 0.04);
	employees[3] = new HourlyEmployee("Karen", "Price", "444-44-4444", 16.75, 40);

	for (int i = 0; i < employees.size(); i++) {
		employees[i]->print();
		BasePlusCommissionEmployee* commissionPtr = dynamic_cast <BasePlusCommissionEmployee*> (employees[i]);
		if (commissionPtr != 0) { 
			std::cout << "Old base salary: $" << commissionPtr->getBaseSalary() << std::endl;          
			commissionPtr->setBaseSalary(1.10 * commissionPtr->getBaseSalary());
			std::cout << "New base salary with 10% increase is: $" << commissionPtr->getBaseSalary() << std::endl; 
		}
		std::cout << "earned $" << employees[i]->earnings() << std::endl;
	}
	for (int j = 0; j < employees.size(); j++) {
		std::cout << "\ndeleting object of " << typeid(*employees[j]).name();       
		delete employees[j];
	}
	std::cin.get();
}
