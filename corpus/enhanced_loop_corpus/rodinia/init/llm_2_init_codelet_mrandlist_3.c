#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long mrand_list[56];
extern int inext;
extern int inextp;
extern double a[];
extern int len;
extern int i;
extern long lval;
extern double factor;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to handle two iterations per loop
    int i;
    for (i = 0; i < len; i += 2) {
        // First element in the stride
        int idx1 = i;
        inext = (inext >= 54) ? 0 : inext + 1;
        inextp = (inextp >= 54) ? 0 : inextp + 1;
        lval = mrand_list[inext] - mrand_list[inextp];
        if (lval < 0L)
            lval += 9223372036854775807L;
        mrand_list[inext] = lval;
        a[idx1] = (double)lval * factor;

        // Second element in the stride (if within bounds)
        if (i + 1 < len) {
            int idx2 = i + 1;
            inext = (inext >= 54) ? 0 : inext + 1;
            inextp = (inextp >= 54) ? 0 : inextp + 1;
            lval = mrand_list[inext] - mrand_list[inextp];
            if (lval < 0L)
                lval += 9223372036854775807L;
            mrand_list[inext] = lval;
            a[idx2] = (double)lval * factor;
        }
    }
}
