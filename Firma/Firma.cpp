#include <iostream>
#include "Employee.h"
#include "Intern.h"
#include "Manager.h"

void ChangeSalary(Employee& applicant, Employee& target, unsigned int new_salary)
{
    // gdy user proboje sobie zmienic sam wyplate
    if (&applicant == &target)
    {
        std::cout << "Nie mozna zmienic sobie samemu wynagrodzenia!!" << std::endl;
    }
    else
    {
        // gdy nie ma uprawnien
        if (applicant.m_acces_level >= 2)
        {
            target.SetSalary(new_salary);
        }
        else
            std::cout << "Nie masz uprawnien!" << std::endl;
    }
}

int main()
{
    // inicjacja do testow
    Manager m1("Jan", "Brzeczyszczykiewicz", "1234", 70000, 0);
    Manager m2("Rafal", "Trela", "1234", 1000, 0);
    Intern i1("Halina", "Duc", "1234", 2200);
    Intern i2("Maciej", "Dobrzynski", "1234", 3600);

    // przedstanienia sie
    m1.IntroduceYourself();
    m2.IntroduceYourself();

    // testowanie funkcji zmieniania wyplat
    ChangeSalary(m1, m2, 2000);
    m2.IntroduceYourself();

    ChangeSalary(m1, m1, 3000);
    ChangeSalary(i1, i2, 2000);

}
