#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo*der;
    Nodo*izq;
};
Nodo*arbol=NULL;
//insertar nuevo nodo
void insertar(Nodo*&arbol, int n){
    if(arbol==NULL){
        Nodo*nuevo=new Nodo();
        nuevo->dato=n;
        arbol=nuevo;
        arbol->der=NULL;
        arbol->izq=NULL;
    }
    else{
        if(n==arbol->dato){
            return;
        }
        else{
            if(n<arbol->dato){
                insertar(arbol->izq,n);
            }
            else{
                 insertar(arbol->der,n);
            }
        }
    }
}
//busqueda de valor
void buscarpre(Nodo* arbol, int n) {
    if (arbol == nullptr) {
        cout << "El dato no existe" << endl;
        return;
    }

    if (arbol->dato == n) {
        cout << "Se encontró el dato" << endl;
    } else if (n < arbol->dato) {
        buscarpre(arbol->izq, n);
    } else {
        buscarpre(arbol->der, n);
    }
}
//busqueda de valor
void buscarIN(Nodo* arbol, int n) {
    if (arbol == nullptr) {
        cout << "El dato no existe" << endl;
        return;
    }

    if (n < arbol->dato) {
        buscarIN(arbol->izq, n);
    } else if (arbol->dato == n) {
        cout << "Se encontró el dato" << endl;
    } else {
        buscarIN(arbol->der, n);
    }
}
//busqueda de valor
void buscarPos(Nodo* arbol, int n) {
    if (arbol == nullptr) {
        cout << "El dato no existe" << endl;
        return;
    }

    if (n < arbol->dato) {
        buscarPos(arbol->izq, n);
    } else if (n>arbol->dato) {
        buscarPos(arbol->der, n);
    } else {
        if(arbol->dato == n){
            cout << "Se encontró el dato" << endl;
        }
    }
}
//impresion in order
void imprimirino(Nodo* arbol) {
    if (arbol == nullptr) {
        return;
    }

    imprimirino(arbol->izq);
    cout << arbol->dato <<" ";
    imprimirino(arbol->der);
}
//impresion Pre order
void imprimirpre(Nodo* arbol) {
    if (arbol == nullptr) {
        return;
    }
    cout << arbol->dato <<" ";
    imprimirpre(arbol->izq);
    imprimirpre(arbol->der);
}
//impresion Pos orden
void imprimirpos(Nodo* arbol) {
    if (arbol == nullptr) {
        return;
    }
    imprimirpos(arbol->izq);
    imprimirpos(arbol->der);
    cout << arbol->dato <<" ";
}
//Eliminar
// Función para buscar y eliminar un dato en un árbol binario
void eliminar(Nodo*& raiz, int dato) {
  if (raiz == nullptr) {
      cout<<"Valor no exsite";
    return;
  }
  if (dato < raiz->dato) {
    eliminar(raiz->izq, dato);
  }
  else if (dato > raiz->dato) {
    eliminar(raiz->der, dato);
  }
  else {
    Nodo* ayuda = raiz;
    if (raiz->izq == nullptr && raiz->der == nullptr) {
      raiz = nullptr;
      cout<<"Valor eliminado";
    }
    else if (raiz->izq == nullptr) {
      raiz = raiz->der;
      cout<<"Valor eliminado";
    }
    else if (raiz->der == nullptr) {
      raiz = raiz->izq;
      cout<<"Valor eliminado";
    }
    else {
      ayuda = raiz->izq; 
      while (ayuda->der != nullptr) { 
        ayuda = ayuda->der;
      }
      
      raiz->dato = ayuda->dato;
      eliminar(raiz->izq, ayuda->dato);
      cout<<"Valor eliminado";
    }
  }
}



int main()
{
    int valor;
    int n1;
    cout<<"Inserta un dato, si no quieres insertar mas escribe 0"<<endl;
    do{
        cout<<"valor : ";
        cin>>n1;
        if(n1>0){
        insertar(arbol,n1);
        }
        else{
            break;
        }
        
    }
    while(n1>0);
    cout<<"que valor buscas:";
    cin>> n1;
    cout<<endl<<"Busqueda pre: ";
    buscarpre(arbol,n1);
    cout<<endl<<"Busqueda IN: ";
    buscarIN(arbol,n1);
    cout<<endl<<"Busqueda Pos: ";
    buscarPos(arbol,n1);
    cout<<endl<<"impresion pre"<<endl;
    imprimirpre(arbol);
    cout<<endl<<"impresion in"<<endl;
    imprimirino(arbol);
    cout<<endl<<"impresion Pos "<<endl;
    imprimirpos(arbol);
    cout<<endl<<endl<<"Digite valor a eliminar: ";
    cin>>n1;
    eliminar(arbol, n1);
    cout<<endl<<"impresion pre"<<endl;
    imprimirpre(arbol);
    cout<<endl<<"impresion in"<<endl;
    imprimirino(arbol);
    cout<<endl<<"impresion Pos "<<endl;
    imprimirpos(arbol);
    
    
}