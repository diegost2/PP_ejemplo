#include "Usuario.h"
#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED
typedef struct{
    char nombreProducto[20];
    int idUsuario;
    int idProducto;
    int Stock;
    float precio;
    int estado;
}eProducto;


#endif // PUBLICACION_H_INCLUDED
void Aux_ALTAPRO(eProducto listado[],int limite);
int eProducto_buscarLugarLibre(eProducto listado[],int limite);
int ePro_siguienteId(eProducto listado[],int limite);
void eProducto_init(eProducto listado[],int limite,int valor);
void eProducto_mostrarListado(eProducto listado[],eUsuario lista[],int limite, int limiteUsuario);
void eProducto_mostrarUno(eProducto listado);
void ModificarAuxPRO(eProducto listado[],eUsuario lista[], int limite, int limiteUsuario);
void BajaAuxPRO(eProducto listado[],eUsuario lista[], int limite, int limiteUsuario);
int BuscarIDPRO(eProducto lista[], int tam, int numero);

