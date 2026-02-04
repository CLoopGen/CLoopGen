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
for (ctr = 0; ctr < 4; ctr++) {
    outptr = output_buf[ctr % 2] + output_col;
    tmp10 = ((INT32)wsptr[0]) << (13 + 2);
    tmp0 = (((INT32)wsptr[7]) * (-((INT32)5906))) + 
           (((INT32)wsptr[5]) * (((INT32)6967))) + 
           (((INT32)wsptr[3]) * (-((INT32)10426))) + 
           (((INT32)wsptr[1]) * (((INT32)29692)));
    INT32 sum = tmp10 + tmp0;
    INT32 diff = tmp10 - tmp0;
    JSAMPLE val0 = range_limit[(int)((sum + (((INT32)1) << (17))) >> 18) & (255 * 4 + 3)];
    JSAMPLE val1 = range_limit[(int)((diff + (((INT32)1) << (17))) >> 18) & (255 * 4 + 3)];
    outptr[0] = val0;
    outptr[1] = val1;
    outptr[2] = val1;
    outptr[3] = val0;
    wsptr += 8;
}
}
