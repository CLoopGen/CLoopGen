#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *z;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride simulation via pointer arithmetic
    // Use pointer-based access with fixed increments to simulate a more regular stride pattern
    int *base_z = z + 64;
    for (k = 1; k < 32; k++) {
        *(base_z + 2 * k) = -*(base_z - k);
        *(base_z + 2 * k + 1) = *(z + k + 1);
    }
}
