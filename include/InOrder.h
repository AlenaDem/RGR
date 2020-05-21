#ifndef INORDER_H_INCLUDED
#define INORDER_H_INCLUDED

#include "Order.h"

class InOrder : public Order {

private:

public:
    InOrder() = default;
    InOrder(double sum, string date, Contractor contractor, string employee, string basis)
        : Order {sum, date, contractor, employee, basis}
    {
    }

    ~InOrder()
    {
    }

    friend ostream& operator<< (ostream &out, const InOrder &inorder);
    friend istream& operator>> (istream &in, InOrder &inorder);
    friend bool operator<(const InOrder& lhs, const InOrder& rhs);

    void print() override;

};


#endif // INORDER_H_INCLUDED
