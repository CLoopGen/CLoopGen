#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double J[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    for (i = 0; i < 100; i += 2) {
        J[i] = i;
    }
    for (i = 1; i < 100; i += 2) {
        J[i] = i;
    }
}
