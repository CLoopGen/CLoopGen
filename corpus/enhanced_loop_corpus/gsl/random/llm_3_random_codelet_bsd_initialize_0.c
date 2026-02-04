#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long *x;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse Consecutive Memory Access Pattern
    // Traverse the array in reverse order, maintaining dependency on previous element.
    // This changes the access pattern to reverse sequential.
    for (i = n - 1; i >= 1; i--)
        x[i] = 1103515245 * x[i - 1] + 12345;
}
