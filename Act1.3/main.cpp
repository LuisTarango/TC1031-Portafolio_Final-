// Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales
// Programa que ordena una bitacora y despliega los datos de manera ascendente en un rango de tiempo
// Autores: Leonardo Delgado Rios (A00827915), Luis Fernando Tarango Felix (A00827678)
// Fecha de ultima modificacion: 09/12/20

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Crea un indice para facilitar el ordenamiento de fecha y crea un digito a partir de esta 
//(ejemplo Jul 28 quedaria grabado en el indice como 728 en la posicion[i] que su contraparte en la bitacora)
// Complejidad: O(n)
vector<int> index(vector<string> bit, int n){
    vector<int> arr;
    string line;
    string temp;
    string mo;
    string d;
    int mon;
    int day;
    
    for (int i=0;i<n;i++){
        mo.clear();
        d.clear();
        line=bit[i];
        for (int m=0;m<3;m++){
            temp=line[m];   
            mo.append(temp);
        }
        if (mo=="Jan"){mon=1;}if (mo=="Feb"){mon=2;}if (mo=="Mar"){mon=3;}if (mo=="Apr"){mon=4;}if (mo=="May"){mon=5;}if (mo=="Jun"){mon=6;}
        if (mo=="Jul"){mon=7;}if (mo=="Aug"){mon=8;}if (mo=="Sep"){mon=9;}if (mo=="Oct"){mon=10;}if (mo=="Nov"){mon=11;}if (mo=="Dec"){mon=12;}
        for (int j=4; j<6;j++){
            temp=line[j];
            if(temp==" "){break;}
            d.append(temp);
            day=stoi(d);
        }
        arr.push_back((mon*100)+day);
    }
    return arr;
}

//Ordena los vectores en bitacora
// Complejidad: O(n)
void une(vector<int> &index,vector<int> &ax,vector<string> &bit,vector<string> &aux,int ini,int fin) {
    int m = (ini+fin)/2;
    int i = ini, j = m+1, k = ini;
    while(i<=m && j<=fin) {
        if(index[i] <= index[j]) { // forma ascendente
          // forma descendente index[i] >= index[j]
            aux[k] = bit[i];
            ax[k++] = index[i++];
        }
        else {
            aux[k] = bit[j];
            ax[k++] = index[j++];
        }
    }
    while(i<=m) {
        aux[k] = bit[i];
        ax[k++] = index[i++];
    }
    while(j<=fin) {
        aux[k] = bit[j];
        ax[k++] = index[j++];
    }
    for(int z=ini; z<=fin; z++) {
        index[z] = ax[z];
        bit[z] = aux[z];
    }
}

//Ordena los vectores en bitacora
// Complejidad: O(n log n)
void merge(vector<int> &index,vector<int> &ax,vector<string> &bit,vector<string> &aux,int ini,int fin) {
    if(ini < fin) {
        int m = (ini + fin)/2;
        merge(index,ax,bit,aux,ini,m);
        merge(index,ax,bit,aux,m+1,fin);
        une(index,ax,bit,aux,ini,fin);
    }
}

//Realiza la Busqueda entre las fechas de inicio y fin selecionadas por el usuario
// Complejidad: O(n)
void search(int month1, int day1, int month2, int day2,vector<int> index,vector<string> bit){
    int start=(month1*100)+day1;
    int finish=(month2*100)+day2;
    for (int i=0;i<bit.size();i++){
        if (index[i]>=start && index[i]<=finish){
            cout<<bit[i]<<endl;
        }
    }
}

int main(){
    ifstream bit("bitacora.txt");
    vector<string> arrbit;
    string x;
    int y;
    while (bit.good()){
        getline(bit,x);
        arrbit.push_back(x);
    }
    bit.close();cout<<"Files Loaded...\n";
    int n=arrbit.size();
    vector<int> ind, ax(n);
    vector<string> aux(n);

    ind=index(arrbit,n);
    
    merge(ind,ax,arrbit,aux,0,n-1);
    
    ofstream bitOrder("bitacoraOrdenada.txt");
    for (int i=0;i<arrbit.size();i++){
        if (i==arrbit.size()-1){
            bitOrder<<arrbit[i];
        }else{bitOrder<<arrbit[i]<<endl;}
    }
    bitOrder.close();cout<<"Ordered file complete...\n";

    int day1,month1,day2,month2;
    string mo1,mo2;
    cout<<"Enter desired starting month (Jan-Dec):\n";
    cin>>mo1;
    cout<<"Enter desired starting day (1-31):\n";
    cin>>day1;
    cout<<"Enter desired end month (Jan-Dec):\n";
    cin>>mo2;
    cout<<"Enter desired end day (1-31):\n";
    cin>>day2;
    if (mo1=="Jan"){month1=1;}if (mo1=="Feb"){month1=2;}if (mo1=="Mar"){month1=3;}if (mo1=="Apr"){month1=4;}if (mo1=="May"){month1=5;}if (mo1=="Jun"){month1=6;}
    if (mo1=="Jul"){month1=7;}if (mo1=="Aug"){month1=8;}if (mo1=="Sep"){month1=9;}if (mo1=="Oct"){month1=10;}if (mo1=="Nov"){month1=11;}if (mo1=="Dec"){month1=12;}
    if (mo2=="Jan"){month2=1;}if (mo2=="Feb"){month2=2;}if (mo2=="Mar"){month2=3;}if (mo2=="Apr"){month2=4;}if (mo2=="May"){month2=5;}if (mo2=="Jun"){month2=6;}
    if (mo2=="Jul"){month2=7;}if (mo2=="Aug"){month2=8;}if (mo2=="Sep"){month2=9;}if (mo2=="Oct"){month2=10;}if (mo2=="Nov"){month2=11;}if (mo2=="Dec"){month2=12;}
    
    search(month1,day1,month2,day2,ind,arrbit);
}