/* Utilice la definición de lista del punto anterior para implementar un procedimiento/función que convierta un número en base decimal a base binaria. */

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

void DecimalABinario(int numero, tlista &lista) {
    IniciarLista(lista);
    if (numero == 0) {
        pnodo nuevo;
        CrearNodo(nuevo, 0);
        AgregarInicio(lista, nuevo);
        return;
    }
    while (numero > 0) {
        int bit = numero % 2;
        pnodo nuevo;
        CrearNodo(nuevo, bit);
        AgregarInicio(lista, nuevo); // MSB al inicio
        numero /= 2;
    }
}

void MostrarBinario(tlista &lista) {
    pnodo i = lista.inicio;
    while (i != NULL) {
        cout << i->dato;
        i = i->sig;
    }
    cout << endl;
}

int main(){
    int numero;
    tlista binario;
    cout << "Ingrese un numero decimal: ";
    cin >> numero;
    DecimalABinario(numero, binario);
    cout << "Representacion binaria: ";
    MostrarBinario(binario);

    while (binario.inicio != NULL) {
        pnodo aux = QuitarInicio(binario);
        delete aux;
    }
    return 0;
}