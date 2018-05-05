#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Usuario.h"
#include "Producto.h"
#define CANTIDADPRO 15
#define CANTIDADUSU 10

int main()
{
    eUsuario Usuarios[CANTIDADUSU];
    eUsuario_init(Usuarios,CANTIDADUSU,-1);
    eProducto Productos[CANTIDADPRO];
    eProducto_init(Productos,CANTIDADPRO,-1);

    char respuesta='s';
    int opcion;

    while(respuesta=='s')
    {
        printf("\n1)ALTA ");
        printf("\n2)MODIFICAR");
        printf("\n3)BAJA ");
        printf("\n4)PUBLICAR PRODUCTO ");
        printf("\n5)MODIFICAR PRODUCTO ");
        printf("\n6)CANCELAR PUBLICACION ");

        printf("\n\nOpcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            {
                Aux_ALTA(Usuarios,CANTIDADUSU);
                break;
            }
        case 2:
            {
                ModificarAux(Usuarios,CANTIDADUSU);
                break;
            }
        case 3:
            {
                BajaAux(Usuarios,CANTIDADUSU);
                getch();
                break;
            }
        case 4:
            {
                Aux_ALTAPRO(Productos,CANTIDADPRO);
                break;
            }
        case 5:
            {
               ModificarAuxPRO(Productos,Usuarios,CANTIDADPRO,CANTIDADUSU);
               getch();
               break;
            }
        case 6:
            {
                BajaAuxPRO(Productos,Usuarios,CANTIDADPRO,CANTIDADUSU);
                getch();
                break;
            }
        //case 7:
        default:
            {
                printf("Opcion Incorrecta.");
            }

        }
        system("cls");
    }

    return 0;
}
