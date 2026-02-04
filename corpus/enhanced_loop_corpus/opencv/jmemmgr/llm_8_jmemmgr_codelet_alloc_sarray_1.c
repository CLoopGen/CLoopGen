#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int JDIMENSION;

typedef short J12SAMPLE;

typedef J12SAMPLE *J12SAMPROW;

typedef J12SAMPROW *J12SAMPARRAY;

extern JDIMENSION samplesperrow;
extern JDIMENSION rowsperchunk;
extern JDIMENSION currow;
extern JDIMENSION i;
extern J12SAMPARRAY result12;
extern J12SAMPROW workspace12;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    // Trip count halved, but each iteration performs two assignments and pointer arithmetic with offset scaling
    JDIMENSION j;
    for (i = rowsperchunk / 2; i > 0; i--) {
        result12[currow++] = workspace12;
        result12[currow++] = workspace12 + samplesperrow;
        workspace12 += 2 * samplesperrow;
    }
    // Handle remaining row if original rowsperchunk was odd
    if (rowsperchunk % 2) {
        result12[currow++] = workspace12;
    }
}
