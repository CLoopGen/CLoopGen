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
    for (i = rowsperchunk; i > 0; i--) {
        result12[currow] = workspace12;
        currow++;
        if (i == rowsperchunk / 2) {
            workspace12 += samplesperrow;
        }
        workspace12 += samplesperrow;
    }
}
