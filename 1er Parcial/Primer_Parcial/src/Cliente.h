
#ifndef CLIENTE_H_
#define CLIENTE_H_
#define TEXT_SIZE 20
#define CANT_CLIENTE 100

typedef struct
{
    char calle[TEXT_SIZE];
    int altura;

}Direccion;

typedef struct
{
    int idCliente;
    int isEmpty;
    char nombreCliente[TEXT_SIZE];
    char localidadCliente[TEXT_SIZE];
    char cuitCliente[14];
    Direccion direccion;

}Cliente;

void imprimeMenu();
void imprimeMenuModif();

int cliente_Inicializar(Cliente array[], int size);

int cliente_buscarEmpty(Cliente array[], int size, int* posicion);

int cliente_buscarID(Cliente array[], int size, int valorBuscado, int* posicion);

int cliente_alta(Cliente array[], int size, int* contadorID);

int cliente_baja(Cliente clieArray[], int sizeClieArray,int contadorID, int* flag);

int cliente_modificar(Cliente array[], int sizeArray,int contadorID);

int cliente_listar(Cliente array[], int size);


#endif // CLIENTE_H_INCLUDED
