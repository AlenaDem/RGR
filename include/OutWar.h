#ifndef OUTWAR_H_INCLUDED
#define OUTWAR_H_INCLUDED

#include "Order.h"

using namespace std;

class OutOrder : public Order {

private:

public:
    OutOrder(double sum, int date, string contractor, string employee, string basis)
        : Order {sum, date, contractor, employee, basis}
    {
    }

    void print() override {
        cout << "Расходный ордер:\nСумма: " << sum << "\nДата: " << date << "\nКонтрагент: " << contractor;
        cout << "\nСотрудник: " << employee << "\nОснование: " << basis << "\n\n";
    }

    void historyoutw() {
    ofstream fout("History.txt", ios_base::app);
    if (fout.is_open()) {
        fout << "Расходный ордер:\nСумма: " << sum << "\nДата: " << date << "\nКонтрагент: " << contractor;
        fout << "\nСотрудник: " << employee << "\nОснование: " << basis << "\n\n";
        cout << "Кассовый ордер записан в историю операций.\n\n";
    }
    fout.close();
    }
};


#endif // OUTWAR_H_INCLUDED
