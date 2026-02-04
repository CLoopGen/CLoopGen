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
    long temp;
    for (i = 0; i < len; i++) {
        inext = (inext >= 54) ? 0 : inext + 1;
        inextp = (inextp >= 54) ? 0 : inextp + 1;
        temp = mrand_list[inext] - mrand_list[inextp];
        if (temp < 0L)
            temp += 9223372036854775807L;
        mrand_list[inext] = temp;
        a[i] = (double)temp * factor;
        lval = temp; // Update lval only after computation, removing direct use in dependency chain
    }
}
