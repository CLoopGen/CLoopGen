#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int left;
int i;
int min_width;
uint16_t *src16;
uint16_t *dst16;

void init_vars() {
    min_width = 67108864; // 128MB of data (67M elements * 2 bytes ~ 128MB), adjust for ~0.01s runtime
    src16 = (uint16_t*)aligned_alloc(32, min_width * sizeof(uint16_t));
    dst16 = (uint16_t*)aligned_alloc(32, min_width * sizeof(uint16_t));

    if (!src16 || !dst16) {
        exit(1);
    }

    for (int idx = 0; idx < min_width; idx++) {
        src16[idx] = rand() % 1000;
    }
    left = rand() % 1000;
}