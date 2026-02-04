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
    // Variant 1: Consecutive memory access using pointer arithmetic with pre-increment
    JSAMPROW wp = workspace;
    for (JDIMENSION idx = 0; idx < rowsperchunk; idx++) {
        result[currow + idx] = wp;
        wp += samplesperrow;
    }
    currow += rowsperchunk;
    workspace = wp;
}
