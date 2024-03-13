# Doubly Linked List Implementation

## Description
This project involves the implementation of a doubly linked list. In a linked list, each node points to the next node in the list, while in a doubly linked list, each node also points to the previous node. Additionally, a doubly linked list has a pointer to the first element and a pointer to the last element. Figure 1 depicts the diagram of the list to be implemented.

![Figure 1: Doubly Linked List representing the sequence [7, 4, 2]](listaEnlazada.png)

## Task
To complete this project, you have two files: `Lista.h` and `Lista.hpp`. In the first file, you must complete the private part of the `Lista` class, respecting the structure of a doubly linked list. In the second file, you must complete the definition of the functions exported by the class.

### Methods to Implement:
- `Lista();`: Default constructor of the `Lista` class.
- `Lista(const Lista& l);`: Copy constructor of the `Lista` class. This method is already implemented by calling `operator=`.
- `~Lista();`: Destructor of the `Lista` class.
- `Lista& operator=(const Lista& aCopiar);`: Assignment operator.
- `void agregarAdelante(const int& elem);`: Adds an element to the beginning of the list.
- `void agregarAtras(const int& elem);`: Adds an element to the end of the list.
- `void eliminar(Nat i);`: Deletes the i-th element of the list.
- `int longitud() const;`: Returns the number of elements in the list.
- `const int& iesimo(Nat i) const;`: Returns a constant reference to the element at the i-th position of the list.
- `int& iesimo(Nat i);`: Returns a reference to the element at the i-th position of the list.

### Optional Method:
Optionally, you can complete the definition of the method `void mostrar(ostream& o)` which serves to display the list. This method takes an `ostream` variable as a parameter, which is the output stream where you should print the list. For example, you can call the function with the output stream corresponding to the standard output as follows: `my_list.mostrar(std::cout)`.

## Memory Management
Your implementation must not leak memory. We recommend using Valgrind to test if your implementation has memory leaks.