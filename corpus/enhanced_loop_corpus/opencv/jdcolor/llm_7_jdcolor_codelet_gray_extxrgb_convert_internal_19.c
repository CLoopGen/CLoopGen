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
    JSAMPROW local_out = outptr;
    JSAMPROW local_in = inptr;
    JDIMENSION local_cols = num_cols;
    for (col = 0; col < local_cols; col++) {
        local_out[0] = 255;
        local_out[1] = local_in[col];
        local_out[2] = local_in[col];
        local_out[3] = local_in[col];
        local_out += 4;
    }
    outptr = local_out;
}
