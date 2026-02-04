#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t min;
extern  size_t max;
extern  size_t steps;
extern unsigned char codes[8];
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reverse traversal
    // Instead of accessing codes[i+1], we traverse backwards and write in decreasing index order
    // This maintains data dependency but changes spatial locality
    for (i = (ssize_t)steps - 1; i >= 1; i--)
        codes[i + 1] = (unsigned char)((((ssize_t)steps - i) * (ssize_t)min + i * (ssize_t)max) / (ssize_t)steps);
}
