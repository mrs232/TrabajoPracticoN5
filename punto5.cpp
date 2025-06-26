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

// Ordenacion por seleccion de menor a mayor
void ordenar_seleccion(pnodo &lista) {
    for (pnodo i = lista; i != NULL; i = i->siguiente) {
        pnodo minNodo = i;
        for (pnodo j = i->siguiente; j != NULL; j = j->siguiente) {
            if (j->dato < minNodo->dato) {
                minNodo = j;
            }
        }
        if (minNodo != i) {
            int temp = i->dato;
            i->dato = minNodo->dato;
            minNodo->dato = temp;
        }
    }
}

// Combina dos listas enlazadas sin importar el orden
void combinar_listas(pnodo &lista1, pnodo &lista2, pnodo &resultado) {
    iniciar_lista(resultado); // Inicializar lista resultado
    pnodo temp;
    for (pnodo i = lista1; i != NULL; i = i->siguiente) { // Copiar lista1
        temp = new tnodo;
        temp->dato = i->dato;
        temp->siguiente = resultado;
        resultado = temp;
    }
    for (pnodo i = lista2; i != NULL; i = i->siguiente) { // Copiar lista2
        temp = new tnodo;
        temp->dato = i->dato;
        temp->siguiente = resultado;
        resultado = temp;
    }
}

// Combina dos listas enlazadas y el resultado queda ordenado
void combinar_listas_ordenado(pnodo &lista1, pnodo &lista2, pnodo &resultado) {
    iniciar_lista(resultado);
    pnodo temp;
    // Copiar lista1 ordenadamente
    for (pnodo i = lista1; i != NULL; i = i->siguiente) {
        temp = new tnodo;
        temp->dato = i->dato;
        temp->siguiente = NULL;
        agregar_ordenado(resultado, temp);
    }
    // Copiar lista2 ordenadamente
    for (pnodo i = lista2; i != NULL; i = i->siguiente) {
        temp = new tnodo;
        temp->dato = i->dato;
        temp->siguiente = NULL;
        agregar_ordenado(resultado, temp);
    }
}

int main() {
    pnodo lista, lista2, resultado;
    iniciar_lista(lista);
    iniciar_lista(lista2);
    iniciar_lista(resultado);

    int opcion;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Agregar al inicio (lista 1)\n";
        cout << "2. Agregar al final (lista 1)\n";
        cout << "3. Agregar ordenado (lista 1)\n";
        cout << "4. Mostrar lista 1\n";
        cout << "5. Ordenar por seleccion (lista 1)\n";
        cout << "6. Agregar al inicio (lista 2)\n";
        cout << "7. Agregar al final (lista 2)\n";
        cout << "8. Agregar ordenado (lista 2)\n";
        cout << "9. Mostrar lista 2\n";
        cout << "10. Combinar listas (sin orden)\n";
        cout << "11. Combinar listas (ordenado)\n";
        cout << "12. Mostrar lista combinada\n";
        cout << "13. Salir\n";
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
                cout << "Lista 1:" << endl;
                mostrar(lista);
                break;
            case 5:
                ordenar_seleccion(lista);
                cout << "Lista 1 ordenada por seleccion." << endl;
                break;
            case 6: {
                pnodo nuevo;
                crear_nodo(nuevo);
                agregar_inicio(lista2, nuevo);
                break;
            }
            case 7: {
                pnodo nuevo;
                crear_nodo(nuevo);
                agregar_final(lista2, nuevo);
                break;
            }
            case 8: {
                pnodo nuevo;
                crear_nodo(nuevo);
                agregar_ordenado(lista2, nuevo);
                break;
            }
            case 9:
                cout << "Lista 2:" << endl;
                mostrar(lista2);
                break;
            case 10:
                // Liberar resultado anterior si existe
                while(resultado != NULL) {
                    pnodo aux = eliminar_inicio(resultado);
                    delete aux;
                }
                combinar_listas(lista, lista2, resultado);
                cout << "Listas combinadas (sin orden)." << endl;
                break;
            case 11:
                // Liberar resultado anterior si existe
                while(resultado != NULL) {
                    pnodo aux = eliminar_inicio(resultado);
                    delete aux;
                }
                combinar_listas_ordenado(lista, lista2, resultado);
                cout << "Listas combinadas (ordenado)." << endl;
                break;
            case 12:
                cout << "Lista combinada:" << endl;
                mostrar(resultado);
                break;
            case 13:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while(opcion != 13);

    // Liberar memoria restante
    while(lista != NULL) {
        pnodo aux = eliminar_inicio(lista);
        delete aux;
    }
    while(lista2 != NULL) {
        pnodo aux = eliminar_inicio(lista2);
        delete aux;
    }
    while(resultado != NULL) {
        pnodo aux = eliminar_inicio(resultado);
        delete aux;
    }

    return 0;
}