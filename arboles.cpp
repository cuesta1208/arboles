#include <iostream>
using namespace std;

// Nodo del árbol binario
struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;

    Nodo(int valor) : dato(valor), izq(nullptr), der(nullptr) {}
};

// Inserta un valor siguiendo la regla de un árbol binario de búsqueda
Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == nullptr) return new Nodo(valor);

    if (valor < raiz->dato)
        raiz->izq = insertar(raiz->izq, valor);
    else if (valor > raiz->dato)
        raiz->der = insertar(raiz->der, valor);
    // Si el valor ya existe, no se inserta duplicado

    return raiz;
}

// Recorrido InOrder: Izquierda -> Raíz -> Derecha
// (en un árbol de búsqueda imprime los valores ordenados)
void inOrder(Nodo* raiz) {
    if (raiz == nullptr) return;
    inOrder(raiz->izq);
    cout << raiz->dato << " ";
    inOrder(raiz->der);
}

// Recorrido PreOrder: Raíz -> Izquierda -> Derecha
void preOrder(Nodo* raiz) {
    if (raiz == nullptr) return;
    cout << raiz->dato << " ";
    preOrder(raiz->izq);
    preOrder(raiz->der);
}

// Recorrido PostOrder: Izquierda -> Derecha -> Raíz (extra)
void postOrder(Nodo* raiz) {
    if (raiz == nullptr) return;
    postOrder(raiz->izq);
    postOrder(raiz->der);
    cout << raiz->dato << " ";
}

// Libera la memoria del árbol (usa recorrido postorder)
void liberar(Nodo* raiz) {
    if (raiz == nullptr) return;
    liberar(raiz->izq);
    liberar(raiz->der);
    delete raiz;
}

int main() {
    Nodo* raiz = nullptr;

    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : valores) {
        raiz = insertar(raiz, v);
    }

    /*
     Árbol resultante:

              50
            /    \
          30      70
         /  \    /  \
       20   40  60   80
    */

    cout << "InOrder:   ";
    inOrder(raiz);
    cout << endl;

    cout << "PreOrder:  ";
    preOrder(raiz);
    cout << endl;

    cout << "PostOrder: ";
    postOrder(raiz);
    cout << endl;

    liberar(raiz);
    return 0;
}