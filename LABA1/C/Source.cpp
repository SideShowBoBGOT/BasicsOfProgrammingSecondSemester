#include<iostream>
#include"Header.h"
using namespace std;

int main()
{
    char file_name1[_MAX_PATH] = "first.txt";
    char file_name2[_MAX_PATH] = "second.txt";
    char file_name3[_MAX_PATH] = "third.txt";
    create_files();
    cout << "Enter strings for the first file" << endl;
    fill_file(file_name1);
    cout << "Enter strings for the second file" << endl;
    fill_file(file_name2);
    fill_common();
    cout << "Common rows: " << count_rows() << endl;
    cout << "First file: " << endl;
    show_contents(file_name1);
    cout << "Second file: " << endl;
    show_contents(file_name2);
    cout << "Third file: " << endl;
    show_contents(file_name3);
    system("pause");
    return 0;
}
