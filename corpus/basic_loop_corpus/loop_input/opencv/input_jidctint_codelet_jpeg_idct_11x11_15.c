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
static JSAMPLE **output_buf_rows;

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
JLONG tmp25;
JLONG z1;
JLONG z2;
JLONG z3;
JLONG z4;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

void init_vars() {
    const int data_size = 16 * 1024 * 1024;
    range_limit_data = (JSAMPLE *)calloc(data_size, sizeof(JSAMPLE));
    wsptr_data = (int *)calloc(8 * 11 + 1, sizeof(int));
    output_buf_rows = (JSAMPLE **)calloc(11, sizeof(JSAMPLE *));
    
    for (int i = 0; i < 11; i++) {
        output_buf_rows[i] = (JSAMPLE *)calloc(20, sizeof(JSAMPLE));
    }
    
    if (!range_limit_data || !wsptr_data || !output_buf_rows) {
        exit(1);
    }
    
    for (int i = 0; i < data_size; i++) {
        range_limit_data[i] = (JSAMPLE)(i & 255);
    }
    
    for (int i = 0; i < 8 * 11; i++) {
        wsptr_data[i] = (i % 2 == 0) ? (1 << 10) : -(1 << 10);
    }
    
    output_buf = output_buf_rows;
    output_col = 0;
    wsptr = wsptr_data;
    range_limit = range_limit_data;
    ctr = 0;
}