// Actividad Integral de BST
// Archivo header utilizado para el desarrollo de la aplicación para la actividad integradora
// Autores: Leonardo Delgado Rios (A00827915), Luis Fernando Tarango Felix (A00827678)
// Fecha de ultima modificacion: 10/25/20
class NodeT { 
  public:
    NodeT(string data, long long clave);
    NodeT(string data, NodeT *left, NodeT *right, int counter, long long clave);
    string getData();
    void setData(string data);
    long long getClave();
    void setClave(long long clave);
    NodeT* getLeft();
    void setLeft(NodeT *left);
    NodeT* getRight();
    void setRight(NodeT *right);
    int getCounter();
    void setCounter(int counter);
  private:
    string data;
    int counter;
    long long clave;
    NodeT *left;
    NodeT *right;
};

NodeT :: NodeT(string data, long long clave) {
  this-> data = data;
  this-> clave = clave;
  this-> left = nullptr;
  this-> right = nullptr;
  this-> counter = 1;
}

NodeT :: NodeT(string data, NodeT *left, NodeT *right, int counter, long long clave) {
  this-> data = data;
  this-> clave = clave;
  this-> left = left;
  this-> right = right;
  this-> counter = counter;
}

string NodeT :: getData() {
  return data;
}

long long NodeT :: getClave() {
  return clave;
}

NodeT* NodeT :: getLeft() {
  return left;
}

NodeT* NodeT :: getRight() {
  return right;
}

int NodeT :: getCounter() {
  return counter;
}

void NodeT :: setData(string data) {
  this-> data = data;
}

void NodeT :: setClave(long long clave) {
  this-> clave = clave;
}

void NodeT :: setLeft(NodeT *left) {
  this-> left = left;
}

void NodeT :: setRight(NodeT *right) {
  this-> right = right;
}

void NodeT :: setCounter(int counter) {
  this-> counter = counter;
}