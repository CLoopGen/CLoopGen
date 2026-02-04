#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long JLONG;

extern JSAMPARRAY output_buf;
extern JDIMENSION output_col;
extern JLONG tmp0;
extern JLONG tmp10;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 1; ctr++) {
    for (int block = 0; block < 2; block++) {
        outptr = output_buf[ctr] + output_col + (block * 4);
        if (wsptr[1] == 0 && wsptr[3] == 0 && wsptr[5] == 0 && wsptr[7] == 0) {
            JSAMPLE dcval = range_limit[(int)((((JLONG)wsptr[0]) + (((JLONG)1) << ((1 + 3) - 1))) >> (1 + 3)) & (255 * 4 + 3)];
            for (int i = 0; i < 4; i++) {
                outptr[i] = dcval;
            }
        } else {
            tmp10 = ((JLONG)((unsigned long)((JLONG)wsptr[0]) << (13 + 2)));
            tmp0 = (((JLONG)wsptr[7]) * (-((JLONG)5906))) + 
                   (((JLONG)wsptr[5]) * (((JLONG)6967))) + 
                   (((JLONG)wsptr[3]) * (-((JLONG)10426))) + 
                   (((JLONG)wsptr[1]) * (((JLONG)29692)));
            JSAMPLE result0 = range_limit[(int)(((tmp10 + tmp0) + (((JLONG)1) << ((13 + 1 + 3 + 2) - 1))) >> (13 + 1 + 3 + 2)) & (255 * 4 + 3)];
            JSAMPLE result1 = range_limit[(int)(((tmp10 - tmp0) + (((JLONG)1) << ((13 + 1 + 3 + 2) - 1))) >> (13 + 1 + 3 + 2)) & (255 * 4 + 3)];
            outptr[0] = result0;
            outptr[1] = result1;
            outptr[2] = result1;
            outptr[3] = result0;
        }
        wsptr += 8;
    }
}
}
