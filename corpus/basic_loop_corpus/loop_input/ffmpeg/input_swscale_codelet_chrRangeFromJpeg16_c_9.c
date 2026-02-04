#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
int i;
int32_t *dstU;
int32_t *dstV;

void init_vars() {
    width = 1 << 20;  // Approximately 4 million elements, ~16MB per array

    dstU = (int32_t *)malloc(width * sizeof(int32_t));
    dstV = (int32_t *)malloc(width * sizeof(int32_t));

    for (i = 0; i < width; i++) {
        dstU[i] = i % 1000;
        dstV[i] = i % 1000;
    }
}

void loop();  // Forward declaration to avoid implicit declaration error