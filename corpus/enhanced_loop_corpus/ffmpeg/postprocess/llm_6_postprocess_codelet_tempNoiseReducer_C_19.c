#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern uint8_t *tempBlurred;
extern int y;
extern int d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_d = 0;
    for (y = 0; y < 8; y++) {
        int x;
        int row_offset = y * stride;
        for (x = 0; x < 8; x++) {
            int idx = x + row_offset;
            int ref = tempBlurred[idx];
            int cur = src[idx];
            int d1 = ref - cur;
            temp_d += d1 * d1; // Accumulate into local variable to remove WAW on 'd' across iterations
        }
    }
    d = temp_d; // Write to 'd' only once after loop (eliminates loop-carried WAW dependency)
}
