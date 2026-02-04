#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int JDIMENSION;
typedef unsigned short J16SAMPLE;
typedef J16SAMPLE *J16SAMPROW;
typedef J16SAMPROW *J16SAMPARRAY;

JDIMENSION samplesperrow = 8192;
JDIMENSION rowsperchunk = 4096;
JDIMENSION currow = 0;
JDIMENSION i;

static J16SAMPLE *workspace16_base;
J16SAMPROW workspace16;

static J16SAMPARRAY result16_storage;
J16SAMPARRAY result16;

void init_vars() {
    workspace16_base = (J16SAMPLE *)calloc(samplesperrow * rowsperchunk, sizeof(J16SAMPLE));
    if (!workspace16_base) exit(1);
    
    result16_storage = (J16SAMPROW *)calloc(rowsperchunk, sizeof(J16SAMPROW));
    if (!result16_storage) exit(1);

    workspace16 = workspace16_base;
    result16 = result16_storage;
    currow = 0;
}