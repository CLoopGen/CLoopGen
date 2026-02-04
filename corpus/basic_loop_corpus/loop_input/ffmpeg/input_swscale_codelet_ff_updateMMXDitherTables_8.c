#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int vChrFilterSize;
int16_t **tmpU;
int i;

void init_vars() {
    vChrFilterSize = 131072; // Approximately 1MB of int16_t pointers (131072 * 8 bytes = ~1MB on 64-bit)
    i = 1;

    tmpU = (int16_t**)calloc(vChrFilterSize, sizeof(int16_t*));
    if (!tmpU) exit(1);

    for (int idx = 0; idx < vChrFilterSize; idx++) {
        tmpU[idx] = (int16_t*)malloc(16 * sizeof(int16_t)); // Small arrays of 16 elements
        if (!tmpU[idx]) exit(1);
        for (int j = 0; j < 16; j++) {
            tmpU[idx][j] = (int16_t)(idx + j);
        }
    }
}