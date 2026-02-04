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
    JDIMENSION outer_col, inner_col;
    JDIMENSION block_size = 3;
    JDIMENSION total_elements = num_cols * block_size;
    for (outer_col = 0; outer_col < total_elements; outer_col += block_size) {
        for (inner_col = 0; inner_col < block_size && (outer_col + inner_col) < total_elements; inner_col++) {
            JDIMENSION linear_idx = outer_col + inner_col;
            JDIMENSION col_idx = linear_idx / block_size;
            if (linear_idx % block_size == 0) {
                outptr0[col_idx] = *inptr++;
            } else if (linear_idx % block_size == 1) {
                outptr1[col_idx] = *inptr++;
            } else if (linear_idx % block_size == 2) {
                outptr2[col_idx] = *inptr++;
            }
        }
    }
}
