#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double dist[36];
extern double dsum[36];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    // Traverse the array from the end to the beginning
    for (i = 35; i >= 1; i--)
        dsum[i] = dsum[i - 1] + dist[i];
}
