#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *input;
extern int i;
extern int temp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Introduce loop-carried dependency by accumulating a value across iterations
    int carry = 0;
    for (i = 0; i < 4; i++) {
        const int offset = 4 * i;
        // Make current iteration partially depend on previous via 'carry'
        const int adjusted_val = input[offset + 0] + carry;
        const int z0 = 13 * (adjusted_val + input[offset + 2]);
        const int z1 = 13 * (adjusted_val - input[offset + 2]);
        const int z2 = 7 * input[offset + 1] - 17 * input[offset + 3];
        const int z3 = 17 * input[offset + 1] + 7 * input[offset + 3];
        temp[offset + 0] = z0 + z3;
        temp[offset + 1] = z1 + z2;
        temp[offset + 2] = z1 - z2;
        temp[offset + 3] = z0 - z3;
        // Update carry for next iteration (loop-carried RAW dependency)
        carry = (z0 + z1) >> 4;
    }
}
