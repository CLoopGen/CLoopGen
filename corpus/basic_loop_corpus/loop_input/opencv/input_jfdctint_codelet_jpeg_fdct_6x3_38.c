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

static JSAMPLE *sample_data_storage[3];
JSAMPARRAY sample_data = sample_data_storage;
JDIMENSION start_col = 0;
INT32 tmp0;
INT32 tmp1;
INT32 tmp2;
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
DCTELEM *dataptr;
JSAMPROW elemptr;
int ctr;

void init_vars() {
    const int data_size = 8 * 1024 * 1024; // ~8MB per row to meet time target
    for (int i = 0; i < 3; i++) {
        sample_data[i] = malloc((start_col + 6) * sizeof(JSAMPLE));
        if (!sample_data[i]) {
            fprintf(stderr, "Allocation failed\n");
            exit(1);
        }
        for (JDIMENSION j = 0; j < 6; j++) {
            sample_data[i][start_col + j] = (JSAMPLE)((i * 6 + j + 1) * 23); 
        }
    }

    DCTELEM *full_dataptr = malloc(data_size * sizeof(DCTELEM));
    if (!full_dataptr) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    dataptr = full_dataptr;
}