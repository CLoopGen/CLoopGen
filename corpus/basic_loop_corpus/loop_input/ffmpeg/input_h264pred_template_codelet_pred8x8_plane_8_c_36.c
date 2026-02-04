#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int k;
int stride = 65536; // Chosen to ensure reasonable memory access pattern and performance
uint8_t *src0;
uint8_t *src1;
uint8_t *src2;
int H = 0;
int V = 0;

static uint8_t *buf0;
static uint8_t *buf1;
static uint8_t *buf2;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data per buffer

    buf0 = (uint8_t*)aligned_alloc(32, data_size);
    buf1 = (uint8_t*)aligned_alloc(32, data_size);
    buf2 = (uint8_t*)aligned_alloc(32, data_size);

    if (!buf0 || !buf1 || !buf2) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        buf0[i] = rand() % 256;
        buf1[i] = rand() % 256;
        buf2[i] = rand() % 256;
    }

    src0 = buf0 + 4; // Ensure that src0[-k] and src0[k] are valid for k in [2,4]
    src1 = buf1 + stride * 2; // Allow += stride twice (k=2,3,4 => 3 times, but start at offset 2)
    src2 = buf2 + data_size - 1 - stride * 2; // Allow -= stride safely

    H = 0;
    V = 0;
}