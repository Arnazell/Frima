#pragma once
#include "Intern.h"
#include "Employee.h"

class Intern : public Employee
{
public:
	Intern(const std::string& imie, const std::string& nazwisko, const std::string& haslo, unsigned int wyplata);

	virtual void IntroduceYourself() const override;
};