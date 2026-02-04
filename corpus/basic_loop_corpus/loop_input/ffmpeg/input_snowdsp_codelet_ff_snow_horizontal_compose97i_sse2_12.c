#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

IDWTELEM *b;
int w_r;
int i;
IDWTELEM *dst;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB of data
    const size_t num_elements = data_size / sizeof(IDWTELEM);

    b = aligned_alloc(16, data_size);
    dst = aligned_alloc(16, data_size);

    w_r = (int)(num_elements - 16); // Ensure i < w_r - 15 stays in bounds
    i = 0;

    for (size_t idx = 0; idx < num_elements; ++idx) {
        b[idx] = (IDWTELEM)(idx % 32768);
        dst[idx] = (IDWTELEM)((idx + 1) % 32768);
    }
}