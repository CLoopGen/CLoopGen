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

    int shift = (14 + 1) / 2; // shift = 7
    int coarse_size_per_dim = width;
    int fine_size_per_dim = (1 << shift);
    int coarse_total = coarse_size_per_dim * fine_size_per_dim;
    int fine_total = coarse_total * fine_size_per_dim;

    srcp = (uint16_t*)calloc(width, sizeof(uint16_t));
    ccoarse = (uint16_t*)calloc(coarse_total, sizeof(uint16_t));
    cfine = (uint16_t*)calloc(fine_total, sizeof(uint16_t));

    for (int i = 0; i < width; i++) {
        srcp[i] = (uint16_t)(i % (1 << (shift * 2)));
    }
}