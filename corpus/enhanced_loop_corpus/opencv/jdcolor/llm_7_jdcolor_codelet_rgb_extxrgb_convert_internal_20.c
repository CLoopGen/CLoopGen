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
    JSAMPLE temp0, temp1, temp2;
    for (col = 0; col < num_cols; col++) {
        temp0 = inptr0[col];
        temp1 = inptr1[col];
        temp2 = inptr2[col];
        local_out[1] = temp0;
        local_out[2] = temp1;
        local_out[3] = temp2;
        local_out[0] = 255;
        local_out += 4;
    }
}
