#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <Windows.h>

#include "Order.h"
#include "InOrder.h"
#include "OutOrder.h"
#include "OrderManager.h"
#include "Date.h"

using namespace std;

void printHelp() {
    cout << "�������� ��������:"
         << "\n1 - ������� ��������� �������� �����"
         << "\n2 - ������� ��������� �������� �����"
         << "\n\n3 - ��������� �������� � ����"
         << "\n4 - ��������� ������ �� �����"
         << "\n\n5 - �������� ������� ��������"
         << "\n6 - �������� �������� �� ����������� ���������������"
         << "\n7 - �������� ������� �� ����������� ����"
         << "\n\n0 - �����"
         << "\n? - ������\n\n";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    OrderManager manager;
    printHelp();
    string input;
    while (input != "0") {
        getline(cin, input);

        if (input == "?") {
            printHelp();
        }

        if (input == "1") {
            manager.createInOrder();
            cout << "����� ������, �������� ���������� ��������:\n";
        }

        if (input == "2") {
            manager.createOutOrder();
            cout << "����� ������, �������� ���������� ��������:\n";
        }

        if (input == "3") {
            cout << "������� ��� ����� ��� ����������: \n";
            string filename;
            cin >> filename;
            manager.store(filename);
            cout << "������ ��������� � ����. �������� ���������� ��������:\n";
        }

        if (input == "4") {
            cout << "������� ��� ����� ��� ��������: \n";
            string filename;
            cin >> filename;
            manager.load(filename);
            cout << "������ �� ����� ���������. �������� ���������� ��������:\n";
        }

        if (input == "5") {
            cout << "��� ������ - ����� - ���� - ���������� - ��������� - ���������\n";
            manager.printOrders();
            cout << "\n�������� ���������� ��������:\n";
        }

        if (input == "6") {
            auto filter = manager.createOrderFilter();
            cout << "��� ������ - ����� - ���� - ���������� (�������� - ����) - ��������� - ���������\n";
            manager.printFilteredOrders(filter);
            cout << "\n�������� ���������� ��������:\n";
        }
        if (input == "7") {
            manager.printBalance();
            cout << "\n�������� ���������� ��������:\n";
        }
    }
    return 0;
}
