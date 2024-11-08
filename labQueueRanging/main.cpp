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

    cout << "������� ���������� ����������: ";
    cin >> members;
    while (members < 2) {
        if (members < 2) {
            members = 0;
            system("cls");
			cout << "������� ������������ ���������� ����������! ������� ���������� �� ������ 2!" << endl;
			cout << "������� ���������� ����������: " << endl;
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
                cout << "��� �������: ";
                for (auto s : surnames) 
                {
                    cout << s << " ";
                }
                cout << endl;
            }

            string surname;
            int completedLabs, nextLab, isTryed;
            cout << "������� �������: ";
            cin >> surname;
            cout << "������� ���������� ��� ���������� ���. ����� ���������: ";
            cin >> completedLabs;
            cout << "������� ����� ���. ������ ������� ����� ������� ��������(���� �� ���������, �� ����� ���������): ";
            cin >> nextLab;
            cout << "������� �������� �� �������� ������� ���. ������ �� ������� �������(1 - ��, 0 - ���): ";
            cin >> isTryed;

            surnames.push_back(surname);
            member[surname] = { completedLabs, nextLab, isTryed * 10 };
            system("cls");

        }

        ranging(member, surnames);
    }
    else 
    {
        cout << "���������� ������ ���� ������ ����!";
    }
    cout << "��� ������ ������� �� ����� ������ ������!";
    getchar();
    getchar();
}