#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;
extern int instride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; col < num_cols; col++) {
        if (inptr[0] == 0) {
            outptr[col] = 255; // Replace zero samples with max value
        } else {
            outptr[col] = inptr[0];
        }
        inptr += instride;
    }
}
