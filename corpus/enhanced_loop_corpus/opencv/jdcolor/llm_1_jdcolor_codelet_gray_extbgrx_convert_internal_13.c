#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; col < num_cols; col += 2) {
        for (JDIMENSION step = 0; step < 2; step++) { // Unroll original logic into inner loop handling two elements
            JDIMENSION current_col = col + step;
            if (current_col < num_cols) {
                outptr[2] = outptr[1] = outptr[0] = inptr[current_col];
                outptr[3] = 255;
                outptr += 4;
            }
        }
    }
}
