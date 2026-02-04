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
        JDIMENSION idx = col * 3;
        local_out[idx + 2] = inptr2[col];
        local_out[idx + 1] = inptr1[col];
        local_out[idx + 0] = inptr0[col];
    }
    outptr = local_out + num_cols * 3;
}
