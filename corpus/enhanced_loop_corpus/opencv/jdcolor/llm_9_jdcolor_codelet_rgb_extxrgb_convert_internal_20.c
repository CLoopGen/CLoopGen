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
    for (col = 0; col < num_cols; col++) {
        JDIMENSION idx = col * 3;
        outptr[1] = (inptr0[idx % num_cols] + inptr0[(idx + 1) % num_cols] + inptr0[(idx + 2) % num_cols]) / 3;
        outptr[2] = (inptr1[idx % num_cols] + inptr1[(idx + 1) % num_cols] + inptr1[(idx + 2) % num_cols]) / 3;
        outptr[3] = (inptr2[idx % num_cols] + inptr2[(idx + 1) % num_cols] + inptr2[(idx + 2) % num_cols]) / 3;
        outptr[0] = 255;
        outptr += 4;
    }
}
