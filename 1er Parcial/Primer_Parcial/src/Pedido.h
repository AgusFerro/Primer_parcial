
#ifndef PEDIDO_H_
#define PEDIDO_H_

#define TEXT_SIZE 20
#define CANT_PEDIDO 1000

#include "Cliente.h"

typedef struct
{
    int idPedido;
    int isEmpty;
    int idCliente;
    float cantKilos;
    int estado; //0-pendiente/1-completado
    int kilosHDPE;
    int kilosLDPE;
    int kilosPP;

}Pedidos;

int pedidos_Inicializar(Pedidos array[], int size);

int pedidos_buscarEmpty(Pedidos array[], int size, int* posicion);

int pedidos_buscarID(Pedidos array[], int size, int valorBuscado, int* posicion);

int pedidos_alta(Pedidos array[], int size, int* contadorID, int contadorCliente);

int pedidos_procesar(Pedidos array[], int sizeArray, int contadorID);

int pedidos_listar(Pedidos array[], int size);


#endif /* PEDIDO_H_ */
