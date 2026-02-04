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
JLONG tmp1;
JLONG tmp10;
JLONG tmp11;
JLONG tmp12;
JLONG z1;
JLONG z2;
JLONG z3;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to ensure runtime around 0.01s
#define WSPTR_SIZE (5 * 5)
#define RANGE_LIMIT_SIZE (256 * 4 + 4)

static JSAMPLE *output_buf_data = NULL;
static JSAMPROW *output_buf_rows = NULL;
static int *wsptr_data = NULL;
static JSAMPLE *range_limit_data = NULL;

void init_vars() {
    // Allocate range_limit: accessed with mask (255*4+3), so need at least 1027 elements
    range_limit_data = (JSAMPLE*)calloc(RANGE_LIMIT_SIZE, sizeof(JSAMPLE));
    for (int i = 0; i < RANGE_LIMIT_SIZE; i++) {
        range_limit_data[i] = (JSAMPLE)(i & 0xFF);
    }
    range_limit = range_limit_data;

    // Allocate wsptr data: loop runs 5 times, each step uses 5 ints, total 25 ints
    wsptr_data = (int*)malloc(WSPTR_SIZE * sizeof(int));
    for (int i = 0; i < WSPTR_SIZE; i++) {
        wsptr_data[i] = (i % 256) - 128;
    }
    wsptr = wsptr_data;

    // Allocate output buffer: 5 rows, each row has at least output_col + 5 elements
    output_col = 0; // Ensure no offset issues
    output_buf_rows = (JSAMPROW*)malloc(5 * sizeof(JSAMPROW));
    output_buf_data = (JSAMPLE*)malloc(DATA_SIZE * sizeof(JSAMPLE));
    for (int i = 0; i < 5; i++) {
        output_buf_rows[i] = &output_buf_data[i * (DATA_SIZE / 5)];
        for (int j = 0; j < (int)(DATA_SIZE / 5); j++) {
            output_buf_rows[i][j] = (JSAMPLE)((i + j) % 256);
        }
    }
    output_buf = output_buf_rows;

    // Initialize scalars
    tmp0 = 0;
    tmp1 = 0;
    tmp10 = 0;
    tmp11 = 0;
    tmp12 = 0;
    z1 = 0;
    z2 = 0;
    z3 = 0;
    outptr = NULL;
    ctr = 0;
}