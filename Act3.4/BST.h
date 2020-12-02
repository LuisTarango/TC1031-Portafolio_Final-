// Actividad Integral de BST
// Archivo header utilizado para el desarrollo de la aplicación para la actividad integradora
// Autores: Leonardo Delgado Rios (A00827915), Luis Fernando Tarango Felix (A00827678)
// Fecha de ultima modificacion: 10/25/20
#include "NodeT.h"

class BST{
	public:
		BST();
		~BST();
		void add(string data, long long clave);
		bool search(string data);
		void remove(string data);
		void visit(int num);
		int height();
		void ancestors(string data);
		int whatLevelAmI(string data);
    long long makeKey(string data);
    long long ipToLong(string ip);
    int consultaMayor();
    void muestraMayor(int mayor);
    string ipMuestra(long long clave);
	private:
		NodeT *root;
		void preOrden(NodeT *r);
    void inOrden(NodeT *r);
    void postOrden(NodeT *r);
    void levelByLevel(NodeT *r);
		void destruye(NodeT *r);
		int howManyChildren(NodeT *r);
		string succ(NodeT *r);
		string pred(NodeT *r);
		int count(NodeT *r);
};

BST::BST(){
	root = nullptr;
}

BST::~BST(){
	destruye(root);
}

// Función que destruye el BST
// Complejidad O(n)
void BST::destruye(NodeT *r){
	if (r != nullptr){
		destruye(r->getLeft());
		destruye(r->getRight());
		delete r;
	}
}

// Función que obtiene el sucesor
// Complejidad O(n)
string BST::succ(NodeT *r){
	NodeT *curr = r->getRight();
	while (curr->getLeft() != nullptr){
		curr = curr->getLeft();
	}
	return curr->getData();
}

// Función que obtiene el predecesor
// Complejidad O(n)
string BST::pred(NodeT *r){
	NodeT *curr = r->getLeft();
	while (curr->getRight() != nullptr){
		curr = curr->getRight();
	}
	return curr->getData();
}

// Función que añade un nuevo nodo al BST
// Complejidad O(n)
void BST::add(string data, long long clave){
	NodeT *curr = root;
	NodeT *father = nullptr;
	while (curr != nullptr){
		if (curr->getClave() == clave){
      int tmp = curr->getCounter() + 1;
      curr->setCounter(tmp);
			return;
		}
		father = curr;
		curr = (curr->getClave() > clave) ? curr->getLeft() : curr->getRight();
	}
	if (father == nullptr){
		root = new NodeT(data, clave);
	}
	else{
		father->getClave() > clave ? father->setLeft(new NodeT(data, clave)) : 
								father->setRight(new NodeT(data, clave));
	}

}

// Función que muestra los hijos de un nodo padre
// Complejidad O(1)
int BST::howManyChildren(NodeT *r){
	int cont = 0;
	if (r->getLeft() != nullptr){
		cont++;
	}
	if (r->getRight() != nullptr){
		cont++;
	}
	return cont;
}

// Función que elimina un nodo del BST
// Complejidad O(n)
void BST::remove(string data){
	NodeT *curr = root;
	NodeT *father = nullptr;
  bool check = BST::search(data);
  long long clave = ipToLong(data);
  if(check) {
	  while (curr != nullptr && curr->getClave() != clave) {
      father = curr;
      curr = (curr->getClave() > clave) ? curr->getLeft() : curr->getRight();
	  }
    if (curr->getCounter() > 1) {
      int tmp = curr->getCounter() - 1;
      curr->setCounter(tmp);
      return;
    }
	  int cantHijos = howManyChildren(curr);
	  switch (cantHijos){
	  	case 0: if (father == nullptr){
				root = nullptr;
			}
			else {
				if (father->getClave() > clave){
					father->setLeft(nullptr);
				}
				else {
					father->setRight(nullptr);
				}
			}
			delete curr;
			break;
		  case 1: if (father == nullptr){
				if (curr->getLeft() != nullptr){
					root = curr->getLeft();
				}
				else {
					root = curr->getRight();
				}
			  }
			  else{
					if (father->getClave() > clave){
						// quiero borrar al hijo izq del padre
						if (curr->getLeft() != nullptr){
							// único hijo esta a la izq.
							father->setLeft(curr->getLeft());
						}
						else{
							// único hijo esta a la der.
							father->setLeft(curr->getRight());
						}
					}
					else{
						// quiero borrar al hijo der del padre
						if (curr->getLeft() != nullptr){
							// único hijo esta a la izq.
							father->setRight(curr->getLeft());
						}
						else{
							// único hijo esta a la der.
							father->setRight(curr->getRight());
						}
					}
				}
				delete curr;
				break;
		case 2: string sucesor = succ(curr);
				remove(sucesor);
				curr->setData(sucesor);
				break;
    }
  }
  else {
    cout << "El valor ingresado no se encuentra en el BST" << endl;
  }
}

// Función que busca un nodo en especifico en el BST
// Complejidad O(n)
bool BST::search(string data){
	NodeT *curr = root;
  long long clave = ipToLong(data);
	while (curr != nullptr){
		if (curr->getClave() == clave){
			return true;
		}
		curr = (curr->getClave() > clave) ? curr->getLeft() : curr->getRight();
	}
	return false;
}

// Función que muestra el nivel en el que se encuentra un nodo del BST
// Complejidad O(n)
int BST :: whatLevelAmI(string data) {
  NodeT *curr = root;
  int i = 0;
  long long clave = ipToLong(data);
  while(curr != nullptr) {
    if(curr->getClave() == clave) {
      return i;
    }
    curr = (curr->getClave() > clave) ? curr->getLeft() : curr->getRight();
    i++;
  }
  return -1;
}

// Función que muestros los antecesores de un nodo en especifico del BST
// Complejidad O(n)
void BST :: ancestors(string data) {
  NodeT *curr = root;
  queue <NodeT *> q;
  long long clave = ipToLong(data);
  while(curr != nullptr) {
    if(curr->getClave() == clave) {
      if(curr->getClave() == root->getClave()) {
        cout << curr->getData();
      }
      else {
        while(q.empty() != true) {
          int cont = q.size();
          while(cont > 0) {
            cout << q.front()->getClave() << " ["<< q.front()->getCounter()<< "] ";
            q.pop();
            cont--;
          }
        }
      }
    }
    q.push(curr);
    curr = (curr->getClave() > clave) ? curr->getLeft() : curr->getRight();
  }
  cout << endl;
}

// Función que muestra la información del BST por preOrden
// Complejidad: O(n)
void BST::preOrden(NodeT *r){
	if (r != nullptr){
		cout << r->getClave() << " ["<<r->getCounter()<<"]" << endl;
		preOrden(r->getLeft());
		preOrden(r->getRight());
	}
}

// Función que muestra la información del BST por inOrden
// Complejidad: O(n)
void BST :: inOrden(NodeT *r) {
  if(r != nullptr) {
    inOrden(r->getLeft());
    cout << r->getClave() << " ["<<r->getCounter()<<"]" << endl;
    inOrden(r->getRight());
  }
}

// Función que muestra la información del BST por postOrden
// Complejidad: O(n)
void BST :: postOrden(NodeT *r) {
  if(r != nullptr) {
    postOrden(r->getLeft());
    postOrden(r->getRight());
    cout << r->getClave() << " ["<<r->getCounter()<<"]" << endl;
  }
}

// Función que muestra la información del BST nivel por nivel
// Complejidad: O(n)
void BST :: levelByLevel(NodeT *r) {
  if(r != nullptr) {
    queue <NodeT *> qU;
    qU.push(r);
    while(qU.empty() != true) {
        int cont = qU.size();
        while(cont > 0) {
          NodeT *aux = qU.front();
          cout << aux->getClave() << " ["<<aux->getCounter()<<"]" << endl;
          qU.pop();
          if(aux->getLeft() != nullptr) {
            qU.push(aux->getLeft());
          }
          if(aux->getRight() != nullptr) {
            qU.push(aux->getRight());
          }
          cont--;
        }
    }
  }
}

// Función que utiliza un menú para seleccionar el tipo de muestra de datos
// Complejidad: O(1)
void BST :: visit(int num) {
  NodeT *curr = root;
  switch(num) {
    case (1): preOrden(curr);
    break;
    case (2): inOrden(curr);
    break;
    case (3): postOrden(curr);
    break;
    case (4): levelByLevel(curr);
    break;
    default: cout << "Número ingresado no se encuentra en el rango 1-4..." << endl;
  }
}

// Función que cuenta el total de nodos
//Complejidad: O(n)
int BST::count(NodeT *r){
	if (r == nullptr){
		return 0;
	}
	return 1 + count(r->getLeft()) + count(r->getRight());
}

// Función que muestra la altura del BST
// Complejidad: O(n)
int BST :: height() {
  NodeT *curr = root;
  int i = 0;
  if(curr != nullptr) {
    queue <NodeT *> q;
    q.push(curr);
    while(q.empty() != true) {
      int cont = q.size();
      i++;
      while(cont > 0) {
        NodeT *aux = q.front();
        q.pop();
        if(aux->getLeft() != nullptr) {
          q.push(aux->getLeft());
        }
        if(aux->getRight() != nullptr) {
          q.push(aux->getRight());
        }
        cont--;        
      }
    }
  }
  return i;
}

// Función que desarrolla la ip que contienen los datos de la bitacora en base a la key
// Complejidad O(n)
string BST :: ipMuestra(long long clave) {
  NodeT *curr = root;
  int sCounter=0;
  string x, ip;
  char space = ' ';
  while(curr != nullptr) {
    if(curr->getClave() == clave) {
      x = curr->getData();
      for(int i=0; i<x.size(); i++) {
        if(sCounter == 3) {
          if(x[i] == ':') {return ip;}
          else {ip.push_back(x[i]);}
        }
        else {
          if (x[i]==space) {sCounter++;}
        }
      }
    }
    curr = (curr->getClave() > clave) ? curr->getLeft() : curr->getRight();
  } return "";
}

// Función que desarrolla una Key en base a la ip que contienen los datos de la bitacora
// Complejidad O(n)
long long BST :: makeKey(string data){
  int sCounter=0;
  string ip;
  long long clave;
  char space = ' ';
  for (int i=0;i<data.size();i++){
    if (sCounter==3){
      if (data[i]==space){clave=ipToLong(ip); return clave;}
      else{ip.push_back(data[i]);}
    }
    else{
      if (data[i]==space){sCounter++;}
    }
  } return 0;
}

// Función que convierte el valor de string de la ip de los datos que contiene el archivo txt a long long 
// Complejidad O(n)
long long BST :: ipToLong(string ip){
	int idx = 0;
	long long datoFinal= 0, dato = 0;
	while (idx < ip.size()){
    if(ip[idx] == ':') {
      break;
    }
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

// Función que regresa el valor mayor de consulta dentro de las IPs del BST
// Complejidad O(n)
int BST :: consultaMayor() {
  NodeT *curr = root;
  int mayor = 0;
	if(curr != nullptr) {
    queue <NodeT *> q;
    q.push(curr);
    while(q.empty() != true) {
      int cont = q.size();
      while(cont > 0) {
        NodeT *aux = q.front();
        if(aux->getCounter() > mayor) {
          mayor = aux->getCounter();
        }
        q.pop();
        if(aux->getLeft() != nullptr) {
          q.push(aux->getLeft());
        }
        if(aux->getRight() != nullptr) {
          q.push(aux->getRight());
        }
        cont--;
      }
    }
  }
  return mayor;
}

// Función que muestra las 5 IPs con mayor cantidad de consulta de manera ascendente en caso de que existan IPs con la misma cantidad de consulta
// Complejidad O(n)
void BST :: muestraMayor(int mayor) {
  NodeT *curr = root;
  int pCounter = 0;
  if(curr != nullptr) {
    while (pCounter < 5) {
      queue <NodeT *> q;
      q.push(curr);
      while(q.empty() != true) {
        int cont = q.size();
        while(cont > 0) {
          NodeT *aux = q.front();
          if(aux->getCounter() == mayor) {
            cout << BST::ipMuestra(aux->getClave()) << " [" << aux->getCounter() << "] " << " " << endl;
            pCounter++;
          }
          q.pop();
          if(aux->getLeft() != nullptr) {
            q.push(aux->getLeft());
          }
          if(aux->getRight() != nullptr) {
            q.push(aux->getRight());
          }
          cont--;
        }
      }
      mayor--;
    }
  }
  cout << endl;
}