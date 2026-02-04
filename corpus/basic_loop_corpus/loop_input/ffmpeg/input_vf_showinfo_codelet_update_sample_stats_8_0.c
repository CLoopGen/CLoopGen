#include <stdlib.h>
#include <stdint.h>

uint8_t *src;
int len;
int64_t *sum;
int64_t *sum2;
int i;

void init_vars() {
    len = 1 << 24; // 16.7 million elements ~ approx 0.01 sec on modern CPU
    src = (uint8_t*)aligned_alloc(32, len * sizeof(uint8_t));
    sum = (int64_t*)aligned_alloc(32, sizeof(int64_t));
    sum2 = (int64_t*)aligned_alloc(32, sizeof(int64_t));

    *sum = 0;
    *sum2 = 0;

    for (int j = 0; j < len; j++) {
        src[j] = (uint8_t)(j % 251); // deterministic non-zero values < 256
    }
}