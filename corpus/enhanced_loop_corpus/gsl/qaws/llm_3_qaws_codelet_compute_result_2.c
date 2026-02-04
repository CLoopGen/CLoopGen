#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *r;
extern  double *cheb24;
extern size_t i;
extern double res24;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access — traverse arrays from last to first element
    for (i = 24; ; i--) {
        res24 += r[i] * cheb24[i];
        if (i == 0) break;
    }
}
