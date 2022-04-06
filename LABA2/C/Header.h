#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Worker {
private:
    string patronym;
    string name;
    string surname;
    string birth_date;
public:
    Worker();
    Worker(string patronym, string name, string surname, string birth_date);
    string GetPatronym();
    string GetName();
    string GetSurname();
    string GetBirthDate();
    void SetPatronym(string patronym);
    void SetName(string name);
    void SetSurname(string surname);
    void SetBirthDate(string birth_date);
    static bool WorkerAgeComparator(Worker w1, Worker w2);
};
class Company {
private:
    vector<Worker>workers;
public:
    Company();
    Worker get_oldest();
};
