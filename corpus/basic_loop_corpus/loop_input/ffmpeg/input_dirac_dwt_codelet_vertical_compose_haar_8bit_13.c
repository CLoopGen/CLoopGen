#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
int i;
int16_t *b0;
int16_t *b1;

void init_vars() {
    width = 1 << 20; // Approximately 1MB of data per array (2^20 elements * 2 bytes = ~2MB total)

    b0 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b1 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));

    for (i = 0; i < width; i++) {
        b0[i] = (int16_t)(rand() % 1000);
        b1[i] = (int16_t)(rand() % 1000);
    }
}