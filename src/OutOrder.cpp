#include "OutOrder.h"

using namespace std;

ostream& operator<< (ostream &out, const OutOrder &outorder) {
    out << "��������� �����" << outorder.sep
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
        cout << "��������� �����:\n�����: " << sum << "\n����: " << date << "\n����������: " << contractor;
        cout << "\n���������: " << employee << "\n���������: " << basis << "\n\n";
}
