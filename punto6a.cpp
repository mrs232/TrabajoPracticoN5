#include <iostream>
using namespace std;

struct tnodo {
    int dato;
    tnodo* siguiente;
};
typedef tnodo* pnodo;

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

void iniciar_lista(pnodo &lista) {
    lista = NULL;
}

void agregar_inicio(pnodo &lista, pnodo nuevo) {
    nuevo->siguiente = lista;
    lista = nuevo;
}

void agregar_final(pnodo &lista, pnodo nuevo) {
    if (lista == NULL) {
        lista = nuevo;
    } else {
        pnodo i = lista;
        while (i->siguiente != NULL) {
            i = i->siguiente;
        }
        i->siguiente = nuevo;
    }
}

void agregar_ordenado(pnodo &lista, pnodo nuevo) {
    if (lista == NULL || nuevo->dato < lista->dato) {
        nuevo->siguiente = lista;
        lista = nuevo;
    } else {
        pnodo i = lista;
        while (i->siguiente != NULL && i->siguiente->dato < nuevo->dato) {
            i = i->siguiente;
        }
        nuevo->siguiente = i->siguiente;
        i->siguiente = nuevo;
    }
}

pnodo eliminar_inicio(pnodo &lista) {
    pnodo borrado;
    if (lista == NULL) {
        borrado = NULL;
    } else {
        borrado = lista;
        lista = lista->siguiente;
        borrado->siguiente = NULL;
    }
    return borrado;
}

pnodo eliminar_final(pnodo &lista) {
    pnodo borrado;
    if (lista == NULL) {
        borrado = NULL;
    } else if (lista->siguiente == NULL) {
        borrado = lista;
        lista = NULL;
    } else {
        pnodo i = lista;
        while (i->siguiente->siguiente != NULL) {
            i = i->siguiente;
        }
        borrado = i->siguiente;
        i->siguiente = NULL;
    }
    return borrado;
}

pnodo eliminar_nodo(pnodo &lista, int valor) {
    pnodo borrado;
    if (lista == NULL) {
        borrado = NULL;
    } else if (lista->dato == valor) {
        borrado = lista;
        lista = lista->siguiente;
        borrado->siguiente = NULL;
    } else {
        pnodo i = lista;
        while (i->siguiente != NULL && i->siguiente->dato != valor) {
            i = i->siguiente;
        }
        if (i->siguiente != NULL) {
            borrado = i->siguiente;
            i->siguiente = borrado->siguiente;
            borrado->siguiente = NULL;
        } else {
            borrado = NULL;
        }
    }
    return borrado;
}

void mostrar(pnodo lista) {
    pnodo i;
    if (lista != NULL) {
        for (i = lista; i != NULL; i = i->siguiente) {
            cout << "Nodo: " << i->dato << endl;
        }
    } else {
        cout << "Lista vacía";
    }
}

bool buscar_nodo(pnodo lista, int valor) {
    pnodo i;
    bool encontrado = false;
    if (lista != NULL) {
        for (i = lista; i != NULL && !encontrado; i = i->siguiente) {
            if (i->dato == valor) {
                encontrado = true;
            }
        }
    }
    return encontrado;
}

// Funcion para verificar si un numero es primo
bool es_primo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// Cuenta los numeros primos en la lista
int contar_primos(pnodo lista) {
    int cuenta = 0;
    for (pnodo i = lista; i != NULL; i = i->siguiente) {
        if (es_primo(i->dato)) cuenta++;
    }
    return cuenta;
}

int main() {
    pnodo lista;
    iniciar_lista(lista);

    int opcion;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Agregar al inicio\n";
        cout << "2. Agregar al final\n";
        cout << "3. Agregar ordenado\n";
        cout << "4. Mostrar lista\n";
        cout << "5. Contar primos\n";
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
            case 5: {
                int primos = contar_primos(lista);
                cout << "Cantidad de numeros primos en la lista: " << primos << endl;
                break;
            }
            case 6:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while(opcion != 6);

    // Liberar memoria restante
    while(lista != NULL) {
        pnodo aux = eliminar_inicio(lista);
        delete aux;
    }

    return 0;
}