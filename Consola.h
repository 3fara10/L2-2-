#ifndef 
#define 

typedef int TElem;

class Collection {
private:
    TElem *valoare;
    int *occurrences;
    int distinctelements;
    int capacity;
public:
    Collection();
    //Collection(const Collection &c);
    void add(TElem v, int k);
    void resize();
    int size();


    int get_occ(int poz);
    int get_val(int poz);

    int get_occurrences_element(TElem elem);

    void afis();
    void set_distinctsElements(int d);
    void set_Occurrences(TElem elem, int occ);
    int searchPoz(TElem v);
    Collection& operator=(Collection colectie);

    ~Collection();
};



#endif 
