#include <iostream>
using namespace std;

struct tnodo {
    int dato;
    tnodo* siguiente;
};
typedef tnodo* pnodo;

// --- TDA PILA ---
struct Pila {
    pnodo tope;
};

void crear_pila(Pila &p) {
    p.tope = NULL;
}

bool pila_vacia(Pila &p) {
    return p.tope == NULL;
}

void push(Pila &p, int valor) {
    pnodo nuevo = new tnodo;
    if (nuevo != NULL) {
        nuevo->dato = valor;
        nuevo->siguiente = p.tope;
        p.tope = nuevo;
    } else {
        cout << "Memoria insuficiente" << endl;
    }
}

bool pop(Pila &p, int &valor) {
    if (pila_vacia(p)) {
        return false;
    }
    pnodo borrado = p.tope;
    valor = borrado->dato;
    p.tope = borrado->siguiente;
    delete borrado;
    return true;
}

bool top(Pila &p, int &valor) {
    if (pila_vacia(p)) {
        return false;
    }
    valor = p.tope->dato;
    return true;
}

void liberar_pila(Pila &p) {
    while (!pila_vacia(p)) {
        int tmp;
        pop(p, tmp);
    }
}

void mostrar_pila(Pila &p) {
    pnodo i = p.tope;
    if (i == NULL) {
        cout << "Pila vacía" << endl;
    } else {
        cout << "Elementos en la pila (tope a base):" << endl;
        while (i != NULL) {
            cout << i->dato << endl;
            i = i->siguiente;
        }
    }
}
// --- FIN TDA PILA ---

// --- TDA COLA ---
struct Cola {
    pnodo frente;
    pnodo final;
    int contador;
};

void crear_cola(Cola &c) {
    c.frente = NULL;
    c.final = NULL;
    c.contador = 0;
}

bool cola_vacia(Cola &c) {
    return c.frente == NULL;
}

void PushQueue(Cola &c, int valor) {
    pnodo nuevo = new tnodo;
    if (nuevo != NULL) {
        nuevo->dato = valor;
        nuevo->siguiente = NULL;
        if (cola_vacia(c)) {
            c.frente = nuevo;
            c.final = nuevo;
        } else {
            c.final->siguiente = nuevo;
            c.final = nuevo;
        }
        c.contador++;
    } else {
        cout << "Memoria insuficiente" << endl;
    }
}

bool PopQueue(Cola &c, int &valor) {
    if (cola_vacia(c)) {
        return false;
    }
    pnodo borrado = c.frente;
    valor = borrado->dato;
    c.frente = borrado->siguiente;
    if (c.frente == NULL) {
        c.final = NULL;
    }
    delete borrado;
    c.contador--;
    return true;
}

bool TopQueue(Cola &c, int &valor) {
    if (cola_vacia(c)) {
        return false;
    }
    valor = c.frente->dato;
    return true;
}

void mostrar_cola(Cola &c) {
    pnodo i = c.frente;
    if (i == NULL) {
        cout << "Cola vacía" << endl;
    } else {
        cout << "Elementos en la cola (frente a final):" << endl;
        while (i != NULL) {
            cout << i->dato << endl;
            i = i->siguiente;
        }
    }
    cout << "Cantidad de elementos en la cola: " << c.contador << endl;
}

void liberar_cola(Cola &c) {
    int tmp;
    while (PopQueue(c, tmp));
}
// --- FIN TDA COLA ---

int main() {
    Pila pila;
    Cola cola;
    crear_pila(pila);
    crear_cola(cola);

    int opcionPrincipal;
    do {
        cout << "\n--- MENU PRINCIPAL ---\n";
        cout << "1. Operar con PILA\n";
        cout << "2. Operar con COLA\n";
        cout << "3. Salir\n";
        cout << "Ingrese opcion: ";
        cin >> opcionPrincipal;

        if (opcionPrincipal == 1) {
            int opcion;
            do {
                cout << "\n--- MENU PILA ---\n";
                cout << "1. PushStack (apilar)\n";
                cout << "2. PopStack (desapilar)\n";
                cout << "3. TopStack (ver tope)\n";
                cout << "4. Mostrar pila\n";
                cout << "5. Volver al menu principal\n";
                cout << "Ingrese opcion: ";
                cin >> opcion;

                switch(opcion) {
                    case 1: {
                        int valor;
                        cout << "Ingrese valor a apilar: ";
                        cin >> valor;
                        push(pila, valor);
                        break;
                    }
                    case 2: {
                        int valor;
                        if (pop(pila, valor))
                            cout << "Elemento desapilado: " << valor << endl;
                        else
                            cout << "Pila vacia, no se puede desapilar." << endl;
                        break;
                    }
                    case 3: {
                        int valor;
                        if (top(pila, valor))
                            cout << "Elemento en el tope: " << valor << endl;
                        else
                            cout << "Pila vacia." << endl;
                        break;
                    }
                    case 4:
                        mostrar_pila(pila);
                        break;
                    case 5:
                        break;
                    default:
                        cout << "Opcion invalida." << endl;
                }
            } while(opcion != 5);
        } else if (opcionPrincipal == 2) {
            int opcion;
            do {
                cout << "\n--- MENU COLA ---\n";
                cout << "1. PushQueue (encolar)\n";
                cout << "2. PopQueue (desencolar)\n";
                cout << "3. TopQueue (ver frente)\n";
                cout << "4. Mostrar cola\n";
                cout << "5. Volver al menu principal\n";
                cout << "Ingrese opcion: ";
                cin >> opcion;

                switch(opcion) {
                    case 1: {
                        int valor;
                        cout << "Ingrese valor a encolar: ";
                        cin >> valor;
                        PushQueue(cola, valor);
                        break;
                    }
                    case 2: {
                        int valor;
                        if (PopQueue(cola, valor))
                            cout << "Elemento desencolado: " << valor << endl;
                        else
                            cout << "Cola vacia, no se puede desencolar." << endl;
                        break;
                    }
                    case 3: {
                        int valor;
                        if (TopQueue(cola, valor))
                            cout << "Elemento en el frente: " << valor << endl;
                        else
                            cout << "Cola vacia." << endl;
                        break;
                    }
                    case 4:
                        mostrar_cola(cola);
                        break;
                    case 5:
                        break;
                    default:
                        cout << "Opcion invalida." << endl;
                }
            } while(opcion != 5);
        } else if (opcionPrincipal == 3) {
            cout << "Saliendo..." << endl;
        } else {
            cout << "Opcion invalida." << endl;
        }
    } while(opcionPrincipal != 3);

    liberar_pila(pila);
    liberar_cola(cola);

    return 0;
}