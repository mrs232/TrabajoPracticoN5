#include<iostream>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
                    int dato;
                    pnodo sig;
                    pnodo ant;
                    };
typedef struct tlista{
                    pnodo inicio;
                    pnodo fin;
                    };

void IniciarLista(tlista &lista)
{
    lista.inicio = NULL;
    lista.fin = NULL;
}

void CrearNodo(pnodo &nuevo, int valor)
{
    nuevo = new tnodo;
    if(nuevo != NULL)
    {
        nuevo -> dato = valor;
        nuevo -> sig = NULL;
        nuevo -> ant = NULL;
    }
}

void AgregarInicio(tlista &lista, pnodo nuevo)
{
    if(lista.inicio == NULL){
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else{
        nuevo->sig = lista.inicio;
        lista.inicio->ant = nuevo;
        lista.inicio = nuevo;
    }
}

void AgregarFinal(tlista &lista, pnodo nuevo){
    if(lista.inicio == NULL){
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else{
        lista.fin->sig = nuevo;
        nuevo->ant = lista.fin;
        lista.fin = nuevo;
    }
}

pnodo QuitarInicio(tlista &lista) {
    pnodo extraido;
    if (lista.inicio == NULL) {
        extraido = NULL;
    } else if (lista.inicio == lista.fin) {
        extraido = lista.inicio;
        lista.inicio = NULL;
        lista.fin = NULL;
    } else {
        extraido = lista.inicio;
        lista.inicio = lista.inicio->sig;
        lista.inicio->ant = NULL;
        extraido->sig = NULL;
    }
    return extraido;
}

pnodo QuitarFinal(tlista &lista) {
    pnodo extraido;
    if (lista.fin == NULL) {
        extraido = NULL;
    } else if (lista.inicio == lista.fin) {
        extraido = lista.fin;
        lista.inicio = NULL;
        lista.fin = NULL;
    } else {
        extraido = lista.fin;
        lista.fin = lista.fin->ant;
        lista.fin->sig = NULL;
        extraido->ant = NULL;
    }
    return extraido;
}

void MostrarLista(const tlista &lista) {
    pnodo aux = lista.inicio;
    cout << "Lista: ";
    while (aux != NULL) {
        cout << aux->dato << " ";
        aux = aux->sig;
    }
    cout << endl;
}

void EliminarMultiplosDe3(tlista &lista) {
    pnodo actual = lista.inicio;
    while (actual != NULL) { // Recorremos la lista
        pnodo siguiente = actual->sig;
        if (actual->dato % 3 == 0) { 
            // Eliminar nodo actual
            if (actual == lista.inicio) {
                QuitarInicio(lista);
            } else if (actual == lista.fin) {
                QuitarFinal(lista);
            } else { // Nodo en el medio
                // Reacomodar enlaces del nodo anterior y siguiente
                actual->ant->sig = actual->sig;
                actual->sig->ant = actual->ant;
                delete actual;
            }
        }
        actual = siguiente;
    }
}

int main(){
    // Ejemplo de uso:
    tlista lista;
    IniciarLista(lista);
    pnodo n1, n2, n3, n4;
    CrearNodo(n1, 3);
    CrearNodo(n2, 5);
    CrearNodo(n3, 9);
    CrearNodo(n4, 7);
    AgregarFinal(lista, n1);
    AgregarFinal(lista, n2);
    AgregarFinal(lista, n3);
    AgregarFinal(lista, n4);
    cout << "Lista original:" << endl;
    MostrarLista(lista);
    EliminarMultiplosDe3(lista);
    cout << "Lista luego de eliminar multiplos de 3:" << endl;
    MostrarLista(lista);
    
    return 0;
}