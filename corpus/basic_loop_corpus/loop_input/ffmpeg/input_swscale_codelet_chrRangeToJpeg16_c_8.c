#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
int i;
int32_t *dstU;
int32_t *dstV;

void init_vars() {
    width = 65536;  // Size to achieve ~0.01 sec runtime on modern CPU

    dstU = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    dstV = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));

    for (int j = 0; j < width; j++) {
        dstU[j] = (j * 7489) % 65536;  // Arbitrary initialization within plausible range
        dstV[j] = (j * 9283) % 65536;
    }
}