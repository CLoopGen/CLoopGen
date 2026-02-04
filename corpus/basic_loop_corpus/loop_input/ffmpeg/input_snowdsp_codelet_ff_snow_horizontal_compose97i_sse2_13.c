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
    const size_t data_size = 16 * 1024 * 1024; // 16 MB of data
    w_l = (int)(data_size / sizeof(IDWTELEM)) - 31; // Ensure we don't go out of bounds in loop
    if (w_l <= 0) w_l = 16;

    b = aligned_alloc(16, data_size);
    ref = aligned_alloc(16, data_size);

    for (int j = 0; j < data_size / sizeof(IDWTELEM); ++j) {
        b[j] = (IDWTELEM)(j & 0xFF);
        ref[j] = (IDWTELEM)((j + 50) & 0xFF);
    }

    i = 0;
}