#include "Date.h"
#include <sstream>
#include <iostream>

using namespace std;

Date::Date()
{
}

Date::Date(string s)
{
    int d, m, y;
    istringstream ss(s);
    ss >> d;
    ss.ignore(1);
    ss >> m;
    ss.ignore(1);
    ss >> y;

    if (y < 1970 || y >= 3000)
        return;
    if (m < 1 || m > 12)
        return;
    if ((d < 1 || d > daysInMonth[m - 1]) && m != 2)
        return;
    if (m == 2 && d > daysInMonth[m - 1] + isLeap(y))
        return;

    year = y;
    month = m;
    day = d;
}

bool Date::isLeap(int y) const {
    if (y % 4 != 0)
        return false;
    else if (y % 100 == 0 && y % 400 != 0) return false;
    return true;
}

void Date::print() const {
    cout << "Date(" << day << ", " << month << ", " << year << ")";
}

ostream& operator<< (ostream &out, const Date &date) {
    out << date.day << "." << date.month << "." << date.year;
    return out;
}

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.year != rhs.year)
        return lhs.year < rhs.year;
    if (lhs.month != rhs.month)
        return lhs.month < rhs.month;
    return lhs.day < rhs.day;
}

bool operator==(const Date& lhs, const Date& rhs) {
        return (lhs.year == rhs.year &&
                lhs.month == rhs.month &&
                lhs.day == rhs.day);
}

bool operator!=(const Date& lhs, const Date& rhs) {
        return !(lhs == rhs);
}

bool operator<=(const Date& lhs, const Date& rhs) {
    return (lhs < rhs) || (lhs == rhs);
}


