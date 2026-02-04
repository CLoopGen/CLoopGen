#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int JDIMENSION;

typedef unsigned short J16SAMPLE;

typedef J16SAMPLE *J16SAMPROW;

typedef J16SAMPROW *J16SAMPARRAY;

extern JDIMENSION samplesperrow;
extern JDIMENSION rowsperchunk;
extern JDIMENSION currow;
extern JDIMENSION i;
extern J16SAMPARRAY result16;
extern J16SAMPROW workspace16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JDIMENSION j;
    for (j = 0; j < rowsperchunk; j++) {
        for (i = 1; i > 0; i--) {
            result16[currow++] = workspace16;
            workspace16 += samplesperrow;
        }
    }
}
