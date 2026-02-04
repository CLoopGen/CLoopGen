#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION count;
extern int instride;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
JDIMENSION outer_count;
for (outer_count = num_cols / 2; outer_count > 0; --outer_count) {
    *outptr++ = *inptr;
    inptr += instride;
    if (--count > 0) {
        *outptr++ = *inptr;
        inptr += instride;
        --count;
    }
}
if (count > 0) {
    *outptr++ = *inptr;
}
}
