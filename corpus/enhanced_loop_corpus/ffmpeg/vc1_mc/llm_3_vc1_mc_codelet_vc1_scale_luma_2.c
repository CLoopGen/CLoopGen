#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *srcY;
extern int k;
extern int linesize;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process every 2nd element in a zig-zag pattern within bounds
    uint8_t *temp_srcY = srcY;
    for (j = 0; j < k; j++) {
        // Access elements with stride of 2, forward and backward alternation per row
        if (j % 2 == 0) {
            for (i = 0; i < k; i += 2) {
                temp_srcY[i] = ((temp_srcY[i] - 128) >> 1) + 128;
            }
        } else {
            for (i = k - (k % 2 == 0 ? 2 : 1); i >= 0; i -= 2) {
                temp_srcY[i] = ((temp_srcY[i] - 128) >> 1) + 128;
            }
        }
        temp_srcY += linesize;
    }
}
