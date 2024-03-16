#include "Manager.h"

Manager::Manager(const std::string& imie, const std::string& nazwisko, const std::string& haslo, unsigned int wyplata, unsigned int podwladni)
	: Employee(imie, nazwisko, haslo, wyplata, 2), m_Subordinate_Count(podwladni)
{
}

void Manager::IntroduceYourself() const
{
	std::cout << "Hej, tu manager " << m_Name << " " << m_Surname << "Zarabiam: " << m_Salary << " zl" << std::endl;
}
