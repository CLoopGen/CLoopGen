#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *bsrc;
uint8_t *osrc;
uint8_t *msrc;
uint8_t *dst;
ptrdiff_t blinesize;
ptrdiff_t olinesize;
ptrdiff_t mlinesize;
ptrdiff_t dlinesize;
int w;
int h;
int x;
int y;

static uint8_t *bsrc_data;
static uint8_t *osrc_data;
static uint8_t *msrc_data;
static uint8_t *dst_data;

void init_vars() {
    w = 2048;
    h = 128;

    blinesize = w;
    olinesize = w;
    mlinesize = w;
    dlinesize = w;

    size_t total_size = w * h;

    bsrc_data = (uint8_t*)aligned_alloc(32, total_size);
    osrc_data = (uint8_t*)aligned_alloc(32, total_size);
    msrc_data = (uint8_t*)aligned_alloc(32, total_size);
    dst_data = (uint8_t*)aligned_alloc(32, total_size);

    if (!bsrc_data || !osrc_data || !msrc_data || !dst_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        bsrc_data[i] = rand() & 0xFF;
        osrc_data[i] = rand() & 0xFF;
        msrc_data[i] = rand() & 0xFF;
        dst_data[i] = 0;
    }

    bsrc = bsrc_data;
    osrc = osrc_data;
    msrc = msrc_data;
    dst = dst_data;
}

__attribute__((destructor))
static void cleanup() {
    free(bsrc_data);
    free(osrc_data);
    free(msrc_data);
    free(dst_data);
}