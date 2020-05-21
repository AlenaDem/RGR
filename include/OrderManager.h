#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H
#include "InOrder.h"
#include "OutOrder.h"
#include "OrderFilter.h"
#include <vector>



class OrderManager
{
    public:
        OrderManager();
        virtual ~OrderManager();

        void store(const string& filename) const;
        void load(const string& filename);
        void createInOrder();
        void createOutOrder();
        OrderFilter createOrderFilter();
        void printOrders();
        void printOrders(vector<InOrder> inOrd, vector<OutOrder> outOrd);
        void printFilteredOrders(OrderFilter &filter);
        void printBalance();
        void printBalance(vector<InOrder> inOrd, vector<OutOrder> outOrd);

    private:
        vector<InOrder> inOrders;
        vector<OutOrder> outOrders;
        double balance = 0;
};

#endif // ORDERMANAGER_H
