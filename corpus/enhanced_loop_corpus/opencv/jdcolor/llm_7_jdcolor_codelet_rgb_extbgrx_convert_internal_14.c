#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JSAMPROW local_out = outptr;
    for (col = 0; col < num_cols; col++) {
        JDIMENSION offset = col * 4;
        local_out[offset + 0] = inptr2[col];
        local_out[offset + 1] = inptr1[col];
        local_out[offset + 2] = inptr0[col];
        local_out[offset + 3] = 255;
    }
    outptr += num_cols * 4;
}
