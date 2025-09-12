#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int factTail(int n, int a);

int main(int argc, char *argv[]) {
    int n,i;
    char respuesta;
    
  
    if (argc < 2) {
        printf("No se proporciono un numero como argumento.\n");
        printf("Ingrese un numero para calcular su factorial: ");
        scanf("%d", &n);
        getchar(); 
    } else {
    
        for (i = 0; argv[1][i] != '\0'; i++) {
            if (!isdigit(argv[1][i])) {
                printf("Error: El argumento debe ser un número entero no negativo.\n");
                return 1;
            }
        }
        n = atoi(argv[1]);
    }
    
    do {
        printf(".............Factorial Iterativo..............\n");
        
        if (n < 0) {
            printf("Error: El factorial no está definido para números negativos.\n");
        } else {
            printf("Factorial de %d es: %d\n", n, factTail(n, 1));
        }
        
        printf("¿Deseas calcular otro factorial? (s/n): ");
        scanf(" %c", &respuesta);
        
        if (respuesta == 'S' || respuesta == 's') {
            printf("Ingrese un numero para calcular el factorial: ");
            scanf("%d", &n);
        }
    } while (respuesta == 'S' || respuesta == 's');
    
    return 0;
}

int factTail(int n, int a) {
    if (n < 0) {
        return 0;
    } else if (n == 0) {
        return 1;
    } else if (n == 1) {
        return a;
    } else {
        return factTail(n - 1, n * a);
    }
}
