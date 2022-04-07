#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include"Header.h"
Worker::Worker() {};
Worker::Worker(string patronym, string name, string surname, string birth_date) {
    this->patronym = patronym;
    this->name = name;
    this->surname = surname;
    this->birth_date = birth_date;
}
string Worker::GetPatronym() {
    return this->patronym;
}
string Worker::GetName() {
    return this->name;
}
string Worker::GetSurname() {
    return this->surname;
}
string Worker::GetBirthDate() {
    return this->birth_date;
}
void Worker::SetPatronym(string patronym) {
    this->patronym = patronym;
}
void Worker::SetName(string name) {
    this->name = name;
}
void Worker::SetSurname(string surname) {
    this->surname = surname;
}
void Worker::SetBirthDate(string birth_date) {
    this->birth_date = birth_date;
}
bool Worker::WorkerAgeComparator(Worker w1, Worker w2) {
    string age1;
    string age2;
    for (int i = 0; i < w1.birth_date.length(); i++)
    {
        if (isdigit(w1.birth_date[i])) {
            age1 += w1.birth_date[i];
            age2 += w2.birth_date[i];
        }
    }
    string age1_c;
    string age2_c;
    for (int i = 4; i < 8; i++)
    {
        age1_c += age1[i];
        age2_c += age2[i];
    }
    for (int i = 0; i < 4; i++)
    {
        age1_c += age1[i];
        age2_c += age2[i];
    }
    return atoi(age1_c.c_str()) < atoi(age2_c.c_str());
}
Company::Company() {
    string buf = "y";
    int count = 1;
    while (buf == "y") {
        string patronym;
        string name;
        string surname;
        string birth_date;
        cout << "Worker " << count << endl;
        cout << "Patronym: ";
        cin >> patronym;
        cin.ignore();
        cout << "Name: ";
        cin >> name;
        cin.ignore();
        cout << "Surname: ";
        cin >> surname;
        cin.ignore();
        cout << "Date of Birth( MM-DD-YYYY ): ";
        cin >> birth_date;
        cin.ignore();
        this->workers.push_back(
            Worker(patronym, name, surname, birth_date)
        );
        do {
            cout << "Wann`a continue?y/n: " << endl;
            cin >> buf;
            cin.ignore();
        } while (buf != "y" && buf != "n");
        count++;
    }
}
Worker Company::get_oldest() {
    return *min_element(this->workers.begin(), this->workers.end(), Worker::WorkerAgeComparator);
}