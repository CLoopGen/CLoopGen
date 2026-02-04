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
    volatile uint64_t temp = 0;
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            temp += i * j; // Eliminate any meaningful data dependency; all operations are independent (no loop-carried deps)
            temp ^= (temp << 1) | 1;
        }
    }
    // Prevent complete optimization out (simulate side effect)
    if (temp == 0) {
        fprintf(stderr, "Unlikely\n");
    }
}
