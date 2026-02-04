#include <stdint.h>
#include <stdlib.h>

int i;
uint16_t *left;

void init_vars() {
    left = (uint16_t *)aligned_alloc(32, 64 * sizeof(uint16_t));
    for (int idx = 0; idx < 64; idx++) {
        left[idx] = (uint16_t)(idx * 10);
    }
}