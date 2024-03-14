#ifndef STRING_MAP_H_
#define STRING_MAP_H_

#include <string>

template<typename T>
class string_map {
public:
    // CONSTRUCTOR
    string_map();

    // CONSTRUCTOR POR COPIA
    string_map(const string_map<T>& aCopiar);

    // OPERADOR ASIGNACION
    string_map& operator=(const string_map& d);

    // DESTRUCTOR
    ~string_map();

    // INSERT 
    void insert(const std::pair<std::string, T>&);

    // COUNT
    int count(const std::string &key) const;

    // AT
    const T& at(const std::string& key) const;
    T& at(const std::string& key);

    // ERASE
    void erase(const std::string& key);

    // SIZE
    int size() const;

    // EMPTY
    bool empty() const;

    // OPTATIVO
    T &operator[](const std::string &key);

private:

    struct Nodo {
        const unsigned int sz = 256;
        Nodo** siguientes;
        T* definicion;
        Nodo(): siguientes{new Nodo*[256]()}, definicion{nullptr} {}
        Nodo(T* def): siguientes{new Nodo*[256]()}, definicion{def} {}
        ~Nodo() {
            delete definicion;
            for (int i = 0; i < 256; i++) {
                if (siguientes[i]) {
                    delete siguientes[i];
                }
            }
            delete[] siguientes;
        }
        Nodo(const Nodo& n):  siguientes{new Nodo*[256]()}, definicion{n.definicion ? new T(*n.definicion) : nullptr} {
            for (int i = 0; i < 256; i++) {
                if (n.siguientes[i]) {
                    siguientes[i] = new Nodo(*n.siguientes[i]);
                }
            }
        }

        unsigned int hijos() {
            unsigned int res = 0;
            for (int i = 0; i < 256; i++) {
                if (siguientes[i]) {
                    res++;
                }
            }
            return res;
        }
    };

    Nodo* _raiz;
    int _size;
};

#include "string_map.hpp"

#endif