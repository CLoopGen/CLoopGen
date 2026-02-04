#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int top;
extern unsigned long *bdp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access from top-1 down to 1
    for (i = top - 1; i >= 1; i--)
        bdp[i] = 0;
}
