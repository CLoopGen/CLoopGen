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

JSAMPARRAY sample_data;
JDIMENSION start_col;
INT32 tmp0;
INT32 tmp1;
DCTELEM *dataptr;
JSAMPROW elemptr;
int ctr;

void init_vars() {
    const int data_size = 1 << 20; // ~1MB of input data
    sample_data = (JSAMPARRAY)malloc(4 * sizeof(JSAMPROW));
    dataptr = (DCTELEM*)malloc(data_size * sizeof(DCTELEM));
    
    for (int i = 0; i < 4; i++) {
        sample_data[i] = (JSAMPROW)malloc((start_col + 2) * sizeof(JSAMPLE));
    }
    
    start_col = 0; // Ensure no out-of-bounds access with elemptr[0] and elemptr[1]
    
    // Initialize pixel data to non-zero values for realistic computation
    for (int i = 0; i < 4; i++) {
        for (JDIMENSION j = 0; j < start_col + 2; j++) {
            sample_data[i][j] = (JSAMPLE)(i * 64 + j * 32);
        }
    }
}