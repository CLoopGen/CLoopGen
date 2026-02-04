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
    JDIMENSION outer = rowsperchunk / 2;
    JDIMENSION remainder = rowsperchunk % 2;
    for (i = outer; i > 0; i--) {
        result16[currow++] = workspace16;
        workspace16 += samplesperrow;
        result16[currow++] = workspace16;
        workspace16 += samplesperrow;
    }
    for (i = remainder; i > 0; i--) {
        result16[currow++] = workspace16;
        workspace16 += samplesperrow;
    }
}
