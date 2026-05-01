// buggy_mem_fixed.c -- NO ejecutar sin Valgrind
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /* ERROR 1: La correccion consiste en el ciclo for iterar hasta 4 */
    int *p = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) /* <= en vez de < */
    p[i] = i;

    /* ERROR 2: La correccion consiste en invocar la funcion free(q) despues de la impresion por pantalla */
    char *q = malloc(100);
    strcpy(q, "hola mundo");
    printf("%s\n", q);
    free(q);


    /* ERROR 3: La correccion consiste en colocar free(p) despues de la ultima invocacion de p */
    printf("p[0] = %d\n", p[0]); /* acceso ilegal */
    free(p);
    
    return 0;
}
