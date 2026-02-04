#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

extern JSAMPARRAY sample_data;
extern JDIMENSION start_col;
extern float *workspaceptr;
extern JSAMPROW elemptr;
extern int elemr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using array indexing instead of pointer arithmetic
    for (elemr = 0; elemr < 8; elemr++) {
        JSAMPROW row = sample_data[elemr] + start_col;
        for (int col = 0; col < 8; col++) {
            workspaceptr[col] = (float)(row[col] - 128);
        }
        workspaceptr += 8;
    }
}
