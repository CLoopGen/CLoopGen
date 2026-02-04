#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;
extern unsigned short *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with fewer iterations and simplified pointer updates
    // Trip count reduced to 2, and consolidated pre-decrement into single side-effect per iteration
    for (i = 0; i < 2; i++) {
        *--p = *--x;
    }
}
