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
extern JSAMPROW outptr3;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; col < num_cols * 4; col++) {
        JDIMENSION index = col / 4;
        JDIMENSION offset = col % 4;
        JSAMPROW outptrs[4] = {outptr0, outptr1, outptr2, outptr3};
        if (index < num_cols) {
            outptrs[offset][index] = *inptr++;
        }
    }
}
