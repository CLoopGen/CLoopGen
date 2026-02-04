#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int k;
int stride;
uint16_t * src0;
uint16_t * src1;
uint16_t * src2;
int H;
int V;

static uint16_t *buffer_src0;
static uint16_t *buffer_src1;
static uint16_t *buffer_src2;

void init_vars() {
    const size_t data_size = 134217728; // 128 MB of data (adjustable for timing ~0.01s)
    const int max_k = 8;

    stride = 16;

    buffer_src0 = aligned_alloc(32, (data_size + 2 * max_k) * sizeof(uint16_t));
    buffer_src1 = aligned_alloc(32, data_size * sizeof(uint16_t));
    buffer_src2 = aligned_alloc(32, data_size * sizeof(uint16_t));

    if (!buffer_src0 || !buffer_src1 || !buffer_src2) {
        exit(1);
    }

    src0 = buffer_src0 + max_k;
    src1 = buffer_src1 + data_size / 2;
    src2 = buffer_src2 + data_size / 2;

    for (size_t i = 0; i < data_size + 2 * max_k; ++i) {
        buffer_src0[i] = rand() % 1000;
    }
    for (size_t i = 0; i < data_size; ++i) {
        buffer_src1[i] = rand() % 1000;
        buffer_src2[i] = rand() % 1000;
    }

    H = 0;
    V = 0;
}