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
    // Variant 2: Strided access with reversed iteration and indirect indexing
    JSAMPROW wp = workspace;
    for (JDIMENSION idx = 0; idx < rowsperchunk; idx++) {
        JDIMENSION rev_idx = rowsperchunk - 1 - idx; // Reverse the order of assignment
        result[currow + rev_idx] = wp;
        wp += samplesperrow;
    }
    currow += rowsperchunk;
    workspace = wp;
}
