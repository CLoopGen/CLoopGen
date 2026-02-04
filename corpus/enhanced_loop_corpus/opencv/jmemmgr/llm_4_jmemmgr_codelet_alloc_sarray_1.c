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
        if (currow % 2 == 0) {
            result12[currow++] = workspace12;
        } else {
            result12[currow++] = workspace12;
        }
        workspace12 += samplesperrow;
    }
}
