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

void MostrarMayorMenor(const tlista &lista) {
    if (lista.inicio == NULL) {
        cout << "La lista está vacía." << endl;
        return;
    }
    int mayor = lista.inicio->dato;
    int menor = lista.inicio->dato;
    pnodo aux = lista.inicio->sig;
    while (aux != NULL) {
        if (aux->dato > mayor) mayor = aux->dato;
        if (aux->dato < menor) menor = aux->dato;
        aux = aux->sig;
    }
    cout << "Mayor: " << mayor << endl;
    cout << "Menor: " << menor << endl;
}

int main(){
    // Ejemplo de uso
    tlista lista;
    IniciarLista(lista);
    pnodo n1, n2, n3;
    CrearNodo(n1, 5);
    CrearNodo(n2, 10);
    CrearNodo(n3, 3);
    AgregarFinal(lista, n1);
    AgregarFinal(lista, n2);
    AgregarFinal(lista, n3);
    MostrarMayorMenor(lista);
    return 0;
}