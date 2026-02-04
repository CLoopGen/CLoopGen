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
JLONG tmp0;
JLONG tmp10;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

#define DATA_SIZE (128 * 1024 * 1024)
static JSAMPLE *output_data;
static int *wsptr_data;
static JSAMPLE *range_limit_data;

void init_vars() {
    output_data = calloc(DATA_SIZE, sizeof(JSAMPLE));
    wsptr_data = malloc(DATA_SIZE * sizeof(int));
    range_limit_data = malloc((256 * 4 + 4) * sizeof(JSAMPLE));

    for (size_t i = 0; i < DATA_SIZE; ++i) {
        wsptr_data[i] = rand() % 3 - 1;
    }

    for (int i = 0; i < (256 * 4 + 4); ++i) {
        range_limit_data[i] = (JSAMPLE)(i & 255);
    }

    output_buf = malloc(2 * sizeof(JSAMPROW));
    for (int i = 0; i < 2; ++i) {
        output_buf[i] = &output_data[i * (DATA_SIZE / 2)];
    }

    wsptr = wsptr_data;
    range_limit = range_limit_data;
    output_col = 0;
}