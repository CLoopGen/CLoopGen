#include <stdio.h>

#include <inttypes.h>

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
extern JDIMENSION col;
extern int ci;
extern int nc;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ci = 0; ci < nc; ci += 2) { // Process two components per iteration
    JSAMPROW outptr0 = output_buf[ci][output_row];
    JSAMPROW outptr1 = (ci + 1 < nc) ? output_buf[ci+1][output_row] : NULL;
    inptr = *input_buf;
    for (col = 0; col < num_cols; col++) {
        outptr0[col] = inptr[ci];
        if (ci + 1 < nc) {
            outptr1[col] = inptr[ci+1];
        }
        inptr += nc;
    }
}
}
