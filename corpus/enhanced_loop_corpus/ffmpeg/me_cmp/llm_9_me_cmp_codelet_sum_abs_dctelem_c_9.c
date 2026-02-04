#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0;
    for (i = 0; i < 32; i++) {
        int16_t val = block[i] * block[i]; // Square the value to increase arithmetic intensity
        sum += (val > 0 ? val : -val); // Redundant ternary due to squaring, but maintains pattern
    }
}
