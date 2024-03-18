#pragma once
#include <iostream>
#include <vector>

class Employee
{
private:
	// zmiana wynagrodzenia odbywa sie tylko przez zewnetrzna funkcje ChangeSalary, ktora weryfikuje uprawnienia
	void SetSalary(unsigned int wyplata);

protected:
	// zlicza obiekty klas pochodnych
	static int number_instance;

	std::string m_Name;
	std::string m_Surname;
	std::string m_Password;

	unsigned int m_Salary;

	// kazdy pracownik ma pewien kod ktory nadaje mu odpowiednie uprawnienia, im wyzszy tym ma wieksze
	// ustawiam go przy wywylowaniu konstruktora biezacej klasy w konstrkutorach klas pochodnych (na sztywno dla danej klasy) 
	unsigned int m_acces_level;

	// unikalny identyfikator kazdego uzytkownika - domyslnie jego numer powstania (uwaga na dublowanie przy kasowaniu obiektow)
	const int m_Id;

public:
	// kontener z wskaznikami na wszystkie obiekty klasy pochodnej, bardzo przydatne, kazdy obiekt dziedziczacy z klasy employee w swoim konstruktorze sie tam dopisuje
	static std::vector<Employee*> employees;

	// konstruktor 
	Employee(const std::string& imie, const std::string& nazwisko, const std::string& haslo, unsigned int wyplata, unsigned int dostep);

	//---------------------------------------------------------------------------------------
	// pola virtualne - zachowanie w zaleznosci od specyfiki klas pochodnych

	// drukuje informajce o konkretnym obiekcie
	virtual void IntroduceYourself() const = 0;

	// o wszystkich obiektach danej klasy pochodnej
	virtual void PrintClassObjects() const = 0;
	//---------------------------------------------------------------------------------------
	//drukuje wszystkie obiekty z kontenera employees
	void PrintRelatives() const;

	// zwraca wskaznik do osoby o szukanym id, gdy nie znajdzize zwraca nullptr
	Employee* FindByID(unsigned int) const;
	//zwraca id obiektu 
	unsigned int GetId() const;

	// deklaracje przyjaüni
	friend void ChangeSalary(Employee& applicant, Employee& target, unsigned int new_salary);
	friend void ChangeSalary(Employee& applicant);
};

// Poziomy dostepu:
// 0 nieproszony gosc
// 1 intern
// 2 manager

