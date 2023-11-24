/*
proyecto equipo 5
integrantes:
Devin Alexander Vázquez Alonso 23310138
Angel Leonardo Vaca Ojeda 23310142
Juan Carlos Estrada Arriaga 23310106
Christian Alexis Rosario Gálvez 23310134
Gabriel Pilar Soto 23310116
*/
#include <stdio.h>
#include <string.h> //usare esta libreria que permite manejar los strings



struct Producto{// se hace la estructura que tendra cada producto (nombre y cantidad)
    char nombre_p[50];
    int cantidad;
};

void mostrar_productos(struct Producto inP[],int n_product, char text[50]){
    printf("Esta es la lista de los productos...\n");
    for (int i = 0; i < n_product; i++)
    {
    printf("\n-----------\n");
    printf("%d) %s --> ",i+1,inP[i].nombre_p);
    printf("%d",inP[i].cantidad);
                    
    }
    printf("\n-----------\n");
    printf("Eliga cual quiere %s:  ",text);
}

int main(){


    printf("----------------------------------------\n| ");
    printf("BIENVENIDOS A LA PAPELERIA LAS VACAS");
    printf(" |\n----------------------------------------\n");


    //vemos cuanto sera el maximo de productos de la papeleria
    int espacio_papeleria;
    printf("ingrese para cuantos productos tiene espacio en la papeleria: ");
    scanf("%d",&espacio_papeleria);
    //llevaremos a cabo el menu de opciones
    int opc;

    int num_productos = 0; //indicador de cuantos productos hay en la papeleria
    struct Producto productos[espacio_papeleria];//arreglo de todos los productos

    do //se utiliza un do-while para que se repita hasta que el usuario desida salir
    {
        //menu principal
        printf("\n---------------\nQue le gustaria hacer???\n---------------\n");
        printf("1) Producto nuevo\n");
        printf("2) Buscar Producto\n");
        printf("3) Actualizar Producto\n");
        printf("4) Agregar Producto\n");
        printf("5) Eliminar producto\n");
        printf("6) salir\n\n");
        printf("Eliga.... : ");
        scanf("%d",&opc);

        switch (opc)
        {
        case 1:
            if (num_productos < espacio_papeleria)
            {
                //pedimos los datos del producto y los agregamos usando como indice num_productos
                printf("\nNombre del Producto: ");
                scanf("%s",&productos[num_productos].nombre_p);
                printf("Cantidad Agregada: ");
                scanf("%d",&productos[num_productos].cantidad);
                //cada ves que se agrega un elemento se incrementa num_productos
                num_productos++;  //y asi funciona como un indice actualizado
                printf("\nEl producto se a agregado..\n");
                
            }else{
                printf("\nYa no hay espacio!!!!!...\n");//en cado de que este llena la papeleria este no dejara agregar
            }
            
            break;
        case 2:
            if (num_productos > 0)
            {
                //establecemos una variable que contenga el nombre del producto a buscar
                char search[50];
                printf("Nombre del producto a Buscar: ");
                scanf("%s",&search);

                int encontrado = 0; // esta variable no ayudara a saber si se a encontrado o no el producto

                //se realiza la busqueda a cada uno de los elemetos para encontrar coincidencias
                for (int i = 0; i < num_productos; i++)
                {
                    if (strcmp(productos[i].nombre_p,search) == 0) // esta funcion nos permite comparar entre dos strings para hallar coincidencias
                    {
                        printf("\n____________\nSe encontro el producto!\n");
                        printf("%s --> %d\n_______________\n",productos[i].nombre_p,productos[i].cantidad);
                        encontrado = 1; //una ves encontrada una coincidencia la variable se pondra en 1 simulando se un true
                        break;
                    }
                    
                }
                if (!encontrado)
                {
                    printf("\nProducto no encontrado...\n");//en caso de no haber encontrado coincidencias este dira esto
                }
                
                
            }else{
                printf("\nNo hay productos que buscar...\n");//en caso de no haber elementos
            }
            
            break;
        case 3:
            /*
            se imprimen todos los productos para que el usuario eliga cual actualizar
            esto se repite en varias ocasiones en diferentes prosesos como "agregar" y "eliminar"
            */
            if (num_productos > 0)
            {
                int indice;
                
                mostrar_productos(productos,num_productos,"Actualizar");
                
                scanf("%d",&indice);
                indice--;
                if (indice >=0 && indice < num_productos)// se verifica que el valor sea apropiado del array
                {
                    printf("Nombre nuevo: ");
                    scanf("%s",&productos[indice].nombre_p);
                    printf("Cantidad actual: ");
                    scanf("%d",&productos[indice].cantidad);
                    printf("\nProducto Actualizado....\n");
                }else{
                    printf("\nEl puesto que usted indico esta fuera de rango...\n");//en caso de que no
                }
                

            }else{
                printf("\nNo hay productos que Actualizar\n");//si no hay elementos no se podra actualizar
            }
            
            break;
        case 4:
            if (num_productos > 0)
            {
                int indice_b, add; // add sirve para almacenar la cantidad que se le sumara al producto
                
                mostrar_productos(productos,num_productos,"agregar stok");

                scanf("%d",&indice_b);
                indice_b--;
                
                if (indice_b >=0 && indice_b < num_productos){
                    printf("cuanto es lo que quieres agregar: ");
                    scanf("%d",&add);
                    if (add < 0)
                    {
                        printf("\nvalor incorrecto...\n");
                        break;
                    }
                    productos[indice_b].cantidad += add;// a la cantidad que ya tenia se le agrego la nueva mercancia

                    printf("\ncantidad agregada con exito...\n"); 

                }else{
                    printf("\nEl puesto que usted indico esta fuera de rango...\n");
                }
            }else{
                printf("\nNo hay Productos para agregar....\n");
            }
            
            break;
        case 5:
            if (num_productos > 0)
            {
                int indice_c;

                mostrar_productos(productos,num_productos,"Eliminar");
                scanf("%d",&indice_c);
                indice_c--;

                if (indice_c >=0 && indice_c < num_productos){
                    /*
                    este for sive para que se vallan recorriendo los valores a partir del indice
                    que se eligio, esto para simular que se elimino
                    ejemplo:
                    antes:  (1,2,3,4,5)   digamos que eligimos el elemento 3
                    despues: (1,2,4,5, ) los valores solo se recorrieron para asi eliminar el 3
                    */
                    for (int i = indice_c; i < num_productos - 1; i++)
                    {
                        strcpy(productos[i].nombre_p,productos[i+1].nombre_p);//esta funcion permite copiar strings
                        productos[i].cantidad = productos[i+1].cantidad;
                    }
                    num_productos--;
                    printf("\nel producto a sido eliminado...\n");
                }else{
                    printf("\nEl puesto que usted indico esta fuera de rango...\n");
                }
                
            }else{
                printf("\nno hay productos que eliminar...\n");
            }
            
            break;
        case 6:
            /*
            al salir te imprime como quedaron los productos al final
            */
            printf("\n___________________________________\n\nEstos son los productos finales");
                for (int i = 0; i < num_productos; i++)
                {
                    printf("\n_________\n");
                    printf("%s --> ",productos[i].nombre_p);
                    printf("%d",productos[i].cantidad);
                    
                    }
            printf("\n_________\n");
            printf("\nsaliendo....");
            break;
        
        default:
            printf("Opcion Erronea intente de nuevo...\n");
            break;
        }

    } while (opc != 6);

    return 0;
}