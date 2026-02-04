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
    JDIMENSION temp_cols = (num_cols + 2) / 3; // Reduce effective iterations by processing in chunks conceptually, though logic adjusted to maintain correctness
    for (col = 0; col < temp_cols; col++) {
        JDIMENSION base = col * 3;
        if (base < num_cols) {
            outptr[0] = outptr[1] = outptr[2] = inptr[base];
            outptr += 3;
        }
        if (base + 1 < num_cols) {
            outptr[0] = outptr[1] = outptr[2] = inptr[base + 1];
            outptr += 3;
        }
        if (base + 2 < num_cols) {
            outptr[0] = outptr[1] = outptr[2] = inptr[base + 2];
            outptr += 3;
        }
    }
}
