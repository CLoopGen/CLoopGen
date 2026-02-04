#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *mean;
extern int32 n_dim;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float32 temp = 0.0;
    for (i = 0; i < n_dim; i++) {
        temp += mean[i];
        mean[i] = 0.;
    }
    // Introduces a loop-carried dependency via 'temp' (WAW and RAW dependencies on temp)
    // Also creates a read-after-write (RAW) dependence on mean[i] before assignment
}
