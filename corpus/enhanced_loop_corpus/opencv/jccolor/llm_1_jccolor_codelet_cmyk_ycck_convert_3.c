#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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
    JDIMENSION stride = (num_cols + 3) / 4;
    for (col = 0; col < stride; col++) {
        JDIMENSION base_col;
        for (base_col = 0; base_col < num_cols; base_col += stride) {
            JDIMENSION current_col = base_col + col;
            if (current_col >= num_cols) continue;

            JSAMPROW local_inptr = inptr + current_col * 4;
            r = 255 - ((int)(local_inptr[0]));
            g = 255 - ((int)(local_inptr[1]));
            b = 255 - ((int)(local_inptr[2]));

            outptr3[current_col] = local_inptr[3];
            outptr0[current_col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (255 + 1))] + ctab[b + (2 * (255 + 1))]) >> 16);
            outptr1[current_col] = (JSAMPLE)((ctab[r + (3 * (255 + 1))] + ctab[g + (4 * (255 + 1))] + ctab[b + (5 * (255 + 1))]) >> 16);
            outptr2[current_col] = (JSAMPLE)((ctab[r + (5 * (255 + 1))] + ctab[g + (6 * (255 + 1))] + ctab[b + (7 * (255 + 1))]) >> 16);
        }
    }
}
