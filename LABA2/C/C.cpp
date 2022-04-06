#include <iostream>
#include"Header.h"
using namespace std;

int main()
{
    Company c = Company();
    Worker old_worker = c.get_oldest();
    cout << "Surname: " << old_worker.GetSurname()<<"\t"
        << "Name: " << old_worker.GetName()<<"\t"
        << "Patronym: " << old_worker.GetPatronym()<<"\t"
        << "BirthDate: " << old_worker.GetBirthDate() << endl;
    system("pause");
    return 0;
}


