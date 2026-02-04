#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *z__;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed iteration
    // Instead of accessing z__ with strided pattern (every other element), 
    // rewrite to write consecutive pairs in reverse order.
    integer idx = (*n << 1) * 2;
    for (k = *n << 1; k >= 2; k -= 2) {
        z__[idx]     = 0.F;
        z__[idx - 1] = z__[k];
        z__[idx - 2] = 0.F;
        z__[idx - 3] = z__[k - 1];
        idx -= 4;
    }
}
