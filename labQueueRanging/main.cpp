#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <map>
#include <string>
#include <vector>
#include "welocome.h"
#include "ranging.h"
using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);

	//start animation
    startWelocomeAnimation();

    //main block
    int members = 0;
    map <string, vector <int>> member; //original dictionary with all data from info entering cycle
    vector <string> surnames; //list of surnames for sorting the dictionary

    cout << "¬ведите количество участников: ";
    cin >> members;
    while (members < 2) {
        if (members < 2) {
            members = 0;
            system("cls");
			cout << "¬ведено некорректное количество участников! ¬ведите количество не меньше 2!" << endl;
			cout << "¬ведите количество участников: " << endl;
            cin >> members;
        }
    }
    system("cls");

    if (members >= 2) //info entering cycle
    {
        for (int i = 0;i != members;++i) 
        {
            if (i > 0) 
            {
                cout << "”же введены: ";
                for (auto s : surnames) 
                {
                    cout << s << " ";
                }
                cout << endl;
            }

            string surname;
            int completedLabs, nextLab, isTryed;
            cout << "¬ведите фамилию: ";
            cin >> surname;
            cout << "¬ведите количество уже защищенных лаб. работ участника: ";
            cin >> completedLabs;
            cout << "¬ведите номер лаб. работы которую будет сдавать участник(если их несколько, то номер последней): ";
            cin >> nextLab;
            cout << "¬ведите подходил ли участник сдавать лаб. работу на прошлом зан€тии(1 - да, 0 - нет): ";
            cin >> isTryed;

            surnames.push_back(surname);
            member[surname] = { completedLabs, nextLab, isTryed * 10 };
            system("cls");

        }

        ranging(member, surnames);
    }
    else 
    {
        cout << "”частников должно быть больше двух!";
    }
    cout << "ƒл€ выхода нажмите на любую кнопку дважды!";
    getchar();
    getchar();
}