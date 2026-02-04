#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int JDIMENSION;
typedef short J12SAMPLE;
typedef J12SAMPLE *J12SAMPROW;
typedef J12SAMPROW *J12SAMPARRAY;

JDIMENSION samplesperrow = 8192;
JDIMENSION rowsperchunk = 4096;
JDIMENSION currow = 0;
JDIMENSION i;

J12SAMPLE *workspace_base;
J12SAMPROW workspace12;
J12SAMPARRAY result12;

void init_vars() {
    workspace_base = (J12SAMPLE *)calloc(samplesperrow * rowsperchunk, sizeof(J12SAMPLE));
    if (!workspace_base) exit(1);

    result12 = (J12SAMPARRAY)calloc(rowsperchunk, sizeof(J12SAMPROW));
    if (!result12) exit(1);

    workspace12 = workspace_base;

    currow = 0;
}