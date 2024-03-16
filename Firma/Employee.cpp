#include "Employee.h"

Employee::Employee(const std::string& imie, const std::string& nazwisko, const std::string& haslo, unsigned int wyplata, unsigned int dostep)
	: m_Name(imie), m_Surname(nazwisko), m_Salary(wyplata), m_acces_level(dostep)
{

}

void Employee::SetSalary(unsigned int wyplata)
{
	m_Salary = wyplata;
}
