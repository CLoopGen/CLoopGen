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
for (ci = 0; ci < nc; ci++) {
    inptr = *input_buf;
    outptr = output_buf[ci][output_row];
    col = 0;
    for (; col < num_cols; col++) {
        outptr[col] = inptr[ci];
        inptr += nc;
    }
}
for (; col < num_cols; col++) {
    outptr[col] = inptr[ci];
}
}
