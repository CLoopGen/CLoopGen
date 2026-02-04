#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *vector;
extern int i;
extern int beta;
extern int lag;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Reverse consecutive memory access
    // Process elements from high to low address, maintaining dependency safety
    // Ensure that i-lag has already been processed in prior iterations when needed
    // Since this computation uses older values (i-lag), reverse order is safe as long as i-lag < i
    for (i = 59; i >= lag; i--) {
        vector[i] += beta * vector[i - lag] >> 15;
    }
}
