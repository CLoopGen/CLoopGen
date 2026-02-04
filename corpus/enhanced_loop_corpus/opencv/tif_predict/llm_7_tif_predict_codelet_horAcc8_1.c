#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t cc;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t j = i;
    for (; j < cc; j++) {
        i = j; // Create a read-after-write (RAW) dependency: j used before potential update in next iteration
        // Eliminate direct loop-carried dependency on loop index by using local j, but maintain semantic equivalence
    }
}
