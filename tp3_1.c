#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    produxto *productos;
}cliente;

int main() {
    char *tiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
    getchar();
    return 0;
}