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
        for (x = 0; x < 8; x += 2) {
            int diff1 = s1[x] - s2[x] - s1[x + stride] + s2[x + stride];
            int diff2 = (x + 1 < 8) ? (s1[x+1] - s2[x+1] - s1[x+1 + stride] + s2[x+1 + stride]) : 0;
            score += (diff1 >= 0 ? diff1 : -diff1);
            if (x + 1 < 8)
                score += (diff2 >= 0 ? diff2 : -diff2);
        }
        s1 += stride;
        s2 += stride;
    }
}
