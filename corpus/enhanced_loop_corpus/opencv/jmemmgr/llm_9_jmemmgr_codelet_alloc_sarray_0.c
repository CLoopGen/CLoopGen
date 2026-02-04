#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int JDIMENSION;

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

extern JDIMENSION samplesperrow;
extern JSAMPARRAY result;
extern JSAMPROW workspace;
extern JDIMENSION rowsperchunk;
extern JDIMENSION currow;
extern JDIMENSION i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced arithmetic operations per iteration by precomputing offset
    // Uses a single pointer that advances by total size per row, avoiding repeated addition
    JSAMPLE* current_ptr = workspace;
    JDIMENSION total_bytes_per_row = samplesperrow; // effectively sizeof(JSAMPLE) * count, but JSAMPLE is byte

    for (i = rowsperchunk; i > 0; i--) {
        result[currow++] = current_ptr;
        current_ptr += total_bytes_per_row; // Single arithmetic operation, clearer stride use
    }

    // Update workspace to reflect final position (if needed by caller, though not captured here)
    workspace = current_ptr;
}
