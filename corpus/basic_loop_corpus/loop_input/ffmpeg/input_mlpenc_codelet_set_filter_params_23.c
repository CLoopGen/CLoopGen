#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t coefs[32][32];
int32_t *fcoeff;
unsigned int i;
int order;

void init_vars() {
    order = 32;
    fcoeff = (int32_t*)malloc(order * sizeof(int32_t));
    for (int j = 0; j < 32; ++j) {
        for (int k = 0; k < 32; ++k) {
            coefs[j][k] = rand() % 1000;
        }
    }
}