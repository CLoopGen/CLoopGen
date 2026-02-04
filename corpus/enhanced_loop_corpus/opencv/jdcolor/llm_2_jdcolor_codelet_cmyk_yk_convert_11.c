#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern INT32 y;
extern INT32 *Rytab;
extern INT32 *Gytab;
extern INT32 *Bytab;
extern JSAMPROW outptr;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JSAMPROW inptr3;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    JSAMPROW local_inptr0 = inptr0;
    JSAMPROW local_inptr1 = inptr1;
    JSAMPROW local_inptr2 = inptr2;
    JSAMPROW local_inptr3 = inptr3;
    JSAMPROW local_outptr = outptr;
    
    for (col = 0; col < num_cols; col++) {
        y = Rytab[255 - ((int)(*local_inptr0))];
        y += Gytab[255 - ((int)(*local_inptr1))];
        y += Bytab[255 - ((int)(*local_inptr2))];
        *local_outptr++ = (JSAMPLE)(y >> 16);
        *local_outptr++ = *local_inptr3;
        
        local_inptr0++;
        local_inptr1++;
        local_inptr2++;
        local_inptr3++;
    }
    outptr = local_outptr; // update global if needed by caller
}
