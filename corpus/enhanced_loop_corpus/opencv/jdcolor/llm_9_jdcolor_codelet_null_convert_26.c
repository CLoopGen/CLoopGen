#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef JSAMPARRAY *JSAMPIMAGE;

typedef unsigned int JDIMENSION;

extern JSAMPIMAGE input_buf;
extern JDIMENSION input_row;
extern JSAMPARRAY output_buf;
extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern int num_components;
extern JDIMENSION num_cols;
extern int ci;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ci = 0; ci < num_components && ci < 2; ci++) { // Reduced trip count with early bound limit
    inptr = input_buf[ci][input_row];
    outptr = *output_buf;
    for (col = 0; col < num_cols; col += 2) { // Strided iteration: process every second column
        outptr[ci] = inptr[col];
        if (col + 1 < num_cols) {
            outptr[num_components] = inptr[col + 1]; // Additional write to increase data movement
        }
        outptr += 2 * num_components;
    }
}
}
