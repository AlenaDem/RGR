#include "InOrder.h"

using namespace std;

ostream& operator<< (ostream &out, const InOrder &inorder) {
    out << "Приходный ордер" << inorder.sep
        << inorder.sum << inorder.sep
        << inorder.date << inorder.sep
        << inorder.contractor.name << inorder.sep
        << inorder.contractor.account_number << inorder.sep
        << inorder.employee << inorder.sep
        << inorder.basis << endl;
    return out;
}

bool operator<(const InOrder& lhs, const InOrder& rhs) {
    return lhs.date < rhs.date;
}

void InOrder::print() {
        cout << "Приходный ордер:\nСумма: " << sum << "\nДата: " << date << "\nКонтрагент: " << contractor;
        cout << "\nСотрудник: " << employee << "\nОснование: " << basis << "\n\n";
}
