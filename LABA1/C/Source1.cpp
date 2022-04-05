#include <string.h>
#include <limits.h>
#include <direct.h>
#include<iostream>
#include <fstream>
#include"Header.h"
using namespace std;
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
    while (!file.eof()) {
        file.getline(buf, _MAX_PATH);
        count++;
    }
    file.close();
    if (count)
        count--;
    return count;
}
void fill_common() {
    ifstream file1("first.txt", ios::in);
    ifstream file2("second.txt", ios::in);
    ofstream file3("third.txt", ios::in);
    char buf1[_MAX_PATH];
    char buf2[_MAX_PATH];
    while (!file1.eof()) {
        file1.getline(buf1, _MAX_PATH);
        while (!file2.eof() & strcmp(buf1, "")) {
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
void fill_file(char* file_name, string a_or_w) {
    if (a_or_w == "a") {
        ofstream file(file_name, ios::out | ios::app);
        char buf[_MAX_PATH];
        cin.getline(buf, _MAX_PATH);
        string str = buf;
        while (str[0] != 5) {
            str += "\n";
            file << str.c_str();
            cin.getline(buf, _MAX_PATH);
            str = buf;
        }
        file.close();
    }
    else {
        ofstream file(file_name, ios::out | ios::trunc);
        char buf[_MAX_PATH];
        cin.getline(buf, _MAX_PATH);
        string str = buf;
        while (str[0] != 5) {
            str += "\n";
            file << str.c_str();
            cin.getline(buf, _MAX_PATH);
            str = buf;
        }
        file.close();
    }
}
void create_files(string a_or_w) {
    if (a_or_w =="w") {
        ofstream file1("first.txt", ios::out | ios::trunc);
        ofstream file2("second.txt", ios::out | ios::trunc);
        file1.close();
        file2.close();
    }
    ofstream file3("third.txt", ios::out | ios::trunc);

    file3.close();
}