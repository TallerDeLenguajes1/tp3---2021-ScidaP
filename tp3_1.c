#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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
        printf("--- Cargando datos del cliente N %d ---\n", i+1);
        printf("- Ingrese el nombre del cliente -\n");
        (Cliente + i)->nombreCliente = (char*) malloc(sizeof(char)*100);
        fflush(stdin);
        gets((Cliente + i)->nombreCliente);
        fflush(stdin);
        (Cliente + i)->nombreCliente = (char *) malloc(strlen((Cliente + i)->nombreCliente) * sizeof(char));
        (Cliente + i)->clienteID = rand() % (1000 - 5 + 1) + 5; // Entre 1000 y 5
        (Cliente + i)->cantidadProductosAPedir = rand() % (100 - 10 + 1) + 5;
        (Cliente + i)->productos = (producto *) malloc(cant*sizeof(producto));
        for (int j = 0; j < (Cliente + i)->cantidadProductosAPedir; j++) {
            (Cliente + i)->productos->productoID = rand() % (500 - 0 + 1) + 0;
            (Cliente + i)->productos->cantidad = rand() % (40 - 5 + 1) + 5;
            (Cliente + i)->productos->tipoProducto = (char*) malloc(sizeof(char)*20);
            (Cliente + i)->productos->tipoProducto = (tiposProductos + rand() % (5 - 0 + 1) + 0);
            (Cliente + i)->productos->precioUnitario = (float)20 + rand() % (100 - 10 + 1) + 10;
        }

    }
}

void mostrarClientes(int cant, cliente *Cliente) {
    for(int i = 0; i < cant; i++) {
        printf("---Mostrando datos del cliente N %d\n---", cant+1);
        printf("Nombre: %s\n", (Cliente + i)->nombreCliente);
        printf("ID: %d\n", (Cliente + i)->clienteID);
        printf("Cantidad de productos a pedir: %s\n", (Cliente + i)->cantidadProductosAPedir);
        printf("Nombre: %s\n", (Cliente + i)->productos);
        for (int j = 0; j < (Cliente + i)->cantidadProductosAPedir; j++) {
            printf("- Mostrando producto N%d\n -", (Cliente + i)->productos->productoID);
            printf("Cantidad del producto: %d\n", (Cliente + i)->productos->cantidad);
            printf("Tipo de producto: $s\n", (Cliente + i)->productos->tipoProducto);
            printf("Precio unitario: %d\n", (Cliente + i)->productos->precioUnitario);
            puts("---------------------");
        }
    }
}

int main() {
    int cantClientes;
    printf("Ingrese la cantidad de clientes\n");
    scanf("%d", &cantClientes);
    cliente *Clientes = (cliente*) malloc(cantClientes*sizeof(cliente));
    cargarClientes(cantClientes, Clientes);
    int elegir;
    printf("Desea ver los clientes cargados ? Use S/N\n");
    scanf("%c", &elegir);
    if (elegir == 'S') {
        mostrarClientes(cantClientes, Clientes);
    }
    getchar();
    return 0;
}