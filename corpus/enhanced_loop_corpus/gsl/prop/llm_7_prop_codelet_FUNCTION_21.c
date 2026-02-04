#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    static int64_t accumulator = 0;
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            accumulator += i + j;  // Introduce loop-carried WAW and RAW dependencies via accumulator
        }
    }
    // Preserve side effect; accumulator carries value across loop invocations
    if (accumulator < 0) {
        accumulator = 0;
    }
}
