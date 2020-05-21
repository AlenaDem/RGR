#ifndef WAR_H_INCLUDED
#define WAR_H_INCLUDED

#include <string>
#include <iostream>
#include <fstream>
#include "Date.h"
#include "Contractor.h"

using namespace std;

class Order {

protected:
    double sum;
    Date date;
    Contractor contractor;
    string employee;
    string basis;
    string sep = " - ";

public:
    Order() : sum(0.0), employee("UnknownE"), basis("UnknownB") {sep = " ";}

    Order(double t_sum, string t_date, Contractor t_contractor, string t_employee, string t_basis) : date{t_date} {
        sum = t_sum;
        contractor = t_contractor;
        employee = t_employee;
        basis = t_basis;
    }

    virtual void setSeparator(const string s) {sep = s;};

    virtual void print() = 0;

    virtual void set_sum(double w_sum);
    virtual void set_date(string w_date);
    virtual void set_contractor(string w_contractor_name, string w_contractor_account_number);
    virtual void set_employee(string w_employee);
    virtual void set_basis(string w_basis);

    virtual double get_sum() const;
    virtual Date get_date() const;
    virtual Contractor get_contractor() const;
    virtual string get_employee() const;
    virtual string get_basis() const;
};

#endif // WAR_H_INCLUDED
