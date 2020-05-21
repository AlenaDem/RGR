#ifndef OUTORDER_H_INCLUDED
#define OUTORDER_H_INCLUDED

#include "Order.h"

class OutOrder : public Order {

private:

public:
    OutOrder() = default;
    OutOrder(double sum, string date, Contractor contractor, string employee, string basis)
        : Order {sum, date, contractor, employee, basis}
    {
    }

    ~OutOrder()
    {
    }

    friend ostream& operator<< (ostream &out, const OutOrder &outorder);
    friend istream& operator>> (istream &out, OutOrder &outorder);
    friend bool operator<(const OutOrder& lhs, const OutOrder& rhs);

    void print() override;

};


#endif // OUTORDER_H_INCLUDED
