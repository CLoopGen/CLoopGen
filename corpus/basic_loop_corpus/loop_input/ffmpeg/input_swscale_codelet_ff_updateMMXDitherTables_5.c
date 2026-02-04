#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int vLumFilterSize = 131072;
int i = 1;

int16_t **tmpA;

void init_vars() {
    tmpA = (int16_t**)calloc(vLumFilterSize, sizeof(int16_t*));
    if (!tmpA) exit(1);

    for (int idx = 0; idx < vLumFilterSize; idx++) {
        tmpA[idx] = (int16_t*)malloc(16 * sizeof(int16_t));
        if (!tmpA[idx]) exit(1);
        for (int j = 0; j < 16; j++) {
            tmpA[idx][j] = (int16_t)(idx + j);
        }
    }
}