//
// Created by Home on 10.05.2024.
//
#pragma once
#ifndef MONEY_H
#define MONEY_H
#include <istream>

#endif //MONEY_H
#pragma once

using namespace std;
class Money {
private:
    double value;
    int occurrences;
public:
    Money();
    Money(double newValue,int newOccurrences);
    ~Money();

    double getValue() const;
    int getOccurrences() const;
    void setValue(double newValue);
    void setOccurences(int newOccurrences);

    bool operator <(const Money& money) const;
    friend ostream& operator<<(ostream& os, const Money& money);
    friend istream& operator>>(istream& is, Money& money);
    Money& operator=(const Money& newMoney);
};
