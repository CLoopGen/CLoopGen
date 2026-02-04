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
    for (i = 0; i < len; i++) {
        inext = (inext + 1) & 55; // Bitwise masking to replace conditional wrap-around (assumes 55 is power-of-two minus one, close behavior)
        inextp = (inextp + 1) % 55; // Use modulo instead of conditional for variety in control flow
        lval = mrand_list[inext] - mrand_list[inextp];
        lval += (lval < 0L) ? 9223372036854775807L : 0L; // Replace if with conditional expression
        mrand_list[inext] = lval;
        a[i] = (double)lval * factor;
    }
}
