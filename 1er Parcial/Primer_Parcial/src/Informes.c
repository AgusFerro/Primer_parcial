#include "Pedido.h"
#include "Cliente.h"

#include <string.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "Inputs.h"
#include "Informes.h"

int imprimir_clientes(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray)
{
    int retorno=-1;
    int pedidosPend = 0;
    int posicion,i;

    if(clieArray!=NULL && sizeClieArray>0)
    {
    	for(i=0;i<sizeClieArray;i++)
    	    {
    			if(clieArray[i].isEmpty==1)
    	          {
    	            continue;
    	          }
                else if(clieArray[i].isEmpty==0 && clieArray[i].idCliente > 0)
    	            {
    	            	printf( "\n ID: %d"
    	            	        "\n Cuil: %s"
    	            			"\n Nombre: %s"
    	            			"\n Localidad: %s"
    	                		"\n Calle: %s"
    	   	            		"\n Altura: %d",
								clieArray[i].idCliente,
								clieArray[i].cuitCliente,
								clieArray[i].nombreCliente,
								clieArray[i].localidadCliente,
								clieArray[i].direccion.calle,
    	            		    clieArray[i].direccion.altura);
    	            	for(posicion=0;posicion<sizePediArray;posicion++)
    	            	{
    	            		if(clieArray[i].idCliente == pediArray[posicion].idCliente
    	            			&& pediArray[posicion].isEmpty==0
								&& pediArray[posicion].estado==0)
    	            		{
    	            			pedidosPend++;
    	            		}
    	            	}
    	            printf("\nCantidad de pendientes: %d",pedidosPend);
    	            pedidosPend=0;

    	            }

    	        }
    	        retorno=0;
    }
    return retorno;
}

int imprimir_pendientes(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray)
{
    int retorno=-1;
    int posicion,i;

    if(pediArray!=NULL && sizePediArray>0)
    {
    	for(i=0;i<sizePediArray;i++)
    	    {
    			if(pediArray[i].isEmpty==0 && pediArray[i].estado == 0)
    	          {
    				for(posicion=0;posicion<sizeClieArray;posicion++)
    				{
    					if(pediArray[i].idCliente == clieArray[posicion].idCliente
    							&& clieArray[posicion].isEmpty == 0
								&& clieArray[posicion].idCliente > 0)
    					{
    						printf( "\n ID: %d"
    						    	"\n Cuit: %s"
    						    	"\n Calle: %s"
    						    	"\n Altura: %d"
    								"\n Kilos a recolectar: %d"
									"\n Estado: Pendiente",
									pediArray[i].idPedido,
    								clieArray[posicion].cuitCliente,
 									clieArray[posicion].direccion.calle,
    		               		    clieArray[posicion].direccion.altura,
									pediArray[i].cantKilos);

    					}
    				}
    	          }


    	    }
    	        retorno=0;
    }
    return retorno;
}

int imprimir_procesados(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray)
{
    int retorno=-1;
    int posicion,i;

    if(pediArray!=NULL && sizePediArray>0)
    {
    	for(i=0;i<sizePediArray;i++)
    	    {
    			if(pediArray[i].isEmpty==0 && pediArray[i].estado == 1)
    	          {
    				for(posicion=0;posicion<sizeClieArray;posicion++)
    				{
    					if(pediArray[i].idCliente == clieArray[posicion].idCliente
    							&& clieArray[posicion].isEmpty == 0
								&& clieArray[posicion].idCliente > 0)
    					{
    						printf( "\n ID: %d"
    						    	"\n Cuit: %s"
    						    	"\n Calle: %s"
    						    	"\n Altura: %d"
    								"\n Kilos de HDPE: %d"
    								"\n Kilos de LDPE: %d"
    								"\n Kilos de PP: %d"
									"\n Estado: Completado",
									pediArray[i].idPedido,
    								clieArray[posicion].cuitCliente,
 									clieArray[posicion].direccion.calle,
    		               		    clieArray[posicion].direccion.altura,
									pediArray[i].kilosHDPE,
									pediArray[i].kilosLDPE,
									pediArray[i].kilosPP);

    					}
    				}
    	          }


    	    }
    	        retorno=0;
    }
    return retorno;
}
