#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int INTFLOAT;

INTFLOAT (*dst)[2];
INTFLOAT (*src0)[2];
INTFLOAT *src1;
int n;
int i;

static INTFLOAT *dst_data;
static INTFLOAT *src0_data;
static INTFLOAT *src1_data;

void init_vars() {
    n = 65536;

    dst_data = (INTFLOAT *)aligned_alloc(32, n * 2 * sizeof(INTFLOAT));
    src0_data = (INTFLOAT *)aligned_alloc(32, n * 2 * sizeof(INTFLOAT));
    src1_data = (INTFLOAT *)aligned_alloc(32, n * sizeof(INTFLOAT));

    dst = (INTFLOAT(*)[2])dst_data;
    src0 = (INTFLOAT(*)[2])src0_data;
    src1 = src1_data;

    for (int idx = 0; idx < n; idx++) {
        src0[idx][0] = rand() % 65536;
        src0[idx][1] = rand() % 65536;
        src1[idx] = rand() % 65536;
        dst[idx][0] = 0;
        dst[idx][1] = 0;
    }
}