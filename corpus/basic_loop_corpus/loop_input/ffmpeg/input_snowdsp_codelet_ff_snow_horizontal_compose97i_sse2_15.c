#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

IDWTELEM *b;
IDWTELEM *temp;
int w_r;
int i;
IDWTELEM *src;

void init_vars() {
    const size_t data_size = 16 * 1024 * 1024; // 16 MB of data
    w_r = (int)(data_size / sizeof(IDWTELEM)) - 8; // Ensure i < w_r - 7 is safe
    if (w_r <= 0) w_r = 8;

    b = aligned_alloc(16, data_size + 32);
    temp = aligned_alloc(16, data_size + 32);
    src = aligned_alloc(16, data_size + 32);

    for (int j = 0; j < (data_size / sizeof(IDWTELEM)) + 16; ++j) {
        src[j] = (IDWTELEM)(j & 0xFF);
        b[j] = (IDWTELEM)((j + 1) & 0xFF);
        temp[j] = 0;
    }

    i = 0;
}