#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
uint16_t *ccoarse;
uint16_t *cfine;
int radiusV;
uint16_t *srcp;

void init_vars() {
    width = 32768;
    radiusV = 5;

    srcp = (uint16_t*)aligned_alloc(64, width * sizeof(uint16_t));
    ccoarse = (uint16_t*)aligned_alloc(64, width * (1 << ((12 + 1) / 2)) * sizeof(uint16_t));
    cfine = (uint16_t*)aligned_alloc(64, width * (1 << ((12 + 1) / 2)) * (1 << ((12 + 1) / 2)) * sizeof(uint16_t));

    for (int i = 0; i < width; i++) {
        srcp[i] = (uint16_t)(i * 31 % 4096);
    }

    for (int i = 0; i < width * (1 << ((12 + 1) / 2)); i++) {
        ccoarse[i] = 0;
    }

    for (int i = 0; i < width * (1 << ((12 + 1) / 2)) * (1 << ((12 + 1) / 2)); i++) {
        cfine[i] = 0;
    }
}