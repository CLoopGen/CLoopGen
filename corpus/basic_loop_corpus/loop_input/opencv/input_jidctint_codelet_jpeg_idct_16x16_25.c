#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long JLONG;

static JSAMPLE *range_limit_data;
static JSAMPROW *output_buf_data;
static int *wsptr_data;

JSAMPARRAY output_buf;
JDIMENSION output_col;
JLONG tmp0;
JLONG tmp1;
JLONG tmp2;
JLONG tmp3;
JLONG tmp10;
JLONG tmp11;
JLONG tmp12;
JLONG tmp13;
JLONG tmp20;
JLONG tmp21;
JLONG tmp22;
JLONG tmp23;
JLONG tmp24;
JLONG tmp25;
JLONG tmp26;
JLONG tmp27;
JLONG z1;
JLONG z2;
JLONG z3;
JLONG z4;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

void init_vars() {
    const size_t total_data_size = 16 * 1024 * 1024; // ~16MB for data
    range_limit_data = (JSAMPLE *)calloc(total_data_size, sizeof(JSAMPLE));
    if (!range_limit_data) exit(1);

    for (size_t i = 0; i < total_data_size; i++) {
        range_limit_data[i] = (JSAMPLE)((i >> 2) & 0xFF);
    }

    output_buf_data = (JSAMPROW *)calloc(16, sizeof(JSAMPROW));
    if (!output_buf_data) exit(1);

    for (int i = 0; i < 16; i++) {
        output_buf_data[i] = (JSAMPLE *)calloc(32, sizeof(JSAMPLE));
        if (!output_buf_data[i]) exit(1);
        for (int j = 0; j < 32; j++) {
            output_buf_data[i][j] = (JSAMPLE)(j ^ i);
        }
    }

    wsptr_data = (int *)calloc(8 * 16 + 1, sizeof(int));
    if (!wsptr_data) exit(1);

    for (int i = 0; i < 8 * 16; i++) {
        wsptr_data[i] = (i + 1) * 17;
    }

    output_buf = output_buf_data;
    output_col = 0;
    wsptr = wsptr_data;
    range_limit = range_limit_data;
}