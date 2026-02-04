#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < 6 - 2; i++) {
        temp += *x;      // Introduce RAW dependency: read before write
        *x++ = temp;     // WAW with previous write to *x, and loop-carried dependence via temp
        temp = 0;        // Reset temp, but dependence still carried through loop iterations
    }
}
