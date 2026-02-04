#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr;
extern JSAMPROW outptr0;
extern JSAMPROW outptr1;
extern JSAMPROW outptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled in groups of 4
    // This variant assumes num_cols is a multiple of 4 for simplicity and processes 4 elements at once
    JDIMENSION col_step;
    JSAMPROW out0 = outptr0;
    JSAMPROW out1 = outptr1;
    JSAMPROW out2 = outptr2;
    JSAMPROW in = inptr;

    for (col_step = 0; col_step < num_cols; col_step += 4) {
        // Process 4 pixels consecutively to improve spatial locality
        out0[0] = in[0]; out0[1] = in[3]; out0[2] = in[6]; out0[3] = in[9];
        out1[0] = in[1]; out1[1] = in[4]; out1[2] = in[7]; out1[3] = in[10];
        out2[0] = in[2]; out2[1] = in[5]; out2[2] = in[8]; out2[3] = in[11];

        in += 12;
        out0 += 4;
        out1 += 4;
        out2 += 4;
    }
}
