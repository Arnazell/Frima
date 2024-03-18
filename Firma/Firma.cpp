#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "Employee.h"
#include "Intern.h"
#include "Manager.h"


using namespace std; 


// drukowanie menu w przypadku gdy user jest zalogowany
void PrintMenuLogged(Employee& logged)
{
    cout << "------------------------------------------------------------------------" << std::endl;
    cout << "Zalogowano jako: " << std::endl;
    logged.IntroduceYourself();
    cout << "------------------------------------------------------------------------" << std::endl << std::endl;
    cout << "1: " << "Przedstaw mnie" << std::endl;
    cout << "2: " << "Przedstaw osoby o tej samej randze" << std::endl;
    cout << "3: " << "Przedstaw wszystkich" << std::endl;
    cout << "4: " << "Zmien konus wyplate" << std::endl;
    cout << "5: " << "Zakoncz program" << std::endl << std::endl;
}

// funkcja zgodna z zadaniem, moze sie przydac
void ChangeSalary(Employee& applicant, Employee& target, unsigned int new_salary)
{
    // gdy user proboje sobie zmienic sam wyplate
    if (&applicant == &target)
    {
        cout << "Nie mozna zmienic sobie samemu wynagrodzenia!!" << std::endl;
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

// przeciazona funkcja obslugujaca pobranie danych uzytkownika ktoremu zmieniamy wyplate i jej wysokosci
void ChangeSalary(Employee& applicant)
{
    Employee* target = NULL;
    unsigned int new_salary,  id;

    while(true)
    {
        
        cout << "Podaj id Osoby ktorej chcesz zmienic wyplate: ";
        cin >> id;
  
        cout << endl << "Podaj kwote ktora ta osoba powinna zarabiac: ";
        cin >> new_salary;
        // sytuacja sie sypie gdy ktos wprowadzi liczbe ujemna: ale ogarniemy nastepnym razem...
       
        // jedyne 10 linijek o ktorych wiem tylko ze chyba dzialaja
        if (std::cin.fail())
        {
            cin.clear(); // resetuje stan strumienia
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // usuwa nieprawidłowe dane ze strumienia
            cout << endl << "Wprowadzono nieprawidlowe dane. Prosze wprowadzic liczbe calkowita.\n";
        }
        else
            break;
    }

    // jak sie nie ma co sie lubi to sie lubi co sie ma;;((
    target = target->FindByID(id);
    // jesli znaleziono osobe
    if (target)
    {
        // gdy user proboje sobie zmienic sam wyplate
        if (&applicant == target)
        {
            cout << "Nie mozna zmienic sobie samemu wynagrodzenia!!" << std::endl;
        }
        else
        {
            // gdy nie ma uprawnien
            if (applicant.m_acces_level >= 2)
            {
                target->SetSalary(new_salary);
            }
            else
                cout << "Nie masz uprawnien!" << std::endl;
        }
    }
    else
    {
        cout << "Nie znaleziono takiej osoby" << std::endl;
    }
}

int main()
{
    //-------------------------------------------------------------------------------------------------------------
    // inicjacja do testow
    //-------------------------------------------------------------------------------------------------------------
    Manager m1("Jan", "Brzeczyszczykiewicz", "1234", 70000, 0);
    Manager m2("Rafal", "Trela", "1234", 1000, 0);
    Manager m3("Rafal", "Trela", "1234", 1000, 0);
    Manager m4("Rafal", "Trela", "1234", 1000, 0);
    Manager m5("Rafal", "Trela", "1234", 1000, 0);
    Intern i1("Halina", "Duc", "1234", 2200);
    Intern i2("Maciej", "Dobrzynski", "1234", 3600);


    //-------------------------------------------------------------------------------------------------------------
    // menu
    //-------------------------------------------------------------------------------------------------------------
    enum menu { PrzedstawMnie = 1, PrzedstawRange, PrzedstawWszystkich, ZmienWyplate, Koniec };
    bool run = true;
    
    // domyslnie powinno byc null - logowanie odbyloby sie w petli
    Employee* logged = &m1;

    // nie mam pomyslu jak ogarnac menu wiec ta flaga pomaga mi w tym aby funckja printmenulooged nie byla wywolywana dwa razy 
    bool FirstDisplay = true;
    int wybor;

    // glowna petla programu
    while (run)
    {
        if (logged) 
        {
            // gdy zaczynamy z pusta konsola musimy wydrukowac menu
            if (FirstDisplay)
            {
                PrintMenuLogged(*logged);
                FirstDisplay = false;
            }
            // wybor uzytkownika
            cout << "Wybierz opcje: ";
            cin >> wybor;
   
            // gdy mamy dane to czyscimy konsole i drukujemy menu + efekt wybranego dzialania
            system("cls");
            PrintMenuLogged(*logged);
            switch (wybor)
            {
            case PrzedstawMnie: {logged->IntroduceYourself(); break; }
            case PrzedstawRange: {logged->PrintClassObjects(); break;  }
            case PrzedstawWszystkich: {logged->PrintRelatives();  break; }
            case ZmienWyplate: {ChangeSalary(*logged);  break; }
            case Koniec: {run = false;  break; }
            }

        }
        else
        {
            unsigned int id;
            string haslo;
            cout << "Nie jestes zalogowany!" << std::endl;
            cout << "Podaj id: " << std::endl;
            cin >> id;
            cout << "Podaj haslo: " << std::endl;
            cin >> haslo;
        }
    }
    }
