#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern int r;
extern int g;
extern int b;
extern JLONG *ctab;
extern JSAMPROW inptr;
extern JSAMPROW outptr0;
extern JSAMPROW outptr1;
extern JSAMPROW outptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JSAMPROW local_inptr = inptr;
    JSAMPROW local_out0 = outptr0;
    JSAMPROW local_out1 = outptr1;
    JSAMPROW local_out2 = outptr2;
    const int shift = 255 + 1;
    for (col = 0; col < num_cols; col += 2) {
        // Process two pixels per iteration with strided memory access
        r = local_inptr[3]; g = local_inptr[2]; b = local_inptr[1];
        int r_next = local_inptr[7], g_next = local_inptr[6], b_next = local_inptr[5];

        local_inptr += 8; // Advance by 8 bytes (2 RGBA pixels)

        // First pixel
        local_out0[0] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * shift)] + ctab[b + (2 * shift)]) >> 16);
        local_out1[0] = (JSAMPLE)((ctab[r + (3 * shift)] + ctab[g + (4 * shift)] + ctab[b + (5 * shift)]) >> 16);
        local_out2[0] = (JSAMPLE)((ctab[r + (5 * shift)] + ctab[g + (6 * shift)] + ctab[b + (7 * shift)]) >> 16);

        // Second pixel
        if (col + 1 < num_cols) {
            local_out0[1] = (JSAMPLE)((ctab[r_next + 0] + ctab[g_next + (1 * shift)] + ctab[b_next + (2 * shift)]) >> 16);
            local_out1[1] = (JSAMPLE)((ctab[r_next + (3 * shift)] + ctab[g_next + (4 * shift)] + ctab[b_next + (5 * shift)]) >> 16);
            local_out2[1] = (JSAMPLE)((ctab[r_next + (5 * shift)] + ctab[g_next + (6 * shift)] + ctab[b_next + (7 * shift)]) >> 16);
        }

        local_out0 += 2;
        local_out1 += 2;
        local_out2 += 2;
    }
}
