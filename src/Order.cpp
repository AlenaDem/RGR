#include "Order.h"

using namespace std;

void Order::set_sum(double w_sum) {
    sum = w_sum;
}

void Order::set_date(string w_date) {
    date = Date(w_date);
}

void Order::set_contractor(string w_contractor_name, string w_contractor_account_number) {
    contractor.name = w_contractor_name;
    contractor.account_number = w_contractor_account_number;
}

void Order::set_employee(string w_employee) {
    employee = w_employee;
}

void Order::set_basis(string w_basis) {
    basis = w_basis;
}

double Order::get_sum() const {
    return sum;
}

Date Order::get_date() const {
    return date;
}

Contractor Order::get_contractor() const {
    return contractor;
}

string Order::get_employee() const {
    return employee;
}

string Order::get_basis() const {
    return basis;
}
