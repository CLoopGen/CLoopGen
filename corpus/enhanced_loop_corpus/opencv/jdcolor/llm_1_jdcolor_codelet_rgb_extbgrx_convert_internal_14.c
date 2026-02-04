#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JDIMENSION temp_col;
    if (num_cols > 0) {
        for (temp_col = 0; temp_col < num_cols; temp_col++) {
            col = temp_col;
            outptr[2] = inptr0[col];
            outptr[1] = inptr1[col];
            outptr[0] = inptr2[col];
            outptr[3] = 255;
            outptr += 4;
        }
    }
}
