// Copyright 2021 7kachika
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#define PADDING 12
using namespace std;


class transcipt {
    public:
        string name;
        list<float> score;
        transcipt(string iname) : name(iname) {}
    void addScore(float value) {
        score.push_back(value);
    }
};


list<string> courses;
list<transcipt> classroom;


void clearBuffer() {
    char buff[255];
    cin.getline(buff,'\n');
}


void inputCourse() {
    int count(0);
    cout << "Please enter the number of courses: ";
    cin >> count;
    clearBuffer();

    for (int i = 0; i < count; i++) {
        string name;
        cout << "Course " << i + 1 << " name: ";
        getline(cin, name);
        courses.push_back(name);
    }
    cout << '\n';
}


void inputScore() {
    int count(0);
    cout << "Please enter the number of students: ";
    cin >> count;
    clearBuffer();

    for (int i = 0; i < count; i++) {
        string name;
        cout << "Name of Student #" << i << ": ";
        getline(cin, name);
        transcipt student = transcipt(name);

        for (string course : courses) {
            int value(0);
            cout << course << " score: ";
            cin >> value;
            student.addScore(value);
        }
        clearBuffer();
        classroom.push_back(student);
        cout << '\n';
    }
    cout << '\n';
}


void printCourse() {
    cout << setw(PADDING)<< "Name" << ' ';
    for (string course : courses) {
        cout << setw(PADDING) << course << ' ';
    }
    cout << setw(PADDING) << "Total"<< ' ';
    cout << setw(PADDING) << "Average"<< ' ';
    cout << '\n';
}


void printGrade(transcipt student) {
    cout << setw(PADDING) << student.name << ' ';

    float total(0);
    for (float value : student.score) {
        cout << setw(PADDING) << value << ' ';
        total += value;
    }
    cout << setw(PADDING) << total << ' ';
    cout << setw(PADDING) << total / courses.size() << ' ';
    cout << '\n';
}

int main(int argc, char *argv[])
{
    inputCourse();
    inputScore();

    printCourse();

    for (transcipt student : classroom) {
        printGrade(student);
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}
