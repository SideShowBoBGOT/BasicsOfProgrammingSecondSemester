#include <iostream>
#include"Header.h"
using namespace std;
int main()
{
    int year1 = 0;
    int month1 = 0;
    int day1 = 0;

    int year2 = 0;
    int month2 = 0;
    int day2 = 0;

    int year3 = 0;
    int month3 = 0;
    int day3 = 0;

    cout << "Enter year1: ";
    cin >> year1;
    cin.ignore();

    cout << "Enter month1: ";
    cin >> month1;
    cin.ignore();

    cout << "Enter day1: ";
    cin >> day1;
    cin.ignore();

    cout << "Enter year2: ";
    cin >> year2;
    cin.ignore();

    cout << "Enter month2: ";
    cin >> month2;
    cin.ignore();

    cout << "Enter day2: ";
    cin >> day2;
    cin.ignore();

    cout << "Enter year3: ";
    cin >> year3;
    cin.ignore();

    cout << "Enter month3: ";
    cin >> month3;
    cin.ignore();

    cout << "Enter day3: ";
    cin >> day3;
    cin.ignore();

    Data d1 = Data(day1, month1, year1);
    Data d2 = Data(day2, month2, year2);
    Data d3 = Data(day3, month3, year3);

    cout << "D1:" << endl;
    cout << "\tYear: " << d1.GetYear()
        << "\tMonth: " << d1.GetMonth()
        << "\tDay: " << d1.GetDay() << endl;
    ++d1;

    cout << "D1:" << endl;
    cout << "\tYear: " << d1.GetYear()
        << "\tMonth: " << d1.GetMonth()
        << "\tDay: " << d1.GetDay() << endl;

    cout << "D2:" << endl;
    cout << "\tYear: " << d2.GetYear()
        << "\tMonth: " << d2.GetMonth()
        << "\tDay: " << d2.GetDay() << endl;

    d2++;

    cout << "D2:" << endl;
    cout << "\tYear: " << d2.GetYear()
        << "\tMonth: " << d2.GetMonth()
        << "\tDay: " << d2.GetDay() << endl;
    
    cout << "D1>D2?: " << (d1 > d2) << endl;

    cout << "D3 Rest: " << d3.RestDays() << endl;

    system("pause");
    return 0;
}


