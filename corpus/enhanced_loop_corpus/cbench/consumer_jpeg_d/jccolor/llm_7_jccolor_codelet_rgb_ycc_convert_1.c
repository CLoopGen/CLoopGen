#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern int r;
extern int g;
extern int b;
extern INT32 *ctab;
extern JSAMPROW inptr;
extern JSAMPROW outptr0;
extern JSAMPROW outptr1;
extern JSAMPROW outptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT32 r_val, g_val, b_val;
    for (col = 0; col < num_cols; col++) {
        r_val = ctab[((int)(inptr[0])) + 0];
        g_val = ctab[((int)(inptr[1])) + (1 * (255 + 1))];
        b_val = ctab[((int)(inptr[2])) + (2 * (255 + 1))];
        inptr += 3;
        outptr0[col] = (JSAMPLE)((r_val + g_val + b_val) >> 16);
        
        r_val = ctab[((int)(inptr[-3])) + (3 * (255 + 1))];
        g_val = ctab[((int)(inptr[-2])) + (4 * (255 + 1))];
        b_val = ctab[((int)(inptr[-1])) + (5 * (255 + 1))];
        outptr1[col] = (JSAMPLE)((r_val + g_val + b_val) >> 16);
        
        r_val = ctab[((int)(inptr[-3])) + (5 * (255 + 1))];
        g_val = ctab[((int)(inptr[-2])) + (6 * (255 + 1))];
        b_val = ctab[((int)(inptr[-1])) + (7 * (255 + 1))];
        outptr2[col] = (JSAMPLE)((r_val + g_val + b_val) >> 16);
    }
}
