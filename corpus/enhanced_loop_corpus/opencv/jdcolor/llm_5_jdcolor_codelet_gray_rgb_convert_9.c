#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW outptr;
extern JSAMPROW inptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; col < num_cols; col++) {
        outptr[0] = inptr[col];
        outptr[1] = (col % 2 == 0) ? inptr[col] : (inptr[col] + 1);
        outptr[2] = (col % 3 == 0) ? inptr[col] : (inptr[col] - 1);
        outptr += 3;
    }
}
