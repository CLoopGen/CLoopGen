#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

int i;
int16_t (*src)[8];

static int16_t *src_data = NULL;

void init_vars() {
    const size_t total_elements = (1 << 20) / sizeof(int16_t); // ~1MB of data
    const size_t rows = total_elements / 8;
    
    src_data = aligned_alloc(32, rows * 8 * sizeof(int16_t));
    if (!src_data) {
        exit(1);
    }

    for (size_t idx = 0; idx < rows * 8; ++idx) {
        src_data[idx] = (int16_t)(idx % 251); // prime to avoid patterns
    }

    src = (int16_t(*)[8])src_data;
}