#pragma once
#include <iostream>
class Employee
{
private:
	// zmiana wynagrodzenia odbywa sie tylko przez zewnetrzna funkcje ChangeSalary, ktora weryfikuje uprawnienia
	void SetSalary(unsigned int wyplata);

protected:
	std::string m_Name;
	std::string m_Surname;
	std::string m_Password;

	unsigned int m_Salary;
	// kazdy pracownik ma pewien kod ktory nadaje mu odpowiednie uprawnienia, im wyzszy tym ma wieksze
	// ustawiam go przy wywylowaniu konstruktora biezacej klasy w konstrkutorach klas pochodnych (na sztywno dla danej klasy) 
	unsigned int m_acces_level;

public:
	// konstruktor (haszuje haslo)
	Employee(const std::string& imie, const std::string& nazwisko, const std::string& haslo, unsigned int wyplata, unsigned int dostep);

	// metody virtualne - zachowanie w zaleznosci od specyfiki klas pochodnych
	virtual void IntroduceYourself() const = 0;

	// deklaracje przyjaüni
	friend void ChangeSalary(Employee& applicant, Employee& target, unsigned int new_salary);
};

// Poziomy dostepu:
// 0 nieproszony gosc
// 1 intern
// 2 manager

