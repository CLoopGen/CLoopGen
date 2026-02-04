#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *r;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with stride of 2
    for (i = 8; i--; r += 2, *r = 0)
        ;
}
