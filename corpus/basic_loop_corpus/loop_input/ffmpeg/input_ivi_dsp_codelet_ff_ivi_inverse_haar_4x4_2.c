#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *flags;
int i;
int shift;
int sp1;
int sp2;
int32_t *src;
int32_t *dst;
int t0;
int t1;
int t2;
int t3;
int t4;

static uint8_t flags_data[4];
static int32_t src_data[16 * 256 * 256]; // 16 elements per iteration, scaled to ~16MB total
static int32_t dst_data[16 * 256 * 256]; // same size

void init_vars() {
    flags = flags_data;
    src = src_data;
    dst = dst_data;

    for (int idx = 0; idx < 4; idx++) {
        flags_data[idx] = (idx & 1); // alternate true/false
    }

    for (int idx = 0; idx < 16 * 256 * 256; idx++) {
        src_data[idx] = (int32_t)(idx * 7 + 1);
        dst_data[idx] = 0;
    }

    i = 0;
    shift = 0;
    sp1 = 0;
    sp2 = 0;
    t0 = 0;
    t1 = 0;
    t2 = 0;
    t3 = 0;
    t4 = 0;
}