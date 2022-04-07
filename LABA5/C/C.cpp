#include <iostream>
#include<vector>
#include<algorithm>
#include"Header.h"
using namespace std;
int main()
{
    srand(time(NULL));
    int year1 = 0;
    int month1 = 0;
    int day1 = 0;

    int year2 = 0;
    int month2 = 0;
    int day2 = 0;

    cout<<"Enter interval"<<endl;
    cout << "\tEnter the first date" << endl;
    EnterArgs(day1, month1, year1);
    cout << "\tEnter the second date" << endl;
    EnterArgs(day2, month2, year2);

    TDate d1 = TDate(day1, month1, year1);
    TDate d2 = TDate(day2, month2, year2);
    
    vector<TDate*>dates;
    for (int i = 0; i < 10; i++)
    {
        dates.push_back(new TDate1(1 + rand() % 28, 1 + rand() % 12, year1 - 3 + rand() % (year2 - year1 + 7)));
        dates.push_back(new TDate2(1 + rand() % 28, 1 + rand() % 12, year1 - 3 + rand() % (year2 - year1 + 7)));
    }

    cout <<endl<< "Dates" << endl;

    for (int i = 0; i < dates.size(); i++)
    {
        cout << dates[i]->date_string() << endl;
    }

    cout << endl << "Between" << endl;

    for (int i = 0; i < dates.size(); i++)
    {
        if (*dates[i] >= d1 && *dates[i] <= d2) {
            cout << dates[i]->date_string() << endl;
        }
    }

    cout <<endl<< "The Latest" << endl;
    cout << (*min_element(dates.begin(), dates.end(), TDate::TDateComparator))->date_string() << endl;
    system("pause");
    return 0;
}
 
