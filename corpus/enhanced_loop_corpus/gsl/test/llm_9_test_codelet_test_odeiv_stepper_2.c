#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double scale_abs[15];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with minimal operations; simulates lightweight initialization
    for (i = 0; i < 5; i++) {
        scale_abs[i * 3] = 1.0;  // Strided access, fewer iterations, same array coverage pattern
    }
}
