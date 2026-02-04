#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long *x;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access with offset
    // Traverse array from near the end to beginning with reverse dependency flow
    for (i = n - 2; i >= 1; i--)
        x[i] = 1103515145 * x[i + 1] + 12345;
}
