#include <stdio.h>

#include <inttypes.h>

extern unsigned long *dst;
extern  unsigned long *src;
extern int top;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access from end to beginning
    for (i = top - 1; i >= 0; i--)
        dst[i] = src[i];
}
