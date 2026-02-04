#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *buf;
ptrdiff_t pitch;
int16_t tmp[64];
int i;
int j;

static int16_t *buf_data;
static ptrdiff_t buf_pitch;

void init_vars() {
    const size_t data_size = 1 << 20;
    const int block_count = data_size / (8 * sizeof(int16_t));
    buf_pitch = 8;
    pitch = buf_pitch;

    buf_data = aligned_alloc(64, block_count * buf_pitch * 8 * sizeof(int16_t));
    if (!buf_data) exit(1);

    buf = buf_data;

    for (int idx = 0; idx < 64; idx++) {
        tmp[idx] = (int16_t)(idx * 3);
    }

    for (int b = 0; b < block_count; b++) {
        int16_t *block = &buf_data[b * buf_pitch * 8];
        for (int i_inner = 0; i_inner < 8; i_inner++) {
            for (int j_inner = 0; j_inner < 8; j_inner++) {
                block[i_inner * buf_pitch + j_inner] = 0;
            }
        }
    }
}