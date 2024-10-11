#include "../include/promocion.h"

//  La estructura almacena un id de tipo entero, dos fechas para representar el inicio y el fin 
// de la promocion, así como la información de qué productos forman parte de la promocion.
struct rep_promocion {
    int idPromo;
    TFecha start;
    TFecha finish;
    TConjuntoProductos productos;
};

TPromocion crearTPromocion(int idProm, TFecha ini, TFecha fin, int cantMax){ 
    TPromocion nuevo = new rep_promocion;
    nuevo->idPromo = idProm;
    nuevo->start = ini;
    nuevo->finish = fin;
    nuevo->productos = crearTConjuntoProductos(cantMax);
    return nuevo; 
    }

void agregarATPromocion(TPromocion &prom, TProducto p){
    int idProd = idTProducto(p);
    insertarTConjuntoProductos(prom->productos,idProd);
}

void imprimirTPromocion(TPromocion prom){
    printf("Promocion #%u ",prom->idPromo);
    printf("del ");
    imprimirTFecha(prom->start);
    printf(" al ");
    imprimirTFecha(prom->finish);
    printf("\n");
    printf("Productos: ");
    imprimirTConjuntoProductos(prom->productos);
}

void liberarTPromocion(TPromocion &prom){
    liberarTConjuntoProductos(prom->productos);
    liberarTFecha(prom->start);
    liberarTFecha(prom->finish);
    delete prom;
    prom = NULL;
}

bool perteneceATPromocion(TPromocion prom, TProducto p){ return perteneceTConjuntoProductos(prom->productos,idTProducto(p)); }

int idTPromocion(TPromocion prom){ return prom->idPromo; }

TFecha fechaInicioTPromocion(TPromocion prom){ return prom->start; }

TFecha fechaFinTPromocion(TPromocion prom){ return prom->finish; }

bool sonPromocionesCompatibles(TPromocion prom1, TPromocion prom2){ 
    if(compararTFechas(prom2->finish, prom1->start))
        return false; 
    
    }



