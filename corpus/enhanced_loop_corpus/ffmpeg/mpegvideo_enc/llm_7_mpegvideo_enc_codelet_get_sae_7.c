#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int ref;
extern int stride;
extern int x;
extern int y;
extern int acc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    acc = 0;
    int prev_val = 0;
    for (y = 0; y < 16; y++) {
        for (x = 0; x < 16; x++) {
            int index = x + y * stride;
            int diff = src[index] - ref;
            int abs_diff = (diff >= 0) ? diff : -diff;
            // Introduce artificial WAW and RAW dependency using prev_val
            abs_diff = (prev_val > abs_diff) ? prev_val : abs_diff;
            acc += abs_diff;
            prev_val = abs_diff; // Loop-carried dependence introduced
        }
    }
}
