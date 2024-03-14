#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include <assert.h>
#include <string>
#include <iostream>

using namespace std;

template <class T>
class Conjunto {
public:
    // Constructor. Generates an empty set.
    Conjunto();

    // Destructor. Clears the memory.
    ~Conjunto();

    // Inserts an element into the set. If it already exists, the set remains unchanged.
    void insertar(const T&);

    // Determines if an element belongs to the set or not.
    bool pertenece(const T&) const;

    // Deletes an element from the set. If it does not exist, the set remains unchanged.
    void remover(const T&);

    // Next element after the one received as a parameter, in order.
    const T& siguiente(const T& elem);

    // Returns the minimum element of the set according to <.
    const T& minimo() const;

    // Returns the maximum element of the set according to <.
    const T& maximo() const;

    // Returns the number of elements in the set.
    unsigned int cardinal() const;

    // Displays the set.
    void mostrar(std::ostream&) const;

private:
    struct Nodo {
        // Constructor, takes the element represented by the node.
        Nodo(const T& v) : valor{v}, izq{nullptr}, der{nullptr} {};

        // The element represented by the node.
        T valor;

        // Pointer to the root of the left subtree.
        Nodo* izq;

        // Pointer to the root of the right subtree.
        Nodo* der;

        unsigned int hijos() {
            int hijosDer = der ? der->hijos() : 0;
            int hijosIzq = izq ? izq->hijos() : 0;
            return 1 + hijosDer + hijosIzq;
        }

        unsigned int profundidad() {
            int profDer = der ? der->profundidad() : 0;
            int profIzq = izq ? izq->profundidad() : 0;
            return 1 + max(profDer, profIzq);
        }
    };

    // Pointer to the root of our tree.
    Nodo* _raiz;

    const T& _minimo(Nodo* n) {
        Nodo* nodoActual = n;
        while (nodoActual->izq) {
            nodoActual = nodoActual->izq;
        }
        return nodoActual->valor;
    }

    void _destruir(Nodo* n) {
        if (n) {
            _destruir(n->izq);
            _destruir(n->der);
            delete n;
        }
    }
};

template<class T>
std::ostream& operator<<(std::ostream& os, const Conjunto<T>& c) {
    c.mostrar(os);
    return os;
}

#include "Conjunto.hpp"

#endif