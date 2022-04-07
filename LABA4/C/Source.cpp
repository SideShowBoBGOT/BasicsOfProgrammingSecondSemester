#include<iostream>
#include"Header.h"
using namespace std;
Data::Month::Month() {}
Data::Month::Month(string name, int number, int days) {
    this->number = number;
    this->days = days;
}
void Data::Update() {
    if (this->day > this->month.days) {
        this->day = 1;
        this->month.number++;
    }
    if (this->month.number > 12) {
        this->month = months[0];
        this->year++;
    }
    this->month = months[this->month.number - 1];
    if (this->month.number == 2 && IsFourth(year)) {
        this->month.days %= 100;
    }
    if (this->month.number == 2 && !IsFourth(year)) {
        this->month.days /= 100;
    }
}
Data::Data() {
    this->day = 6;
    this->month = months[0];
    this->year = 1;
}
Data::Data(int year) {
    this->day = 1;
    this->month = months[0];
    this->year = year;
}
Data::Data(int day, int month, int year) {
    this->day = day;
    this->month = months[month - 1];
    if (month == 2 && IsFourth(year)) {
        this->month.days %= 100;
    }
    if (month == 2 && !IsFourth(year)) {
        this->month.days /= 100;
    }
    this->year = year;
}
int Data::GetDay() {
    return this->day;
}
int Data::GetMonth() {
    return this->month.number;
}
int Data::GetYear() {
    return this->year;
}
bool Data::IsFourth(int year) {
    bool res = 0;
    if (year % 4 == 0 || (year % 100 == 0 && year % 400 == 0)) {
        res = 1;
    }
    return res;
}
Data& Data::operator++() {
    this->month.number++;
    this->Update();
    return *this;
}
Data Data::operator++(int) {
    this->day++;
    this->Update();
    return *this;
}
bool Data::operator >(const Data& d) {
    bool res = 0;
    if (this->year > d.year) {
        res = 1;
    }
    else if (this->year == d.year) {
        if (this->month.number > d.month.number) {
            res = 1;
        }
        else if (this->month.number == d.month.number) {
            if (this->day > d.day) {
                res = 1;
            }
        }
    }
    return res;
}
int Data::RestDays() {
    int total_days = (IsFourth(this->year)) ? 366 : 365;
    int days_passed = 0;
    for (int i = 0; i < this->month.number; i++) {
        if (i == 1) {
            int feb_days = (IsFourth(this->year)) ? 29 : 28;
            days_passed += feb_days;
        }
        else {
            days_passed += months[i].days;
        }
    }
    return total_days - days_passed;
}