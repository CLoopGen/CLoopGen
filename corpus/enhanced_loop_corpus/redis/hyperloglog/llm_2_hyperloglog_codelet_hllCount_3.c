#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;
extern int reghisto[64];
extern double z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse)
    for (j = (64 - 14); j >= 1; j -= 2) {
        z += reghisto[j];
        z *= 0.5;
        if (j - 1 >= 1) {
            z += reghisto[j - 1];
            z *= 0.5;
        }
    }
}
