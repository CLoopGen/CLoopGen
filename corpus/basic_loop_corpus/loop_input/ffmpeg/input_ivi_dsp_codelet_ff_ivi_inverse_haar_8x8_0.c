#include <stdlib.h>
#include <stdint.h>

uint8_t *flags;
int i;
int shift;
int sp1;
int sp2;
int sp3;
int sp4;
int32_t *src;
int32_t *dst;
int t0;
int t1;
int t2;
int t3;
int t4;
int t5;
int t6;
int t7;
int t8;

#define DATA_SIZE (64 * 1024 * 1024 / sizeof(int32_t)) // ~256MB total data, adjusted for int32_t

static uint8_t internal_flags[8] = {1, 0, 1, 1, 0, 1, 0, 1};
static int32_t *internal_src_base;
static int32_t *internal_dst_base;

void init_vars() {
    internal_src_base = (int32_t *)calloc(DATA_SIZE, sizeof(int32_t));
    internal_dst_base = (int32_t *)calloc(DATA_SIZE, sizeof(int32_t));

    if (!internal_src_base || !internal_dst_base) {
        exit(1);
    }

    for (size_t j = 0; j < DATA_SIZE; j++) {
        internal_src_base[j] = (int32_t)(j % 1000);
    }

    flags = internal_flags;
    src = internal_src_base;
    dst = internal_dst_base;
}