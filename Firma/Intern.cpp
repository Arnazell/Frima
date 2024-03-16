#include "Intern.h"
#include "Employee.h"


// korzystamy z konstruktora klasy bazowej
Intern::Intern(const std::string& imie, const std::string& nazwisko, const std::string& haslo, unsigned int wyplata)
	: Employee(imie, nazwisko, haslo, wyplata, 1)
{
}

void Intern::IntroduceYourself() const
{
	std::cout << "Hej, tu starzysta " << m_Name << " " << m_Surname << "Zarabiam: " << m_Salary << " zl" << std::endl;
}
