#include <stdio.h>

#include <inttypes.h>

extern int len;
extern int i;
extern int *hit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    for (i = len; i >= 1; i--)
        hit[i] = 0;
}
