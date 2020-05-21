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
        cout << "��������� �����:\n�����: " << sum << "\n����: " << date << "\n����������: " << contractor;
        cout << "\n���������: " << employee << "\n���������: " << basis << "\n\n";
    }

    void historyoutw() {
    ofstream fout("History.txt", ios_base::app);
    if (fout.is_open()) {
        fout << "��������� �����:\n�����: " << sum << "\n����: " << date << "\n����������: " << contractor;
        fout << "\n���������: " << employee << "\n���������: " << basis << "\n\n";
        cout << "�������� ����� ������� � ������� ��������.\n\n";
    }
    fout.close();
    }
};


#endif // OUTWAR_H_INCLUDED
