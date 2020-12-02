// Actividad Integral de BST
// Programa que crea una BST, lo ordena y despliega los datos conforme a la cantidad de consulta de los IPs de manera ascendente.
// Autores: Leonardo Delgado Rios (A00827915), Luis Fernando Tarango Felix (A00827678)
// Fecha de ultima modificacion: 10/25/20
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#include "BST.h"

int main(){
  BST lista;
  ifstream bit("bitacoraOrdenada.txt");
  string x;
  long long key;

  while (bit.good()){
    getline(bit,x);
    key=lista.makeKey(x);
    lista.add(x,key);
  }
  cout << "Altura del arbol: "<< lista.height()<< endl;

  int mayor = lista.consultaMayor();
  cout << "El mayor número de consultas es: " << mayor << endl;
  
  cout << "Las 5 IPs más consultadas son: "<< endl; lista.muestraMayor(mayor);
}   