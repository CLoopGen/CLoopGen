#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

int mirror;
int src_w;
int sliceh_start;
int sliceh_end;
int c0_linesize;
int c1_linesize;
int c2_linesize;
int c0_shift_h;
int c1_shift_h;
int c2_shift_h;
uint8_t *c0_data;
uint8_t *c1_data;
uint8_t *c2_data;
int d0_linesize;
int d1_linesize;
int d2_linesize;
int c0_shift_w;
int c1_shift_w;
int c2_shift_w;
int x;
int y;
uint8_t *d0_data;
uint8_t *d1_data;
uint8_t *d2_data;

#define DATA_SIZE_MB 64
#define TOTAL_BYTES (DATA_SIZE_MB * 1024 * 1024)

static uint8_t *buffer_c0;
static uint8_t *buffer_c1;
static uint8_t *buffer_c2;
static uint8_t *buffer_d0;
static uint8_t *buffer_d1;
static uint8_t *buffer_d2;

void init_vars() {
    const size_t total_size = TOTAL_BYTES;
    buffer_c0 = (uint8_t*)aligned_alloc(32, total_size);
    buffer_c1 = (uint8_t*)aligned_alloc(32, total_size);
    buffer_c2 = (uint8_t*)aligned_alloc(32, total_size);
    buffer_d0 = (uint8_t*)aligned_alloc(32, total_size);
    buffer_d1 = (uint8_t*)aligned_alloc(32, total_size);
    buffer_d2 = (uint8_t*)aligned_alloc(32, total_size);

    if (!buffer_c0 || !buffer_c1 || !buffer_c2 || !buffer_d0 || !buffer_d1 || !buffer_d2) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    memset(buffer_c0, 0, total_size);
    memset(buffer_c1, 1, total_size);
    memset(buffer_c2, 2, total_size);
    memset(buffer_d0, 0, total_size);
    memset(buffer_d1, 0, total_size);
    memset(buffer_d2, 0, total_size);

    mirror = 0;
    src_w = 1920;
    sliceh_start = 0;
    sliceh_end = 1080;

    c0_shift_w = 0;
    c1_shift_w = 1;
    c2_shift_w = 1;

    c0_shift_h = 0;
    c1_shift_h = 1;
    c2_shift_h = 1;

    c0_linesize = 1920;
    c1_linesize = 960;
    c2_linesize = 960;

    d0_linesize = 1920;
    d1_linesize = 960;
    d2_linesize = 960;

    c0_data = buffer_c0;
    c1_data = buffer_c1;
    c2_data = buffer_c2;
    d0_data = buffer_d0;
    d1_data = buffer_d1;
    d2_data = buffer_d2;

    for (int i = 0; i < src_w; ++i) {
        buffer_c0[i] = (uint8_t)(i & 0xFF);
        buffer_c1[i >> c1_shift_w] = (uint8_t)((i >> c1_shift_w) & 0xFF);
        buffer_c2[i >> c2_shift_w] = (uint8_t)((i >> c2_shift_w) & 0xFF);
    }

    for (int i = 0; i < sliceh_end; ++i) {
        ptrdiff_t offset_d0 = (ptrdiff_t)i * d0_linesize;
        ptrdiff_t offset_d1 = (ptrdiff_t)i * d1_linesize;
        ptrdiff_t offset_d2 = (ptrdiff_t)i * d2_linesize;
        if (offset_d0 >= total_size || offset_d1 >= total_size || offset_d2 >= total_size) {
            fprintf(stderr, "Offset out of bounds during initialization\n");
            exit(1);
        }
    }
}