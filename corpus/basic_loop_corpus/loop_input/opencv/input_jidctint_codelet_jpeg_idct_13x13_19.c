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
static JSAMPROW outptr_row;
static int *wsptr_global;

JSAMPARRAY output_buf;
JDIMENSION output_col;
JLONG tmp10;
JLONG tmp11;
JLONG tmp12;
JLONG tmp13;
JLONG tmp14;
JLONG tmp15;
JLONG tmp20;
JLONG tmp21;
JLONG tmp22;
JLONG tmp23;
JLONG tmp24;
JLONG tmp25;
JLONG tmp26;
JLONG z1;
JLONG z2;
JLONG z3;
JLONG z4;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

void init_vars() {
    const size_t range_limit_size = 256 * 4 + 4;
    range_limit_data = (JSAMPLE*)calloc(range_limit_size, sizeof(JSAMPLE));
    for (size_t i = 0; i < range_limit_size; i++) {
        range_limit_data[i] = (JSAMPLE)((i >> 2) & 0xFF);
    }
    range_limit = range_limit_data;

    const int block_count = 13;
    const int row_width = 16; 
    output_buf_data = (JSAMPROW*)calloc(block_count, sizeof(JSAMPROW));
    outptr_row = (JSAMPLE*)calloc(block_count * row_width, sizeof(JSAMPLE));
    for (int i = 0; i < block_count; i++) {
        output_buf_data[i] = outptr_row + i * row_width;
    }
    output_buf = output_buf_data;
    output_col = 0;

    wsptr_data = (int*)calloc(8 * 13, sizeof(int));
    for (int i = 0; i < 8 * 13; i++) {
        wsptr_data[i] = (i % 2 == 0) ? (100 + i) : (-50 - i);
    }
    wsptr = wsptr_data;

    tmp10 = 0;
    tmp11 = 0;
    tmp12 = 0;
    tmp13 = 0;
    tmp14 = 0;
    tmp15 = 0;
    tmp20 = 0;
    tmp21 = 0;
    tmp22 = 0;
    tmp23 = 0;
    tmp24 = 0;
    tmp25 = 0;
    tmp26 = 0;
    z1 = 0;
    z2 = 0;
    z3 = 0;
    z4 = 0;
    ctr = 0;
}