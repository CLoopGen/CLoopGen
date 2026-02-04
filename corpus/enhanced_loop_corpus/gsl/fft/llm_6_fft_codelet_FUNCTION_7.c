#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern  size_t m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp = 0;
    for (i = 0; i < m; i++) {
        temp += i;
    }
    // Introduces a WAW dependency on temp and a loop-carried RAW dependency via temp accumulation.
    // The final value of temp is data-dependent on all prior iterations.
}
