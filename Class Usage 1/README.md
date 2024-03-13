# Class Usage

This repository contains the resolution of the specified exercises. Each exercise can be solved by editing the file `src/functions.cpp`. Below are the specifications for each function. Initially, you can utilize the set, map, and vector modules from the standard library. However, later on, it will be necessary to use modules provided by the course. Reference specifications are provided at the end of this document.

In the workshop package, there are tests for the functions to be implemented. These tests can be compiled using the `tests` target in CLion. Alternatively, you can compile and execute the tests without using CLion by following these steps:

1. In a terminal, navigate to the root directory of the project. There should be a `CMakeLists.txt` file in this directory.

2. Execute the command `$> cmake .` (including the period at the end). This will generate a Makefile.

3. Execute the command `$> make TTT`, where `TTT` is one of the mentioned targets. This will create an executable with the name of the target in the current directory.

4. Execute the command `$> ./TTT`, where `TTT` is the name of the target used previously. This will run the executable.

Once modifications are made to the program, there's no need to rerun cmake; simply execute `make TTT && ./TTT`.

## Exercises
### Exercise 1
```cpp
quitar_repetidos(in s : secu(int)) → res : secu(int)
Pre ≡ {true}
Post ≡ {
    Mismos elementos: (∀ x : int) (pertenece(x, res) ⇐⇒ pertenece(x, s))
    Sin repetidos res: (∀ i, j: nat) (i, j ≤ long(res) ⇒ res[i] = res[j] ⇐⇒ i = j)
}
```
> Returns a sequence with the same elements but without duplicates.

### Exercise 2
If you didn't use a set while solving exercise 1, solve it again using this module.

### Exercise 3
```cpp
mismos_elementos(in a : secu(int), in b : secu(int)) → res : bool
Pre ≡ {true}
Post ≡ {res ⇐⇒ (∀ x : int) (pertenece(x, a) ⇐⇒ pertenece(x, b))}
```
>Verifies if the two sequences have the same elements, regardless of the order or the number of occurrences.

### Exercise 4
If you didn't use a set while solving exercise 3, solve it again using this module.

### Exercise 5
```cpp
contar_apariciones(in s : secu(int)) → res : dict(int, int)
Pre ≡ {true}
Post ≡ {
    Claves correctas: (∀ x : int) (pertenece(x, s) ⇐⇒ x ∈ claves(res))
    Apariciones correctas: (∀ x : int) (x ∈ claves(res) ⇒ obtener(x, res) = cantidad_apariciones(x, s))
}
```
> Generates a dictionary where each distinct element that appears in the input sequence is associated with the number of its appearances, provided it appears at least once.

### Exercise 6
```cpp
filtrar_repetidos(in s : secu(int)) → res : secu(int)
Pre ≡ {true}
Post ≡ {(∀ x : int) (pertenece(x, res) ⇐⇒ pertenece(x, s) ∧ cantidad_apariciones(x, s) = 1)}
```
>  Removes elements with more than one occurrence from the input list.

### Exercise 7: For-Range
```cpp
interseccion(in a : conj(int), in b : conj(int)) → res : conj(α)
Pre ≡ {true}
Post ≡ {(∀ x : α) (x ∈ res ⇐⇒ x ∈ a ∧ x ∈ b)}
```
> Intersection of sets a and b.

### Exercise 8
```cpp
agrupar_por_unidades(in s : secu(int)) → res : dict(int, conj(int))
Pre ≡ {Sin repetidos: (∀ i, j : nat) (i, j < long(s) ⇒ s[i] = s[j] ⇐⇒ i = j)}
Post ≡ {
    Están todos los elementos: (∀ x : int) (pertenece(x, s) ⇐⇒ (∃ y : int) (def?(y, res) ∧ x ∈ obtener(y, res)) )
    Están en la definición correcta: (∀ k : int) (k ∈ claves(res) ⇒ (∀ s : int) (pertenece(s, obtener(k, res)) ⇒ s mod 10 = k) )
    No hay grupos vacíos: (∀ k : int) (k ∈ claves(res) ⇒ ¬ ∅?(obtener(k, res)))
}
```
> Groups the elements of the sequence according to the least significant digit.

### Excercise 9
```cpp
traducir(in tr : secu(tupla(char, char)), in str : secu(char)) → res : secu(char)
Pre ≡ {Sin claves repetidas: (∀ i, j : nat) (i, j < long(tr) ⇒ π1(tr[i]) = π1(tr[j]) ⇐⇒ i = j)}
Post ≡ {
    Mismos elementos: long(res) = long(str)
    Traducción: (∀ i : nat) (i < long(str) ⇒
        (∃ j : nat) ( j < long(tr) ∧ π1(tr[j]) = str[i] ∧ res[i] = π2(tr[j]) )∨
        (∀ j : nat) ( j < long(tr) ∧ π1(tr[j]) ≠ str[i] ∧ str[i] = res[i])
    )
}
```
> Translates the string `str` character by character using the associations in `tr`. If `tr` has no association, the character remains the same.

### Exercise 10: Algobot
In Algorithms and Data Structures 2, workshops and assignments are submitted via email. The subject of the email contains the list of university registration numbers separated by ';'. For example, a team of two people would put as the subject: 103/92;05/04. Additionally, the email has the assignment files attached.

The algobot is responsible for processing these emails. Among its capabilities, the algobot can connect to the course's Gmail account and download unread emails. Once these emails are downloaded, they need to be processed. In the following exercises, we will implement some of these processes. To do this, we will model part of the email processing using three ADTs: Mail, Date, and LU. For each of the ADTs, we will have a C++ implementation that we will use in the following exercises. The appendices of this document contain the ADTs and the interfaces of the C++ modules (see below).

One of the first tasks that the algobot performs with the emails containing assignment submissions is to check that no participant is part of more than one group. Considering that each email has a set of LUs in its subject, we need to check that these do not repeat. However, the same group can submit several assignments before the deadline, so the registration numbers can repeat but always in equal sets. The problem to solve is to decide whether, given a list of emails, there is any participant who has appeared in more than one group.

```cpp
integrantes_repetidos(in s : secu(Mail)) → res : bool
Pre ≡ {(∀ m : Mail) (pertenece(m, s) ⇒ asunto_valido(m))}
Post ≡ {res = ¬ (∀ i, j : nat) (i, j < long(s) ∧ i ≠ j ⇒ libretas(s[i]) = libretas(s[j]) ∨ libretas(s[i]) ∩ libretas(s[j]) = ∅)}
```
> Returns true if there are two different groups with common members among the emails.

### Exercise 11
```cpp
entregas_finales(in s : secu(Mail)) → res : dicc(conj(LU), Mail)
Pre ≡ {(∀ m : Mail) (pertenece(m, s) ⇒ asunto valido(m))}
Post ≡ {
    Están los grupos con entregas: (∀ g : conj(LU)) (g ∈ claves(res) ⇐⇒ (∃ i : nat) (i < long(s) ∧ libretas(s[i]) = g ∧ adjunto(s[i])))
    El mail asociado es el último con adjunto: (∀ g : conj(LU)) (g ∈ claves(res) ⇒ (∀ i : nat) (i < long(s) ⇒ (¬ adjuntos(s[i]) ∨ libretas(s[i]) ≠ g) ∨ (fecha(s[i]) ≤ fecha(obtener(g, res))) ) )
}
```
> Returns a dictionary that associates, for each group that has made some delivery with attachments, the last mail sent with any attachment.


## C++ Classes
### Mail
```cpp
class Mail {
public:
    string asunto();
    Fecha fecha();
    bool adjunto();
    // PRE: El asunto tiene un formato válido para extraer libretas
    set<LU> libretas();
};
```
### LU
```cpp
class LU {
public:
    int numero();
    int anio();
};
```
### Fecha
```cpp
class Fecha {
public:
    // Operador para comparar tiempos.
    bool operator<(Fecha otro);
};
```
