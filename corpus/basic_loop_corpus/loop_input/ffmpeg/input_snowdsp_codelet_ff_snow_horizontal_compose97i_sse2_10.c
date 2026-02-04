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
    const size_t data_size = 64 * 1024 * 1024; // 64 MB total data
    const size_t element_size = sizeof(IDWTELEM);
    const size_t num_elements = data_size / element_size;

    b = aligned_alloc(16, data_size);
    ref = aligned_alloc(16, data_size);

    if (!b || !ref) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; ++idx) {
        b[idx] = (IDWTELEM)(idx % 32768);
        ref[idx] = (IDWTELEM)((idx * 3) % 32768);
    }

    w_l = (int)(num_elements - 16); // Ensure i < w_l - 15 does not exceed bounds
    i = 0;
}