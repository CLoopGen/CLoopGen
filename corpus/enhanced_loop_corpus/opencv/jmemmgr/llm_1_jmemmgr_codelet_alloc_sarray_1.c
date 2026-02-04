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
    JDIMENSION outer = rowsperchunk / 2;
    JDIMENSION remainder = rowsperchunk % 2;
    for (i = outer; i > 0; i--) {
        result12[currow++] = workspace12;
        workspace12 += samplesperrow;
        result12[currow++] = workspace12;
        workspace12 += samplesperrow;
    }
    for (i = remainder; i > 0; i--) {
        result12[currow++] = workspace12;
        workspace12 += samplesperrow;
    }
}
