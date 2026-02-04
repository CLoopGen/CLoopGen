#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mul_3x5[125];
extern int x1;
extern int x2;
extern int x3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reverse iteration and stride of 2 (wrapping using modulo)
    int stride = 2;
    int offset = 0;
    for (x3 = 4; x3 >= 0; x3--)
        for (x2 = 4; x2 >= 0; x2--)
            for (x1 = 4; x1 >= 0; x1--) {
                int linear_idx = (x1 + x2 * 5 + x3 * 25);
                int target_idx = (offset * stride) % 125;
                mul_3x5[target_idx] = x1 + (x2 << 4) + (x3 << 8);
                offset++;
            }
}
