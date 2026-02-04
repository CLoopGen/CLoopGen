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
    for (y = 1; y < h && score < 10000; y++) {
        int local_sum = 0;
        for (x = 0; x < 8; x++) {
            int term = s1[x] - s2[x] - s1[x + stride] + s2[x + stride];
            local_sum += term * term;
        }
        score += local_sum;
        if (local_sum == 0) continue;
        s1 += stride;
        s2 += stride;
    }
}
