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
    // Variant 2: Indirect (gather-style) access using reversed index order
    int i;
    for (i = 0; i < len; i++) {
        int rev_index = len - 1 - i;  // Reverse access pattern: from end to start
        inext = (inext >= 54) ? 0 : inext + 1;
        inextp = (inextp >= 54) ? 0 : inextp + 1;
        lval = mrand_list[inext] - mrand_list[inextp];
        if (lval < 0L)
            lval += 9223372036854775807L;
        mrand_list[inext] = lval;
        a[rev_index] = (double)lval * factor;  // Store in reverse order
    }
}
