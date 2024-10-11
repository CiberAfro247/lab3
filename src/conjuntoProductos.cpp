#include "../include/conjuntoProductos.h"


// Definición de tipo TConjuntoProductos como un puntero a rep_conjuntoproductos
// El conjunto es acotado, y la cantidad máxima de elementos define el rango de 
// identificadores que almacena.
// Los identificadores que almacena el conjunto cumplen 0 <= id < cantMax
struct rep_conjuntoProductos{
    bool* conjProductos;
    int cant;
    int cantMax;
};

TConjuntoProductos crearTConjuntoProductos(int cantMax){ 
    TConjuntoProductos nuevo = new rep_conjuntoProductos;
    nuevo->conjProductos = new bool[cantMax+1]();
    nuevo->cantMax = cantMax;
    nuevo->cant = 0;
    return nuevo;
}

void insertarTConjuntoProductos(TConjuntoProductos &conjuntoProductos, int idProducto){
    
    if(idProducto < conjuntoProductos->cantMax && conjuntoProductos->conjProductos[idProducto] == false){
        conjuntoProductos->conjProductos[idProducto] = true;
        conjuntoProductos->cant++;
    }
}

void imprimirTConjuntoProductos(TConjuntoProductos conjuntoProductos){
    for(int i = 0; i < conjuntoProductos->cantMax; i++){
        if(conjuntoProductos->conjProductos[i] == true){
            printf("%u ",i);
        }
    }
    printf("\n");
}

void liberarTConjuntoProductos(TConjuntoProductos &conjuntoProductos){
    delete []conjuntoProductos->conjProductos;
    delete conjuntoProductos;
    conjuntoProductos = NULL;
}

bool esVacioTConjuntoProductos(TConjuntoProductos conjuntoProductos){
     if (conjuntoProductos->cant == 0){
            return true;
     }
     else {
        return false;
     }
}

int cantidadTConjuntoProductos(TConjuntoProductos conjuntoProductos){ return conjuntoProductos->cant; }

int cantMaxTConjuntoProductos(TConjuntoProductos conjuntoProductos){ return conjuntoProductos->cantMax; }

bool perteneceTConjuntoProductos(TConjuntoProductos conjuntoProductos, int idProducto) { 
    return idProducto >= 0 && idProducto < conjuntoProductos->cantMax && conjuntoProductos->conjProductos[idProducto];
}

void borrarDeTConjuntoProductos(TConjuntoProductos &conjuntoProductos, int idProducto){
   if(idProducto < conjuntoProductos->cantMax && conjuntoProductos->conjProductos[idProducto] == true){
        conjuntoProductos->conjProductos[idProducto] = false;
        conjuntoProductos->cant--;    
   }
}

TConjuntoProductos unionTConjuntoProductos(TConjuntoProductos conjuntoProductos1, TConjuntoProductos conjuntoProductos2){
    TConjuntoProductos ret = crearTConjuntoProductos(conjuntoProductos1->cantMax);
    for( int i = 0; i < conjuntoProductos1->cantMax; i++){
        ret->conjProductos[i] = conjuntoProductos1->conjProductos[i] || conjuntoProductos2->conjProductos[i];
    }
    return ret;
 }

TConjuntoProductos interseccionTConjuntoProductos(TConjuntoProductos conjuntoProductos1, TConjuntoProductos conjuntoProductos2){
    TConjuntoProductos ret = crearTConjuntoProductos(conjuntoProductos1->cantMax);
    for( int i = 0; i < conjuntoProductos1->cantMax; i++){
        ret->conjProductos[i]= conjuntoProductos1->conjProductos[i] && conjuntoProductos2->conjProductos[i];
    }
    return ret;    
 }

TConjuntoProductos diferenciaTConjuntoProductos(TConjuntoProductos conjuntoProductos1, TConjuntoProductos conjuntoProductos2){ 
    TConjuntoProductos ret = crearTConjuntoProductos(conjuntoProductos1->cantMax);
    for( int i = 0; i < conjuntoProductos1->cantMax; i++){
        ret->conjProductos[i]= conjuntoProductos1->conjProductos[i] && !conjuntoProductos2->conjProductos[i];
    }
    return ret;
 }
