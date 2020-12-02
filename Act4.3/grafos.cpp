#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

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


void printListAdj(vector<vector<string> > &listAdj){
    ofstream bitGraph("grafoBit.txt");
	for (int i=0; i<listAdj.size(); i++){
		//cout<<listAdj[i][0];
        bitGraph<<listAdj[i][0];
        for (int j=1; j<listAdj[i].size();j++){
            //cout<<" - "<<listAdj[i][j];
            bitGraph<<" - "<<listAdj[i][j];
        }//cout<<endl;
        bitGraph<<endl;
	}
}

void fanOuts(vector<vector<string>> &listAdj){
    int num=0;
    for (int i=0;i<listAdj.size();i++){
        if (listAdj[i].size()>num){
            num=listAdj[i].size();
        }
    }
    for (int i=0;i<listAdj.size();i++){
        if (listAdj[i].size()==num){
            cout<<listAdj[i][0]<<" con "<<num-1<<" accesos intentados."<<endl;
        }
    }
}

int main(){
    string file="bitacoraACT4_3_B.txt";

    fstream bit;
    bit.open(file.c_str());
    int n,m;
    string n1,m1;
    bit>>n1;
    bit>>m1;
    n=stoi(n1);
    m=stoi(m1);

    vector<vector <string> > listAdj(n);

    makeAdjList(listAdj,file,n,m);
    //printListAdj(listAdj);                //Si se desea sacar la lista de ayacencai a un archivo
    cout<<endl<<"Mayor numero de FanOuts:"<<endl;
    fanOuts(listAdj);

}