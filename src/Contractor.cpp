#include "Contractor.h"

Contractor::Contractor()
{
}

Contractor::~Contractor()
{
}

Contractor::Contractor(string name, string acc_num) : name{name}, account_number{acc_num}
{
}

ostream& operator<< (ostream &out, const Contractor &contractor) {
    out << contractor.name << " " << contractor.account_number;
    return out;
}

bool operator==(const Contractor& lhs, const Contractor& rhs) {
        return (lhs.name == rhs.name &&
                lhs.account_number == rhs.account_number);
}

bool operator!=(const Contractor& lhs, const Contractor& rhs) {
        return !(lhs == rhs);
}

Contractor& Contractor::operator= (const Contractor &contractor) {
    if (this == &contractor)
        return *this;

    name = contractor.name;
    account_number = contractor.account_number;
    return *this;
}
