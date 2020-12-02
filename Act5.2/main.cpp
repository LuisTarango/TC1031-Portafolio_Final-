// Actividad Integral de Hash Tables
// Programa que crea un genera una hashtable para la bitacora y se puede realizar una bisqueda por medio de llaves(ip)
// Autores: Leonardo Delgado Rios (A00827915), Luis Fernando Tarango Felix (A00827678)
// Fecha de ultima modificacion: 11/28/20

#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <vector>

using namespace std;

// Datos del resumen de cada acceso de las ips
struct resumen{
    string month;
    string day;
    string time;
    string reason;
};

// Complejidad O(1) 
// Convierte la ip en el formato de llave (remueve el puerto)
string ipToKey(string ip){
    string ip2;
    ip2=ip.substr(0,ip.size()-5);
    return ip2;
}

// Complejidad O(n) 
// Carga los datos a la HashTable
void loadData(string file, unordered_map<string,vector<resumen>> &hashT){
    fstream bit;
    ifstream bit2;
    bit.open(file.c_str());
    bit2.open(file);

    string ip,line,line2, month, time, day, reason;
    struct resumen res;


    cout<<"Loading Data..."<<endl;   
    while (!bit.eof()){
        getline(bit2,line2);
        if (line2.size()==0){break;}

        bit>>month;
        bit>>day;
        bit>>time;
        bit>>ip;
        ip=ipToKey(ip);
        getline(bit,line);
        line=line.substr(1,line.size());
        res.month=month;
        res.day=day;
        res.time=time;
        res.reason=line;

        hashT[ip].push_back(res);
    }
    cout<<"Done"<<endl;
}

// Complejidad O(n)
// recibe una IP e imprime los resultados de la su bsuqueda en la HashTable
void hashSearch(string ip,unordered_map<string,vector<resumen>> &hashT){
    if (hashT[ip].size()==0){cout<<"IP not found in database"<<endl;}
    else{
        cout<<"Accessed "<<hashT[ip].size()<<" times"<<endl;
        cout<<"Summary for "<<ip<<":"<<endl;
    }
    for (int i=0;i<hashT[ip].size();i++){
        cout<<"["<<i+1<<"]";
        cout<<hashT[ip][i].month<<" ";
        cout<<hashT[ip][i].day<<" ";
        cout<<hashT[ip][i].time<<" ";
        cout<<hashT[ip][i].reason<<endl;
    }
}


// Programa que crea un genera una hashtable para la bitacora y se puede realizar una bisqueda por medio de llaves(ip)
int main(){
    unordered_map<string,vector<resumen>> hashT;

    string file="bitacoraACT5_2.txt";

    loadData(file,hashT);
    string ip;
    string ask;

    cout<<"Look for IP? Yes (Y) No (N)"<<endl;
    cin>>ask;
    while (ask=="Y"){
        cout<<"Enter IP you want to look for:"<<endl;
        cin>>ip;
        hashSearch(ip,hashT);
        cout<<"Look for another IP? Yes (Y) No (N)"<<endl;
        cin>>ask;
    }
}