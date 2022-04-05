#include <iostream>
#include<vector>
using namespace std;
class Worker {
private:
    string patronym;
    string name;
    string surname;
    string birth_date;
public:
    Worker() {};
    Worker(string patronym,  string name,  string surname,  string birth_date) {
        this->patronym = patronym;
        this->name = name;
        this->surname = surname;
        this->birth_date = birth_date;
    }
    string GetPatronym() {
        return this->patronym;
    }
    string GetName() {
        return this->name;
    }
    string GetSurname() {
        return this->surname;
    }
    string GetBirthDate() {
        return this->birth_date;
    }
    void SetPatronym(string patronym) {
        this->patronym = patronym;
    }
    void SetName(string name) {
        this->name = name;
    }
    void SetSurname(string surname) {
        this->surname = surname;
    }
    void SetBirthDate(string birth_date) {
        this->birth_date = birth_date;
    }
};
vector<Worker> init_workers() {
    vector<Worker>company;
    char buf[_MAX_PATH] = { 'y' };
    int count = 1;
    while (buf[0] == 'y') {
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
        company.push_back(
            Worker(patronym, name, surname, birth_date)
        );
        while (buf != "y" || buf != "n") {
            cout << "Wann`a continue?y/n" << endl;
            cin >> buf;
            cin.ignore();
        }
        count++;
    }
    return company;
}
Worker get_oldest(vector<Worker>company) {

}

int main()
{
    vector<Worker>company;
    
}


