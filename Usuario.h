#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
typedef struct{
    char nombre[25];
    char contrasena[20];
    int idUsuario;
    int estado;
}eUsuario;


#endif // USUARIO_H_INCLUDED
void eUsuario_mostrarUno(eUsuario listado);
void eUsuario_mostrarListado(eUsuario listado[],int limite);
int eUsuario_buscarLugarLibre(eUsuario listado[],int limite);
void eUsuario_init(eUsuario listado[],int limite,int valor);
void Aux_ALTA(eUsuario listado[],int limite);
int eUsu_siguienteId(eUsuario listado[],int limite);
void ModificarAux(eUsuario listado[],int limite);
void BajaAux(eUsuario listado[], int limite);
int BuscarID(eUsuario lista[], int tam, int numero);
