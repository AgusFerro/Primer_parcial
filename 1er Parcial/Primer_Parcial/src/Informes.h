
#ifndef INFORMES_H_
#define INFORMES_H_

int imprimir_clientes(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray);
//imprime los clientes y la cantidad de pedidos pendientes de cada uno

int imprimir_pendientes(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray);
//imprime unicamente los pedidos pendientes con cuil de cliente,direccion de cliente, y cantidad de kilos a recolectar

int imprimir_procesados(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray);
//imprime unicamente los pedidos completados con cuil de cliente,direccion de cliente, y cantidad de kilos de cada tipo de plastico reciclado

int informe_cliente_pedientes(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray);
//imprime el cliente con mas pedidos pendientes

int informe_cliente_procesados(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray);
//imprime el cliente con mas pedidos procesados

int informe_cliente_pedidos(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray);
//imprime el cliente con mas pedidos

int informe_cliente_maxReciclado(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray);
//imprime el cliente que reciclo mas kilos

int informe_cliente_minReciclado(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray);
//imprime el cliente que reciclo menos kilos

int informe_cliente_masDeMil(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray);
//imprime la cantidad de clientes que reciclaron mas de mil kilos

int informe_cliente_menosDeCien(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray);
//imprime la cantidad de clientes que reciclaron menos de 100 kilos

int informe_procesados_porcentaje(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray);
//imprime los pedidos procesados con el porcentaje de basura reciclado

int localidad_pendientes(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray);
//imprime la cantidad de pedidos pendientes que tiene una localidad

int informe_cliente_pp_promedio(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray);
//imprime la cantidad de kilos de PP reciclado por cliente

int informe_tipo_plastico(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray);
//imprime la cantidad de plastico reciclado de un tipo y por cliente

#endif
