#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dstU;
int16_t *dstV;
int width;
int i;

void init_vars() {
    width = 131072; // Size to achieve ~0.01 sec runtime (adjustable based on system)

    dstU = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    dstV = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));

    for (i = 0; i < width; i++) {
        dstU[i] = rand() % 32767;
        dstV[i] = rand() % 32767;
    }
}