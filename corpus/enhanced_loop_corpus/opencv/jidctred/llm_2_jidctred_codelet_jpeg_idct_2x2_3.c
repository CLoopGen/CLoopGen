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
for (ctr = 0; ctr < 2; ctr++) {
    outptr = output_buf[ctr] + output_col;
    int offset = ctr * 8; // Strided access pattern: each iteration accesses a block of 8 in wsptr with stride based on ctr
    if (wsptr[offset + 1] == 0 && wsptr[offset + 3] == 0 && wsptr[offset + 5] == 0 && wsptr[offset + 7] == 0) {
        JSAMPLE dcval = range_limit[(int)((((JLONG)wsptr[offset]) + (((JLONG)1) << ((1 + 3) - 1))) >> (1 + 3)) & (255 * 4 + 3)];
        outptr[0] = dcval;
        outptr[1] = dcval;
        continue;
    }
    tmp10 = ((JLONG)((unsigned long)((JLONG)wsptr[offset]) << (13 + 2)));
    tmp0 = (((JLONG)wsptr[offset + 7]) * (-((JLONG)5906))) + (((JLONG)wsptr[offset + 5]) * (((JLONG)6967))) + (((JLONG)wsptr[offset + 3]) * (-((JLONG)10426))) + (((JLONG)wsptr[offset + 1]) * (((JLONG)29692)));
    outptr[0] = range_limit[(int)(((tmp10 + tmp0) + (((JLONG)1) << ((13 + 1 + 3 + 2) - 1))) >> (13 + 1 + 3 + 2)) & (255 * 4 + 3)];
    outptr[1] = range_limit[(int)(((tmp10 - tmp0) + (((JLONG)1) << ((13 + 1 + 3 + 2) - 1))) >> (13 + 1 + 3 + 2)) & (255 * 4 + 3)];
}
}
