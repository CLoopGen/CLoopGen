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
    JDIMENSION col_even, col_odd;
    JDIMENSION half_cols = num_cols / 2;

    for (col_even = 0; col_even < half_cols; col_even++) {
        JDIMENSION base_col = col_even * 2;
        JSAMPROW local_inptr = inptr + (base_col * 4);

        r = 255 - ((int)(local_inptr[0]));
        g = 255 - ((int)(local_inptr[1]));
        b = 255 - ((int)(local_inptr[2]));

        outptr3[base_col] = local_inptr[3];
        outptr0[base_col] = (JSAMPLE)((ctab[r + 0] + ctab[g + 256] + ctab[b + 512]) >> 16);
        outptr1[base_col] = (JSAMPLE)((ctab[r + 768] + ctab[g + 1024] + ctab[b + 1280]) >> 16);
        outptr2[base_col] = (JSAMPLE)((ctab[r + 1280] + ctab[g + 1536] + ctab[b + 1792]) >> 16);

        if (base_col + 1 < num_cols) {
            r = 255 - ((int)(local_inptr[4]));
            g = 255 - ((int)(local_inptr[5]));
            b = 255 - ((int)(local_inptr[6]));

            outptr3[base_col + 1] = local_inptr[7];
            outptr0[base_col + 1] = (JSAMPLE)((ctab[r + 0] + ctab[g + 256] + ctab[b + 512]) >> 16);
            outptr1[base_col + 1] = (JSAMPLE)((ctab[r + 768] + ctab[g + 1024] + ctab[b + 1280]) >> 16);
            outptr2[base_col + 1] = (JSAMPLE)((ctab[r + 1280] + ctab[g + 1536] + ctab[b + 1792]) >> 16);
        }
    }

    col = num_cols; 
}
