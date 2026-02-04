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
    // Variant 2: Strided memory access – process one column across all rows before moving to next column
    for (int col = 0; col < 8; col++) {
        for (elemr = 0; elemr < 8; elemr++) {
            JSAMPLE val = sample_data[elemr][start_col + col];
            *workspaceptr++ = (float)(val - 128);
        }
    }
}
