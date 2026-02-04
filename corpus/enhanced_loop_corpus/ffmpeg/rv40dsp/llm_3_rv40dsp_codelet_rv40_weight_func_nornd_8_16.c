#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src1;
extern uint8_t *src2;
extern int w1;
extern int w2;
extern ptrdiff_t stride;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with pointer arithmetic using step size larger than 1
    for (j = 0; j < 8; j += 2) {  // Process every other row to increase stride effect
        for (i = 0; i < 8; i += 4) {  // Access every 4th element in the row
            // Handle block of 4 elements with bounds check
            for (int k = 0; k < 4 && i + k < 8; k++) {
                dst[i + k] = ((unsigned int)w2 * src1[i + k] + (unsigned int)w1 * src2[i + k] + 16) >> 5;
            }
        }
        src1 += 2 * stride;  // Advance by two rows
        src2 += 2 * stride;
        dst += 2 * stride;
    }
    // Handle any remaining odd row if needed (ensure full coverage)
    if (j < 8) {
        for (i = 0; i < 8; i++) {
            dst[i] = ((unsigned int)w2 * src1[i] + (unsigned int)w1 * src2[i] + 16) >> 5;
        }
    }
}
