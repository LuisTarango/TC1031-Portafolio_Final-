// Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales
// Archivo .h que utilizará el programa que crea una DoubleLinkedList y la ordena y despliega los datos conforme a los IPs ordenados
// Autores: Leonardo Delgado Rios (A00827915), Luis Fernando Tarango Felix (A00827678)
// Fecha de ultima modificacion: 10/10/20

class Node {
    public:
        Node();
        Node(string data, long long clave);
        Node(string data,Node *next,Node *prev, long long clave);
        string getData();
        Node* getNext();
        Node* getPrev();
        void setData(string data);
        void setNext(Node *next);
        void setPrev(Node *prev);
        void setClave(long long clave);
        long long getClave();
    private:
        string data;
        long long clave;
        Node *next;
        Node *prev;
};

Node :: Node() {
    this-> prev = nullptr;
    this-> next = nullptr;
}

Node :: Node(string data, long long clave) {
    this-> prev = nullptr;
    this-> data = data;
    this-> clave = clave;
    this-> next = nullptr;
}

Node :: Node(string data, Node *next, Node *prev, long long clave) {
    this-> prev = prev;
    this-> data = data;
    this-> clave = clave;
    this-> next = next;
}

// Función que regresa la información que contiene
// Complejidad 0(1)
string Node :: getData() {
    return data;
}

// Función que regresa el siguiente
// Complejidad 0(1)
Node* Node :: getNext() {
    return next;
}

// Función que regresa el anterior
// Complejidad 0(1)
Node* Node  :: getPrev() {
    return prev;
}

// Función que establece la información  
// Complejidad 0(1)
void Node :: setData(string data) {
    this-> data = data;
}

// Función que establece el siguiente
// Complejidad 0(1)
void Node :: setNext(Node *next) {
    this-> next = next;
}

// Función que establece el anterior 
// Complejidad 0(1)
void Node :: setPrev(Node *prev) {
    this-> prev = prev;
}

// Función que establece la clave 
// Complejidad 0(1)
void Node :: setClave(long long clave){
    this-> clave = clave;
}

// Función que regresa la clave 
// Complejidad 0(1)
long long Node :: getClave(){
    return clave;
}