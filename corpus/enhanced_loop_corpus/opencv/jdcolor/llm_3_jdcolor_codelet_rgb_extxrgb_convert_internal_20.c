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
JSAMPROW local_inptr0 = inptr0;
JSAMPROW local_inptr1 = inptr1;
JSAMPROW local_inptr2 = inptr2;
JSAMPROW local_outptr = outptr;
JDIMENSION stride = 4;
for (col = 0; col < num_cols; col++) {
    *(local_outptr + 1) = *local_inptr0++;
    *(local_outptr + 2) = *local_inptr1++;
    *(local_outptr + 3) = *local_inptr2++;
    *(local_outptr + 0) = 255;
    local_outptr += stride;
}
}
