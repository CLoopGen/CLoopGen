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
    volatile uint64_t accumulator = 0;

    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            accumulator += (i * size2 + j) ^ accumulator;
        }
    }

    // Prevent optimization by using accumulator in a side effect
    if (accumulator == 0) {
        fprintf(stderr, "Accumulator is zero\n");
    }
}
