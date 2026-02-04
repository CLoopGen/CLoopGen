#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long JLONG;
typedef JLONG DCTELEM;

JSAMPLE *sample_data_mem;
JSAMPARRAY sample_data;
DCTELEM *workspaceptr_base;
DCTELEM *workspaceptr;
JSAMPROW elemptr;
int elemr;
JDIMENSION start_col;

void init_vars() {
    const int data_size = 262144; // 256KB of input data
    sample_data_mem = (JSAMPLE*)calloc(data_size, sizeof(JSAMPLE));
    sample_data = (JSAMPARRAY)calloc(8, sizeof(JSAMPROW));

    for (int i = 0; i < 8; i++) {
        sample_data[i] = sample_data_mem + i * 32768;
    }

    workspaceptr_base = (DCTELEM*)calloc(64, sizeof(DCTELEM));
    workspaceptr = workspaceptr_base;

    start_col = 0;

    for (int i = 0; i < data_size; i++) {
        sample_data_mem[i] = (JSAMPLE)(i % 256);
    }
}