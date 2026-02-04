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
    // Variant 1: Consecutive memory access with array base offset precomputation
    JSAMPROW row0 = output_buf[0] + output_col;
    JSAMPROW row1 = output_buf[1] + output_col;
    int *wsptr0 = wsptr;
    int *wsptr1 = wsptr + 8;

    for (int i = 0; i < 2; i++) {
        JSAMPROW outptr_local = (i == 0) ? row0 : row1;
        int *wsptr_local = (i == 0) ? wsptr0 : wsptr1;

        if ((wsptr_local[1] | wsptr_local[3] | wsptr_local[5] | wsptr_local[7]) == 0) {
            JSAMPLE dcval = range_limit[(int)((((INT32)wsptr_local[0]) + (((INT32)1) << ((2 + 3) - 1))) >> (2 + 3)) & (255 * 4 + 3)];
            outptr_local[0] = dcval;
            outptr_local[1] = dcval;
            continue;
        }
        tmp10 = ((INT32)wsptr_local[0]) << (13 + 2);
        tmp0 = (((INT32)wsptr_local[7]) * (-((INT32)5906))) + 
               (((INT32)wsptr_local[5]) * (((INT32)6967))) + 
               (((INT32)wsptr_local[3]) * (-((INT32)10426))) + 
               (((INT32)wsptr_local[1]) * (((INT32)29692)));
        outptr_local[0] = range_limit[(int)(((tmp10 + tmp0) + (((INT32)1) << ((13 + 2 + 3 + 2) - 1))) >> (13 + 2 + 3 + 2)) & (255 * 4 + 3)];
        outptr_local[1] = range_limit[(int)(((tmp10 - tmp0) + (((INT32)1) << ((13 + 2 + 3 + 2) - 1))) >> (13 + 2 + 3 + 2)) & (255 * 4 + 3)];
    }
    wsptr += 16; // Advance wsptr by total consumed amount
}
