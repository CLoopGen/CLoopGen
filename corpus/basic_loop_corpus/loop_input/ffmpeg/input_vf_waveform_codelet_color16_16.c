#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

int limit;
int src_h;
int slicew_start;
int slicew_end;
int c0_linesize;
int c1_linesize;
int c2_linesize;
int c0_shift_h;
int c1_shift_h;
int c2_shift_h;
uint16_t *c0_data;
uint16_t *c1_data;
uint16_t *c2_data;
int d0_linesize;
int d1_linesize;
int d2_linesize;
int c0_shift_w;
int c1_shift_w;
int c2_shift_w;
int x;
int y;
int d0_signed_linesize;
int d1_signed_linesize;
int d2_signed_linesize;
uint16_t *d0_data;
uint16_t *d1_data;
uint16_t *d2_data;
uint16_t *d0;
uint16_t *d1;
uint16_t *d2;

static uint16_t *c0_data_storage;
static uint16_t *c1_data_storage;
static uint16_t *c2_data_storage;
static uint16_t *d0_data_storage;
static uint16_t *d1_data_storage;
static uint16_t *d2_data_storage;
static uint16_t *d0_storage;
static uint16_t *d1_storage;
static uint16_t *d2_storage;

void init_vars() {
    src_h = 512;
    slicew_start = 0;
    slicew_end = 512;
    c0_shift_w = 1;
    c1_shift_w = 1;
    c2_shift_w = 1;
    c0_shift_h = 1;
    c1_shift_h = 1;
    c2_shift_h = 1;
    limit = 1023;

    const int input_width = slicew_end >> c0_shift_w;
    const int padded_input_width = (input_width + 1) * 2;

    c0_linesize = padded_input_width;
    c1_linesize = padded_input_width;
    c2_linesize = padded_input_width;

    const int output_depth = 1024;
    d0_signed_linesize = output_depth;
    d1_signed_linesize = output_depth;
    d2_signed_linesize = output_depth;

    d0_linesize = slicew_end;
    d1_linesize = slicew_end;
    d2_linesize = slicew_end;

    const size_t c0_size = (src_h / (!c0_shift_h ? 1 : 2) + 1) * c0_linesize;
    const size_t c1_size = (src_h / (!c1_shift_h ? 1 : 2) + 1) * c1_linesize;
    const size_t c2_size = (src_h / (!c2_shift_h ? 1 : 2) + 1) * c2_linesize;

    const size_t d0_data_size = src_h * d0_linesize;
    const size_t d1_data_size = src_h * d1_linesize;
    const size_t d2_data_size = src_h * d2_linesize;

    const size_t d0_storage_size = output_depth * d0_linesize;
    const size_t d1_storage_size = output_depth * d1_linesize;
    const size_t d2_storage_size = output_depth * d2_linesize;

    c0_data_storage = aligned_alloc(64, c0_size * sizeof(uint16_t));
    c1_data_storage = aligned_alloc(64, c1_size * sizeof(uint16_t));
    c2_data_storage = aligned_alloc(64, c2_size * sizeof(uint16_t));
    d0_data_storage = aligned_alloc(64, d0_data_size * sizeof(uint16_t));
    d1_data_storage = aligned_alloc(64, d1_data_size * sizeof(uint16_t));
    d2_data_storage = aligned_alloc(64, d2_data_size * sizeof(uint16_t));
    d0_storage = aligned_alloc(64, d0_storage_size * sizeof(uint16_t));
    d1_storage = aligned_alloc(64, d1_storage_size * sizeof(uint16_t));
    d2_storage = aligned_alloc(64, d2_storage_size * sizeof(uint16_t));

    memset(c0_data_storage, 0, c0_size * sizeof(uint16_t));
    memset(c1_data_storage, 0, c1_size * sizeof(uint16_t));
    memset(c2_data_storage, 0, c2_size * sizeof(uint16_t));
    memset(d0_data_storage, 0, d0_data_size * sizeof(uint16_t));
    memset(d1_data_storage, 0, d1_data_size * sizeof(uint16_t));
    memset(d2_data_storage, 0, d2_data_size * sizeof(uint16_t));
    memset(d0_storage, 0, d0_storage_size * sizeof(uint16_t));
    memset(d1_storage, 0, d1_storage_size * sizeof(uint16_t));
    memset(d2_storage, 0, d2_storage_size * sizeof(uint16_t));

    for (size_t i = 0; i < c0_size; ++i) c0_data_storage[i] = rand() % 2048;
    for (size_t i = 0; i < c1_size; ++i) c1_data_storage[i] = rand() % 2048;
    for (size_t i = 0; i < c2_size; ++i) c2_data_storage[i] = rand() % 2048;

    c0_data = c0_data_storage;
    c1_data = c1_data_storage;
    c2_data = c2_data_storage;
    d0_data = d0_data_storage;
    d1_data = d1_data_storage;
    d2_data = d2_data_storage;
    d0 = d0_storage;
    d1 = d1_storage;
    d2 = d2_storage;
}