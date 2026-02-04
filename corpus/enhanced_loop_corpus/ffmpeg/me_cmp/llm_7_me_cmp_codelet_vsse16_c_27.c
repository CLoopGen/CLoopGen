#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *s1;
extern uint8_t *s2;
extern ptrdiff_t stride;
extern int h;
extern int score;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 1; y < h; y++) {
        int local_sum = 0;
        for (x = 0; x < 16; x += 4) {
            int diff0 = s1[x] - s2[x] - s1[x + stride] + s2[x + stride];
            int diff1 = s1[x+1] - s2[x+1] - s1[x+1 + stride] + s2[x+1 + stride];
            local_sum += diff0 * diff0 + diff1 * diff1;
            if (x + 3 < 16) {
                int diff2 = s1[x+2] - s2[x+2] - s1[x+2 + stride] + s2[x+2 + stride];
                int diff3 = s1[x+3] - s2[x+3] - s1[x+3 + stride] + s2[x+3 + stride];
                local_sum += diff2 * diff2 + diff3 * diff3;
            }
        }
        score += local_sum;
        s1 += stride;
        s2 += stride;
    }
}
