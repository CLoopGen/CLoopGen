#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *y;
int i;
int lut_size;

void init_vars() {
    lut_size = 131072; // 256KB of data (131072 elements * 2 bytes = 262144 bytes)
    y = (uint16_t*)malloc(lut_size * sizeof(uint16_t));
    if (!y) {
        exit(1);
    }
}