
#include "Cliente.h"
#include "Pedido.h"

#include <string.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "Inputs.h"
#include "Validaciones.h"

void imprimeMenu()
{
	printf("\n1.Alta de cliente");
	printf("\n2.Modificacion de cliente");
	printf("\n3.Baja de cliente");
	printf("\n4.Crear pedido de recoleccion");
	printf("\n5.Procesar residuos");
	printf("\n6.Imprimir clientes");
	printf("\n7.Imprimir pedidos pendientes");
	printf("\n8.Imprimir pedidos procesados");
	printf("\n9.Cliente con mas pedidos pendientes");
	printf("\n10.Cliente con mas pedidos procesados");
	printf("\n11.Cliente con mas pedidos");
	printf("\n12.Cliente que mas reciclo");
	printf("\n13.Cliente que menos reciclo");
	printf("\n14.Cantidad de clientes que reciclaron mas de 1000k");
	printf("\n15.Cantidad de clientes que reciclaron menos de 100k");
	printf("\n16.Imprimir pedidos completados con porcentaje");
	printf("\n17.Cantidad de pedidos pendientes por localidad");
	printf("\n18.Cantidad de kilos de polopropileno reciclado");
	printf("\n19.Cantidad de tipos de plastico reciclado por cliente");
	printf("\n20.Salir");
	printf("\n");

}

int cliente_Inicializar(Cliente array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************

int cliente_buscarEmpty(Cliente array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}


int cliente_buscarID(Cliente array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idCliente==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int cliente_buscarCUIT(Cliente array[], int size, char* valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].cuitCliente,valorBuscado)==0)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int cliente_alta(Cliente array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(cliente_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
        	array[posicion].isEmpty=0;
        	utn_getCUIT("\nIngrese Cuil: XX-XXXXXXXX-X","\nError",2,array[posicion].cuitCliente);
        	utn_getName("\nIngrese nombre de Cliente: ","\nError",1,TEXT_SIZE,2,array[posicion].nombreCliente);
            getString("\nIngrese localidad: ","\nError",1,TEXT_SIZE,2,array[posicion].localidadCliente);
            getString("\nIngrese calle: ","\nError",1,TEXT_SIZE,2,array[posicion].direccion.calle);
            utn_getInt(&array[posicion].direccion.altura,"\nIngrese altura: ","\nError",1,5000,2);
            (*contadorID)++;
            array[posicion].idCliente = *contadorID;
            printf( "\n ID: %d"
            		"\n Cuil: %s"
            		"\n Nombre: %s"
            		"\n Localidad: %s"
            		"\n Calle: %s"
            		"\n Altura: %d",
				   array[posicion].idCliente,
				   array[posicion].cuitCliente,
				   array[posicion].nombreCliente,
				   array[posicion].localidadCliente,
				   array[posicion].direccion.calle,
				   array[posicion].direccion.altura);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************

int cliente_baja(Cliente clieArray[], int sizeClieArray,int contadorID, int* flag)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(clieArray!=NULL && sizeClieArray>0)
    {
    	cliente_listar(clieArray,sizeClieArray);
    	utn_getInt(&id,"\nID de cliente a dar de baja: ","\nError",1,contadorID,1);
        if(cliente_buscarID(clieArray,sizeClieArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
        	printf( "\n ID: %d"
        	        "\n Cuil: %s"
            		"\n Nombre: %s"
            		"\n Localidad: %s"
              		"\n Calle: %s"
            		"\n Altura: %d",
					clieArray[posicion].idCliente,
					clieArray[posicion].cuitCliente,
					clieArray[posicion].nombreCliente,
					clieArray[posicion].localidadCliente,
					clieArray[posicion].direccion.calle,
					clieArray[posicion].direccion.altura);
        	utn_getChar("\nEsta seguro que desea dar de baja? S/N","\nError",'A','S',2,&opcion);
        	switch(opcion)
        	{
        	  case 'S':
        		  clieArray[posicion].isEmpty=1;
        		  clieArray[posicion].idCliente=0;
        		  strcpy(clieArray[posicion].nombreCliente,"");
        		  strcpy(clieArray[posicion].localidadCliente,"");
        		  strcpy(clieArray[posicion].cuitCliente,"");
        		  strcpy(clieArray[posicion].direccion.calle,"");
        		  clieArray[posicion].direccion.altura=0;
        		  (*flag)--;
        		  printf("\nBaja correcta");
        	      break;
        	  case 'N':
        		  printf("\nBaja cancelada");
        	      break;
        	  default:
        		  printf("\nOpcion no valida");
        	 }

        }

        retorno=0;
    }

   	return retorno;
}


int cliente_modificar(Cliente array[], int sizeArray, int contadorID)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
    	cliente_listar(array,sizeArray);
    	utn_getInt(&id,"\nID de cliente a modificar: ","\nError",1,contadorID,2);
        if(cliente_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
            	printf( "\n ID: %d"
            	        "\n Cuil: %s"
            	        "\n Nombre: %s"
            	        "\n Localidad: %s"
            	        "\n Calle: %s"
            	        "\n Altura: %d",
            			array[posicion].idCliente,
						array[posicion].cuitCliente,
            			array[posicion].nombreCliente,
            			array[posicion].localidadCliente,
            			array[posicion].direccion.calle,
            			array[posicion].direccion.altura);
                utn_getChar("\nModificar: Direccion(A) Localidad(B) S(Salir)","\nError",'A','S',2,&opcion);
                switch(opcion)
                {
                    case 'A':
                    	getString("\nIngrese calle: ","\nError",1,TEXT_SIZE,2,array[posicion].direccion.calle);
                    	utn_getInt(&array[posicion].direccion.altura,"\nIngrese altura: ","\nError",1,5000,2);
                        break;
                    case 'B':
                    	getString("\nIngrese localidad: ","\nError",1,TEXT_SIZE,2,array[posicion].localidadCliente);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************

int cliente_listar(Cliente array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            else if(array[i].isEmpty==0 && array[i].idCliente>0)
            {
            	printf( "\n ID: %d"
            	        "\n Cuil: %s"
            			"\n Nombre: %s"
            			"\n Localidad: %s"
                		"\n Calle: %s"
   	            		"\n Altura: %d",
            			array[i].idCliente,
            		    array[i].cuitCliente,
               		    array[i].nombreCliente,
            		    array[i].localidadCliente,
            		    array[i].direccion.calle,
            		    array[i].direccion.altura);
            }
        }
        retorno=0;
    }
    return retorno;
}




