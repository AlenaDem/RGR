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
    cout << "Выберите действие:"
         << "\n1 - создать приходный кассовый ордер"
         << "\n2 - создать расходный кассовый ордер"
         << "\n\n3 - сохранить операции в файл"
         << "\n4 - загрузить данные из файла"
         << "\n\n5 - просмотр истории операций"
         << "\n6 - просмотр операций по определённым характеристикам"
         << "\n7 - просмотр баланса за определённую дату"
         << "\n\n0 - выход"
         << "\n? - помощь\n\n";
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
            cout << "Ордер создан, выберите дальнейшее действие:\n";
        }

        if (input == "2") {
            manager.createOutOrder();
            cout << "Ордер создан, выберите дальнейшее действие:\n";
        }

        if (input == "3") {
            cout << "Введите имя файла для сохранения: \n";
            string filename;
            cin >> filename;
            manager.store(filename);
            cout << "Данные загружены в файл. Выберите дальнейшее действие:\n";
        }

        if (input == "4") {
            cout << "Введите имя файла для загрузки: \n";
            string filename;
            cin >> filename;
            manager.load(filename);
            cout << "Данные из файла загружены. Выберите дальнейшее действие:\n";
        }

        if (input == "5") {
            cout << "Тип ордера - сумма - дата - контрагент - сотрудник - основание\n";
            manager.printOrders();
            cout << "\nВыберите дальнейшее действие:\n";
        }

        if (input == "6") {
            auto filter = manager.createOrderFilter();
            cout << "Тип ордера - сумма - дата - контрагент (название - счёт) - сотрудник - основание\n";
            manager.printFilteredOrders(filter);
            cout << "\nВыберите дальнейшее действие:\n";
        }
        if (input == "7") {
            manager.printBalance();
            cout << "\nВыберите дальнейшее действие:\n";
        }
    }
    return 0;
}
