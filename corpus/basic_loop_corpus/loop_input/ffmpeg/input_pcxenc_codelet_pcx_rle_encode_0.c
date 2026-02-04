#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int src_plane_size;
int nplanes;
int p;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    nplanes = 4;
    src_plane_size = (1 << 20) / nplanes;
    int total_src_size = src_plane_size * nplanes;
    int total_dst_size = total_src_size * 2;

    src_buffer = aligned_alloc(32, total_src_size);
    dst_buffer = aligned_alloc(32, total_dst_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (int i = 0; i < total_src_size; i++) {
        src_buffer[i] = rand() % 256;
    }

    src = src_buffer;
    dst = dst_buffer;
    p = 0;
}