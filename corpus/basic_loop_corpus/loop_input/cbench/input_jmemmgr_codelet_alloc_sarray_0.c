#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef unsigned int JDIMENSION;
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;

JDIMENSION samplesperrow = 8192;
JSAMPARRAY result;
JSAMPROW workspace;
JDIMENSION rowsperchunk = 16384;
JDIMENSION currow = 0;
JDIMENSION i;

void init_vars() {
    result = (JSAMPARRAY)malloc((currow + rowsperchunk) * sizeof(JSAMPROW));
    if (!result) {
        exit(1);
    }

    workspace = (JSAMPROW)malloc(samplesperrow * rowsperchunk * sizeof(JSAMPLE));
    if (!workspace) {
        free(result);
        exit(1);
    }
}