#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern  size_t n;
extern size_t * pp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step by 2)
    for (i = 0; i < n; i += 2) {
        pp[i] = i;
    }
}
