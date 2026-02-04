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
for (ctr = 0; ctr < 1; ctr++) {
    for (int block = 0; block < 2; block++) {
        outptr = output_buf[ctr] + output_col + (block * 4);
        if ((wsptr[1] | wsptr[3] | wsptr[5] | wsptr[7]) == 0 && 
            (wsptr[9] | wsptr[11] | wsptr[13] | wsptr[15]) == 0) {
            JSAMPLE dcval = range_limit[(int)((((INT32)wsptr[0]) + (((INT32)1) << (4))) >> 5) & (255 * 4 + 3)];
            for (int i = 0; i < 8; i++) {
                outptr[i] = dcval;
            }
            wsptr += 16;
        } else {
            for (int k = 0; k < 8; k += 2) {
                tmp10 = ((INT32)wsptr[k]) << 15;
                tmp0 = (((INT32)wsptr[k+7%8]) * (-5906)) + 
                       (((INT32)wsptr[k+5%8]) * 6967) + 
                       (((INT32)wsptr[k+3%8]) * (-10426)) + 
                       (((INT32)wsptr[k+1%8]) * 29692);
                outptr[k]   = range_limit[(int)(((tmp10 + tmp0) + (1 << 17)) >> 18) & (255 * 4 + 3)];
                outptr[k+1] = range_limit[(int)(((tmp10 - tmp0) + (1 << 17)) >> 18) & (255 * 4 + 3)];
            }
            wsptr += 16;
        }
    }
}
}
