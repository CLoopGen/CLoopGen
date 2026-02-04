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
    for (col = 0; col < num_cols; col++) {
        JDIMENSION idx = col * 2;
        outptr0[idx] = inptr[1] + 1;
        outptr1[idx] = inptr[2] + 2;
        outptr2[idx] = inptr[3] + 3;
        if (idx + 1 < num_cols * 2) {
            outptr0[idx + 1] = inptr[1] ^ 0xFF;
            outptr1[idx + 1] = inptr[2] ^ 0xFF;
            outptr2[idx + 1] = inptr[3] ^ 0xFF;
        }
        inptr += 4;
    }
}
