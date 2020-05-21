#include "InOrder.h"

using namespace std;

ostream& operator<< (ostream &out, const InOrder &inorder) {
    out << "��������� �����" << inorder.sep
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
        cout << "��������� �����:\n�����: " << sum << "\n����: " << date << "\n����������: " << contractor;
        cout << "\n���������: " << employee << "\n���������: " << basis << "\n\n";
}
