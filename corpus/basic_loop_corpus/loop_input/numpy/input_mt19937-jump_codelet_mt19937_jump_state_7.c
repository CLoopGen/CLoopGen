#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned long poly_coef[624];
unsigned long *pf;
int i;

void init_vars() {
    pf = (unsigned long*)malloc(625 * sizeof(unsigned long));
    if (!pf) {
        exit(1);
    }
    for (int j = 0; j < 624; j++) {
        poly_coef[j] = (unsigned long)(j * 314159);
    }
    for (int j = 0; j < 625; j++) {
        pf[j] = 0UL;
    }
}