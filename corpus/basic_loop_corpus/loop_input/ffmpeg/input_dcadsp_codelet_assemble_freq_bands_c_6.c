#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *dst;
int32_t *src0;
int32_t *src1;
ptrdiff_t len;
int i;

static int32_t *src0_buf;
static int32_t *src1_buf;
static int32_t *dst_buf;

void init_vars() {
    len = 64 * 1024 * 1024; // ~256MB of total data (64M elements * 4 bytes)

    src0_buf = (int32_t *)aligned_alloc(32, len * sizeof(int32_t));
    src1_buf = (int32_t *)aligned_alloc(32, len * sizeof(int32_t));
    dst_buf = (int32_t *)aligned_alloc(32, 2 * len * sizeof(int32_t));

    if (!src0_buf || !src1_buf || !dst_buf) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (ptrdiff_t j = 0; j < len; j++) {
        src0_buf[j] = (int32_t)(j * 2);
        src1_buf[j] = (int32_t)(j * 3);
    }

    src0 = src0_buf;
    src1 = src1_buf;
    dst = dst_buf;
}