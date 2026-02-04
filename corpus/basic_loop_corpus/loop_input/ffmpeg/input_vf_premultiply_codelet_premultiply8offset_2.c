#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *msrc;
uint8_t *asrc;
uint8_t *dst;
ptrdiff_t mlinesize;
ptrdiff_t alinesize;
ptrdiff_t dlinesize;
int w;
int h;
int offset;
int x;
int y;

static uint8_t *msrc_data;
static uint8_t *asrc_data;
static uint8_t *dst_data;

void init_vars() {
    w = 2048;
    h = 128;
    offset = 16;
    
    mlinesize = w + 32;
    alinesize = w + 16;
    dlinesize = w + 64;
    
    size_t msrc_size = mlinesize * h;
    size_t asrc_size = alinesize * h;
    size_t dst_size = dlinesize * h;
    
    msrc_data = (uint8_t*)aligned_alloc(32, msrc_size);
    asrc_data = (uint8_t*)aligned_alloc(32, asrc_size);
    dst_data = (uint8_t*)aligned_alloc(32, dst_size);
    
    if (!msrc_data || !asrc_data || !dst_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    for (size_t i = 0; i < msrc_size; i++) {
        msrc_data[i] = (uint8_t)(i & 255);
    }
    for (size_t i = 0; i < asrc_size; i++) {
        asrc_data[i] = (uint8_t)((i * 7) & 255);
    }
    for (size_t i = 0; i < dst_size; i++) {
        dst_data[i] = 0;
    }
    
    msrc = msrc_data;
    asrc = asrc_data;
    dst = dst_data;
}

static void cleanup_vars() {
    free(msrc_data);
    free(asrc_data);
    free(dst_data);
}