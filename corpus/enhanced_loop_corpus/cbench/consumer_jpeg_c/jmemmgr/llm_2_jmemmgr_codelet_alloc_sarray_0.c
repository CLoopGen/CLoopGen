#include <stdio.h>

#include <inttypes.h>

typedef unsigned int JDIMENSION;

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

extern JDIMENSION samplesperrow;
extern JSAMPARRAY result;
extern JSAMPROW workspace;
extern JDIMENSION rowsperchunk;
extern JDIMENSION currow;
extern JDIMENSION i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 iterations
    JDIMENSION remaining = rowsperchunk;
    JSAMPROW current_workspace = workspace;
    JDIMENSION idx = currow;

    for (i = remaining / 2; i > 0; i--) {
        result[idx++] = current_workspace;
        current_workspace += samplesperrow;
        result[idx++] = current_workspace;
        current_workspace += samplesperrow;
    }

    // Handle remaining element if rowsperchunk is odd
    if (remaining % 2) {
        result[idx++] = current_workspace;
    }

    currow = idx;
    workspace = current_workspace;
}
