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
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_col = 0;
    while (local_col < num_cols) {
        int r_val = ((int)(inptr[local_col * 3 + 0]));
        int g_val = ((int)(inptr[local_col * 3 + 1]));
        int b_val = ((int)(inptr[local_col * 3 + 2]));
        outptr[local_col] = (JSAMPLE)((ctab[r_val + 0] + ctab[g_val + (1 * (255 + 1))] + ctab[b_val + (2 * (255 + 1))]) >> 16);
        local_col++;
    }
}
