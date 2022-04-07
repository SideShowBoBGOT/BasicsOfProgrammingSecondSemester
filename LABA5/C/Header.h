#pragma once
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class TDate {
protected:
    class Month {
    public:
        int number;
        int days;
        string name;
        Month();
        Month(string name, int number, int days);
    };
    Month months[12] = {
        Month("January", 1, 31),
        Month("February", 2, 28),
        Month("March", 3, 31),
        Month("April", 4, 30),
        Month("May", 5, 31),
        Month("June", 6, 30),
        Month("July", 7, 31),
        Month("August", 8, 31),
        Month("September", 9, 30),
        Month("October", 10, 31),
        Month("November", 11, 30),
        Month("December", 12, 31),
    };

    int day;
    int month;
    int year;

    static bool IsFourth(int year);
    int GetDays(int year, int month);
public:
    TDate();
    TDate(int day, int month, int year);
    int GetDay();
    int GetMonth();
    int GetYear();
    TDate& operator+=(int value);
    TDate& operator-=(int value);
    bool operator >(const TDate& d) const;
    bool operator ==(const TDate& d) const;
    bool operator<(const TDate& d) const;
    bool operator>=(const TDate& d) const;
    bool operator<=(const TDate& d) const;
    bool operator!=(const TDate& d) const;
    virtual string date_string();
    static bool TDateComparator(TDate* d1, TDate* d2);
};
class TDate1 : public TDate {
public:
    TDate1() :TDate() {};
    TDate1(int day, int month, int year) :TDate(day, month, year) {};
    string date_string() override;
};
class TDate2 : public TDate {
public:
    TDate2() :TDate(){};
    TDate2(int day, int month, int year) :TDate(day, month, year) {};
    string date_string() override;
};
void EnterArgs(int& day, int& month, int& year);
