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
    JLONG temp_sum = 0;
    int skip_computation = 0;
    for (int i = 1; i <= 7; i += 2) {
        if (wsptr[i] != 0) {
            temp_sum += ((JLONG)wsptr[i]) * (i == 1 ? 29692 : (i == 3 ? -10426 : (i == 5 ? 6967 : -5906)));
        } else {
            if (i == 1 || i == 3 || i == 5 || i == 7) continue;
        }
        if (wsptr[1] == 0 && wsptr[3] == 0 && wsptr[5] == 0 && wsptr[7] == 0) {
            skip_computation = 1;
        }
    }
    if (skip_computation) {
        JSAMPLE dcval = range_limit[(int)((((JLONG)wsptr[0]) + (((JLONG)1) << ((1 + 3) - 1))) >> (1 + 3)) & (255 * 4 + 3)];
        outptr[0] = dcval;
        outptr[1] = dcval;
        wsptr += 8;
        continue;
    }
    tmp10 = ((JLONG)((unsigned long)((JLONG)wsptr[0]) << (13 + 2)));
    tmp0 = temp_sum;
    outptr[0] = range_limit[(int)(((tmp10 + tmp0) + (((JLONG)1) << ((13 + 1 + 3 + 2) - 1))) >> (13 + 1 + 3 + 2)) & (255 * 4 + 3)];
    outptr[1] = range_limit[(int)(((tmp10 - tmp0) + (((JLONG)1) << ((13 + 1 + 3 + 2) - 1))) >> (13 + 1 + 3 + 2)) & (255 * 4 + 3)];
    wsptr += 8;
}
}
