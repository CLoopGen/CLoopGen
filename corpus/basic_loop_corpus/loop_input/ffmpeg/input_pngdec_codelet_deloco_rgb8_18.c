#include <stdint.h>
#include <stdlib.h>

uint8_t *dst;
int size;
int alpha;
int i;

void init_vars() {
    size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime
    alpha = 1; // ensures step is 4, a reasonable stride
    dst = (uint8_t *)aligned_alloc(32, size * sizeof(uint8_t));
    
    for (int j = 0; j < size; ++j) {
        dst[j] = (uint8_t)(j % 251);
    }
}