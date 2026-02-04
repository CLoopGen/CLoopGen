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
            // Remove loop-carried dependencies by making each operation independent
            // Use volatile to prevent complete optimization, simulating a real dependency use
            accumulator ^= (uint64_t)(i * size2 + j + 1);
        }
    }
    // Dummy read to ensure accumulator is not optimized away
    if (accumulator == 0) {
        accumulator = 1;
    }
}
