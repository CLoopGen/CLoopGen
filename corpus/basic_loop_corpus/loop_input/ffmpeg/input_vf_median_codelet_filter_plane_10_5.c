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
    width = 1 << 17;  // Approximately 131072 elements

    radiusV = 5;

    int shift = (10 + 1) / 2;  // shift = 5
    int coarse_size = width * (1 << shift);  // width * 32
    int fine_size = (1 << shift) * coarse_size + (1 << shift);  // 32 * coarse_size + 32

    ccoarse = (uint16_t*)calloc(coarse_size, sizeof(uint16_t));
    cfine = (uint16_t*)calloc(fine_size, sizeof(uint16_t));
    srcp = (uint16_t*)malloc(width * sizeof(uint16_t));

    for (int i = 0; i < width; i++) {
        srcp[i] = rand() & 0x3FF;  // 10-bit values (0-1023)
    }
}