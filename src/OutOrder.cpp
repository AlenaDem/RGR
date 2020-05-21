#include "OutOrder.h"

using namespace std;

ostream& operator<< (ostream &out, const OutOrder &outorder) {
    out << "Расходный ордер" << outorder.sep
        << outorder.sum << outorder.sep
        << outorder.date << outorder.sep
        << outorder.contractor.name << outorder.sep
        << outorder.contractor.account_number << outorder.sep
        << outorder.employee << outorder.sep
        << outorder.basis << endl;
    return out;
}

bool operator<(const OutOrder& lhs, const OutOrder& rhs) {
    return lhs.date < rhs.date;
}

void OutOrder::print() {
        cout << "Приходный ордер:\nСумма: " << sum << "\nДата: " << date << "\nКонтрагент: " << contractor;
        cout << "\nСотрудник: " << employee << "\nОснование: " << basis << "\n\n";
}
