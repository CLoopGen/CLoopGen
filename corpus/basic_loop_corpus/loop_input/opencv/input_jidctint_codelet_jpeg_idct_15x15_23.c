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
static JSAMPLE **output_buf_data;
static int *wsptr_data;

JSAMPARRAY output_buf;
JDIMENSION output_col;
JLONG tmp10;
JLONG tmp11;
JLONG tmp12;
JLONG tmp13;
JLONG tmp14;
JLONG tmp15;
JLONG tmp16;
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
    const int data_size = 1 << 20; // ~1MB of input data
    const int num_rows = 16;
    const int row_width = 32;

    range_limit_data = (JSAMPLE*)calloc(data_size, sizeof(JSAMPLE));
    output_buf_data = (JSAMPLE**)calloc(num_rows, sizeof(JSAMPROW));
    wsptr_data = (int*)calloc(8 * 16, sizeof(int));

    for (int i = 0; i < data_size; i++) {
        range_limit_data[i] = (JSAMPLE)(i & 255);
    }

    for (int i = 0; i < num_rows; i++) {
        JSAMPROW row = (JSAMPROW)calloc(row_width, sizeof(JSAMPLE));
        for (int j = 0; j < row_width; j++) {
            row[j] = (JSAMPLE)((i * row_width + j) & 255);
        }
        output_buf_data[i] = row;
    }

    for (int i = 0; i < 8 * 16; i++) {
        wsptr_data[i] = (int)(i * 17 % 1000 - 500);
    }

    output_buf = output_buf_data;
    output_col = 0;
    wsptr = wsptr_data;
    range_limit = range_limit_data;
    outptr = output_buf[0];
}