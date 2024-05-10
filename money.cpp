#pragma once
#include "money.h"
Money::Money()
{
    this->value = 0;
    this->occurrences=0;
}

Money::Money(double newValue,int newOccurrences)
{
    this->value = newValue;
    this->occurrences=newOccurrences;
}

Money::~Money()
{
}

double Money::getValue() const
{
    return this->value;
}

int Money::getOccurrences() const
{
    return this->occurrences;
}

void Money::setValue(double newValue)
{
    this->value = newValue;
}

void Money::setOccurences(int newOccurrences)
{
    this->occurrences=newOccurrences;
}

bool Money::operator<(const Money& money) const
{
    return this->value < money.value;
}

Money& Money::operator=(const Money& newMoney)
{
    this->value=newMoney.value;
    this->occurrences=newMoney.occurrences;
    return *this;
}

ostream& operator<<(ostream& os, const Money& money)
{
    os << money.getValue();
    return os;
}

istream& operator>>(istream& is, Money& money)
{
    is >> money.value;
    return is;
}
