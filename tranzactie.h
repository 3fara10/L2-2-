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
    Tranzactie(double newSum,VectorDinamic<Money> newBancnote);

    int getId();
    int getSuma();
    //get bancnote
    Money* getAll();

    void setId(int newId);
    void setSuma(double newSuma);
    void setMoney(int position,Money money);
};

//
// Created by Home on 10.05.2024.
//
#pragma once
#include"tranzactie.h"
inline Tranzactie::Tranzactie()
{
    this->suma=0;
}

Tranzactie::Tranzactie(double newSum)
{
    this->suma=newSum;
}

Tranzactie::Tranzactie(double newSum, VectorDinamic<Money> newBancnote)
{
    this->suma=newSum;
    this->bancnote=newBancnote;
}

int Tranzactie::getId()
{
    return this->idTranzactie;
}

int Tranzactie::getSuma()
{
    return this->suma;
}

Money* Tranzactie::getAll()
{
    return this->bancnote.getAll();
}

void Tranzactie::setId(int newId)
{
    this->idTranzactie=newId;
}

void Tranzactie::setSuma(double newSuma)
{
    this->suma=newSuma;
}

void Tranzactie::setMoney(int position, Money money)
{
    this->bancnote.setAt(position,money);
}

