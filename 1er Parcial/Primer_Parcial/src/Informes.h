
#ifndef INFORMES_H_
#define INFORMES_H_

int imprimir_clientes(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray);
//imprime los clientes y la cantidad de pedidos pendientes de cada uno

int imprimir_pendientes(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray);
//imprime unicamente los pedidos pendientes con cuil de cliente,direccion de cliente, y cantidad de kilos a recolectar

int imprimir_procesados(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray);
//imprime unicamente los pedidos completados con cuil de cliente,direccion de cliente, y cantidad de kilos de cada tipo de plastico reciclado

#endif
