#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long INT32;

extern JSAMPARRAY output_buf;
extern JDIMENSION output_col;
extern INT32 tmp0;
extern INT32 tmp10;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ctr = 0; ctr < 2; ctr++) {
        outptr = output_buf[ctr] + output_col;
        int idx = ctr * 8; // Strided access pattern: treat wsptr as a 2D block accessed with stride 8
        if ((wsptr[idx + 1] | wsptr[idx + 3] | wsptr[idx + 5] | wsptr[idx + 7]) == 0) {
            JSAMPLE dcval = range_limit[(int)((((INT32)wsptr[idx + 0]) + (((INT32)1) << ((2 + 3) - 1))) >> (2 + 3)) & (255 * 4 + 3)];
            outptr[0] = dcval;
            outptr[1] = dcval;
            continue;
        }
        tmp10 = ((INT32)wsptr[idx + 0]) << (13 + 2);
        tmp0 = (((INT32)wsptr[idx + 7]) * (-((INT32)5906))) + 
               (((INT32)wsptr[idx + 5]) * (((INT32)6967))) + 
               (((INT32)wsptr[idx + 3]) * (-((INT32)10426))) + 
               (((INT32)wsptr[idx + 1]) * (((INT32)29692)));
        outptr[0] = range_limit[(int)(((tmp10 + tmp0) + (((INT32)1) << ((13 + 2 + 3 + 2) - 1))) >> (13 + 2 + 3 + 2)) & (255 * 4 + 3)];
        outptr[1] = range_limit[(int)(((tmp10 - tmp0) + (((INT32)1) << ((13 + 2 + 3 + 2) - 1))) >> (13 + 2 + 3 + 2)) & (255 * 4 + 3)];
    }
}
