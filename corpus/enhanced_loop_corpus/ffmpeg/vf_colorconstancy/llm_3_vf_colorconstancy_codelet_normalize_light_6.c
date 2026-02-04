#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *light;
extern double abs_val;
extern int plane;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    int indices[3] = {2, 0, 1};  // Arbitrary reordering of indices
    for (plane = 0; plane < 3; ++plane) {
        int idx = indices[plane];
        light[idx] = (light[idx] / abs_val);
        if (!light[idx]) {
            light[idx] = 1.;
        }
    }
}
