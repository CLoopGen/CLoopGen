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
    // Variant 2: Strided memory access - write output with stride of 2, interleaving data
    // Outputs are stored every other position, leaving gaps (stride-2 access)
    JDIMENSION stride_col;
    JSAMPROW in = inptr;
    for (stride_col = 0; stride_col < num_cols; stride_col++) {
        JDIMENSION idx = stride_col * 2; // Stride of 2 in output arrays
        outptr0[idx] = in[0];
        outptr1[idx] = in[1];
        outptr2[idx] = in[2];
        in += 3;
    }
}
