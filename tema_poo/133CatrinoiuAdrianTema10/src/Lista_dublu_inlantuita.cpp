#include "Lista_dublu_inlantuita.h"
//Nod
Nod::Nod()
{
    info=0;
    next=NULL;
    prev=NULL;
}
Nod::Nod(int info)
{
    this->info=info;
    this->prev=NULL;
    this->next=NULL;
}
Nod::Nod(const Nod& ob)
{
    this->info=ob.info;
    this->prev=ob.prev;
    this->next=ob.next;
}
int Nod::getInfo(){
     return info;
}
void Nod::setInfo(int val)
{
    info=val;
}
Nod* Nod::getNext(){
     return next;
    }
void Nod::setNext(Nod *n)
{
    next=n;
}
Nod* Nod::getPrev(){
     return prev;
    }
void Nod::setPrev(Nod *n)
{
    prev=n;
}
Nod::~Nod()
{
    this->info=0;
    this->next=NULL;
    this->prev=NULL;
}



//Lista_dublu_inlantuita
Lista_dublu_inlantuita::Lista_dublu_inlantuita()
{
    this->l=0;
    this->cap=NULL;
    this->ultim=NULL;
}
Nod* Lista_dublu_inlantuita::getFirst(){
     return cap;
    }
void Lista_dublu_inlantuita::setFirst(Nod* n)
{
    cap=n;
}


Nod* Lista_dublu_inlantuita::getLast(){
  return ultim;
    }
void Lista_dublu_inlantuita::setLast(Nod* n)
{
    ultim=n;
}
int Lista_dublu_inlantuita::getLungime()
{
    return l;
}

Nod* Lista_dublu_inlantuita::cautarePozitie( int pozitie)
{
    int i = 0;  //Pozitia curenta
    //Parcurgem lista pana la pozitia curenta, sau
    //pana ajungem la ultimul element al listei
    while (cap != NULL && i < pozitie)
    {
        cap = cap->next;
        i++;
    }
    //In cazul in care am gasit pozitia ceruta, o returnam
    if (i == pozitie)
        return cap;
    else
        return NULL;
}
/*
void Lista_dublu_inlantuita::InserareElement(Nod* element_dat, int valoare)
{
    //Creeam noul nod si ii atribuim valoarea din paramentru
    Nod* elem = new Nod;
    elem->info = valoare;
    elem->next = NULL;
    elem->prev = NULL;
    if (cap == NULL)
    {
        cap = elem;
        return;
    }
    if (cap == element_dat)
    {
        elem->next = cap;
        cap->prev = elem;
        cap = elem;
        return;
    }
    elem->next = element_dat->next;
    elem->prev = element_dat;
    element_dat->next->prev = elem;
    element_dat->next = elem;
}
void Lista_dublu_inlantuita::InserareElementPozitie( int pozitie, int info)
{
    if (pozitie==0)
    {
         //Creeam noul nod si ii atribuim valoarea din paramentru
    Nod* elem =new Nod;
    elem->info=info;
    elem->next=cap; //Mutam sageata catre primul element din lista
    elem->prev=NULL;
    if(cap != NULL)
        cap->prev=elem; // Actualizam sageata primului element din lista

    cap = elem; //Inlocuim primul element din lista
    }
    else
    {
        Nod* predecesor=cautarePozitie(pozitie);
        InserareElement(predecesor,info);
    }
}*/
void Lista_dublu_inlantuita::stergereElement(Nod* elem)
{
    elem->prev->next = elem->next;
    elem->next->prev = elem->prev;
    delete elem;
}
void Lista_dublu_inlantuita::StergereElementPozitie(int pozitie)
{
    if (pozitie == 0)
    {
        Nod* victima = cap;
        cap = cap->next;
        cap->prev = NULL;
        delete victima;
    }
    else
    {
        Nod* predecesor = cautarePozitie(pozitie);
        stergereElement(predecesor);
    }
}
void Lista_dublu_inlantuita::AdaugareLista(int pozitie,int info)
{
    Nod* p=new Nod;

    p->setInfo(info);
    if(cap==NULL)
    {
        cap=p;
        ultim=p;
        l=1;

        return;
    }
    if(pozitie> l)
    {
        ultim->setNext(p);
        p->setPrev(ultim);
        ultim=p;

        l++;
        return;
    }
    if(pozitie<=1)
    {
        cap->setPrev(p);
        p->setNext(cap);
        cap=p;
        l++;

        return;
    }
    else
    {
        Nod *prev=cap;
        Nod *next=cap->getNext();
        for(int i=1;i<pozitie-1;i++)
        {
            prev=next;
            next=next->getNext();
        }
        prev->setNext(p);
        next->setPrev(p);
        p->setPrev(prev);
        p->setNext(next);
        std::cout<<"asd ";
        l++;
    }
}
std::istream& operator >> (std::istream& input, Lista_dublu_inlantuita& lista)
{
    std::cout<<"Nod:";
    int val;
    input>>val;
    lista.AdaugareLista(lista.getLungime()+1,val);
    return input;
}
std::ostream& operator << (std::ostream& output, Lista_dublu_inlantuita& lista)
{
    Nod* p=lista.getFirst();
    while(p){
      std::cout<<p->getInfo()<<",";
      p=p->getNext();
     }
     std::cout<<'\n';
     Nod* u=lista.getLast();
     while(u)
     {
         std::cout<<u->getInfo()<<",";
         u=u->getPrev();
     }
     std::cout<<'\n';
     return output;
}
Lista_dublu_inlantuita operator+(Lista_dublu_inlantuita lista1,Lista_dublu_inlantuita lista2)
{
    Lista_dublu_inlantuita copie;
    Nod *nou=new Nod;
    nou=lista1.getFirst();
    while(nou!=NULL)
    {
        copie.AdaugareLista(copie.getLungime()+1,nou->getInfo());
        nou=nou->getNext();
    }
    nou=lista2.getFirst();
    while(nou!=NULL)
    {
        copie.AdaugareLista(copie.getLungime()+1,nou->getInfo());
        nou=nou->getNext();
    }
    return copie;
}
Lista_dublu_inlantuita::~Lista_dublu_inlantuita()
{
    Nod *p=cap;
       Nod *q;
       //se elibereaza spatiul de memorie rezervat elementelor listei/
       while(p!=0){
          q = p;
        p = p->next;
          delete q;
       }
       cap=ultim = 0;
}
