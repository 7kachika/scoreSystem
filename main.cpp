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

int totalNumber(20);
int totalScore(5);
string *name;
string *subject;
float **score;
int choice(-1);
char ans;

void reLoad() {
    name = new string[totalNumber];
    score = new float *[totalNumber];
    subject = new string [totalScore];
    for (int i = 0; i < totalNumber; i++)
    score[i] = new float [totalScore + 3];
    for (int i = 0; i < totalNumber; i++) {
        name[i] = "Unknown";
        score[i] = new float [totalScore + 3];
        for (int j = 0; j < totalScore + 3; j++)
            score[i][j] = 0;
    }
    for (int i = 0; i < totalScore; i++)
        subject[i] = "Sub.";
}

void clearBuffer() {
     char buff[255];
     cin.getline(buff, '\n');
}

void typeSubject(string *subject, int totalSubject) {
    cout << "        | " << endl;
    cout << "        | " << "The number of subject is " << totalScore << "." << endl;
    cout << "        | " << endl << endl;
    for (int i = 0; i < totalSubject; i++) {
        cout << "Number " << i + 1 << " of subject: ";    cin >> subject[i];
        clearBuffer();
    }
    cout << endl;
    cout << "∥===========================================================================∥" << endl;
    cout << endl;
}

void typeScore(string *name, string *subject, float **score, int n) {
    cout << "        | " << endl;
    cout << "        | " << "The number of student is " << totalNumber << "." << endl;
    cout << "        | " << endl << endl;
    for (int i = 0; i < n; i++) {
        cout << "Name: ";    cin >> name[i];
        cout << endl;
        for (int j = 0; j < totalScore; j++) {
            cout << "        | " << subject[j] + " score: ";    cin >> score[i][j];
        }
    cout << endl;
    cout << "∥===========================================================================∥" << endl;
    cout << endl;
    clearBuffer();
    }
    cout << endl;
}

void compute(float **score, int n) {
     for (int i = 0; i < n; i++) {
         score[i][totalScore] = 0;
         for (int j = 0; j < totalScore; j++) score[i][totalScore] += score[i][j];
         score[i][totalScore + 1] = score[i][totalScore] / totalScore;
     }

     for (int i = 0; i < totalNumber; i++) {
        score[i][totalScore + 2] = 1;
        for (int j = 0; j < totalScore + 1; j++) score[i][totalScore + 2] = (score[i][totalScore + 1] >= score[j][totalScore + 1]) ? score[i][totalScore + 2] : (score[i][totalScore + 2] += 1);
    }
}

void printScore(string *name, float **score, int n) {
    compute(score, totalNumber);
    cout << endl;
    cout << "..............................................................................." << endl;
    cout << "∥===========================================================================∥" << endl;
    cout << "∥                                                                           ∥" << endl;
    cout << endl;
    cout << setw(10)<< "Name";
    for (int i = 0; i < totalScore; i++)
        cout << setw(8) << subject[i];
        cout << setw(8) << "Total";
        cout << setw(8) << "Avg.";
        cout << setw(8) << "Rank";
        cout << endl;

    for (int i=0; i < n; i++){
        cout << setw(10) << name[i];
        for (int j = 0; j < totalScore + 3; j++)
            cout << setw(8)<< score[i][j];
        cout << endl;
    }
    cout << endl;
    cout << "∥                                                                           ∥" << endl;
    cout << "∥===========================================================================∥" << endl;
    cout << "..............................................................................." << endl;
    cout << endl;
}

int main(int argc, char *argv[])
{
    reLoad();
    do {
        cout << "∥                                                                           ∥" << endl;
        cout << "∥                                                                           ∥" << endl;
        cout << "∥===========================================================================∥" << endl;
        cout << "∥                                                                           ∥" << endl;
        cout << "∥                                                                           ∥" << endl;
        cout << "∥                        Basic Results System                               ∥" << endl;
        cout << "∥                                                                           ∥" << endl;
        cout << "∥                                                                           ∥" << endl;
        cout << "∥===========================================================================∥" << endl;
        cout << "∥                                                                           ∥" << endl;
        cout << "∥                                                                           ∥" << endl;
        cout << "∥               Menu | Set number of student      ... [1] |                 ∥" << endl;
        cout << "∥                    | Set number of subject      ... [2] |                 ∥" << endl;
        cout << "∥                    | Set name of subject        ... [3] |                 ∥" << endl;
        cout << "∥                    |                                    |                 ∥" << endl;
        cout << "∥                    | Input score                ... [4] |                 ∥" << endl;
        cout << "∥                    | Show result                ... [5] |                 ∥" << endl;
        cout << "∥                    |                                    |                 ∥" << endl;
        cout << "∥                    | Exit system                ... [6] |                 ∥" << endl;
        cout << "∥                                                                           ∥" << endl;
        cout << "∥                                                                           ∥" << endl;
        cout << "..............................................................................." << endl;
        cout << endl << "Select the number of menu: ";    cin >> choice;
        clearBuffer();
        system("cls");

        cout << "∥                                                                           ∥" << endl;
        cout << "∥                                                                           ∥" << endl;
        cout << "..............................................................................." << endl;
        cout << endl << "Select the number of menu: " << choice << endl << endl;

        switch(choice) {
            // Set number of student
            case 1:
                 cout << "        | " << endl;
                 cout << "        | " << "The number of student is " << totalNumber << "." << endl;
                 cout << "        | " << endl << endl;
                 cout << "How many numbers of student would like to change? (Maximum is 20) ";    cin >> totalNumber;
                 cout << endl;
                 cout << "        | " << endl;
                 cout << "        | " << "The number of student is " << totalNumber << "." << endl;
                 cout << "        | " << endl;
                 cout << endl;
                 cout << "∥===========================================================================∥" << endl;
                 cout << endl;
                 clearBuffer();
                 break;

            // Set number of subject
            case 2:
                 cout << "        | " << endl;
                 cout << "        | " << "The number of subject is " << totalScore << "." << endl;
                 cout << "        | " << endl << endl;
                 cout << "How many numbers of subject would like to change? (Maximum is 5) ";    cin >> totalScore;
                 cout << endl;
                 cout << "        | " << endl;
                 cout << "        | " << "The number of subject is " << totalScore << "." << endl;
                 cout << "        | " << endl;
                 cout << endl;
                 cout << "∥===========================================================================∥" << endl;
                 cout << endl;
                 clearBuffer();
                 cout << "Do you want Set name of subject? Choose (Y/N) ";    cin >> ans;
                 if (ans != 'y' && ans != 'Y')
                    break;

            // Set name of subject
            case 3:
                 typeSubject(subject, totalScore);
                 break;

            // Input Score
            case 4:
                 typeScore(name, subject, score, totalNumber);
                 cout << "Do you want print the result? Choose (Y/N) ";    cin >> ans;
                 if (ans != 'y' && ans != 'Y')
                    break;

            // Show result
            case 5:
                 printScore(name, score, totalNumber);
                 break;

            // Exit system
            case 6:
                 cout << "        | " << endl;
                 cout << "        | " << "Good Bye." << endl;
                 cout << "        | " << endl;
                 break;

            // Error
            default:
                 cout << "        | " << endl;
                 cout << "        | " << "Error: Please confirm the number of menu." << endl;
                 cout << "        | " << endl;
                 break;
        }
        cout << endl;
        system("PAUSE");
        system("cls");
    }while (choice != 6);

    delete [] name;
    for (int i = 0; i < totalScore + 3; i++) delete [] score[i];
    delete [] score;
    delete [] subject;

    return EXIT_SUCCESS;
}
