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
    JDIMENSION col1;
    for (col = 0; col < num_cols; col++) {
        for (col1 = 0; col1 < 1; col1++) { // Artificially increased nesting depth with a single-iteration inner loop
            outptr[0] = outptr[1] = outptr[2] = inptr[col];
            outptr += 3;
        }
    }
}
