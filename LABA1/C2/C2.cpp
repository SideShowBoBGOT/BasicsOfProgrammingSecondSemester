#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
void create_list(void);
void more_half(void);
void show_res(void);
struct cl {
    char surname[255];
    int start_serv;
    int end_serv;
};
int main()
{
    create_list();
    more_half();
    show_res();
    system("pause");
}
void show_res() {
    cl c;
    ifstream file("clients30.txt", ios::binary);
    while (file.read((char*)&c, sizeof(cl))) {
        cout << c.surname << "\t" << c.start_serv << "\t" << c.end_serv << endl;
    }
    file.close();
}
void more_half() {
    ifstream file("clients.txt", ios::binary);
    ofstream file2("clients30.txt", ios::binary);
    vector<cl> cls;
    cl c;
    while (file.read((char*)&c, sizeof(cl))) {
        int h1 = int(c.start_serv / 100);
        int h2 = int(c.end_serv / 100);
        int m1 = int(c.start_serv % 100);
        int m2 = int(c.end_serv % 100);
        int h_delay = abs(h2 - h1);
        int m_delay = abs(m2 - m1);
        int delay = h_delay*60 + m_delay;
        if (delay > 30) {
            cls.push_back(c);
        }
    }
    for (int i = 0; i < cls.size(); i++)
    {
        c = cls[i];
        file2.write((char*)&c, sizeof(cl));
    }
    file.close();
    file2.close();
}
void create_list() {
    vector<cl> clients;
    ofstream file("clients.txt", ios::binary);
    string buf = "y";
    int count = 0;
    bool is_ok = true;
    while (buf == "y") {
        is_ok = true;
        count++;
        cl c;
        cout << "Client " << count << endl;
        cout << "Surname: ";
        cin >> c.surname;
        cin.ignore();
        cout << "Service begin: ";
        cin >> c.start_serv;
        cin.ignore();
        cout << "Service end: ";
        cin >> c.end_serv;
        cin.ignore();

        for (auto i = clients.cbegin(); i != clients.cend()&&is_ok; i++) {
            if ((c.start_serv >= i->start_serv && c.start_serv <= i->end_serv)
                ||(c.end_serv >= i->start_serv && c.end_serv <= i->end_serv)) {
                is_ok = false;
                cout << "Mismatch in time" << endl;;
            }
        }
        if (is_ok) {
            file.write((char*)&c, sizeof(cl));
            clients.push_back(c);
        }
        cout << "Add another client? y/n: ";
        cin >> buf;
        cin.ignore();
    }
    file.close();
}