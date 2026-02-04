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
    JSAMPROW local_in = inptr;
    JSAMPROW local_out = outptr;
    for (col = 0; col < num_cols; col++) {
        JSAMPLE temp = local_in[col];
        local_out[0] = 255;
        local_out[1] = temp;
        local_out[2] = temp;
        local_out[3] = temp;
        local_out += 4;
    }
    outptr = local_out;
}
