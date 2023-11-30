// IMPORTANTE LEER!!!!
/* 
Maestra al momento de hacer el proyecto nos confundimos de equipo, nos dijo que lo dejaramos haci
igual aqui pongo los nombres del equipo para que no nos perjudique
*/
/*
proyecto equipo 4   
integrantes:
Devin Alexander Vázquez Alonso 23310138
Angel Leonardo Vaca Ojeda 23310142
Juan Carlos Estrada Arriaga 23310106
Christian Alexis Rosario Gálvez 23310134
Gabriel Pilar Soto 23310116
*/

#include <stdio.h>
#include <string.h> //usare esta libreria que permite manejar los strings
#include <conio.h>




struct Producto{// se hace la estructura que tendra cada producto (nombre y cantidad)
    char nombre_p[50];
    int cantidad = 0;
    float precio;
};

//funcion para calcular el total
float calc_total(struct Producto inP[],int n_product){
    float total_producto = 0;
    float total_pagar = 0;
    for (int i = 0; i < n_product; i++)
    {
        total_producto = (inP[i].cantidad) * (inP[i].precio);
        total_pagar += total_producto;               
    }
    return total_pagar;
}

// funcion para mostrar todos los productos :)
void mostrar_productos(struct Producto inP[],int n_product, char text[50]){
    printf("Esta es la lista de los productos...\n");
    for (int i = 0; i < n_product; i++)
    {
        
    printf("\n-----------\n");
    printf("%d) %s --> ",i+1,inP[i].nombre_p);
    printf("%d",inP[i].cantidad);
    printf(" == $%2.f", inP[i].precio);
                    
    }
    printf("\n-----------\n");
    printf("Eliga cual quiere %s:  ",text);
}



void mostrar_carrito(struct Producto inP[],int n_product){
    printf("Esta es la lista de tu carrito...\n");
    for (int i = 0; i < n_product; i++)
    {
        
    printf("\n^^^^^^^^^^^\n");
    printf("%d) %s --> ",i+1,inP[i].nombre_p);
    printf("%d",inP[i].cantidad);
    printf(" == $%2.f", inP[i].precio);
                    
    }
    printf("\n^^^^^^^^^^^\n");
    
}

// verifica si quedan existencias de cualquier producto del stok
void verfi_exist(struct Producto inP[],int n_product){
    for (int i = 0; i < n_product; i++)
    {
        if (inP[i].cantidad <= 0)
        {
            printf("\nEl producto %s se a quedado sin existencias...\nFavor de rellenar el stok...\n",inP[i].nombre_p);
            getch();
            break;
        }
        
    }
    
}
void creditos(){
    printf("\n\t\t------ CREDITOS ------\n\n");
    printf("\tPROYECTO:  PAPELERIA LAS VACAS\n\n");
    printf("este programa sirve para llevar a cabo el inventario de una papeleria\n");
    printf("aqui podras manejar el inventario de esta asi como los cobros que se les hace\n");
    printf("a los clientes, todos estos datos pueden ser plasmados en un archivo de texto para\n");
    printf("poder cargarlos sin que se pierdan los datos de cada producto.\n");
    printf("\tINTEGRANTES:\n\n");
    printf("Devin Alexander Vázquez Alonso 23310138\n");
    printf("Angel Leonardo Vaca Ojeda 23310142\n");
    printf("Juan Carlos Estrada Arriaga 23310106\n");
    printf("Christian Alexis Rosario Gálvez 23310134\n");
    printf("Gabriel Pilar Soto 23310116\n\n");
    printf("\t1er semestre, grupo O\n\n");
    printf("\t\t----------------------\n");
}

int main(){


    printf("\t\t----------------------------------------\n\n");
    printf("\t\t| BIENVENIDOS A LA PAPELERIA LAS VACAS |\n\n");
    printf("\t\t----------------------------------------\n\n");


    //vemos cuanto sera el maximo de productos de la papeleria
    int espacio_papeleria = 50;

    FILE *archivo;
    

    //llevaremos a cabo el menu de opciones
    int opc;

    int num_productos = 0; //indicador de cuantos productos hay en la papeleria

    struct Producto productos[espacio_papeleria];//arreglo de todos los productos

    struct Producto Carrito[espacio_papeleria];//arreglo del carrito
    int cont_carrito = 0;
    
    


    do //se utiliza un do-while para que se repita hasta que el usuario desida salir
    {
        //menu principal
        printf("\n---------------\nQue le gustaria hacer???\n---------------\n");
        printf("1) Producto nuevo\n");
        printf("2) Buscar Producto\n");
        printf("3) Actualizar Producto\n");
        printf("4) Agregar Producto al carrito\n");
        printf("5) Eliminar producto\n");
        printf("6) Calcular total\n");
        printf("7) Grabar archivo txt\n");
        printf("8) Abrir archivo\n");
        printf("9) Actualizar archivo\n");
        printf("10) Mostrar Carrito\n");
        printf("11) Mostrar Stok\n");
        printf("12) salir\n\n");
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
                printf("Precio del Producto: ");
                scanf("%f",&productos[num_productos].precio);
                //cada ves que se agrega un elemento se incrementa num_productos
                num_productos++;  //y asi funciona como un indice actualizado
                printf("\nEl producto se a agregado..\n");
                
                printf("\tpresione cualquier tecla para continuar.....\n");
                getch();
                
            }else{
                printf("\nYa no hay espacio!!!!!...\n");//en cado de que este llena la papeleria este no dejara agregar
                
                printf("\tpresione cualquier tecla para continuar.....\n");
                getch();
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
                        printf("%s --> %d == $%2.f\n_______________\n",productos[i].nombre_p,productos[i].cantidad,productos[i].precio);
                        encontrado = 1; //una ves encontrada una coincidencia la variable se pondra en 1 simulando se un true
                        
                        printf("\tpresione cualquier tecla para continuar.....\n");
                        getch();

                        break;
                    }
                    
                }
                if (!encontrado)
                {
                    printf("\nProducto no encontrado...\n");//en caso de no haber encontrado coincidencias este dira esto
                    
                    printf("\tpresione cualquier tecla para continuar.....\n");
                    getch();
                }
                
                
            }else{
                printf("\nNo hay productos que buscar...\n");//en caso de no haber elementos
                
                printf("\tpresione cualquier tecla para continuar.....\n");
                getch();
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
                    printf("Precio actual: ");
                    scanf("%f",&productos[indice].precio);
                    printf("\nProducto Actualizado....\n");

                    verfi_exist(productos,num_productos);

                }else{
                    printf("\nEl puesto que usted indico esta fuera de rango...\n");//en caso de que no

                    printf("\tpresione cualquier tecla para continuar.....\n");
                    getch();
                }
                

            }else{
                printf("\nNo hay productos que Actualizar\n");//si no hay elementos no se podra actualizar

                printf("\tpresione cualquier tecla para continuar.....\n");
                getch();
            }
            
            break;
        case 4:
            //agregar al carrito
            
            if (num_productos > 0)
            {
                int indice_b, add; // add sirve para almacenar la cantidad que se le sumara al producto
                
                mostrar_productos(productos,num_productos,"agregar al carrito");

                scanf("%d",&indice_b);
                indice_b--;
                if (indice_b < 0)
                {
                    printf("\nvalor incorrecto\n");
                    
                    printf("\tpresione cualquier tecla para continuar.....\n");
                    getch();

                    break;
                }
                

                //ve si quedan productos del cual elegiste
                if (productos[indice_b].cantidad <= 0)
                {
                    printf("\nNo quedan suficientes productos en stok lo sentimos :(\n");

                    printf("\tpresione cualquier tecla para continuar.....\n");
                    getch();

                    break;
                }
                
                
                
                if (indice_b >=0 && indice_b < num_productos){
                    printf("cuanto es lo que quieres agregar: ");
                    scanf("%d",&add);
                    if (add < 0)
                    {
                        printf("\nvalor incorrecto...\n");
                        
                        printf("\tpresione cualquier tecla para continuar.....\n");
                        getch();

                        break;
                    }else if (add > productos[indice_b].cantidad)
                    {
                        printf("\nNo hay suficientes productos para agregarlos a su carrito\n");
                        
                        printf("\tpresione cualquier tecla para continuar.....\n");
                        getch();
                        
                        break;
                    }
                    
                    
                    strcpy(Carrito[cont_carrito].nombre_p,productos[indice_b].nombre_p);
                    Carrito[cont_carrito].cantidad += add;
                    Carrito[cont_carrito].precio = productos[indice_b].precio;
                    cont_carrito++;
                    
                    productos[indice_b].cantidad -= add;// a la cantidad que ya tenia se le agrego la nueva mercancia

                    printf("\ncantidad agregada con exito...\n"); 
                    
                    printf("\tpresione cualquier tecla para continuar.....\n");
                    getch();

                    verfi_exist(productos,num_productos);

                }else{
                    printf("\nEl puesto que usted indico esta fuera de rango...\n");
                    
                    printf("\tpresione cualquier tecla para continuar.....\n");
                    getch();
                }
            }else{
                printf("\nNo hay Productos para agregar....\n");

                printf("\tpresione cualquier tecla para continuar.....\n");
                getch();
            }
            
            break;
        case 5:
            
            int opcB;
            printf("desea eliminar producto del carrito o del stock de la tienda??\n");
            printf("1) Stock\n");
            printf("2) Carrito\n");
            printf("3) Regresar\n");
            printf("Eliga...\n");
            scanf("%d",&opcB);

            switch (opcB)
            {
                case 1:
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
                                productos[i].precio = productos[i+1].precio;
                            }
                            num_productos--;
                            printf("\nel producto a sido eliminado...\n");

                            printf("\tpresione cualquier tecla para continuar.....\n");
                            getch();

                        }else{
                            printf("\nEl puesto que usted indico esta fuera de rango...\n");

                            printf("\tpresione cualquier tecla para continuar.....\n");
                            getch();
                        }
                        
                    }else{
                        printf("\nno hay productos que eliminar...\n");
                        
                        printf("\tpresione cualquier tecla para continuar.....\n");
                        getch();
                    }

                    break;
                case 2:
                    //Eliminamos el contenido del carrito

                    if (cont_carrito > 0)
                    {
                        int indice_d;

                        mostrar_carrito(Carrito,cont_carrito);
                        printf("\nCual desea eliminar?: ");
                        scanf("%d",&indice_d);
                        indice_d--;

                        //regresamos la cantidad al stok

                        for (int i = 0; i < num_productos; i++)
                        {
                            if (strcmp( productos[i].nombre_p , Carrito[indice_d].nombre_p ) == 0) // esta funcion nos permite comparar entre dos strings para hallar coincidencias
                            {
                                productos[i].cantidad += Carrito[indice_d].cantidad;
                            }
                                
                        }


                        if (indice_d >=0 && indice_d < cont_carrito){
                            
                            for (int i = indice_d; i < cont_carrito - 1; i++)
                            {
                                strcpy(Carrito[i].nombre_p,Carrito[i+1].nombre_p);//esta funcion permite copiar strings
                                Carrito[i].cantidad = Carrito[i+1].cantidad;
                                Carrito[i].precio = Carrito[i+1].precio;
                            }
                            cont_carrito--;
                            printf("\nel producto a sido eliminado del carrito...\n");

                            printf("\tpresione cualquier tecla para continuar.....\n");
                            getch();
                        }else{
                            printf("\nEl puesto que usted indico esta fuera de rango...\n");
                            
                            printf("\tpresione cualquier tecla para continuar.....\n");
                            getch();
                        }
                        
                    }else{
                        printf("\nno hay productos que eliminar...\n");
                        
                        printf("\tpresione cualquier tecla para continuar.....\n");
                        getch();
                    }

                    
                    break;
                case 3:
                    break;
                default:
                    break;
            }
                


            
        case 6:
            //CALCULAR EL TOTAL A PAGAR
            if (cont_carrito <= 0)
            {
                printf("\nNo tienes productos en el carrito puedes irte de aqui\n");
                break;
            }
            printf("\nel total a pagar es de: $%2.f\n",calc_total(Carrito,cont_carrito));
            
            printf("\tpresione cualquier tecla para continuar.....\n");
            getch();

            break;
        case 7:
            // Grabar archivo
            
            archivo = fopen("stok.txt","w");

            if (archivo == NULL)
            {
                fprintf(stderr,"No se pudo abrir el archivo");
            }

            //empezamos a imprimir todos los datos de los productos en el archivo
            
            for (int i = 0; i < num_productos; i++)
            {
                fprintf(archivo,"%s %d %f\n",productos[i].nombre_p,productos[i].cantidad,productos[i].precio);
                
            }

            printf("\ndatos guardados con exito....\n");
            
            printf("\tpresione cualquier tecla para continuar.....\n");
            getch();

            fclose(archivo);
            
            
            break;
        case 8:
            // Abrir archivo
            archivo = fopen("stok.txt", "r");

            if (archivo == NULL)
            {
                fprintf(stderr, "No se pudo abrir el archivo");
            }
            else
            {
                int cont_lineas = 0;
                //vamos almacenando los valores del txt a la lista de productos
                while (fscanf(archivo, "%s %d %f\n", productos[cont_lineas].nombre_p, &productos[cont_lineas].cantidad, &productos[cont_lineas].precio) == 3)
                {
                    cont_lineas++;
                }

                // No necesitas otro bucle para leer los datos, ya lo hiciste en el bucle while

                fclose(archivo);

                // Actualiza el número de productos después de leer del archivo
                num_productos = cont_lineas;
            }
            printf("\nDatos extraidos con exito\n");
            printf("\tpresione cualquier tecla para continuar.....\n");
            getch();

            break;
        case 9:
            //Actualizar archivo
            archivo = fopen("stok.txt","w");

            if (archivo == NULL)
            {
                fprintf(stderr,"No se pudo abrir el archivo");
            }

            //empezamos a imprimir todos los datos de los productos en el archivo
            
            for (int i = 0; i < num_productos; i++)
            {
                fprintf(archivo,"%s %d %f\n",productos[i].nombre_p,productos[i].cantidad,productos[i].precio);
                
            }

            printf("\ndatos actualizados con exito....\n");
            
            printf("\tpresione cualquier tecla para continuar.....\n");
            getch();

            fclose(archivo);
            break;
        case 10:
            
            if (cont_carrito>0)
            {
                mostrar_carrito(Carrito,cont_carrito);
            }else{
                printf("\nNo hay productos en el carrito\n");
            }
            
            
            break;
        case 11:
            printf("Esta es la lista de los productos...\n");
            for (int i = 0; i < num_productos; i++)
            {
                
                printf("\n-----------\n");
                printf("%d) %s --> ",i+1,productos[i].nombre_p);
                printf("%d",productos[i].cantidad);
                printf(" == $%2.f", productos[i].precio);
                                
            }
            printf("\n-----------\n");
            
            printf("\tpresione cualquier tecla para continuar.....\n");
            getch();

            break;
        case 12:
            creditos();
            printf("\nsaliendo.... (presione cualquier tecla para salir)");
            break;
        default:
            printf("Opcion Erronea intente de nuevo...\n");
            break;
        }

    } while (opc != 12);

    getch();
    return 0;
}


