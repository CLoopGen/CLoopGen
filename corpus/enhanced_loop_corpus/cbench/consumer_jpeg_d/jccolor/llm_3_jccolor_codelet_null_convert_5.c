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
// Change to consecutive write and reverse read access pattern
for (ci = 0; ci < nc; ci++) {
    inptr = input_buf[0];
    outptr = output_buf[ci][output_row];
    // Access input buffer in reverse order for each component
    for (col = 0; col < num_cols; col++) {
        JDIMENSION rev_index = (num_cols - 1 - col) * nc + ci;
        outptr[col] = inptr[rev_index];
    }
}
}
