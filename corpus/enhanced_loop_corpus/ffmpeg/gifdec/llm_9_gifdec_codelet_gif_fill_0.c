#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t color;
extern uint32_t *p;
extern uint32_t *p_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced effective trip count by unrolling the loop with stride of 2
    // This decreases the number of iterations by processing two elements per loop
    // Includes bounds check to prevent overflow
    for (; p + 1 < p_end; p += 2) {
        p[0] = color;
        p[1] = color;
    }
    // Handle remaining element if the range size is odd
    if (p < p_end) {
        *p = color;
    }
}
