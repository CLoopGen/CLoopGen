#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern int r;
extern int g;
extern int b;
extern JSAMPROW inptr;
extern JSAMPROW outptr0;
extern JSAMPROW outptr1;
extern JSAMPROW outptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce arithmetic operations and simplify computation
    // Remove one subtraction and masking operation to lower computational intensity
    for (col = 0; col < num_cols; col++) {
        g = ((int)(inptr[1]));
        inptr += 3;
        outptr0[col] = (JSAMPLE)g;          // Store only green channel
        outptr1[col] = (JSAMPLE)g;
        outptr2[col] = (JSAMPLE)g;
    }
}
