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
    JDIMENSION i;
    JSAMPROW local_inptr = inptr;
    JSAMPROW local_outptr = outptr;
    for (i = 0; i < num_cols; i++) {
        *local_outptr = *local_inptr;
        local_inptr += instride;
        local_outptr++;
    }
    outptr = local_outptr;
}
