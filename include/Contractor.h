#ifndef CONTRACTOR_H
#define CONTRACTOR_H

#include <string>
#include <iostream>

using namespace std;

class Contractor
{
    friend ostream& operator<< (ostream &out, const Contractor &contractor);
    friend bool operator==(const Contractor& lhs, const Contractor& rhs);
    friend bool operator!=(const Contractor& lhs, const Contractor& rhs);
public:
    Contractor();
    Contractor(string name, string acc_num);
    virtual ~Contractor();
    string name{"UnknownCN"};
    string account_number{"UnknownCAN"};
    Contractor& operator= (const Contractor &t_contractor);
};

#endif // CONTRACTOR_H
