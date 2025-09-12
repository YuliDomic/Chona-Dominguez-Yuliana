#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int factRecursion(int n);

int main(int argc, char *argv[]) {
    int n,i;
    char respuesta;
    
   
    if (argc < 2) {
        printf("No se proporcionó un número como argumento.\n");
        printf("Ingrese un número para calcular su factorial: ");
        scanf("%d", &n);
        getchar();
    } else {
      
        for ( i = 0; argv[1][i] != '\0'; i++) {
            if (!isdigit(argv[1][i])) {
                printf("Error: El argumento debe ser un número entero no negativo.\n");
                return 1;
            }
        }
        n = atoi(argv[1]);
    }
    
    do {
        printf(".............Factorial  Recursivo..............\n");
        
        if (n < 0) {
            printf("Error: El factorial no está definido para números negativos.\n");
        } else {
            printf("Factorial de %d es: %d\n", n, factRecursion(n));
        }
        
        printf("¿Deseas calcular otro factorial? (s/n): ");
        scanf(" %c", &respuesta);
        
        if (respuesta == 'S' || respuesta == 's') {
            printf("Ingrese un número para calcular su factorial: ");
            scanf("%d", &n);
        }
    } while (respuesta == 'S' || respuesta == 's');
    
    return 0;
}

int factRecursion(int n) {
    if (n < 0) {
        return 0;
    } else if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factRecursion(n - 1);
    }
}
