#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int src_h = 1024;
int slicew_start = 0;
int slicew_end = 1024;
int c0_linesize = 1024;
int c1_linesize = 1024;
int c2_linesize = 1024;
int c0_shift_h = 0;
int c1_shift_h = 0;
int c2_shift_h = 0;
uint8_t *c0_data;
uint8_t *c1_data;
uint8_t *c2_data;
int d0_linesize = 1024;
int d1_linesize = 1024;
int d2_linesize = 1024;
int c0_shift_w = 0;
int c1_shift_w = 0;
int c2_shift_w = 0;
int x;
int y;
int d0_signed_linesize = 1024;
int d1_signed_linesize = 1024;
int d2_signed_linesize = 1024;
uint8_t *d0_data;
uint8_t *d1_data;
uint8_t *d2_data;
uint8_t *d0;
uint8_t *d1;
uint8_t *d2;

void init_vars() {
    const int total_size = 1 << 20; // ~1MB data
    const int dim = 1024;

    c0_data = (uint8_t*)aligned_alloc(64, total_size);
    c1_data = (uint8_t*)aligned_alloc(64, total_size);
    c2_data = (uint8_t*)aligned_alloc(64, total_size);
    d0_data = (uint8_t*)aligned_alloc(64, total_size);
    d1_data = (uint8_t*)aligned_alloc(64, total_size);
    d2_data = (uint8_t*)aligned_alloc(64, total_size);

    d0 = d0_data;
    d1 = d1_data;
    d2 = d2_data;

    for (int i = 0; i < total_size; i++) {
        c0_data[i] = rand() % 256;
        c1_data[i] = rand() % 256;
        c2_data[i] = rand() % 256;
        d0_data[i] = 0;
        d1_data[i] = 0;
        d2_data[i] = 0;
    }

    src_h = dim;
    slicew_start = 0;
    slicew_end = dim;
    c0_linesize = dim;
    c1_linesize = dim;
    c2_linesize = dim;
    d0_linesize = dim;
    d1_linesize = dim;
    d2_linesize = dim;
    c0_shift_w = 0;
    c1_shift_w = 0;
    c2_shift_w = 0;
    c0_shift_h = 0;
    c1_shift_h = 0;
    c2_shift_h = 0;
    d0_signed_linesize = dim;
    d1_signed_linesize = dim;
    d2_signed_linesize = dim;
}