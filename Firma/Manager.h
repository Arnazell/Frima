#pragma once
#include "Manager.h"
#include "Employee.h"
#include <vector>


class Manager : public Employee
{
private:
	unsigned int m_Subordinate_Count;
public:
	Manager(const std::string& imie, const std::string& nazwisko, const std::string& haslo, unsigned int wyplata, unsigned int podwladni);

	virtual void IntroduceYourself() const override;

	virtual void PrintClassObjects() const override;
	// zmienne statyczne - wspolne dla kazdego obiektu klasy (definicje)
	// kontener z wskaznikami na obiekty klasy Employee: kazdy obiekt w konstruktorze sie tam dopisuje
	static std::vector<Manager*> managers;
};