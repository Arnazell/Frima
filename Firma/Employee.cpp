#include "Employee.h"

// zmienne statyczne - definicje
int Employee::number_instance = 0;
std::vector<Employee*> Employee::employees;

Employee::Employee(const std::string& imie, const std::string& nazwisko, const std::string& haslo, unsigned int wyplata, unsigned int dostep)
	: m_Name(imie), m_Surname(nazwisko), m_Salary(wyplata), m_acces_level(dostep), m_Id(number_instance+1)
{
	number_instance++;
	Employee::employees.push_back(this);
	//IMPLEMENTUJ : szyfrowanie hasla
}

void Employee::PrintRelatives() const
{
	for (Employee* employee : Employee::employees)
	{
		employee->IntroduceYourself();
	}
}

Employee* Employee::FindByID(unsigned int id) const
{
	for (Employee* employee : Employee::employees)
	{
		if (employee->GetId() == id)
			return employee;
	}
	return nullptr;
}

unsigned int Employee::GetId() const
{
	return m_Id;
}

void Employee::SetSalary(unsigned int wyplata)
{
	m_Salary = wyplata;
}
