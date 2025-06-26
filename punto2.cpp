#include <iostream>
using namespace std;

struct tnodo {
    int dato;
    tnodo* siguiente;
};
typedef tnodo* pnodo;

struct Lista {
    pnodo inicio;
    pnodo fin;
    int cantidad;
};

void iniciar_lista(Lista &lista) {
    lista.inicio = NULL;
    lista.fin = NULL;
    lista.cantidad = 0;
}

void crear_nodo(pnodo &nuevo) {
    nuevo = new tnodo;
    if (nuevo != NULL) {
        cout << "Ingrese valor: ";
        cin >> nuevo->dato;
        nuevo->siguiente = NULL;
    } else {
        cout << "Memoria insuficiente" << endl;
    }
}

void agregar_inicio(Lista &lista, pnodo nuevo) {
    nuevo->siguiente = lista.inicio;
    lista.inicio = nuevo;
    if (lista.fin == NULL) {
        lista.fin = nuevo;
    }
    lista.cantidad++;
}

void agregar_final(Lista &lista, pnodo nuevo) {
    nuevo->siguiente = NULL;
    if (lista.inicio == NULL) {
        lista.inicio = nuevo;
        lista.fin = nuevo;
    } else {
        lista.fin->siguiente = nuevo;
        lista.fin = nuevo;
    }
    lista.cantidad++;
}

void agregar_ordenado(Lista &lista, pnodo nuevo) {
    if (lista.inicio == NULL || nuevo->dato < lista.inicio->dato) {
        agregar_inicio(lista, nuevo);
    } else {
        pnodo i = lista.inicio;
        while (i->siguiente != NULL && i->siguiente->dato < nuevo->dato) {
            i = i->siguiente;
        }
        nuevo->siguiente = i->siguiente;
        i->siguiente = nuevo;
        if (nuevo->siguiente == NULL) {
            lista.fin = nuevo;
        }
        lista.cantidad++;
    }
}

pnodo eliminar_inicio(Lista &lista) {
    pnodo borrado = NULL;
    if (lista.inicio != NULL) {
        borrado = lista.inicio;
        lista.inicio = lista.inicio->siguiente;
        if (lista.inicio == NULL) {
            lista.fin = NULL;
        }
        borrado->siguiente = NULL;
        lista.cantidad--;
    }
    return borrado;
}

pnodo eliminar_final(Lista &lista) {
    pnodo borrado = NULL;
    if (lista.inicio == NULL) {
        return NULL;
    } else if (lista.inicio->siguiente == NULL) {
        borrado = lista.inicio;
        lista.inicio = NULL;
        lista.fin = NULL;
    } else {
        pnodo i = lista.inicio;
        while (i->siguiente->siguiente != NULL) {
            i = i->siguiente;
        }
        borrado = i->siguiente;
        i->siguiente = NULL;
        lista.fin = i;
    }
    if (borrado != NULL) lista.cantidad--;
    return borrado;
}

pnodo eliminar_nodo(Lista &lista, int valor) {
    pnodo borrado = NULL;
    if (lista.inicio == NULL) {
        return NULL;
    } else if (lista.inicio->dato == valor) {
        borrado = eliminar_inicio(lista);
    } else {
        pnodo i = lista.inicio;
        while (i->siguiente != NULL && i->siguiente->dato != valor) {
            i = i->siguiente;
        }
        if (i->siguiente != NULL) {
            borrado = i->siguiente;
            i->siguiente = borrado->siguiente;
            if (borrado == lista.fin) {
                lista.fin = i;
            }
            borrado->siguiente = NULL;
            lista.cantidad--;
        }
    }
    return borrado;
}

void mostrar(Lista lista) {
    pnodo i = lista.inicio;
    if (i != NULL) {
        while (i != NULL) {
            cout << "Nodo: " << i->dato << endl;
            i = i->siguiente;
        }
    } else {
        cout << "Lista vacía";
    }
}

bool buscar_nodo(Lista lista, int valor) {
    pnodo i = lista.inicio;
    while (i != NULL) {
        if (i->dato == valor) return true;
        i = i->siguiente;
    }
    return false;
}

int cantidad_elementos(Lista lista) {
    return lista.cantidad;
}

int main() {
    Lista lista;
    iniciar_lista(lista);

    int opcion;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Agregar al inicio\n";
        cout << "2. Agregar al final\n";
        cout << "3. Agregar ordenado\n";
        cout << "4. Mostrar lista\n";
        cout << "5. Cantidad de elementos\n";
        cout << "6. Salir\n";
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                pnodo nuevo;
                crear_nodo(nuevo);
                agregar_inicio(lista, nuevo);
                break;
            }
            case 2: {
                pnodo nuevo;
                crear_nodo(nuevo);
                agregar_final(lista, nuevo);
                break;
            }
            case 3: {
                pnodo nuevo;
                crear_nodo(nuevo);
                agregar_ordenado(lista, nuevo);
                break;
            }
            case 4:
                mostrar(lista);
                break;
            case 5:
                cout << "Cantidad de elementos: " << cantidad_elementos(lista) << endl;
                break;
            case 6:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while(opcion != 6);

    // Liberar memoria restante
    while(lista.inicio != NULL) {
        pnodo aux = eliminar_inicio(lista);
        delete aux;
    }

    return 0;
}