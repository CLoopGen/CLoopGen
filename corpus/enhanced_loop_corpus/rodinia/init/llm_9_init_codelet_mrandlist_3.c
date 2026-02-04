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
    int step = 1;
    for (i = 0; i < len; i += step) {
        inext = (inext >= 54) ? 0 : inext + 1;
        inextp = (inextp >= 54) ? 0 : inextp + 1;
        lval = mrand_list[inext] - mrand_list[inextp];
        lval = (lval < 0L) ? lval + 9223372036854775807L : lval - 1L; // Extra arithmetic operation
        mrand_list[inext] = lval;
        a[i] = ((double)(lval + 1L)) * factor; // Additional arithmetic intensity
        step = 1 + ((lval >> 60) & 1); // Vary effective trip count via adaptive step (still bounded)
    }
}
