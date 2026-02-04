#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long INT32;

JSAMPARRAY output_buf;
JDIMENSION output_col;
INT32 tmp0;
INT32 tmp1;
INT32 tmp2;
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
INT32 z1;
INT32 z2;
INT32 z3;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

#define DATA_SIZE (16 * 1024 * 1024)
#define WSPTR_SIZE (6 * 3 * (DATA_SIZE / (6 * 3)))

static JSAMPLE *output_image_data;
static int *wsptr_data;
static JSAMPLE *range_limit_data;

void init_vars() {
    output_col = 0;

    output_image_data = (JSAMPLE *)calloc(DATA_SIZE, sizeof(JSAMPLE));
    wsptr_data = (int *)calloc(WSPTR_SIZE, sizeof(int));
    range_limit_data = (JSAMPLE *)malloc(512 * sizeof(JSAMPLE));

    if (!output_image_data || !wsptr_data || !range_limit_data) {
        exit(1);
    }

    for (size_t i = 0; i < WSPTR_SIZE; i++) {
        wsptr_data[i] = (i % 7) ? ((int)(113 * i)) % 8192 : 0;
    }

    for (int i = 0; i < 512; i++) {
        range_limit_data[i] = (JSAMPLE)((i < 256) ? 0 : (i < 512) ? i - 256 : 255);
    }

    output_buf = (JSAMPROW *)calloc(3, sizeof(JSAMPROW));
    for (int i = 0; i < 3; i++) {
        output_buf[i] = &output_image_data[i * (DATA_SIZE / 3)];
    }

    wsptr = wsptr_data;
    range_limit = range_limit_data;
}