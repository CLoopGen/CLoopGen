#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern doublereal *delta;
extern integer i__1;
extern integer j;
extern doublereal psi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced effective trip count with increased stride and conditional skip
    // Simulates sparsity or filtering – only processes elements where z[j] exceeds a threshold
    // Lower effective iterations, higher control overhead per iteration
    const doublereal threshold = 1e-6;
    integer step = 2;  // Process every second element to reduce total count
    for (j = 1; j <= i__1; j += step) {
        if (z__[j] > threshold || z__[j] < -threshold) {  // Skip near-zero values
            doublereal abs_z = z__[j] < 0 ? -z__[j] : z__[j];
            psi += (abs_z * z__[j]) / (delta[j] + 1e-9);  // Prevent division by zero with small offset
        }
    }
}
