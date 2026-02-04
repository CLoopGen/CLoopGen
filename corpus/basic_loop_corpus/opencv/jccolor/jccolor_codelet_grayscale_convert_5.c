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
for (count = num_cols; count > 0; count--) {
    *outptr++ = *inptr;
    inptr += instride;
}

}
