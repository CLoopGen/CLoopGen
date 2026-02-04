#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW outptr;
extern JSAMPROW inptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JSAMPROW local_out = outptr;
    JSAMPLE temp;
    for (col = 0; col < num_cols; col++) {
        temp = inptr[col];
        local_out[0] = temp;
        local_out[1] = temp;
        local_out[2] = temp;
        local_out += 3;
    }
    outptr = local_out;
}
