#include "Manager.h"

// zmienne statyczne - definicje
std::vector<Manager*> Manager::managers;

Manager::Manager(const std::string& imie, const std::string& nazwisko, const std::string& haslo, unsigned int wyplata, unsigned int podwladni)
	: Employee(imie, nazwisko, haslo, wyplata, 2), m_Subordinate_Count(podwladni)
{
	managers.push_back(this);
}

void Manager::IntroduceYourself() const
{
	std::cout <<"ID: " << m_Id << " Hej, tu manager " << m_Name << " " << m_Surname << " Zarabiam: " << m_Salary << " zl" << std::endl;
}

void Manager::PrintClassObjects() const
{
	for (Manager* manager : managers)
	{
		manager->IntroduceYourself();
	}
}
