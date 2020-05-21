#ifndef DATE_H
#define DATE_H

#include <string>
#include <vector>

using namespace std;


class Date
{
    friend ostream& operator<< (ostream &out, const Date &date);
    friend bool operator<(const Date& lhs, const Date& rhs);
    friend bool operator<=(const Date& lhs, const Date& rhs);
    friend bool operator==(const Date& lhs, const Date& rhs);
    friend bool operator!=(const Date& lhs, const Date& rhs);
public:
    Date();
    Date(string s);
    void print() const;
    int year{1970};
    int month{1};
    int day{1};
    bool isLeap(int year) const;

private:
    vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};

#endif // DATE_H
