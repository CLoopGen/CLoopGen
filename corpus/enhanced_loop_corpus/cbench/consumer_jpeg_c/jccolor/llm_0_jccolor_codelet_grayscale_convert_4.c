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
    JDIMENSION col1, col2;
    for (col1 = 0; col1 < num_cols; col1++) {
        for (col2 = 0; col2 < 1; col2++) {
            outptr[col1] = inptr[0];
            inptr += instride;
        }
    }
}
