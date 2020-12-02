// Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales
// Archivo .h que utilizará el programa que crea una DoubleLinkedList y la ordena y despliega los datos conforme a los IPs ordenados
// Autores: Leonardo Delgado Rios (A00827915), Luis Fernando Tarango Felix (A00827678)
// Fecha de ultima modificacion: 10/10/20 

#include "Node.h"

class DoubleLinkedList {
    public:
        DoubleLinkedList();
        ~DoubleLinkedList();
        void addFirst(string data, long long clave);
        void addLast(string data, long long clave);
        void deleteFirst();
        void deleteLast();
        int deleteAll();
        void printCont();
        void printReg();
        int getSize(); 
        bool isEmpty();
        long long makeKey(string data);
        long long ipToLong(string ip);
        void sort();
        void createFile();
        void search(string ip1, string ip2);
    private:
        Node *head;
        Node *tail;
        int size;
};

DoubleLinkedList :: DoubleLinkedList() {
    head = new Node;
    tail = new Node;
    head->setPrev(nullptr);
    tail->setNext(nullptr);
    head->setNext(tail);
    tail->setPrev(head);
    size = 0;
}

// Destructor, elimina todos los datos de la lista 
// Complejidad O(n)
DoubleLinkedList :: ~DoubleLinkedList() {
    deleteAll();
    delete head;
    delete tail;
}

// Función que añade un dato en la primera posición
// Complejidad O(1)
void DoubleLinkedList :: addFirst(string data, long long clave) {
    Node *aux = new Node (data,clave);
    aux->setNext(head->getNext());
    aux->setPrev(head);

    head->getNext()->setPrev(aux);
    head->setNext(aux);
    head->setClave(clave);
    size++;
}

// Función que añade un dato en la última posición
// Complejidad O(1)
void DoubleLinkedList :: addLast(string data, long long clave) {
    if(size == 0) {
        addFirst(data, clave);
    }
    else {
        Node *aux = new Node (data,clave);
        aux->setPrev(tail->getPrev());
        aux->setNext(tail);

        tail->getPrev()->setNext(aux);
        tail->setPrev(aux);
        size++;
    }
}

// Función que elimina el dato que se encuentra en la primera posición
// Complejidad O(1)
void DoubleLinkedList :: deleteFirst() {
    if(head->getNext() != tail) {
        Node *curr = head->getNext();
        head->setNext(curr->getNext());
        curr->getNext()->setPrev(head);
        delete curr;
        size--;
    }
}

// Función que elimina el dato que se encuentra en la ultima posición
// Complejidad O(1)
void DoubleLinkedList :: deleteLast() {
    if(size <= 1) {
        deleteFirst();
    }
    else {
        Node *curr = tail->getPrev();
        tail->setPrev(curr->getPrev());
        curr->getPrev()->setNext(tail);
        delete curr;
        size--;
    }
}

// Función que elimina todos los datos de la lista
// Complejidad O(n)
int DoubleLinkedList :: deleteAll() {
    Node *curr = head->getNext();
    while(head->getNext() != tail) {
        head = curr->getNext();
        delete curr;
        curr = head;
    }
    int sizeAux = size;
    size = 0;
    return sizeAux;
}

// Función que devuelve el tamaño de la lista
// Complejidad O(1)
int DoubleLinkedList :: getSize() {
    return size;
}

// Función que señala si la lista se encuentra vacía
// Complejidad O(1)
bool DoubleLinkedList :: isEmpty() {
    return head->getNext() == tail;
}

// Función que muestra los datos que se encuentran en la lista
// Complejidad O(n)
void DoubleLinkedList :: printCont() {
    cout << "Print Continuo..." << endl;
    cout << "La DoubledLinkedList contiene: " << endl;
    Node *curr = head->getNext();
    while(curr != tail) {
        cout << curr->getData() << endl;
        curr = curr->getNext();
    }
}

// Función que muestra los datos que se encuentran en la lista
// Complejidad O(n)
void DoubleLinkedList :: printReg() {
    cout << "Print Regresivo..." << endl;
    cout << "La DoubledLinkedList contiene: " << endl;
    Node *curr = tail->getPrev();
    while(curr != head) {
        cout << curr->getData() << endl;
        curr = curr->getPrev();
    }
}

// Función que desarrolla una Key en base a la ip que contienen los datos de la bitacora
// Complejidad O(n)
long long DoubleLinkedList :: makeKey(string data){
    int sCounter=0;
    string ip;
    long long clave;
    char space = ' ';
    for (int i=0;i<data.size();i++){
        if (sCounter==3){
            if (data[i]==space){clave=ipToLong(ip); return clave;}else{
                ip.push_back(data[i]);
            }
        }else{
            if (data[i]==space){sCounter++;}
            }
    }return 0;
}

// Función que convierte el valor de string de la ip de los datos que contiene el archivo txt a long long 
// Complejidad O(n)
long long DoubleLinkedList :: ipToLong(string ip){
	int idx = 0;
	long long datoFinal= 0, dato = 0;
	while (idx < ip.size()){
		if (ip[idx]!= '.' && ip[idx]!=':'){
			dato = dato*10 + ip[idx]-'0';
		}
		else{
			datoFinal = datoFinal*1000 + dato;
			dato = 0;
		}
		idx++;
	}
	datoFinal = datoFinal*10000 + dato;
	return datoFinal;
}

// Función que ordena los datos de la bitacora en base a su IP
// Complejidad O(n^2)
void DoubleLinkedList :: sort(){
    Node *curr1 = head->getNext(), *curr2;
    long long claveTemp;
    string dataTemp;
    cout<<"Sorting (Puede tomar un minuto)"<<endl;
    while(curr1 != tail) {
        curr2 = curr1->getNext();
        while(curr2 != tail) {
            if (curr1->getClave() > curr2->getClave()){
                claveTemp=curr1->getClave();
                dataTemp=curr1->getData();
                curr1->setClave(curr2->getClave());
                curr1->setData(curr2->getData());
                curr2->setClave(claveTemp);
                curr2->setData(dataTemp);
            }
            curr2 = curr2->getNext();
        }
        curr1 = curr1->getNext();
    }
    createFile();
    cout<<"Bitacora Ordenada y archivo creado"<<endl;
}

// Función que crea un archivo txt con los datos de la bitacora ordenados por su IP
// Complejidad O(n)
void DoubleLinkedList :: createFile(){
    Node *curr = head->getNext();
    ofstream bitOrder("bitacoraOrdenada.txt");
    while(curr != tail) {
        bitOrder<<curr->getData()<<endl;
        curr = curr->getNext();
    }
}

// Función que en base a las IPs proporcionadas, realiza una búsqueda de las mismas dentro de la DLL para posteriormente mostrarlas
// Complejidad O(n)
void DoubleLinkedList :: search(string ip1, string ip2){
    Node *curr = head->getNext();
    long long key1, key2;
    key1 = ipToLong(ip1);
    key2 = ipToLong(ip2);
    while(curr != tail) {
        if (curr->getClave() >= key1 && curr->getClave() <= key2){
            cout << curr->getData() << endl;
        }
        curr = curr->getNext();
    }
}