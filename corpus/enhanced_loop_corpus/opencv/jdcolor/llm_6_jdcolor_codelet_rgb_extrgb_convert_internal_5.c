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
    JDIMENSION col8;
    for (col = 0; col < num_cols; col += 8) {
        col8 = col;
        outptr[0] = inptr0[col8];
        outptr[1] = inptr1[col8];
        outptr[2] = inptr2[col8];
        outptr[3] = inptr0[col8 + 1];
        outptr[4] = inptr1[col8 + 1];
        outptr[5] = inptr2[col8 + 1];
        outptr[6] = inptr0[col8 + 2];
        outptr[7] = inptr1[col8 + 2];
        outptr[8] = inptr2[col8 + 2];
        outptr[9] = inptr0[col8 + 3];
        outptr[10] = inptr1[col8 + 3];
        outptr[11] = inptr2[col8 + 3];
        outptr[12] = inptr0[col8 + 4];
        outptr[13] = inptr1[col8 + 4];
        outptr[14] = inptr2[col8 + 4];
        outptr[15] = inptr0[col8 + 5];
        outptr[16] = inptr1[col8 + 5];
        outptr[17] = inptr2[col8 + 5];
        outptr[18] = inptr0[col8 + 6];
        outptr[19] = inptr1[col8 + 6];
        outptr[20] = inptr2[col8 + 6];
        outptr[21] = inptr0[col8 + 7];
        outptr[22] = inptr1[col8 + 7];
        outptr[23] = inptr2[col8 + 7];
        outptr += 24;
    }
}
