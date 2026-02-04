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
    JDIMENSION col;
    if (num_cols > 0) {
        for (col = 0; col < num_cols; col++) {
            outptr0[col] = inptr[0];
            outptr1[col] = inptr[1];
            outptr2[col] = inptr[2];
            inptr += 3;
            col++;
            if (col < num_cols) {
                outptr0[col] = inptr[0];
                outptr1[col] = inptr[1];
                outptr2[col] = inptr[2];
                inptr += 3;
            }
        }
    }
}
