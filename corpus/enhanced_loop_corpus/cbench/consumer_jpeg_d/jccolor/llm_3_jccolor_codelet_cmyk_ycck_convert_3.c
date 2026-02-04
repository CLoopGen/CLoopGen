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
    JSAMPROW local_inptr = inptr;
    JSAMPROW planes[4] = {outptr0, outptr1, outptr2, outptr3};
    const int offsets[3][3] = {
        {0, 1 * (255 + 1), 2 * (255 + 1)},
        {3 * (255 + 1), 4 * (255 + 1), 5 * (255 + 1)},
        {5 * (255 + 1), 6 * (255 + 1), 7 * (255 + 1)}
    };
    for (col = 0; col < num_cols; col++) {
        r = 255 - ((int)(local_inptr[0]));
        g = 255 - ((int)(local_inptr[1]));
        b = 255 - ((int)(local_inptr[2]));
        planes[3][col] = local_inptr[3];
        local_inptr += 4;
        for (int i = 0; i < 3; i++) {
            INT32 sum = ctab[r + offsets[i][0]] + ctab[g + offsets[i][1]] + ctab[b + offsets[i][2]];
            planes[i][col] = (JSAMPLE)(sum >> 16);
        }
    }
}
