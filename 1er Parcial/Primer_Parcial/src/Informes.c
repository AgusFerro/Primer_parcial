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

int informe_cliente_pedientes(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray)
{
    int retorno=-1;
    int pedidosPend = 0,pedidosPendMax = 0;
    int posicion,i,posPendMax;
    int flag = 0;

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
    	            	for(posicion=0;posicion<sizePediArray;posicion++)
    	            	{
    	            		if(clieArray[i].idCliente == pediArray[posicion].idCliente
    	            			&& pediArray[posicion].isEmpty==0
								&& pediArray[posicion].estado==0)
    	            		{
    	            			pedidosPend++;
    	            		}
    	            	}

    	            	if(flag==0)
    	            	{
    	            		pedidosPendMax = pedidosPend;
    	            		posPendMax = i;
    	            		flag++;
    	            	}

    	            	if(pedidosPend>pedidosPendMax)
    	            	{
    	            		pedidosPendMax = pedidosPend;
    	            		posPendMax = i;
    	            	}

    	            	pedidosPend=0;

    	            }

    	        }

    	printf("\nCliente con mas pedidos pendientes: %s"
    			"\nCantide de pedidos pendientes: %d",
    			clieArray[posPendMax].nombreCliente,
				pedidosPendMax);
        retorno=0;
    }
    return retorno;
}

int informe_cliente_procesados(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray)
{
    int retorno=-1;
    int pedidosProc = 0,pedidosProcMax = 0;
    int posicion,i,posProcMax;
    int flag = 0;

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
    	            	for(posicion=0;posicion<sizePediArray;posicion++)
    	            	{
    	            		if(clieArray[i].idCliente == pediArray[posicion].idCliente
    	            			&& pediArray[posicion].isEmpty==0
								&& pediArray[posicion].estado==1)
    	            		{
    	            			pedidosProc++;
    	            		}
    	            	}

    	            	if(flag==0)
    	            	{
    	            		pedidosProcMax = pedidosProc;
    	            		posProcMax = i;
    	            		flag++;
    	            	}

    	            	if(pedidosProc>pedidosProcMax)
    	            	{
    	            		pedidosProcMax = pedidosProc;
    	            		posProcMax = i;
    	            	}

    	            	pedidosProc=0;

    	            }

    	        }

    	printf("\nCliente con mas pedidos procesados: %s"
    			"\nCantide de pedidos procesados: %d",
    			clieArray[posProcMax].nombreCliente,
				pedidosProcMax);
        retorno=0;
    }
    return retorno;
}

int informe_cliente_pedidos(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray)
{
    int retorno=-1;
    int pedidos = 0,pedidosMax = 0;
    int posicion,i,posMax;
    int flag = 0;

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
    	            	for(posicion=0;posicion<sizePediArray;posicion++)
    	            	{
    	            		if(clieArray[i].idCliente == pediArray[posicion].idCliente
    	            			&& pediArray[posicion].isEmpty==0
								&& (pediArray[posicion].estado==1 || pediArray[posicion].estado==0))
    	            		{
    	            			pedidos++;
    	            		}
    	            	}

    	            	if(flag==0)
    	            	{
    	            		pedidosMax = pedidos;
    	            		posMax = i;
    	            		flag++;
    	            	}

    	            	if(pedidos>pedidosMax)
    	            	{
    	            		pedidosMax = pedidos;
    	            		posMax = i;
    	            	}

    	            	pedidos=0;

    	            }

    	        }

    	printf("\nCliente con mas pedidos: %s"
    			"\nCantide de pedidos: %d",
    			clieArray[posMax].nombreCliente,
				pedidosMax);
        retorno=0;
    }
    return retorno;
}

int informe_cliente_maxReciclado(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray)
{
    int retorno=-1;
    int kilosRecic = 0,kilosRecicMax = 0;
    int posicion,i,posMax;
    int flag = 0;

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
    	            	for(posicion=0;posicion<sizePediArray;posicion++)
    	            	{
    	            		if(clieArray[i].idCliente == pediArray[posicion].idCliente
    	            			&& pediArray[posicion].isEmpty==0
								&& pediArray[posicion].estado==1)
    	            		{
    	            			kilosRecic=0;
    	            			kilosRecic = kilosRecic + pediArray[posicion].kilosHDPE
    	            									+ pediArray[posicion].kilosLDPE
														+ pediArray[posicion].kilosPP;
    	            		}
    	            	}

    	            	if(flag==0)
    	            	{
    	            		kilosRecicMax = kilosRecic;
    	            		posMax = i;
    	            		flag++;
    	            	}

    	            	if(kilosRecic>kilosRecicMax)
    	            	{
    	            		kilosRecicMax = kilosRecic;
    	            		posMax = i;
    	            	}

    	            }

    	        }

    	printf("\nCliente que mas reciclo: %s"
    			"\nCantidad de kilos: %d",
    			clieArray[posMax].nombreCliente,
				kilosRecicMax);
        retorno=0;
    }
    return retorno;
}

int informe_cliente_minReciclado(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray)
{
    int retorno=-1;
    int kilosRecic = 0,kilosRecicMin = 0;
    int posicion,i,posMin;
    int flag = 0;

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
    	            	for(posicion=0;posicion<sizePediArray;posicion++)
    	            	{
    	            		if(clieArray[i].idCliente == pediArray[posicion].idCliente
    	            			&& pediArray[posicion].isEmpty==0
								&& pediArray[posicion].estado==1)
    	            		{
    	            			kilosRecic = 0;
    	            			kilosRecic = kilosRecic + pediArray[posicion].kilosHDPE
    	            									+ pediArray[posicion].kilosLDPE
														+ pediArray[posicion].kilosPP;
    	            		}
    	            	}

    	            	if(flag==0)
    	            	{
    	            		kilosRecicMin = kilosRecic;
    	            		posMin = i;
    	            		flag++;
    	            	}

    	            	if(kilosRecic<kilosRecicMin)
    	            	{
    	            		kilosRecicMin = kilosRecic;
    	            		posMin = i;
    	            	}


    	            }

    	        }

    	printf("\nCliente que menos reciclo: %s"
    			"\nCantidad de kilos: %d",
    			clieArray[posMin].nombreCliente,
				kilosRecicMin);
        retorno=0;
    }
    return retorno;
}

int informe_cliente_masDeMil(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray)
{
    int retorno=-1;
    int kilosRecic = 0,cantCliente = 0;
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
    	            	for(posicion=0;posicion<sizePediArray;posicion++)
    	            	{
    	            		if(clieArray[i].idCliente == pediArray[posicion].idCliente
    	            			&& pediArray[posicion].isEmpty==0
								&& pediArray[posicion].estado==1)
    	            		{
    	            			kilosRecic=0;
    	            			kilosRecic = kilosRecic + pediArray[posicion].kilosHDPE
    	            									+ pediArray[posicion].kilosLDPE
														+ pediArray[posicion].kilosPP;
    	            		}
    	            	}

    	            	if(kilosRecic>1000)
    	            	{
    	            		cantCliente++;
    	            	}

    	            }

    	        }

    	printf("\nCantidad de clientes que reciclaron mas de 1000: %d",cantCliente);
        retorno=0;
    }
    return retorno;
}

int informe_cliente_menosDeCien(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray)
{
    int retorno=-1;
    int kilosRecic=0,cantCliente = 0;
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
    	            	for(posicion=0;posicion<sizePediArray;posicion++)
    	            	{
    	            		if(clieArray[i].idCliente == pediArray[posicion].idCliente
    	            			&& pediArray[posicion].isEmpty==0
								&& pediArray[posicion].estado==1)
    	            		{
    	            			kilosRecic = 0;
    	            			kilosRecic = kilosRecic + pediArray[posicion].kilosHDPE
    	            									+ pediArray[posicion].kilosLDPE
														+ pediArray[posicion].kilosPP;
    	            		}
    	            	}

    	            	if(kilosRecic<100 && pediArray[posicion].idCliente>0)
    	            	{
    	            		cantCliente++;
    	            		kilosRecic=100;
    	            	}

    	            }

    	        }

    	printf("\nCantidad de clientes que reciclaron menos de 100: %d",cantCliente);
        retorno=0;
    }
    return retorno;
}

int informe_procesados_porcentaje(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray)
{
    int retorno=-1;
    int posicion,i;
    float porcentaje,acumulador;

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
    						    	"\n Cuit: %s",
									pediArray[i].idPedido,
									clieArray[posicion].cuitCliente);
    						acumulador = 0;
    						porcentaje = 0;

							acumulador = acumulador +
										pediArray[i].kilosHDPE +
										pediArray[i].kilosLDPE +
										pediArray[i].kilosPP;
							porcentaje = acumulador / pediArray[i].cantKilos;
							porcentaje = porcentaje * 100;
							printf("Porcentaje de plastico reciclado: 0/0 %f",porcentaje);


    					}
    				}
    	          }


    	    }
    	        retorno=0;
    }
    return retorno;
}

int localidad_pendientes(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray)
{
    int retorno=-1;
    int posicion;
    int cantPedidos = 0;
    char localidad[TEXT_SIZE];
    if(clieArray!=NULL && sizeClieArray>0)
    {
    	getString("\nIngrese localidad: ","\nError",1,TEXT_SIZE,2,localidad);
    	for(int i=0;i<sizeClieArray;i++)
    	{
    	    if(clieArray[i].isEmpty==0 && strcmp(clieArray[i].localidadCliente,localidad)==0)
    	    {
    	    	for(posicion=0;posicion<sizePediArray;posicion++)
    	    	{
    	    		if(clieArray[i].idCliente == pediArray[posicion].idCliente
    	    				&& pediArray[posicion].isEmpty == 0
							&& pediArray[posicion].estado == 0)
    	    		{
    	    			cantPedidos++;
    	    		}
    	    	}

    	    }
    	}
    	printf("\nLocalidad: %s"
    			"\nPedidos pendientes: %d",
  				localidad,
  				cantPedidos);
      	retorno=0;
    }
    return retorno;
}

int informe_cliente_pp_promedio(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray)
{
    int retorno=-1;
    int kilosRecic = 0, cantClientes = 0,promedio = 0;
    int posicion,i;
    int idAnterior = 0;

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
    	            	for(posicion=0;posicion<sizePediArray;posicion++)
    	            	{
    	            		if(clieArray[i].idCliente == pediArray[posicion].idCliente
    	            			&& pediArray[posicion].isEmpty==0
								&& pediArray[posicion].estado==1)
    	            		{
    	            			if(idAnterior!=pediArray[posicion].idCliente)
    	            			{
    	            				idAnterior = pediArray[posicion].idCliente;
    	            				cantClientes++;
    	            			}
    	            			kilosRecic = kilosRecic + pediArray[posicion].kilosPP;
    	            		}

    	            	}

    	            	promedio = kilosRecic/cantClientes;

    	            }

    	        }

    	printf("\nPromedio de kilos de PP por cliente: %d",
    			promedio);
        retorno=0;
    }
    return retorno;
}

int informe_tipo_plastico(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray)
{
    int retorno=-1;
    int kilosRecic = 0;
    int i,h,l,p;
    char cuit[14];
    char opcion;

    if(clieArray!=NULL && sizeClieArray>0)
    {
    	utn_getCUIT("\nIngrese cuit: ","\nError",2,cuit);
    	for(i=0;i<sizeClieArray;i++)
    	{
    	    if(clieArray[i].isEmpty==0 && strcmp(clieArray[i].cuitCliente,cuit)==0)
    	    {
    	    	utn_getChar("\nIngrese tipo: _HDPE(A) _LDPE(B) _PP(C)","\nError",'A','C',2,&opcion);
    	    	switch(opcion)
    	    	{
    	    	case 'A':
    	    		for(h=0;h<sizePediArray;h++)
    	    		{
       	    			if(clieArray[i].idCliente == pediArray[h].idCliente
        					&& pediArray[h].isEmpty == 0
    						&& pediArray[h].estado == 1)
    	    		    {
       	    				kilosRecic = kilosRecic + pediArray[h].kilosHDPE;
    	    		    }
    	    		}
    	    		printf("\nKilos reciclados de HDPE: %d",kilosRecic);
    	    		break;
    	    	case 'B':
    	    		for(l=0;l<sizePediArray;l++)
    	       		{
    	      			if(clieArray[i].idCliente == pediArray[l].idCliente
    	      				&& pediArray[l].isEmpty == 0
    	    		    	&& pediArray[l].estado == 1)
    	    		    {
    	    		    	kilosRecic = kilosRecic + pediArray[l].kilosLDPE;
    	    		    }
    	       		}
    	       		printf("\nKilos reciclados de LDPE: %d",kilosRecic);
    	    	    break;
    	    	case 'C':
    	    		for(p=0;p<sizePediArray;p++)
    	      		{
    	       			if(clieArray[i].idCliente == pediArray[p].idCliente
    	   					&& pediArray[p].isEmpty == 0
    	   					&& pediArray[p].estado == 1)
    	       		    {
    	       				kilosRecic = kilosRecic + pediArray[p].kilosPP;
    	       		    }
    	       		}
    	       		printf("\nKilos reciclados de PP: %d",kilosRecic);
    	    	    break;
    	    	default:
    	    		printf("\nOpcion invalida");
    	    		break;
    	    	}
    		}
        	retorno=0;
    	}
    }
    return retorno;
}

