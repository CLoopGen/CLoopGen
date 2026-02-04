#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long *x;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing consecutive elements, access every second element.
    // This modifies the memory access pattern to be strided (stride of 2).
    for (i = 2; i < n; i += 2)
        x[i] = 1103515245 * x[i - 2] + 12345;
}
