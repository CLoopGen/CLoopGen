#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *x;
extern word *xM;
extern int i;
extern word Mc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    word *src = &x[Mc];
    word *dst = xM;
    for (i = 0; i <= 12; i++) {
        *dst++ = *src;
        src += 3;
    }
}
