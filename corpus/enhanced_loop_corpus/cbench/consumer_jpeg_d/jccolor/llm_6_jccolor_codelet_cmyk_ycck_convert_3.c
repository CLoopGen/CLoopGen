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
extern JSAMPROW outptr3;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT32 temp_r[4], temp_g[4], temp_b[4];
    for (col = 0; col < num_cols; col++) {
        r = 255 - ((int)(inptr[0]));
        g = 255 - ((int)(inptr[1]));
        b = 255 - ((int)(inptr[2]));
        outptr3[col] = inptr[3];
        
        temp_r[0] = ctab[r + 0];
        temp_g[0] = ctab[g + (1 * (256))];
        temp_b[0] = ctab[b + (2 * (256))];
        
        temp_r[1] = ctab[r + (3 * 256)];
        temp_g[1] = ctab[g + (4 * 256)];
        temp_b[1] = ctab[b + (5 * 256)];
        
        temp_r[2] = ctab[r + (5 * 256)];
        temp_g[2] = ctab[g + (6 * 256)];
        temp_b[2] = ctab[b + (7 * 256)];

        outptr0[col] = (JSAMPLE)((temp_r[0] + temp_g[0] + temp_b[0]) >> 16);
        outptr1[col] = (JSAMPLE)((temp_r[1] + temp_g[1] + temp_b[1]) >> 16);
        outptr2[col] = (JSAMPLE)((temp_r[2] + temp_g[2] + temp_b[2]) >> 16);

        inptr += 4;
    }
}
