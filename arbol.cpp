#include <iostream>

using namespace std;

struct Nodo {
    int valor;
    Nodo* izquierda;
    Nodo* derecha;
};

class ArbolBinario {
private:
    Nodo* raiz;

public:
    ArbolBinario() {
        raiz = nullptr;
    }

    void insertar(int valor) {
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->valor = valor;
        nuevoNodo->izquierda = nullptr;
        nuevoNodo->derecha = nullptr;

        if (raiz == nullptr) {
            raiz = nuevoNodo;
        } else {
            Nodo* actual = raiz;
            bool insertado = false;

            while (!insertado) {
                if (valor < actual->valor) {
                    if (actual->izquierda == nullptr) {
                        actual->izquierda = nuevoNodo;
                        insertado = true;
                    } else {
                        actual = actual->izquierda;
                    }
                } else {
                    if (actual->derecha == nullptr) {
                        actual->derecha = nuevoNodo;
                        insertado = true;
                    } else {
                        actual = actual->derecha;
                    }
                }
            }
        }
    }

    bool buscar(int valor) {
        Nodo* actual = raiz;

        while (actual != nullptr) {
            if (actual->valor == valor) {
                return true;
            } else if (valor < actual->valor) {
                actual = actual->izquierda;
            } else {
                actual = actual->derecha;
            }
        }

        return false;
    }
};

int main() {
    ArbolBinario arbol;

    
    arbol.insertar(50);
    arbol.insertar(30);
    arbol.insertar(70);
    arbol.insertar(20);
    arbol.insertar(40);
    arbol.insertar(60);
    arbol.insertar(90);

  
    cout << "¿El valor 40 está en el árbol? " << (arbol.buscar(40) ? "Sí" : "No") << endl;
    cout << "¿El valor 90 está en el árbol? " << (arbol.buscar(90) ? "Sí" : "No") << endl;

    return 0;
}
