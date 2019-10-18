#include "Cliente.h"
#include "Pedido.h"

#include <string.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "Inputs.h"

int primerParcial(void);


int main(void)
{
	primerParcial();
}

int primerParcial(void)
	{
		int opcion;
		int reintentos = 3;
		int idClie = 6,idPedi = 9, flag1 = 6, flag2 = 9;

		Cliente listaCliente[CANT_CLIENTE] = {
				{1,"Telefonica","30-11223344-5","CABA","Lima",1234,0},
				{2,"DATASOFT","30-44556677-6","CABA","Corrientes",2547,0},
				{3,"NESTLE","30-88995521-9","Lanus","cucha cucha",555,0},
				{4,"TERRABUSI","30-56781423-5","Quilmes","Rocha",784,0},
				{5,"DIA","31-54581253-3","CABA","Avellaneda",750,0},
				{6,"QUILMES","30-51485759-6","Quilmes","Rocha",741,0}
		};
		Pedidos listaPedidos[CANT_PEDIDO] = {
				{1,1,1,1000,200,145,230,0},
				{2,1,1,800,210,45,30,0},
				{3,2,0,100,0,0,0,0},
				{4,2,0,300,0,0,0,0},
				{5,3,1,1500,500,150,270,0},
				{6,4,1,750,100,50,70,0},
				{7,1,0,200,0,0,0,0},
				{8,5,1,30,10,5,3,0},
				{9,6,0,456,0,0,0,0}
		};

		//cliente_Inicializar(listaCliente,CANT_CLIENTE);
		//pedidos_Inicializar(listaPedidos,CANT_PEDIDO);

		imprimeMenu();
		do
		{
			__fpurge(stdin);
			scanf("%d",&opcion);
			switch(opcion)
			{
				case 1:
					cliente_alta(listaCliente,CANT_CLIENTE,&idClie);
					flag1++;
					imprimeMenu();
					break;

				case 2:
					if(flag1<1)
					{
						printf("\nNo hay datos cargados");
						imprimeMenu();
					}
					else
					{
						cliente_modificar(listaCliente, CANT_CLIENTE,idClie);
						imprimeMenu();
					}
					break;

				case 3:
					if(flag1<1)
					{
						printf("\nNo hay datos cargados");
						imprimeMenu();
					}
					else
					{
						cliente_baja(listaCliente,CANT_CLIENTE,idClie,&flag1);
						imprimeMenu();
					}
					break;

				case 4:
					if(flag1<1)
					{
						printf("\nNo hay datos cargados");
						imprimeMenu();
					}
					else
					{
						cliente_listar(listaCliente,CANT_CLIENTE);
						pedidos_alta(listaPedidos,CANT_PEDIDO,&idPedi,idClie);
						flag2++;
						imprimeMenu();
					}
					break;

				case 5:
					if(flag1<1 || flag2<1)
					{
						printf("\nNo hay datos cargados");
						imprimeMenu();
					}
					else
					{
						pedidos_listar(listaPedidos,CANT_PEDIDO);
						pedidos_procesar(listaPedidos,CANT_PEDIDO,idPedi);
						imprimeMenu();
					}
					break;

				case 6:
					if(flag1<1 || flag2<1)
					{
						printf("\nNo hay datos cargados");
						imprimeMenu();
					}
					else
					{
						imprimir_clientes(listaCliente,listaPedidos,CANT_CLIENTE,CANT_PEDIDO);
						imprimeMenu();
					}
					break;

				case 7:
					if(flag1<1 || flag2<1)
					{
						printf("\nNo hay datos cargados");
						imprimeMenu();
					}
					else
					{
						imprimir_pendientes(listaCliente,listaPedidos,CANT_CLIENTE,CANT_PEDIDO);
						imprimeMenu();
					}
					break;

				case 8:
					if(flag1<1 || flag2<1)
					{
						printf("\nNo hay datos cargados");
						imprimeMenu();
					}
					else
					{
						imprimir_procesados(listaCliente,listaPedidos,CANT_CLIENTE,CANT_PEDIDO);
						imprimeMenu();
					}
					break;

				case 9:
					informe_cliente_pedientes(listaCliente,listaPedidos,CANT_CLIENTE,CANT_PEDIDO);
					imprimeMenu();
					break;
				case 10:
					informe_cliente_procesados(listaCliente,listaPedidos,CANT_CLIENTE,CANT_PEDIDO);
					imprimeMenu();
					break;

				case 11:
					informe_cliente_pedidos(listaCliente,listaPedidos,CANT_CLIENTE,CANT_PEDIDO);
					imprimeMenu();
					break;
				case 12:
					informe_cliente_maxReciclado(listaCliente,listaPedidos,CANT_CLIENTE,CANT_PEDIDO);
					imprimeMenu();
					break;

				case 13:
					informe_cliente_minReciclado(listaCliente,listaPedidos,CANT_CLIENTE,CANT_PEDIDO);
					imprimeMenu();
					break;

				case 14:
					informe_cliente_masDeMil(listaCliente,listaPedidos,CANT_CLIENTE,CANT_PEDIDO);
					imprimeMenu();
					break;

				case 15:
					//arreglar
					informe_cliente_menosDeCien(listaCliente,listaPedidos,CANT_CLIENTE,CANT_PEDIDO);
					imprimeMenu();
					break;

				case 16:
					informe_procesados_porcentaje(listaCliente,listaPedidos,CANT_CLIENTE,CANT_PEDIDO);
					imprimeMenu();
					break;

				case 17:
					localidad_pendientes(listaCliente,listaPedidos,CANT_CLIENTE,CANT_PEDIDO);
					imprimeMenu();
					break;
				case 18:
					//arreglar
					informe_cliente_pp_promedio(listaCliente,listaPedidos,CANT_CLIENTE,CANT_PEDIDO);
					imprimeMenu();
					break;
				case 19:
					//arreglar
					informe_tipo_plastico(listaCliente,listaPedidos,CANT_CLIENTE,CANT_PEDIDO);
					imprimeMenu();
					break;

				case 20:
					printf("Hasta pronto!");
					break;
				default:
					reintentos--;
					printf("Opcion incorrecta, cantidad de reintentos: %d \n",reintentos);
					imprimeMenu();
					break;
				}

			}while(opcion != 20 && reintentos > 1);
			if(reintentos <= 1)
			{
				printf("Cantidad de reintentos agotada\n");
			}
				return 0;
	}
