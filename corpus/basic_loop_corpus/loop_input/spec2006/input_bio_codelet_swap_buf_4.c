#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

typedef int int32;
typedef unsigned int uint32;

int32 n_el;
int32 i;
uint32 *buf32;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of uint32 data
    n_el = data_size / sizeof(uint32);
    buf32 = (uint32*)aligned_alloc(32, data_size);
    if (!buf32) {
        n_el = 0;
        return;
    }
    for (int32 j = 0; j < n_el; j++) {
        buf32[j] = (uint32)(j * 0x9E3779B1U); // Arbitrary non-zero pattern
    }
}