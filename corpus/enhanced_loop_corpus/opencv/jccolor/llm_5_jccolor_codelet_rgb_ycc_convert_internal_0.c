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
    for (col = 0; col < num_cols; col++) {
        r = (inptr[0]);
        g = (inptr[1]);
        b = (inptr[2]);
        inptr += 3;

        int process_red = (r & 1);
        int process_green = (g & 1);
        int valid_blue = (b > 10);

        if (process_red) {
            outptr0[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + 256] + ctab[b + 512]) >> 16);
        } else {
            outptr0[col] = (JSAMPLE)(r & 0xFF);
        }

        if (process_green) {
            outptr1[col] = (JSAMPLE)((ctab[r + 768] + ctab[g + 1024] + ctab[b + 1280]) >> 16);
        } else {
            outptr1[col] = (JSAMPLE)(g ^ 0xFF);
        }

        if (valid_blue) {
            outptr2[col] = (JSAMPLE)((ctab[r + 1280] + ctab[g + 1536] + ctab[b + 1792]) >> 16);
        } else {
            outptr2[col] = (JSAMPLE)0;
        }
    }
}
