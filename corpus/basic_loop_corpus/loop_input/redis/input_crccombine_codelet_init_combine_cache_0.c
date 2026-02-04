#include <stdint.h>
#include <stddef.h>

uint64_t combine_cache[64][64];
uint8_t dim = 64;
unsigned int n;
uint64_t row = 1ULL << 32;

void init_vars() {
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            combine_cache[i][j] = ((uint64_t)i << 32) | j;
        }
    }
    dim = 64;
    row = 1ULL << 32;
}