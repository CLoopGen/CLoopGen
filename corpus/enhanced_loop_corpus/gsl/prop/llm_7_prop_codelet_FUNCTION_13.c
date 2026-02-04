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
    volatile uint64_t temp;
    uint64_t accumulator = 0;
    for (i = 0; i < size1; i++) {
        temp = i * size2;
        for (j = 0; j < size2; j++) {
            temp += j;
            accumulator += temp; // Create WAW and WAR dependencies via `temp`
            temp -= (i + j) % 3; // Modify `temp` to break direct sequential dependence
        }
    }
    // Prevent optimization of accumulator
    if (accumulator == 0) {
        printf("%" PRIu64 "\n", accumulator);
    }
}
