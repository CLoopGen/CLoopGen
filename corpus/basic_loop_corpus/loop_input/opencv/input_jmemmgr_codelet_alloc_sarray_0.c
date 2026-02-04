#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int JDIMENSION;
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;

JDIMENSION samplesperrow;
JSAMPARRAY result;
JSAMPROW workspace;
JDIMENSION rowsperchunk;
JDIMENSION currow;
JDIMENSION i;

void init_vars() {
    // Aim for ~64MB of image data to ensure loop runs long enough (~0.01 sec)
    samplesperrow = 8192;  // Wide row size
    rowsperchunk = 8192;   // Number of rows to process
    currow = 0;

    // Allocate result array (array of pointers to rows)
    result = (JSAMPARRAY)malloc(rowsperchunk * sizeof(JSAMPROW));
    if (!result) exit(1);

    // Allocate one continuous workspace buffer
    JSAMPROW full_workspace = (JSAMPROW)malloc(samplesperrow * rowsperchunk * sizeof(JSAMPLE));
    if (!full_workspace) exit(1);

    // Initialize workspace to point to the beginning of the buffer
    workspace = full_workspace;
}