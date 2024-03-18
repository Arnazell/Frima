#pragma once
#include <vector>
#include "Intern.h"
#include "Employee.h"

class Intern : public Employee
{
public:
	Intern(const std::string& imie, const std::string& nazwisko, const std::string& haslo, unsigned int wyplata);

	virtual void IntroduceYourself() const override;

	virtual void PrintClassObjects() const override;

	// zmienne statyczne - wspolne dla kazdego obiektu klasy (deklaracja)
	// kontener z wskaznikami na obiekty klasy Employee: kazdy obiekt w konstruktorze sie tam dopisuje
	static std::vector<Intern*> interns;
};