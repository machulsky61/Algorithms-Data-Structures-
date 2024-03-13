#ifndef _LISTA_ALUMNOS_H_
#define _LISTA_ALUMNOS_H_

#include <string>
#include <iostream>

using namespace std;

typedef unsigned long Nat;

class Lista {
public:
    Lista(); // Default constructor

    Lista(const Lista& l); // Copy constructor

    ~Lista(); // Destructor

    Lista& operator=(const Lista& aCopiar); // Assignment operator

    void agregarAdelante(const int& elem); // Add element to the front of the list

    void agregarAtras(const int& elem); // Add element to the end of the list

    void eliminar(Nat i); // Delete the i-th element from the list

    int longitud() const; // Return the number of elements in the list

    const int& iesimo(Nat i) const; // Return the i-th element of the list (const)

    int& iesimo(Nat i); // Return the i-th element of the list

    void mostrar(ostream& o); // Show the list in an ostream

    friend ostream& operator<<(ostream& os, Lista& l) { // Overload the << operator
        l.mostrar(os);
        return os;
    }

private:
    struct Nodo {
        Nodo* pre;
        Nodo* sig;
        int val;
        Nodo(const int& elem, Nodo* p = nullptr, Nodo* s = nullptr): val{elem}, pre{p}, sig{s} {};
    };
    Nodo* _pri;
    Nodo* _ult;
    int _lon;
};

#include "Lista.hpp"

#endif