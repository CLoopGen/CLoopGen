#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *buf;
ptrdiff_t pitch;
int16_t tmp[16];
int i;
int j;

static int16_t *buf_data;
static ptrdiff_t buf_pitch;

void init_vars() {
    const size_t data_size = 1 << 20; // ~1MB of int16_t data
    const int rows = data_size / (4 * sizeof(int16_t));
    
    buf_data = calloc(data_size, 1);
    if (!buf_data) exit(1);

    buf_pitch = 4; 
    pitch = buf_pitch;

    buf = buf_data;

    for (int idx = 0; idx < 16; idx++) {
        tmp[idx] = (int16_t)(idx - 8);
    }

    i = 0;
    j = 0;
}