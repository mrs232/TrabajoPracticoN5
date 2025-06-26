// Los analisis del codigo se realizan abajo de la funcion y luego con un main se verifica su funcionamiento.
#include <iostream>
using namespace std;

// Definición de la clase Nodo
class Nodo {
    int dato;
    Nodo* siguiente;
public:
    Nodo(int d, Nodo* sig = nullptr) : dato(d), siguiente(sig) {}
    int getDato() { return dato; }
    Nodo* getSiguiente() { return siguiente; }
    void setSiguiente(Nodo* sig) { siguiente = sig; }
};

/*Lista:
6 → 4 → 9 → 5 → 8 → NULL */

void enigma(Nodo* nodo)
{
    if(nodo != nullptr)
        if(nodo->getSiguiente() == nullptr)
            cout << nodo->getDato() << endl;
        else{
            enigma(nodo->getSiguiente());
            cout << nodo->getDato() << endl;
        }
}
/* 
La función recorre la lista de forma recursiva hasta el último nodo, y luego empieza a imprimir los valores al regresar de la recursión. Es decir, imprime los valores desde el final hasta el principio (orden inverso).

Primero llama a enigma con el siguiente nodo. Cuando llega al final (8), imprime ese dato. Luego imprime el anterior (5), y así sucesivamente hasta volver al nodo original.

Funcion: Imprime los datos de los nodos en orden inverso, desde el último hasta el primero.
Salida esperada:
8 5 9 4 6 */

int misterio(Nodo* nodo)
{
    if(nodo == nullptr)
        return 0;
    else
        return misterio(nodo->getSiguiente()) + 1;
}

/*
Si el nodo actual es nullptr, devuelve 0 (caso base). Si no, llama a misterio con el siguiente nodo y le suma 1.

Es una función recursiva que cuenta cuántos nodos hay en la lista.

Funcion: Cuenta la cantidad de nodos en la lista.
Salida esperada: 5
*/

Nodo* desconocido(Nodo* nodo)
{
    if(nodo == nullptr || nodo->getSiguiente() == nullptr)
        return nodo;
    else
        return desconocido(nodo->getSiguiente());
}

/*
Si el nodo actual es nullptr (lista vacía) o su siguiente es nullptr (último nodo), lo retorna. Si no, sigue buscando en el siguiente nodo.

Busca recursivamente el último nodo de la lista.

Funcion: Devuelve el último nodo de la lista.
Salida esperada: Nodo con dato 8
*/

// --- main para probar ---
int main() {
    // Crear la lista: 6 → 4 → 9 → 5 → 8 → NULL
    Nodo* n5 = new Nodo(8);
    Nodo* n4 = new Nodo(5, n5);
    Nodo* n3 = new Nodo(9, n4);
    Nodo* n2 = new Nodo(4, n3);
    Nodo* n1 = new Nodo(6, n2);
    Nodo* cabeza = n1;

    cout << "enigma (imprime en orden inverso):" << endl;
    enigma(cabeza);

    cout << "misterio (cantidad de nodos): ";
    cout << misterio(cabeza) << endl;

    Nodo* ultimo = desconocido(cabeza);
    cout << "desconocido (ultimo nodo): ";
    cout << ultimo->getDato() << endl;

    // Liberar memoria
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;

    return 0;
}