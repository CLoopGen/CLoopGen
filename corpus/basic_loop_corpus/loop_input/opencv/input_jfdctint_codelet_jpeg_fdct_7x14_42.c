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

JSAMPLE sample_data_buffer[16][64];
JSAMPARRAY sample_data;
DCTELEM workspace[48];
DCTELEM dataptr_storage[256 * 1024 / sizeof(DCTELEM)]; // ~256KB of workspace

JSAMPROW elemptr;
DCTELEM *dataptr;
JDIMENSION start_col;
INT32 tmp0, tmp1, tmp2, tmp3;
INT32 tmp10, tmp11, tmp12;
INT32 z1, z2, z3;
int ctr;

void init_vars() {
    // Initialize sample_data to point into the buffer
    sample_data = (JSAMPARRAY)malloc(16 * sizeof(JSAMPROW));
    for (int i = 0; i < 16; i++) {
        sample_data[i] = sample_data_buffer[i];
    }

    // Initialize start_col to a valid offset (within row bounds)
    start_col = 0;

    // Initialize dataptr to point into our large storage block
    dataptr = dataptr_storage;

    // Initialize ctr to 0 to start loop from beginning
    ctr = 0;

    // Zero-initialize workspace
    for (int i = 0; i < 48; i++) {
        workspace[i] = 0;
    }

    // Optionally initialize sample data with non-zero values to simulate real input
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 64; j++) {
            sample_data_buffer[i][j] = (JSAMPLE)((i * 64 + j) % 256);
        }
    }
}