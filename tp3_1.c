#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct producto {
    int productoID;
    int cantidad;
    char *tipoProducto;
    float precioUnitario;
}producto;

typedef struct cliente {
    int clienteID;
    char *nombreCliente;
    int cantidadProductosAPedir;
    producto *productos;
}cliente;

cliente cargarClientes(int cant, cliente *Cliente) {
    srand(time(NULL));
    char *tiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
    for (int i = 0; i < cant; i++) {
        printf("--- Cargando datos del cliente N°%d\n", cant+1);
        printf("- Ingrese el nobmre del cliente -\n");
        gets((Cliente + i)->nombreCliente);
        (Cliente + i)->nombreCliente = (char *) malloc(strlen((Cliente + i)->nombreCliente) * sizeof(char));
        (Cliente + i)->clienteID = rand() % (1000 - 5 + 1) + 5; // Entre 1000 y 5
        (Cliente + i)->cantidadProductosAPedir = rand() % (100 - 10 + 1) + 5;
        (Cliente + i)->productos = (producto *) malloc(cant*sizeof(producto));
        for (int j = 0; j < cant; j++) {
            (Cliente + i)->productos->productoID = rand() % (500 - 0 + 1) + 0;
            (Cliente + i)->productos->cantidad = rand() % (40 - 5 + 1) + 5;
            (Cliente + i)->productos->tipoProducto = (tiposProductos + rand() % (5 - 0 + 1) + 0);
            (Cliente + i)->productos->precioUnitario = (float)20 + rand() % (100 - 10 + 1) + 10;
        }

    }
}

int main() {
    int cantClientes;
    printf("Ingrese la cantidad de clientes");
    scanf("%d", &cantClientes);
    cliente *Clientes = (cliente*) malloc(cantClientes*sizeof(cliente));
    cargarClientes(cantClientes, Clientes);
    getchar();
    return 0;
}