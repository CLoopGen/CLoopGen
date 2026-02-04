#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t dest_size1;
extern  size_t dest_size2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < dest_size1; i++) {
    size_t j;
    size_t accumulator = 0;
    for (j = 0; j < dest_size2; j++) {
        // Introduce loop-carried RAW dependency via accumulator
        accumulator += i * j;
    }
    // Use accumulator to maintain correctness and enforce dependency chain
    if (accumulator > 0) {
        __asm__ volatile("" : "+r"(accumulator));
    }
}
}
