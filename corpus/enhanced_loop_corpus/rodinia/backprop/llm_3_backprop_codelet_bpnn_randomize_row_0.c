#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *w;
extern int m;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access from high to low index
    for (i = m; i >= 0; i--) {
        w[i] = 0.10000000000000001;
    }
}
