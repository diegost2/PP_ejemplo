#include "Producto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Usuario.h"
#define OCUPADOPRO 1
#define LIBREPRO -1

int BuscarIDPRO(eProducto lista[], int tam, int numero)
{
    int i;
    int retorno=-1;
    for(i=0;i<tam;i++)
    {
        if(lista[i].idProducto==numero)
        {
            retorno=i;
            break;

        }
    }
    return retorno;
}


void Aux_ALTAPRO(eProducto listado[],int limite)
{
    eProducto producto;

    //int password;
    int indice;
    int id;
    id=ePro_siguienteId(listado,limite);
        indice = eProducto_buscarLugarLibre(listado,limite);
        if(indice == -1)
        {
            printf("No hay mas espacio para ingresar.");
            getch();
        }
        else{

            //if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            printf("Ingrese Producto: ");
            fflush(stdin);
            gets(producto.nombreProducto);
            /*printf("Ingrese una password: ");
            fflush("stdin");
            gets(password);
            system("cls");
            printf("Ingresado con exito.");
            getch();
            system("cls");*/

            printf("Ingrese precio: ");
            scanf("%f",&producto.precio);
            printf("Ingrese cantidad en stock: ");
            scanf("%d",&producto.Stock);
            }

            strcpy(listado[indice].nombreProducto,producto.nombreProducto);
            listado[indice].idProducto=id;
            listado[indice].precio=producto.precio;
            listado[indice].Stock=producto.Stock;
            listado[indice].estado = 1;
            //strcpy(listado[indice].contrasena,password);


}

int eProducto_buscarLugarLibre(eProducto listado[],int limite)
{
    int retorno = -1;
    int i;
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == -1)
            {
                retorno = i;
                break;
            }
        }

    return retorno;
}

int ePro_siguienteId(eProducto listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADOPRO)
            {
                    if(listado[i].idProducto>retorno)
                    {
                         retorno=listado[i].idProducto;
                    }

            }
        }
    }

    return retorno+1;
}

void eProducto_init(eProducto listado[],int limite,int valor)
{
    int i;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= valor;
            listado[i].idProducto= 0;
        }

}

void eProducto_mostrarUno(eProducto listado)
{
     printf("\n               %s          %.2f        %d ",listado.nombreProducto,listado.precio, listado.Stock);

}

void eProducto_mostrarListado(eProducto listado[],eUsuario lista[],int limite, int limiteUsuario)
{

    int i;
    printf(" Vendedor    Nombre del Producto   Precio    Stock \n");
    for(i=0; i<limiteUsuario; i++)
        {
            if(lista[i].estado!=-1)
            {
                printf("%s ", lista[i].nombre);

                for(int j=0;j<limite;j++)
                {
                    if(lista[i].idUsuario==listado[j].idUsuario)
                    {
                        //if(listado[j].estado!=-1){
                            eProducto_mostrarUno(listado[j]);
                            break;


                    }

                }

            }
        }
}

void ModificarAuxPRO(eProducto listado[],eUsuario lista[], int limite, int limiteUsuario){
    int valor;
    eProducto producto;
    int idEncontrado;
    int opcion;

    eProducto_mostrarListado(listado,lista,limite,limiteUsuario);
    printf("\nIngrese ID de Producto a Modificar: ");
    scanf("%d",&valor);
    idEncontrado=BuscarIDPRO(listado,limite,valor);
            if(idEncontrado!=-1){
                printf("Esta seguro de querer modificar el producto: %s ", listado[idEncontrado].nombreProducto);
                printf("\n1)SI.");
                printf("\n2)NO.");
                printf("\nOpcion: ");
                scanf("%d",&opcion);
                switch(opcion){
                    case 1:
                        {
                            system("cls");
                            printf("Ingrese nuevo Nombre: ");
                            fflush(stdin);
                            gets(producto.nombreProducto);
                            printf("Ingrese su ID de Producto: ");
                            scanf("%d",&producto.idProducto);
                            printf("Ingrese precio: ");
                            scanf("%f",&producto.precio);
                            printf("Ingrese cantidad en stock: ");
                            scanf("%d",&producto.Stock);

                            strcpy(listado[idEncontrado].nombreProducto,producto.nombreProducto);
                            listado[idEncontrado].idProducto=producto.idProducto;
                            listado[idEncontrado].precio=producto.precio;
                            listado[idEncontrado].Stock=producto.Stock;
                            system("cls");
                            printf("Usuario Cargado con exito!");
                            getch();

                            break;
                        }
                    case 2:
                        {
                            printf("Modificacion Cancelada.");
                            getch();
                            break;

                        }
                    }


                }
            else{
                    printf("Producto no encontrado.");
                    getch();
                }
}

void BajaAuxPRO(eProducto listado[],eUsuario lista[], int limite, int limiteUsuario){
    int valor;
    int idEncontrado;
    int opcion;
    eProducto_mostrarListado(listado,lista,limite,limiteUsuario);
    printf("\nIngrese ID del producto a dar de Baja: ");
    scanf("%d",&valor);
    idEncontrado=BuscarIDPRO(listado,limite,valor);

            if(idEncontrado!=-1){
                printf("Esta seguro de querer borrar al usuario: %s ", listado[idEncontrado].nombreProducto);
                printf("\n1)SI.");
                printf("\n2)NO.");
                printf("\n○2nOpcion: ");
                scanf("%d",&opcion);
                switch(opcion){
                    case 1:
                        {

                            listado[idEncontrado].estado=-1;
                            system("cls");
                            printf("Producto cancelado.!");
                            getch();

                            break;
                        }
                    case 2:
                        {
                            printf("Operacion cancelada.");
                            getch();
                            break;

                        }
                    }


                }
            else{
                    printf("Producto no encontrado.");
                    getch();
                }

}
