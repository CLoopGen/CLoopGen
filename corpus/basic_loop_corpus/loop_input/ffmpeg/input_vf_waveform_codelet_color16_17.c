#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

int mirror;
int limit;
int src_w;
int sliceh_start;
int sliceh_end;
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
uint16_t *d0_data;
uint16_t *d1_data;
uint16_t *d2_data;

static uint16_t *c0_data_base;
static uint16_t *c1_data_base;
static uint16_t *c2_data_base;
static uint16_t *d0_data_base;
static uint16_t *d1_data_base;
static uint16_t *d2_data_base;

void init_vars() {
    // Set parameters to create ~100ms workload on modern CPU
    // Aim for moderate memory footprint (~32-64 MB total)
    
    src_w = 2048;
    sliceh_start = 0;
    sliceh_end = 2048;
    
    c0_shift_w = 1;
    c1_shift_w = 1;
    c2_shift_w = 1;
    
    c0_shift_h = 0;
    c1_shift_h = 0;
    c2_shift_h = 0;
    
    c0_linesize = src_w >> c0_shift_w;
    c1_linesize = src_w >> c1_shift_w;
    c2_linesize = src_w >> c2_shift_w;
    
    d0_linesize = src_w;
    d1_linesize = src_w;
    d2_linesize = src_w;
    
    mirror = 0;
    limit = 512;
    
    size_t c0_size = (size_t)(sliceh_end - sliceh_start + 1) * c0_linesize;
    size_t c1_size = (size_t)(sliceh_end - sliceh_start + 1) * c1_linesize;
    size_t c2_size = (size_t)(sliceh_end - sliceh_start + 1) * c2_linesize;
    size_t d0_size = (size_t)(sliceh_end - sliceh_start + 1) * d0_linesize;
    size_t d1_size = (size_t)(sliceh_end - sliceh_start + 1) * d1_linesize;
    size_t d2_size = (size_t)(sliceh_end - sliceh_start + 1) * d2_linesize;
    
    c0_data_base = aligned_alloc(64, c0_size * sizeof(uint16_t));
    c1_data_base = aligned_alloc(64, c1_size * sizeof(uint16_t));
    c2_data_base = aligned_alloc(64, c2_size * sizeof(uint16_t));
    d0_data_base = aligned_alloc(64, d0_size * sizeof(uint16_t));
    d1_data_base = aligned_alloc(64, d1_size * sizeof(uint16_t));
    d2_data_base = aligned_alloc(64, d2_size * sizeof(uint16_t));
    
    memset(c0_data_base, 0, c0_size * sizeof(uint16_t));
    memset(c1_data_base, 0, c1_size * sizeof(uint16_t));
    memset(c2_data_base, 0, c2_size * sizeof(uint16_t));
    memset(d0_data_base, 0, d0_size * sizeof(uint16_t));
    memset(d1_data_base, 0, d1_size * sizeof(uint16_t));
    memset(d2_data_base, 0, d2_size * sizeof(uint16_t));
    
    // Initialize with non-zero pattern to avoid degenerate cases
    for (size_t i = 0; i < c0_size; i++) {
        c0_data_base[i] = (uint16_t)((i * 7) & 1023);
    }
    for (size_t i = 0; i < c1_size; i++) {
        c1_data_base[i] = (uint16_t)((i * 11) & 1023);
    }
    for (size_t i = 0; i < c2_size; i++) {
        c2_data_base[i] = (uint16_t)((i * 13) & 1023);
    }
    
    c0_data = c0_data_base;
    c1_data = c1_data_base;
    c2_data = c2_data_base;
    d0_data = d0_data_base;
    d1_data = d1_data_base;
    d2_data = d2_data_base;
}