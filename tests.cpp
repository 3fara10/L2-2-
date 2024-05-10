//
// Created by Home on 10.05.2024.
//
#pragma once
#include <cassert>
#include <iostream>
#include <stdexcept>
#include "collection.h"
#include "vectordinamic.h"
#include"tranzactie.h"
#include"money.h"
void testConstructor()
{
    try
    {
        VectorDinamic<int> x(2);
        VectorDinamic<int> y(-3);
        assert(false);
    }
    catch(std::invalid_argument ex)
    {
        assert(true);
        //std::cout<<ex.what()<<std::endl;
    }
}

void testMoneyClass()
{
    // Test default constructor
    Money money1;
    assert(money1.getValue() == 0.0);
    assert(money1.getOccurrences() == 0);

    // Test parameterized constructor
    Money money2(10.5, 2);
    assert(money2.getValue() == 10.5);
    assert(money2.getOccurrences() == 2);

    // Test setters and getters
    money1.setValue(15.75);
    money1.setOccurences(3);
    assert(money1.getValue() == 15.75);
    assert(money1.getOccurrences() == 3);

    assert(money2 < money1);
}

void testCollection() {
    Collection<int> coll;

    // Test add and size methods
    coll.add(10);
    coll.add(20);
    coll.add(30);
    assert(coll.size() == 3);

    // Test search method
    assert(coll.search(10) == true);
    assert(coll.search(40) == false);

    // Test occurrences method
    assert(coll.nroccurrences(10) == 1);
    assert(coll.nroccurrences(20) == 1);
    assert(coll.nroccurrences(30) == 1);
    assert(coll.nroccurrences(40) == 0);

    // Test remove method
    assert(coll.remove(20) == true);
    assert(coll.size() == 2);
    assert(coll.search(20) == false);
    assert(coll.nroccurrences(20) == 0);

    // Test assignment operator
    Collection coll2 = coll;
    assert(coll2.size() == 2);
    assert(coll2.search(10) == true);
    assert(coll2.search(30) == true);
}
void testTransaction()
{
    // Test default constructor
    Tranzactie tranzactie1;
    assert(tranzactie1.getId() == 0);
    assert(tranzactie1.getSuma() == 0);

    // Test parameterized constructor
    VectorDinamic<Money> bancnote;
    bancnote.push_back(Money(10, 5));
    bancnote.push_back(Money(20, 3));
    Tranzactie tranzactie2(200.0, bancnote);
    assert(tranzactie2.getSuma() == 200.0);

    // Test setter and getter methods
    tranzactie1.setId(1);
    tranzactie1.setSuma(100.0);
    assert(tranzactie1.getId() == 1);
    assert(tranzactie1.getSuma() == 100.0);

    // Test getAll method
    Money* allBancnote1 = tranzactie1.getAll();
    assert(allBancnote1 != nullptr);
    assert(tranzactie1.getSuma() == 0); // No money added yet

    Money* allBancnote2 = tranzactie2.getAll();
    assert(allBancnote2 != nullptr);
    assert(tranzactie2.getSuma() == 200.0); // Sum of the money added

    // Test setMoney method
    tranzactie1.setMoney(0, Money(50, 2));
    assert(tranzactie1.getSuma() == 50 * 2); // Total sum should be 100

}
void tests()
{
    testCollection();
    testConstructor();
    testMoneyClass();

}