#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef JSAMPARRAY *JSAMPIMAGE;

typedef unsigned int JDIMENSION;

extern JSAMPARRAY input_buf;
extern JSAMPIMAGE output_buf;
extern JDIMENSION output_row;
extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION count;
extern int num_comps;
extern JDIMENSION num_cols;
extern int ci;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JSAMPROW outptr_local[4]; 
    JSAMPROW inptr_local[4];
    JDIMENSION nc = num_comps > 4 ? 4 : num_comps;

    for (ci = 0; ci < nc; ci++) {
        inptr_local[ci] = input_buf[0] + ci;
        outptr_local[ci] = output_buf[ci][output_row];
    }

    for (count = num_cols; count > 0; count--) {
        for (ci = 0; ci < nc; ci++) {
            outptr_local[ci][count - 1] = *inptr_local[ci];
            inptr_local[ci] += num_comps;
        }
    }

    for (; ci < num_comps; ci++) {
        inptr = input_buf[0] + ci;
        outptr = output_buf[ci][output_row];
        for (count = num_cols; count > 0; count--) {
            *outptr++ = *inptr;
            inptr += num_comps;
        }
    }
}
