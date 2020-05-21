#include "OrderManager.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <locale.h>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

OrderManager::OrderManager()
{
}

OrderManager::~OrderManager()
{
}

void OrderManager::store(const string& filename) const {
    ofstream out(filename, ios::out);
    if (out.is_open()) {
        for (auto order : inOrders) {
            order.setSeparator("\n");
            out << order;
        }
        for (auto order : outOrders) {
            order.setSeparator("\n");
            out << order;
        }
    }
    out.close();
}

void OrderManager::load(const string& filename) {
    inOrders.clear();
    outOrders.clear();
    ifstream in(filename, ios::in);
    string employee, basis, date, line, type;
    Contractor contractor;
    double sum;
    if (!in.is_open())
        return;
    while (getline(in, type)) {
        getline(in, line);
        sum = stod(line);
        getline(in, date);
        getline(in, contractor.name);
        getline(in, contractor.account_number);
        getline(in, employee);
        getline(in, basis);
        if (type == "��������� �����")
            inOrders.push_back(InOrder{sum, date, contractor, employee, basis});
        else if (type == "��������� �����")
            outOrders.push_back(OutOrder{sum, date, contractor, employee, basis});
        else break;
    }
    in.close();
}

void OrderManager::createInOrder() {
    double sum;
    string employee, basis, line, date;
    Contractor contractor;
    cout << "������� ����� ��������:\n";
    getline(cin, line);
    sum = stod(line);
    cout << "������� ���� � ������� ��.��.����:\n";
    getline(cin, date);
    cout << "������� ����������� (�������� �����):\n";
    getline(cin, contractor.name);
    cout << "������� ����� ����� �����������:\n";
    getline(cin, contractor.account_number);
    cout << "������� ����������:\n";
    getline(cin, employee);
    cout << "������� ��������� ��������:\n";
    getline(cin, basis);

    inOrders.push_back(InOrder{sum, date, contractor, employee, basis});
}

void OrderManager::createOutOrder() {
    double sum;
    string employee, basis, date, line;
    Contractor contractor;
    cout << "������� ����� ��������:\n";
    getline(cin, line);
    sum = stod(line);
    cout << "������� ���� � ������� ��.��.����:\n";
    getline(cin, date);
    cout << "������� ����������� (�������� �����):\n";
    getline(cin, contractor.name);
    cout << "������� ����� ����� �����������:\n";
    getline(cin, contractor.account_number);
    cout << "������� ����������:\n";
    getline(cin, employee);
    cout << "������� ��������� ��������:\n";
    getline(cin, basis);

    outOrders.push_back(OutOrder{sum, date, contractor, employee, basis});
}

void OrderManager::printOrders() {
    printOrders(inOrders, outOrders);
}

void OrderManager::printOrders(vector<InOrder> inOrd, vector<OutOrder> outOrd) {
    sort(begin(inOrd), end(inOrd));
    sort(begin(outOrd), end(outOrd));
    size_t i = 0, j = 0;
    while (i < inOrd.size() && j < outOrd.size()) {
        if (inOrd[i].get_date() < outOrd[j].get_date()) {
            cout << inOrd[i];
            i++;
        } else {
            cout << outOrd[j];
            j++;
        }
    }
    for (; i < inOrd.size(); i++)
        cout << inOrd[i];
    for (; j < outOrd.size(); j++)
        cout << outOrd[j];
}

OrderFilter OrderManager::createOrderFilter() {

    double fsum;
    string femployee, fbasis, fdate, fContractorName, fContractorAcc, line;
    OrderFilter filter;
    cout << "����������� �� ����? (1 - ��, 2 - ���)\n";
    getline(cin, line);
    if (line == "1") {
        filter.filterByDate = true;
        cout << "������� ���� � ������� ��.��.����:\n";
        getline(cin, fdate);
        filter.fdate = Date(fdate);
    }
    cout << "����������� �� ����� ��������? (1 - ��, 2 - ���)\n";
    getline(cin, line);
    if (line == "1") {
        filter.filterBySum = true;
        cout << "������� ����� ��������:\n";
        getline(cin, line);
        fsum = stod(line);
        filter.fsum = fsum;
    }
    cout << "����������� �� �����������? (1 - ��, 2 - ���)\n";
    getline(cin, line);
    if (line == "1") {
        filter.filterByContractor = true;
        cout << "������� ����������� (�������� �����):\n";
        getline(cin, fContractorName);
        cout << "������� ����� ����� �����������:\n";
        getline(cin, fContractorAcc);
        filter.fcontractor = Contractor(fContractorName, fContractorAcc);
    }
    cout << "����������� �� ����������? (1 - ��, 2 - ���)\n";
    getline(cin, line);
    if (line == "1") {
        filter.filterByEmployee = true;
        cout << "������� ����������:\n";
        getline(cin, femployee);
        filter.femployee = femployee;
    }
    cout << "����������� �� ��������� ��������? (1 - ��, 2 - ���)\n";
    getline(cin, line);
    if (line == "1") {
        filter.filterByBasis = true;
        cout << "������� ��������� ��������:\n";
        getline(cin, fbasis);
        filter.fbasis = fbasis;
    }
    return filter;
}

void OrderManager::printFilteredOrders(OrderFilter &filter) {
    vector<InOrder> filteredInOrders;
    vector<OutOrder> filteredOutOrders;

    for(auto order : inOrders) {
        if (filter.filterByDate && (order.get_date() != filter.fdate))
            continue;
        if (filter.filterBySum && (order.get_sum() != filter.fsum))
            continue;
        if (filter.filterByEmployee && (order.get_employee() != filter.femployee))
            continue;
        if (filter.filterByContractor && (order.get_contractor() != filter.fcontractor))
            continue;
        if (filter.filterByBasis && (order.get_basis() != filter.fbasis))
            continue;
        filteredInOrders.push_back(order);
    }

    for(auto order : outOrders) {
        if (filter.filterByDate && (order.get_date() != filter.fdate))
            continue;
        if (filter.filterBySum && (order.get_sum() != filter.fsum))
            continue;
        if (filter.filterByEmployee && (order.get_employee() != filter.femployee))
            continue;
        if (filter.filterByContractor && (order.get_contractor() != filter.fcontractor))
            continue;
        if (filter.filterByBasis && (order.get_basis() != filter.fbasis))
            continue;
        filteredOutOrders.push_back(order);
    }
    printOrders(filteredInOrders, filteredOutOrders);
}

void OrderManager::printBalance() {
    printBalance(inOrders, outOrders);
}

void OrderManager::printBalance(vector<InOrder> inOrd, vector<OutOrder> outOrd) {
    sort(begin(inOrd), end(inOrd));
    sort(begin(outOrd), end(outOrd));
    string dateStr;
    cout << "������� ���� ��� ��������� ������� � ������� ��.��.����:\n";
    getline(cin, dateStr);
    Date date(dateStr);
    balance = 0.0;


    for (size_t i = 0; i < inOrd.size(); i++) {
        if (inOrd[i].get_date() <= date) {
            balance = balance + inOrd[i].get_sum();
        }
    }

    for (size_t i = 0; i < outOrd.size(); i++) {
        if (outOrd[i].get_date() <= date) {
            balance = balance - outOrd[i].get_sum();
        }
    }

    cout << "������ �� ���� " << date << ": " << setprecision(15) << balance;
}
