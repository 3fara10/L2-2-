//
// Created by Home on 10.05.2024.
//
#pragma once
#include "money.h"
#include "vectordinamic.h"

class Tranzactie
{
private:
    int idTranzactie;
    double suma;
    VectorDinamic<Money> bancnote;

public:
    Tranzactie();
    Tranzactie(double newSum);
    Tranzactie(double newSum, const VectorDinamic<Money>& newBancnote);

    int getId() const;
    double getSuma() const;
    int getSize() const;
    //get bancnote
    Money* getAll() const;

    void setId(int newId);
    void setSuma(double newSuma);
    void setMoney(int position, const Money& money);
};

//
// Created by Home on 10.05.2024.
//
#pragma once
#include"tranzactie.h"

inline Tranzactie::Tranzactie(): idTranzactie(0)
{
    this->suma = 0;
}

inline Tranzactie::Tranzactie(double newSum): idTranzactie(0)
{
    this->suma = newSum;
}

inline Tranzactie::Tranzactie(double newSum, const VectorDinamic<Money>& newBancnote): idTranzactie(0)
{
    this->suma = newSum;
    this->bancnote = newBancnote;
}

inline int Tranzactie::getId() const
{
    return this->idTranzactie;
}

inline double Tranzactie::getSuma() const
{
    return this->suma;
}

inline int Tranzactie::getSize() const
{
    return this->bancnote.size();
}

inline Money* Tranzactie::getAll() const
{
    Money* bancnote = new Money[this->bancnote.size()]();
    for (int i = 0; i < this->bancnote.size(); i++)
    {
        bancnote[i] = this->bancnote.getAt(i);
    }
    return bancnote;
}

inline void Tranzactie::setId(int newId)
{
    this->idTranzactie = newId;
}

inline void Tranzactie::setSuma(double newSuma)
{
    this->suma = newSuma;
}

inline void Tranzactie::setMoney(int position, const Money& money)
{
    Money x = this->bancnote.update(position, money);
}
