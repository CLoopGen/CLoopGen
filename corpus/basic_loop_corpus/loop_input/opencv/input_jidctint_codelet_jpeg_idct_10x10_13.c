#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long JLONG;

JSAMPARRAY output_buf;
JDIMENSION output_col;
JLONG tmp10;
JLONG tmp11;
JLONG tmp12;
JLONG tmp13;
JLONG tmp14;
JLONG tmp20;
JLONG tmp21;
JLONG tmp22;
JLONG tmp23;
JLONG tmp24;
JLONG z1;
JLONG z2;
JLONG z3;
JLONG z4;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

#define DATA_SIZE (1 << 24)  // ~16.7M integers, roughly 64MB of data

static int *wsptr_base;
static JSAMPLE *range_limit_base;
static JSAMPLE **output_buf_rows;

void init_vars() {
    wsptr_base = (int*)calloc(DATA_SIZE, sizeof(int));
    range_limit_base = (JSAMPLE*)calloc(256 * 4 + 4, sizeof(JSAMPLE));
    output_buf_rows = (JSAMPROW*)calloc(10, sizeof(JSAMPROW));

    for (int i = 0; i < 10; i++) {
        output_buf_rows[i] = (JSAMPLE*)calloc(100, sizeof(JSAMPLE));
    }

    if (!wsptr_base || !range_limit_base || !output_buf_rows) {
        exit(1);
    }

    for (int i = 0; i < 256 * 4 + 4; i++) {
        range_limit_base[i] = (JSAMPLE)(i & 0xFF);
    }

    for (size_t i = 0; i < DATA_SIZE; i++) {
        wsptr_base[i] = (int)(i % 8192);
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 100; j++) {
            output_buf_rows[i][j] = (JSAMPLE)((i * 100 + j) & 0xFF);
        }
    }

    output_buf = output_buf_rows;
    output_col = 0;
    outptr = output_buf[0];
    wsptr = wsptr_base;
    range_limit = range_limit_base;

    tmp10 = 0;
    tmp11 = 0;
    tmp12 = 0;
    tmp13 = 0;
    tmp14 = 0;
    tmp20 = 0;
    tmp21 = 0;
    tmp22 = 0;
    tmp23 = 0;
    tmp24 = 0;
    z1 = 0;
    z2 = 0;
    z3 = 0;
    z4 = 0;
    ctr = 0;
}