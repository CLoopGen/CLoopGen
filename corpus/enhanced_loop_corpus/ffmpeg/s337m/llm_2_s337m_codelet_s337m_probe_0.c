#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int markers[3];
extern int i;
extern int sum;
extern int max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element, then handle remainder)
    int n = sizeof(markers) / sizeof(markers[0]);
    // First pass: even indices
    for (i = 0; i < n; i += 2) {
        sum += markers[i];
        if (markers[max] < markers[i])
            max = i;
    }
    // Second pass: odd indices
    for (i = 1; i < n; i += 2) {
        sum += markers[i];
        if (markers[max] < markers[i])
            max = i;
    }
}
