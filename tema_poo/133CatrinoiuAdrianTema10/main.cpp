#include <iostream>
#include<Lista_dublu_inlantuita.h>
using namespace std;

int main()
{

    Lista_dublu_inlantuita lista1,lista2,lista3;
    int i,n;
    for(int i=1;i<=4;i++)
    {
        lista1.AdaugareLista(i,i);
    }
    for(int i=1;i<=5;i++)
    {
        lista2.AdaugareLista(i,i);
    }
    cout<<lista1;
    cout<<'\n';
    cout<<lista2;
    lista3=lista1+lista2;
    cout<<lista3;
    return 0;
}
