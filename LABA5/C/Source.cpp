#include <iostream>
#include<vector>
#include<algorithm>
#include"Header.h"
using namespace std;
TDate::Month::Month(){}
TDate::Month::Month(string name, int number, int days) {
    this->number = number;
    this->days = days;
}
bool TDate::IsFourth(int year) {
    bool res = 0;
    if (year % 4 == 0 || (year % 100 == 0 && year % 400 == 0)) {
        res = 1;
    }
    return res;
}
int TDate::GetDays(int year, int month) {
    int daysmonth = months[month - 1].days;
    if (months[month - 1].number == 2 && IsFourth(year)) {
        daysmonth = 29;
    }
    return daysmonth;
}
TDate::TDate() {
    this->day = 1;
    this->month = months[0].number;
    this->year = 1;
}
TDate::TDate(int day, int month, int year) {
    this->day = day;
    this->month = months[month - 1].number;
    this->year = year;
}
int TDate::GetDay() {
    return this->day;
}
int TDate::GetMonth() {
    return this->month;
}
int TDate::GetYear() {
    return this->year;
}
TDate& TDate::operator+=(int value) {
    this->day += value;
    while (this->day > GetDays(this->year, this->month)) {
        this->day -= GetDays(this->year, this->month);
        this->month++;
        if (this->month > 12) {
            this->year++;
            this->month = months[0].number;
        }
    }
    return *this;
}
TDate& TDate::operator-=(int value)
{
    this->day -= value;
    while (this->day <= 0) {
        this->month--;
        if (this->month == 0) {
            this->year--;
            this->month = months[11].number;
        }
        this->day += GetDays(this->year, this->month);
    }
    return *this;
}
bool TDate::operator >(const TDate& d) const {
    bool res = 0;
    if (this->year > d.year) {
        res = 1;
    }
    else if (this->year == d.year) {
        if (this->month > d.month) {
            res = 1;
        }
        else if (this->month == d.month) {
            if (this->day > d.day) {
                res = 1;
            }
        }
    }
    return res;
}
bool TDate::operator ==(const TDate& d) const {
    return (this->day == d.day && this->month == d.month && this->year == d.year);
}
bool TDate::operator<(const TDate& d) const
{
    if ((!(*this > d) && !(*this == d))) {
        return true;
    }
    return false;
}
bool TDate::operator>=(const TDate& d) const
{
    if ((*this == d) || (*this > d)) {
        return true;
    }
    return false;
}
bool TDate::operator<=(const TDate& d) const
{
    if ((*this == d) || (*this < d)) {
        return true;
    }
    return false;
}
bool TDate::operator!=(const TDate& d) const
{
    if (!(*this == d)) {
        return true;
    }
    return false;
}
string TDate::date_string() {
    char buf[255];
    string date_str;
    sprintf_s(buf, "%d:", this->day);
    if (this->day < 10)
        date_str += "0";
    date_str += buf;
    sprintf_s(buf, "%d:", this->month);
    if (this->month < 10)
        date_str += "0";
    date_str += buf;
    sprintf_s(buf, "%d", this->year);
    if (this->year < 1000) {
        int temp = this->year;
        while (temp < 1000) {
            temp *= 10;
            date_str += "0";
        }
    }
    date_str += buf;
    return date_str;
}
bool TDate::TDateComparator(TDate* d1, TDate* d2) {
    return *d1 < *d2;
}
string TDate1::date_string() {
    char buf[255];
    string date_str;
    sprintf_s(buf, "%d.", this->day);
    if (this->day < 10)
        date_str += "0";
    date_str += buf;
    sprintf_s(buf, "%d.", this->month);
    if (this->month < 10)
        date_str += "0";
    date_str += buf;
    sprintf_s(buf, "%d", this->year);
    if (this->year < 1000) {
        int temp = this->year;
        while (temp < 1000) {
            temp *= 10;
            date_str += "0";
        }
    }
    date_str += buf;
    return date_str;
}
string TDate2::date_string() {
    char buf[255];
    string date_str;
    sprintf_s(buf, "%d-", this->month);
    if (this->month < 10)
        date_str += "0";
    date_str += buf;
    sprintf_s(buf, "%d-", this->day);
    if (this->day < 10)
        date_str += "0";
    date_str += buf;
    sprintf_s(buf, "%d", this->year);
    if (this->year < 1000) {
        int temp = this->year;
        while (temp < 1000) {
            temp *= 10;
            date_str += "0";
        }
    }
    date_str += buf;
    return date_str;
}
void EnterArgs(int& day, int& month, int& year) {
    cout << "Enter year: ";
    cin >> year;
    cin.ignore();

    cout << "Enter month: ";
    cin >> month;
    cin.ignore();

    cout << "Enter day: ";
    cin >> day;
    cin.ignore();
}