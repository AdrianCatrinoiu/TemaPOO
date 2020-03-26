#include<iostream>

class Nod
{

    int info;
    Nod* prev;
    Nod* next;
public:
    Nod();
    Nod(int info);
    Nod(const Nod&);
    int getInfo();
    void setInfo(int val);
    Nod* getNext();
    void setNext(Nod* n);
    Nod* getPrev();
    void setPrev(Nod* n);
    friend class Lista_dublu_inlantuita;
    ~Nod();
};


class Lista_dublu_inlantuita
{
    int l;
    Nod* cap;
    Nod* ultim;

    public:
        friend class Nod;
        Lista_dublu_inlantuita();
        //Lista_dublu_inlantuita(const Lista_dublu_inlantuita&);
        ~Lista_dublu_inlantuita();
        Nod* getFirst();
        void setFirst(Nod* n);
        Nod* getLast();
        void setLast(Nod* n);
        int getLungime();
        //Nod* cautarePozitie( int pozitie);
        void AdaugareLista(int pozitie,int info);
        void Citire(int n);
        //void InserareElement( Nod* element_dat, int valoare);
       // void InserareElementPozitie( int pozitie, int info);
        //void stergereElement(Nod* elem);
        void StergereElementPozitie(int pozitie);
        friend std::istream& operator>>(std::istream&, Lista_dublu_inlantuita&);
        friend std::ostream& operator<<(std::ostream&, Lista_dublu_inlantuita&);
        friend Lista_dublu_inlantuita operator+( Lista_dublu_inlantuita &lista1, Lista_dublu_inlantuita& lista2);

};


