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
    if ((wsptr[1] | wsptr[3] | wsptr[5] | wsptr[7]) == 0) {
        JSAMPLE dcval = range_limit[(int)((((INT32)wsptr[0]) + (((INT32)1) << ((2 + 3) - 1))) >> (2 + 3)) & (255 * 4 + 3)];
        outptr[0] = dcval;
        outptr[1] = dcval;
        wsptr += 8;
        continue;
    }
    tmp10 = ((INT32)wsptr[0]) << (13 + 2);
    tmp0 = (((INT32)wsptr[7]) * (-((INT32)5906))) + (((INT32)wsptr[5]) * (((INT32)6967))) + (((INT32)wsptr[3]) * (-((INT32)10426))) + (((INT32)wsptr[1]) * (((INT32)29692)));
    outptr[0] = range_limit[(int)(((tmp10 + tmp0) + (((INT32)1) << ((13 + 2 + 3 + 2) - 1))) >> (13 + 2 + 3 + 2)) & (255 * 4 + 3)];
    outptr[1] = range_limit[(int)(((tmp10 - tmp0) + (((INT32)1) << ((13 + 2 + 3 + 2) - 1))) >> (13 + 2 + 3 + 2)) & (255 * 4 + 3)];
    wsptr += 8;
}

}
