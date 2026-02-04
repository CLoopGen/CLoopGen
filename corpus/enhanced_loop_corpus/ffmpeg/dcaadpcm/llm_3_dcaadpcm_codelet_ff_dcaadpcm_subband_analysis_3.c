#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *in;
extern int len;
extern int i;
extern int32_t max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive two-element access with unrolling-like pattern
    for (i = 0; i < len + 4 - 1; i += 2) {
        // Process two consecutive elements per iteration
        int32_t val1 = in[i];
        int32_t val2 = in[i + 1];

        max |= (val1 >= 0 ? val1 : -val1);
        max |= (val2 >= 0 ? val2 : -val2);
    }
    // Handle remaining element if the total count is odd
    if (i == len + 4 - 1) {
        max |= ((in[i]) >= 0 ? (in[i]) : (-(in[i])));
    }
}
