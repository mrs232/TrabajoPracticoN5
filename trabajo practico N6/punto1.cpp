#include <iostream>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
    int dato;
    pnodo sig;
    pnodo ant;};

void IniciarLista(pnodo &inicio){
    inicio = NULL;
}

void CrearNodo(pnodo &nuevo, int valor){
    nuevo = new tnodo;
    if(nuevo != NULL){
        nuevo -> dato = valor;
        nuevo -> sig = NULL;
        nuevo -> ant = NULL;}
}

void agregar_inicio(pnodo &inicio, pnodo nuevo){
    if(inicio == NULL){
        inicio = nuevo;
    }
    else{
        nuevo -> sig = inicio;
        inicio -> ant = nuevo;
        inicio = nuevo;
    }
}

void AgregarFinal(pnodo &inicio, pnodo nuevo){
    pnodo i;
    if(inicio == NULL){
        inicio = nuevo;
    }
    else{
        for(i = inicio; i -> sig != NULL; i = i -> sig);
        i -> sig = nuevo;
        nuevo -> ant = i;
    }
}

void AgregarOrden(pnodo &inicio, pnodo nuevo){
    pnodo i;
    if(inicio == NULL){
        inicio = nuevo;
    }
    else{
        if(nuevo -> dato < inicio -> dato)
        {
            nuevo -> sig = inicio;
            inicio -> ant = nuevo;
            inicio = nuevo;
        }
        else{
            for(i = inicio; i -> sig != NULL && (i -> sig) -> dato < nuevo -> dato; i = i -> sig);
            if(i -> sig != NULL){
                nuevo -> sig = i -> sig;
                nuevo -> ant = i;
                (i -> sig) -> ant = nuevo;
                i -> sig = nuevo;
            }
            else{
                i -> sig = nuevo;
                nuevo -> ant = i;
            }
        }
    }
}

pnodo QuitarInicio(pnodo &inicio){
    pnodo extraido;
    if(inicio == NULL)
    {
        extraido = NULL;
    }
    else{
        if(inicio -> sig == NULL)
        {
            extraido = inicio;
            inicio = NULL;
        }
        else{
            extraido = inicio;
            inicio = inicio -> sig;
            inicio -> ant = NULL;
            extraido -> sig = NULL;
        }
    }
    return extraido;
}

pnodo QuitarFinal(pnodo &inicio){
    pnodo extraido, i;
    if(inicio == NULL)
    {
        extraido = NULL;
    }
    else{
        for(i = inicio; i -> sig != NULL; i = i -> sig);
        extraido = i;
        (i -> ant) -> sig = NULL;
        i -> ant = NULL;
    }
    return extraido;
}

pnodo QuitarNodo(pnodo &inicio, int valor){
    pnodo extraido, i;
    if(inicio == NULL)
    {
        extraido = NULL;
    }
    else{
        if(inicio -> dato == valor)
        {
            extraido = inicio;
            inicio = inicio->sig;
            inicio->ant = NULL;
            extraido->sig = NULL;
        }
        else{
            for(i = inicio; i != NULL && i -> dato != valor; i = i -> sig);
                if(i != NULL){
                    extraido = i;
                    (i -> ant) -> sig = i -> sig;
                    i -> sig = i -> ant;
                    extraido -> sig = NULL;
                    extraido -> ant = NULL;
                }
        }
    }
    return extraido;
}

bool BuscarNodo(pnodo inicio, int valor){
    pnodo i;
    bool encontrado = false;
    for(i = inicio; i != NULL && !encontrado; i = i -> sig){
        if(i -> dato == valor){
            encontrado = true;
        }
    }
    return encontrado;
}

void MostrarLista(pnodo inicio){
    pnodo i;
    if(inicio != NULL)
    {
        for(i = inicio; i != NULL; i = i -> sig){
            cout << i -> dato << endl;
        }
    }
}

int main() {
    pnodo lista;
    IniciarLista(lista);

    int opcion, valor;
    pnodo extraido;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Agregar al inicio\n";
        cout << "2. Agregar al final\n";
        cout << "3. Agregar ordenado\n";
        cout << "4. Quitar del inicio\n";
        cout << "5. Quitar del final\n";
        cout << "6. Quitar nodo por valor\n";
        cout << "7. Buscar nodo\n";
        cout << "8. Mostrar lista\n";
        cout << "9. Salir\n";
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                cout << "Ingrese valor: ";
                cin >> valor;
                pnodo nuevo;
                CrearNodo(nuevo, valor);
                agregar_inicio(lista, nuevo);
                break;
            }
            case 2: {
                cout << "Ingrese valor: ";
                cin >> valor;
                pnodo nuevo;
                CrearNodo(nuevo, valor);
                AgregarFinal(lista, nuevo);
                break;
            }
            case 3: {
                cout << "Ingrese valor: ";
                cin >> valor;
                pnodo nuevo;
                CrearNodo(nuevo, valor);
                AgregarOrden(lista, nuevo);
                break;
            }
            case 4: {
                extraido = QuitarInicio(lista);
                if (extraido != NULL) {
                    cout << "Nodo extraido: " << extraido->dato << endl;
                    delete extraido;
                } else {
                    cout << "Lista vacia." << endl;
                }
                break;
            }
            case 5: {
                extraido = QuitarFinal(lista);
                if (extraido != NULL) {
                    cout << "Nodo extraido: " << extraido->dato << endl;
                    delete extraido;
                } else {
                    cout << "Lista vacia." << endl;
                }
                break;
            }
            case 6: {
                cout << "Ingrese valor a quitar: ";
                cin >> valor;
                extraido = QuitarNodo(lista, valor);
                if (extraido != NULL) {
                    cout << "Nodo extraido: " << extraido->dato << endl;
                    delete extraido;
                } else {
                    cout << "Valor no encontrado o lista vacia." << endl;
                }
                break;
            }
            case 7: {
                cout << "Ingrese valor a buscar: ";
                cin >> valor;
                if (BuscarNodo(lista, valor)) {
                    cout << "Valor encontrado en la lista." << endl;
                } else {
                    cout << "Valor NO encontrado en la lista." << endl;
                }
                break;
            }
            case 8:
                cout << "Contenido de la lista:" << endl;
                MostrarLista(lista);
                break;
            case 9:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while(opcion != 9);

    // Liberar memoria restante
    while (lista != NULL) {
        extraido = QuitarInicio(lista);
        delete extraido;
    }

    return 0;
}