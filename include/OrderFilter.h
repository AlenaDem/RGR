#ifndef ORDERFILTER_H_INCLUDED
#define ORDERFILTER_H_INCLUDED

#include <string>
#include "Date.h"
#include "Contractor.h"

struct OrderFilter {
    double fsum{0};
    Date fdate;
    Contractor fcontractor;
    string femployee{"UnknownE"};
    string fbasis{"UnknownB"};

    bool filterByDate = false;
    bool filterBySum = false;
    bool filterByEmployee = false;
    bool filterByBasis = false;
    bool filterByContractor = false;
};

#endif // ORDERFILTER_H_INCLUDED
