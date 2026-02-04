#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int DWTELEM;

DWTELEM *dst;
DWTELEM *src;
DWTELEM *ref;
int dst_step = 1;
int src_step = 1;
int ref_step = 1;
int mul = 32;
int add = 16;
int shift = 6;
int inverse = 1;
int w = 1 << 20;
int i;

static DWTELEM *dst_buf;
static DWTELEM *src_buf;
static DWTELEM *ref_buf;

void init_vars() {
    const size_t total_size = (size_t)w * 2; // Account for i+1 access

    dst_buf = aligned_alloc(32, total_size * sizeof(DWTELEM));
    src_buf = aligned_alloc(32, total_size * sizeof(DWTELEM));
    ref_buf = aligned_alloc(32, total_size * sizeof(DWTELEM));

    if (!dst_buf || !src_buf || !ref_buf) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < total_size; j++) {
        src_buf[j] = (DWTELEM)(j % 1024);
        ref_buf[j] = (DWTELEM)((j + 512) % 1024);
    }

    dst = dst_buf;
    src = src_buf;
    ref = ref_buf;
}