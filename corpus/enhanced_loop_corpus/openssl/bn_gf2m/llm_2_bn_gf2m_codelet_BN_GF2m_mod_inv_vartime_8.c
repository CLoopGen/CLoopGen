#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int top;
extern unsigned long *cdp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < top; i += 2)
        cdp[i] = 0;
}
