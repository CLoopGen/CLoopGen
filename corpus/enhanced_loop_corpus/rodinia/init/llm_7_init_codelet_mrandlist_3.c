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
    int next_inext, next_inextp;
    for (i = 0; i < len; i++) {
        next_inext = (inext >= 54) ? 0 : inext + 1;
        next_inextp = (inextp >= 54) ? 0 : inextp + 1;
        lval = mrand_list[next_inext] - mrand_list[next_inextp];
        if (lval < 0L)
            lval += 9223372036854775807L;
        mrand_list[next_inext] = lval;
        a[i] = (double)lval * factor;
        inext = next_inext;   // Update state variables after all uses (removes WAW and WAR hazards)
        inextp = next_inextp;
    }
}
