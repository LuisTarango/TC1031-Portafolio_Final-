// Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales
// Programa que crea una DoubleLinkedList y la ordena y despliega los datos conforme a los IPs ordenados
// Autores: Leonardo Delgado Rios (A00827915), Luis Fernando Tarango Felix (A00827678)
// Fecha de ultima modificacion: 10/09/20

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include "DoubleLinkedList.h"

int main(){
    DoubleLinkedList lista;
    ifstream bit("bitacora.txt");
    string x;
    string ip1,ip2;

    long long key;
    while (bit.good()){
        getline(bit,x);
        key=lista.makeKey(x);
        lista.addLast(x,key);
    }

    lista.sort();
    cout<<"Ingrese rango inicial para busqueda de ips"<<endl;
    cin>>ip1;
    cout<<"Ingrese rango final para busqueda de ips"<<endl;
    cin>>ip2;
    lista.search(ip1,ip2);
}   