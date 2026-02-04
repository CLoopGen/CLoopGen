#include <stdio.h>

#include <inttypes.h>

extern int m;
extern double p[1900];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access pattern
    // Traverse the array in reverse order while maintaining one-to-one mapping
    for (i = 0; i < m; i++) {
        int index = m - 1 - i; // Reverse indexing
        p[index] = (double)(i % m) / m;
    }
}
