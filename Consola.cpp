#include "Consola.h"
#include <iostream>
using namespace std;

void printMenu(){
    cout<<"1. Stocare bancnote\n";
    cout<<"2. Inregistrare tranzactii\n";
    cout<<"3. Afisare bancnote\n";
    cout<<"4. Afisare tranzactii\n";
    cout<<"0. Iesire\n";
}

void creareColectie(Collection &colectie){
    int n;
    cout<<"numarul de bancnote: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        int valoare, nr_exemplare;
        cout<<"valoare: ";
        cin>>valoare;
        cout<<"numar exemplare: ";
        cin>>nr_exemplare;
        colectie.add(valoare, nr_exemplare);
    }
}

void creeareAtm(ATM &atm, Collection &colectie){
    //colectie = Collection();
    //creareColectie(colectie);
    atm = ATM(colectie);
}

void print_bancnote(ATM &atm){
    int size = atm.getCollection().size();
    for(int poz = 0; poz < size; poz++){
        cout<<atm.get_val(poz)<<" "<<atm.get_occ(poz)<<endl;
    }
}

void afisare_suma(Tranzaction t){
    int size = t.get_noElements();
    for(int poz = 0; poz < size; poz++){
        cout<<"valoare: "<<t.get_type(poz)<<"; frecventa: "<<t.get_occ(poz)<<endl;
    }
}

void cerinta2(ATM &atm){
    int suma;
    cout<<"Introduceti suma: ";
    cin>>suma;
    Tranzaction t = atm.verificare_suma(suma);
    int size = t.get_noElements();
    //cout<<"eroare1";
    if(size == 0)
        cout<<"nu exista bancnote pentru suma solicitata\n";
    else{
        afisare_suma(t);
        cout<<"apasati 1 pentru salvare si 0 in caz contrar";
        bool ok;
        cin>>ok;
        if(ok)
            atm.add_tranzactie(t);
    }
}

void cerinta4(ATM atm){
    Tranzaction *tranz = atm.getAllTranzactions();
    int size = atm.get_noTranzactii();
    for(int poz = 0; poz < size; poz++){
        cout<<"id: "<<tranz[poz].get_id()<<" ";
        afisare_suma(tranz[poz]);
        cout<<endl;
    }
}

void Consola::consola() {
    int optiune;
    ATM atm;
    Collection colectie;
    creeareAtm(atm, colectie);
    do{
        printMenu();
        cout<<"optiune: ";
        cin>>optiune;
        switch(optiune){
            case 1:
                creareColectie(colectie);
                creeareAtm(atm, colectie);
                cout<<endl;
                break;
            case 2:
                cerinta2(atm);
                break;
            case 3:
                print_bancnote(atm);
                break;
            case 4:
                cerinta4(atm);
                break;
            case 0:
                cout<<"La revedere!\n";
                break;
            default:
                cout<<"Optiune invalida\n";
        }
    }while(optiune != 0);
