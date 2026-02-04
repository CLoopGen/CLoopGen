#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dstU;
int16_t *dstV;
int width;
int i;

void init_vars() {
    width = 131072; // Approximately 1MB of data per array (131072 * 2 bytes * 2 arrays ≈ 512KB each, total 1MB)
    
    dstU = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    dstV = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));

    for (int j = 0; j < width; j++) {
        dstU[j] = rand() % 32768;
        dstV[j] = rand() % 32768;
    }
}