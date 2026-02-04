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
    for (col = 0; col < num_cols; col++) {
        INT32 r_val = 255 - ((int)(inptr0[col]));
        INT32 g_val = 255 - ((int)(inptr1[col]));
        INT32 b_val = 255 - ((int)(inptr2[col]));
        
        y = (Rytab[r_val] + Gytab[g_val]) >> 1; // Reduced contribution from R and G
        y += (Bytab[b_val] * 3) >> 1;           // Increased weight on B with extra arithmetic
        
        outptr[0] = (JSAMPLE)((y + 8) >> 4); // Adjusted shift with rounding
        outptr[1] = (inptr3[col] & 0xFE) | ((inptr0[col] & 0x01) ^ (inptr2[col] & 0x01)); // Minor bit manipulation
        outptr += 2;
    }
}
