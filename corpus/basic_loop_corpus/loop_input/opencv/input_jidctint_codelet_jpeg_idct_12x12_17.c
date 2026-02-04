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
JLONG tmp15;
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

#define DATA_SIZE (16 * 1024 * 1024)

static JSAMPLE *output_buffer_data;
static int *wsptr_data;
static JSAMPLE *range_limit_data;

void init_vars() {
    output_col = 0;

    output_buffer_data = (JSAMPLE *)calloc(DATA_SIZE, sizeof(JSAMPLE));
    range_limit_data = (JSAMPLE *)malloc((255 * 4 + 4) * sizeof(JSAMPLE));
    wsptr_data = (int *)malloc(8 * 12 * sizeof(int));

    if (!output_buffer_data || !range_limit_data || !wsptr_data) {
        exit(1);
    }

    for (size_t i = 0; i < (255 * 4 + 4); i++) {
        range_limit_data[i] = (JSAMPLE)(i & 0xFF);
    }

    for (int i = 0; i < 8 * 12; i++) {
        wsptr_data[i] = (i % 2 == 0) ? (100 + i) : (-100 - i);
    }

    output_buf = (JSAMPROW *)malloc(12 * sizeof(JSAMPROW));
    for (int i = 0; i < 12; i++) {
        output_buf[i] = &output_buffer_data[i * (DATA_SIZE / 12)];
    }

    wsptr = wsptr_data;
    range_limit = range_limit_data;
}