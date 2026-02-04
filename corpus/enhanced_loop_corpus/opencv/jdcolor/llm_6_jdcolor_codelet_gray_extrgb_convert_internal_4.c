#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JDIMENSION col;
    JSAMPROW local_out = outptr;
    JSAMPROW local_in = inptr;
    for (col = 0; col < num_cols; col++) {
        JSAMPLE val = local_in[col];
        local_out[0] = val;
        local_out[1] = val;
        local_out[2] = val;
        local_out += 3;
    }
    outptr = local_out;
}
