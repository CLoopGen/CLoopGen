#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long INT32;
typedef int DCTELEM;

static JSAMPLE *sample_data_storage;
static JSAMPROW *sample_data_rows;
static DCTELEM *dataptr_storage;
JSAMPARRAY sample_data;
DCTELEM *dataptr;
JSAMPROW elemptr;
JDIMENSION start_col;
INT32 tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;
INT32 tmp10, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17;
int ctr;

void init_vars() {
    const size_t total_size = 1 << 20; // ~1MB of data
    sample_data_storage = (JSAMPLE*)calloc(total_size, sizeof(JSAMPLE));
    sample_data_rows = (JSAMPROW*)malloc(8 * sizeof(JSAMPROW));
    dataptr_storage = (DCTELEM*)calloc(8 * 8, sizeof(DCTELEM));

    if (!sample_data_storage || !sample_data_rows || !dataptr_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < 8; i++) {
        sample_data_rows[i] = &sample_data_storage[i * 16];
    }

    sample_data = sample_data_rows;
    dataptr = dataptr_storage;
    start_col = 0;
    elemptr = sample_data[0];

    for (size_t i = 0; i < total_size; i++) {
        sample_data_storage[i] = (JSAMPLE)(i % 256);
    }
}