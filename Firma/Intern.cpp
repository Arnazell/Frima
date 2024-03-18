#include "Intern.h"
#include "Employee.h"

// zmienne statyczne - definicje
std::vector<Intern*> Intern::interns;

// korzystamy z konstruktora klasy bazowej
Intern::Intern(const std::string& imie, const std::string& nazwisko, const std::string& haslo, unsigned int wyplata)
	: Employee(imie, nazwisko, haslo, wyplata, 1)
{
	interns.push_back(this);
}

void Intern::IntroduceYourself() const
{
	std::cout << "ID: " << m_Id <<" Hej, tu starzysta " << m_Name << " " << m_Surname << " Zarabiam: " << m_Salary << " zl" << std::endl;
}

void Intern::PrintClassObjects() const
{
	for (Intern* intern : interns)
	{
		intern->IntroduceYourself();
	}
}
