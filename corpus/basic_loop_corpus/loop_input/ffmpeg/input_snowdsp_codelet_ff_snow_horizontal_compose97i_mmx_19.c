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
    const int elem_size = sizeof(IDWTELEM);

    b = aligned_alloc(16, data_size);
    dst = aligned_alloc(16, data_size);

    if (!b || !dst) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size / elem_size; ++idx) {
        b[idx] = (IDWTELEM)(idx % 32768);
        dst[idx] = (IDWTELEM)((idx + 1) % 32768);
    }

    w_r = (data_size / elem_size) - 1;
    i = 0;
}