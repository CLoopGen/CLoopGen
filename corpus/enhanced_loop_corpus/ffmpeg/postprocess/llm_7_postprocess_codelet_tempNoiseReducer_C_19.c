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
    d = 0;
    for (y = 0; y < 8; y++) {
        int x;
        int prev_diff_sq = 0; // Introduce artificial dependence: each iteration depends on previous d1*d1
        for (x = 0; x < 8; x++) {
            int idx = x + y * stride;
            int ref = tempBlurred[idx];
            int cur = src[idx];
            int d1 = ref - cur;
            int curr_diff_sq = d1 * d1;
            d += curr_diff_sq + prev_diff_sq; // RAW dependency: uses prev_diff_sq from prior iteration
            prev_diff_sq = curr_diff_sq; // Create loop-carried RAW dependency
        }
        d -= prev_diff_sq; // Adjust sum: subtract last added term (since it was added one extra time)
    }
}
