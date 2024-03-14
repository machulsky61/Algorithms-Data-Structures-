#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include <assert.h>
#include <string>
#include <iostream>

using namespace std;

template <class T>
class Conjunto
{
    public:

        // Constructor. Genera un conjunto vacío.
        Conjunto();

        // Destructor. Debe dejar limpia la memoria.
        ~Conjunto();

        // Inserta un elemento en el conjunto. Si este ya existe,
        // el conjunto no se modifica.
        void insertar(const T&);

        // Decide si un elemento pertenece al conjunto o no.
        bool pertenece(const T&) const;

        // Borra un elemento del conjunto. Si este no existe,
        // el conjunto no se modifica.
        void remover(const T&);

        // Siguiente elemento al recibido por párametro, en orden.
        const T& siguiente(const T& elem);

        // Devuelve el mínimo elemento del conjunto según <.
        const T& minimo() const;

        // Devuelve el máximo elemento del conjunto según <.
        const T& maximo() const;

        // Devuelve la cantidad de elementos que tiene el conjunto.
        unsigned int cardinal() const;

        // Muestra el conjunto.
        void mostrar(std::ostream&) const;

    private:
        struct Nodo
        {
            // El constructor, toma el elemento al que representa el nodo.
            Nodo(const T& v): valor{v}, izq{nullptr}, der{nullptr} {};
            // El elemento al que representa el nodo.
            T valor;
            // Puntero a la raíz del subárbol izquierdo.
            Nodo* izq;
            // Puntero a la raíz del subárbol derecho.
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
        // Puntero a la raíz de nuestro árbol.
        Nodo* _raiz;
        const T& _minimo(Nodo* n) {
            Nodo* nodoActual = n;
            while(nodoActual->izq) {
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

#endif // CONJUNTO_H_