// Actividad Integral de Grafos
// Programa que crea un grafo y despliega los datos conforme a la cantidad de consulta de los IPs de manera descendente.
// Autores: Leonardo Delgado Rios (A00827915), Luis Fernando Tarango Felix (A00827678)
// Fecha de ultima modificacion: 11/20/20
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Función que carga los datos dentro del archivo txt a una Lista de Adj.
// Complejidad O(n+m)
void makeAdjList(vector<vector<string>> &listAdj, string file, int n, int m){
    fstream bit;
    bit.open(file.c_str());
    string ip,ip2,trash, newip, newip2;
    bit>>trash;
    bit>>trash;
    //pair<string, string> ips;
    cout<<"Cargando Lista..."<<endl;
    for (int i=0;i<n;i++){
        bit>>ip;
        listAdj[i].push_back(ip);
    }
    
    for (int i=0;i<m;i++){
        while (1==1){
            
            if (trash=="Jan"||trash=="Feb"||trash=="Mar"||trash=="Apr"||trash=="May"||trash=="Jun"||trash=="Jul"||trash=="Aug"||trash=="Sep"||trash=="Oct"||trash=="Nov"||trash=="Dec"){break;}
            bit>>trash;

        }
        bit>>trash;
        bit>>trash;
        bit>>ip;
        bit>>ip2;

        newip="";
        newip2="";
        for (int i=0; i<ip.size();i++){
            if (ip[i]==':'){break;}
            else{newip.push_back(ip[i]);}
        }
        for (int i=0; i<ip2.size();i++){
            if (ip2[i]==':'){break;}
            else{newip2.push_back(ip2[i]);}
        }

        for (int i=0;i<n;i++){
            if (listAdj[i][0]==newip){
                listAdj[i].push_back(newip2);
            }/*if (listAdj[i][0]==newip2){
                listAdj[i].push_back(newip);
            }*/
        }
    }
    cout<<"Completado"<<endl;
}

// Función que muestra los datos que contiene nuestra Lista de Adj.
// Complejidad O(n+m)
void printListAdj(vector<vector<string> > &listAdj){
    ofstream bitGraph("grafoBit.txt");
	for (int i=0; i<listAdj.size(); i++){
		//cout<<listAdj[i][0];
        bitGraph<<listAdj[i][0];
        for (int j=0; j<listAdj[i].size();j++){
            //cout<<" - "<<listAdj[i][j];
            bitGraph<<" - "<<listAdj[i][j];
        }//cout<<endl;
        bitGraph<<endl;
	}
}

// Función que muestra los datos con un mayor de intentos de acceso dentro de la Lista de Adj.
// Complejidad O(n+m)
void muestraMayor(vector<vector<string> > &listAdj, int &mayor){
  for (int i=0;i<listAdj.size();i++){
    if (listAdj[i].size()>mayor){
      mayor = listAdj[i].size();
    }
  }
	for (int i=0; i<listAdj.size(); i++){
    if(listAdj[i].size() == mayor) {
      cout<<"IP: " << listAdj[i][0] << " con un número de intentos de: " << mayor-1 << endl;
    }
	}
}

int main(){
    string file="bitacoraACT4_3_B.txt";

    fstream bit;
    bit.open(file.c_str());
    int n,m, mayor=0;
    string n1,m1;
    bit>>n1;
    bit>>m1;
    n=stoi(n1);
    m=stoi(m1);

    vector<vector <string>> listAdj(n);

    makeAdjList(listAdj,file,n,m);
    muestraMayor(listAdj, mayor);
    //printListAdj(listAdj);                //Si se desea sacar la lista de ayacencai a un archivo
}