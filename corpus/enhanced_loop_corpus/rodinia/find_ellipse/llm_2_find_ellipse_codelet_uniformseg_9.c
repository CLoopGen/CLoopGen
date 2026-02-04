#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double dist[36];
extern double dsum[36];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Process only even indices to create strided pattern
    for (i = 2; i < 36; i += 2)
        dsum[i] = dsum[i - 2] + dist[i];
}
