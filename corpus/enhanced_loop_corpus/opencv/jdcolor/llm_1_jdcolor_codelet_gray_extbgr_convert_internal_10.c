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
    JDIMENSION outer_col;
    JDIMENSION inner_col;
    for (outer_col = 0; outer_col < num_cols; outer_col++) {
        for (inner_col = 0; inner_col < 1; inner_col++) {
            col = outer_col;
            outptr[2] = outptr[1] = outptr[0] = inptr[col];
            outptr += 3;
        }
    }
}
