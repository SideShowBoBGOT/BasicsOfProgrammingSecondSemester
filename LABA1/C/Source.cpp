#include <string.h>
#include <limits.h>
#include <direct.h>
#include<iostream>
#include <fstream>
using namespace std;
void create_files();
void fill_file(char* file_name);
void fill_common();
int count_rows();
void show_contents(char* file_name);
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
void show_contents(char* file_name) {
    ifstream file(file_name, ios::in);
    char buf[_MAX_PATH];
    while (!file.eof()) {
        file.getline(buf, _MAX_PATH);
        strcat_s(buf, "\n");
        cout << buf;
    }
    file.close();
}
int count_rows() {
    ifstream file("third.txt", ios::in);
    char buf[_MAX_PATH];
    int count = 0;
    while (!file.eof()){
        file.getline(buf, _MAX_PATH);
        count++;
    }
    file.close();
    if (count)
        count--;
    return count;
}
void fill_common(){
    ifstream file1("first.txt", ios::in);
    ifstream file2("second.txt", ios::in);
    ofstream file3("third.txt", ios::in);
    char buf1[_MAX_PATH];
    char buf2[_MAX_PATH];
    while (!file1.eof()) {
        file1.getline(buf1, _MAX_PATH);
        while (!file2.eof()&strcmp(buf1,"")) {
            file2.getline(buf2, _MAX_PATH);
            if (!strcmp(buf1, buf2)) {
                strcat_s(buf2, "\n");
                file3 << buf2;
            }
        }
        file2.clear();
        file2.seekg(0, ios::beg);
    }
    file1.close();
    file2.close();
    file3.close();
}
void fill_file(char* file_name) {
    ofstream file(file_name, ios::out | ios::trunc);
    char buf[_MAX_PATH];
    cin.getline(buf, _MAX_PATH);
    string str = buf;
    while (str!="end") {
        str += "\n";
        file << str.c_str();
        cin.getline(buf, _MAX_PATH);
        str = buf;
    }
    file.close();
}
void create_files() {
    ofstream file1("first.txt", ios::out|ios::trunc);
    ofstream file2("second.txt", ios::out|ios::trunc);
    ofstream file3("third.txt", ios::out | ios::trunc);
    file1.close();
    file2.close();
    file3.close();
}