#pragma once
using namespace std;
class Data {
private:
    class Month {
    public:
        int number;
        int days;
        string name;
        Month();
        Month(string name, int number, int days);
    };
    Month months[13] = {
        Month("January", 1, 31),
        Month("February", 2, 2829),
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
    Month month;
    int year;

    void Update();
public:
    Data();
    Data(int year);
    Data(int day, int month, int year);
    int GetDay();
    int GetMonth();
    int GetYear();
    static bool IsFourth(int year);

    //// Prefix increment operator
    Data& operator++();
    //Postfix increment operator
    Data operator++(int);
    bool operator >(const Data& d);

    int RestDays();
};