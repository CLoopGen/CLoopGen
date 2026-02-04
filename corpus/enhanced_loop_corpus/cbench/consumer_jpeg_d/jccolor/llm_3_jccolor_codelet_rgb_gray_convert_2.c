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
    // Variant 2: Strided memory access - process every 4th pixel (unrolled-like pattern) with stride handling
    JDIMENSION stride = 4;
    JDIMENSION remainder = num_cols % stride;
    INT32 temp_r, temp_g, temp_b;

    // Full strides
    for (col = 0; col < num_cols - remainder; col += stride) {
        temp_r = (int)(inptr[col * 3 + 0]);
        temp_g = (int)(inptr[col * 3 + 1]);
        temp_b = (int)(inptr[col * 3 + 2]);
        outptr[col] = (JSAMPLE)((ctab[temp_r] + ctab[temp_g + 256] + ctab[temp_b + 512]) >> 16);

        temp_r = (int)(inptr[(col+1) * 3 + 0]);
        temp_g = (int)(inptr[(col+1) * 3 + 1]);
        temp_b = (int)(inptr[(col+1) * 3 + 2]);
        outptr[col+1] = (JSAMPLE)((ctab[temp_r] + ctab[temp_g + 256] + ctab[temp_b + 512]) >> 16);

        temp_r = (int)(inptr[(col+2) * 3 + 0]);
        temp_g = (int)(inptr[(col+2) * 3 + 1]);
        temp_b = (int)(inptr[(col+2) * 3 + 2]);
        outptr[col+2] = (JSAMPLE)((ctab[temp_r] + ctab[temp_g + 256] + ctab[temp_b + 512]) >> 16);

        temp_r = (int)(inptr[(col+3) * 3 + 0]);
        temp_g = (int)(inptr[(col+3) * 3 + 1]);
        temp_b = (int)(inptr[(col+3) * 3 + 2]);
        outptr[col+3] = (JSAMPLE)((ctab[temp_r] + ctab[temp_g + 256] + ctab[temp_b + 512]) >> 16);
    }

    // Handle remaining elements
    for (; col < num_cols; col++) {
        r = ((int)(inptr[col * 3 + 0]));
        g = ((int)(inptr[col * 3 + 1]));
        b = ((int)(inptr[col * 3 + 2]));
        outptr[col] = (JSAMPLE)((ctab[r] + ctab[g + 256] + ctab[b + 512]) >> 16);
    }
}
