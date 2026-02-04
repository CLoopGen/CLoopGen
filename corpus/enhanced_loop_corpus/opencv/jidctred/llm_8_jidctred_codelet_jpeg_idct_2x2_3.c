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
for (ctr = 0; ctr < 4; ctr++) {
    outptr = output_buf[ctr % 2] + output_col;
    tmp10 = ((JLONG)((unsigned long)((JLONG)wsptr[0]) << (13 + 2)));
    tmp0 = (((JLONG)wsptr[7]) * (-((JLONG)5906))) + 
           (((JLONG)wsptr[5]) * (((JLONG)6967))) + 
           (((JLONG)wsptr[3]) * (-((JLONG)10426))) + 
           (((JLONG)wsptr[1]) * (((JLONG)29692)));
    JSAMPLE val0 = range_limit[(int)(((tmp10 + tmp0) + (((JLONG)1) << ((13 + 1 + 3 + 2) - 1))) >> (13 + 1 + 3 + 2)) & (255 * 4 + 3)];
    JSAMPLE val1 = range_limit[(int)(((tmp10 - tmp0) + (((JLONG)1) << ((13 + 1 + 3 + 2) - 1))) >> (13 + 1 + 3 + 2)) & (255 * 4 + 3)];
    outptr[0] = val0;
    outptr[1] = val1;
    outptr[2] = val1;
    outptr[3] = val0;
    wsptr += 8;
}
}
