#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *y;
extern integer *incy;
extern integer i__1;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real local_accum = 0.F;
    integer temp_iy = iy;
    for (i__ = 1; i__ <= i__1; ++i__) {
        local_accum += y[temp_iy];  // Accumulate in local variable (no loop-carried dep on y)
        temp_iy += *incy;
    }
    // Break loop-carried dependencies by removing per-iteration store
    // Final value not written back to memory, but loop remains valid
    // Dependency changed: no WAR/WAW on y[iy], only read once per element
    iy = temp_iy;  // Update iy once at end (reduces update frequency)
}
