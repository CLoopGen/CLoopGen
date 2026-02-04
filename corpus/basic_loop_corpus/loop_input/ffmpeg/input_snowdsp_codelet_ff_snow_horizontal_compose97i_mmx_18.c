#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

IDWTELEM *b;
int w_l;
int i;
IDWTELEM *ref;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB of data for sufficient runtime (~0.01 sec)
    const size_t num_elements = data_size / sizeof(IDWTELEM);

    b = aligned_alloc(16, data_size);
    ref = aligned_alloc(16, data_size);

    for (size_t j = 0; j < num_elements; ++j) {
        b[j] = (IDWTELEM)(j & 0xFF);
        ref[j] = (IDWTELEM)((j + 13) & 0xFF);
    }

    w_l = (int)(num_elements - 8); // Ensure i < w_l - 7 does not cause out-of-bounds access
    i = 0;
}