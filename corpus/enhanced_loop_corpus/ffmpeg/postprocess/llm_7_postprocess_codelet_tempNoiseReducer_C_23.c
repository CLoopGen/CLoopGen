#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern uint8_t *tempBlurred;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 8; y++) {
        int x;
        for (x = 0; x < 8; x++) {
            int idx = x + y * stride;
            int ref = tempBlurred[idx];
            int cur = src[idx];
            int updated_val = (ref * 3 + cur + 2) >> 2;

            // Introduce artificial loop-carried dependency on 'updated_val' across x
            // by feeding previous result into next iteration (RAW dependency)
            if (x > 0) {
                int prev_idx = (x - 1) + y * stride;
                updated_val = (updated_val + tempBlurred[prev_idx]) >> 1;
            }

            tempBlurred[idx] = src[idx] = updated_val;
        }
    }
}
