#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int vLumFilterSize = 1000000;
int16_t **tmpY;
int i = 1;

void init_vars() {
    tmpY = (int16_t**)calloc(vLumFilterSize, sizeof(int16_t*));
    if (!tmpY) exit(1);
    for (int idx = 0; idx < vLumFilterSize; idx++) {
        tmpY[idx] = (int16_t*)malloc(2 * sizeof(int16_t));
        if (!tmpY[idx]) exit(1);
        tmpY[idx][0] = (int16_t)(idx & 0xFFFF);
        tmpY[idx][1] = (int16_t)((idx + 1) & 0xFFFF);
    }
}