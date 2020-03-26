#include <iostream>
#include<Lista_dublu_inlantuita.h>
using namespace std;

int main()
{

    Lista_dublu_inlantuita lista1,lista2,lista3;
    int i,n;
    cout<<"Lungime Prima Lista:"<<'\n';
    cin>>n;
    lista1.Citire(n);

    cout<<"Lista 1:"<<lista1;
    cout<<'\n';
    cout<<"Stergere lista 1";
    cout<<'\n';
    lista1.StergereElementPozitie(1);
    cout<<"Lista 1:"<<lista1;
    cout<<'\n';
    cout<<"Lungime a 2-a Lista:"<<'\n';
    cin>>n;
    lista2.Citire(n);

    cout<<"Lista 2:"<<lista2;
    cout<<'\n';
    cout<<"Stergere lista 2";
    cout<<'\n';
    lista2.StergereElementPozitie(2);
    cout<<"Lista 2:"<<lista2;
    cout<<'\n';

    lista3=lista1+lista2;
    cout<<lista3;
    return 0;
}
