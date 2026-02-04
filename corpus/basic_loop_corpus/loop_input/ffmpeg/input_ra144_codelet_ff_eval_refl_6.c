#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coefs;
int i;
int buffer2[10];

void init_vars() {
    coefs = (int16_t*)aligned_alloc(_Alignof(int16_t), 10 * sizeof(int16_t));
    for (int j = 0; j < 10; j++) {
        coefs[j] = (int16_t)(j * 2);
    }
}