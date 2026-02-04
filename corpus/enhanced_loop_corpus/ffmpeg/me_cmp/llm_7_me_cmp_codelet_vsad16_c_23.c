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
        for (x = 0; x < 16; x++) {
            int val = (s1[x] - s2[x]) + (s2[x + stride] - s1[x + stride]);
            local_sum += (val >= 0) ? val : -val;
        }
        score += local_sum;
        s1 += stride;
        s2 += stride;
    }
}
