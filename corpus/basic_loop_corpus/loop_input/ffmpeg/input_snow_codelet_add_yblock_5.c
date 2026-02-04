#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef short IDWTELEM;

IDWTELEM *dst;
uint8_t *dst8;
uint8_t *obmc;
int b_w;
int b_h;
int dst_stride;
int src_stride;
int obmc_stride;
int add;
uint8_t *block[4];
int x;
int y;

void init_vars() {
    const size_t approx_data_size = 16 * 1024 * 1024; // Aim for ~16MB of total data
    const int side = (int)(sqrt(approx_data_size / (sizeof(uint8_t) * 5 + sizeof(IDWTELEM))));
    b_w = side;
    b_h = side;
    dst_stride = b_w;
    src_stride = b_w;
    obmc_stride = b_w * 2; // Ensure alignment and padding
    add = 1;

    // Allocate dst: IDWTELEM array of size b_h x dst_stride
    dst = (IDWTELEM*)calloc(b_h * dst_stride, sizeof(IDWTELEM));
    // Allocate dst8: uint8_t array of size b_h x src_stride
    dst8 = (uint8_t*)malloc(b_h * src_stride * sizeof(uint8_t));
    // Allocate obmc: uint8_t array of size b_h x obmc_stride (with padding)
    obmc = (uint8_t*)malloc(b_h * obmc_stride * sizeof(uint8_t));

    // Allocate each block as a contiguous buffer of size b_h x src_stride
    for (int i = 0; i < 4; i++) {
        block[i] = (uint8_t*)malloc(b_h * src_stride * sizeof(uint8_t));
    }

    // Initialize all arrays with deterministic non-zero values to avoid zero optimizations
    for (int i = 0; i < b_h * dst_stride; i++) {
        dst[i] = (IDWTELEM)(i % 256);
    }
    for (int i = 0; i < b_h * src_stride; i++) {
        dst8[i] = (uint8_t)((i + 17) % 256);
    }
    for (int i = 0; i < b_h * obmc_stride; i++) {
        obmc[i] = (uint8_t)((i + 33) % 129); // Small weights for OBMC
    }
    for (int b_idx = 0; b_idx < 4; b_idx++) {
        for (int i = 0; i < b_h * src_stride; i++) {
            block[b_idx][i] = (uint8_t)((i + b_idx * 64) % 256);
        }
    }
}