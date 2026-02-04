#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int top;
extern unsigned long *cdp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    for (i = top - 1; i >= 0; i--)
        cdp[i] = 0;
}
