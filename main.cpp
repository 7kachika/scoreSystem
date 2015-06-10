// Copyright 2015 7kachika
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

#include <cstdlib>
#include <iostream>
#include <iomanip>
#define Max 120
using namespace std;

void clearBuffer() {
        char buff[255];
        cin.getline(buff,'\n');
     }


void inputScore(char name[][25], float score[][7], int n) {
    for (int i=0; i<n; i++){
        cout << "輸入名字:";
        cin.getline(name[i], '\n');
        cout << "輸入國文成績:";     cin >> score[i][0];
        cout << "輸入英文成績:";     cin >> score[i][1];
        cout << "輸入數學成績:";     cin >> score[i][2];
        cout << "輸入物理成績:";     cin >> score[i][3];
        cout << "輸入程式成績:";     cin >> score[i][4];
        clearBuffer();
    }
}

void compute(float score[][7], int n) {
    for (int i=0; i<n; i++){
        score[i][5]=0;
        for (int j=0; j<5; j++) score[i][5]+=score[i][j];
        score[i][6]=score[i][5]/5.0;
    }
}

void printTitle() {
    cout << setw(10)<< "姓      名" << " ";
    cout << setw(6) << "國  文"<< " ";
    cout << setw(6) << "英  文"<< " ";
    cout << setw(6) << "數  學"<< " ";
    cout << setw(6) << "物  理"<< " ";
    cout << setw(6) << "程  式"<< " ";
    cout << setw(6) << "總  分"<< " ";
    cout << setw(6) << "平  均"<< " " << endl;
}

void printScore(char name[][25], float score[][7], int n) {
    for (int i=0; i<n; i++){
        cout << setw(10) << (char *)name[i] << " ";
        cout << setw(6)<< score[i][0] << " ";
        cout << setw(6)<< score[i][1] << " ";
        cout << setw(6)<< score[i][2] << " ";
        cout << setw(6)<< score[i][3] << " ";
        cout << setw(6)<< score[i][4] << " ";
        cout << setw(6)<< score[i][5] << " ";
        cout << setw(6)<< score[i][6] << endl;
    }
}

int main(int argc, char *argv[])
{
    char name[Max][25];
    float score[Max][7];
    int numberOfStudent(0);

    cout << "學生人數:";  cin >> numberOfStudent;
    clearBuffer();

    inputScore(name, score, numberOfStudent);
    compute(score,numberOfStudent);
    printTitle();
    printScore(name, score, numberOfStudent);

    system("PAUSE");
    return EXIT_SUCCESS;
}
