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
for (y = 1; y < h; y += 2) {
    if (y + 1 < h) {
        for (x = 0; x < 8; x++) {
            int diff_current = s1[x] - s2[x] - s1[x + stride] + s2[x + stride];
            int diff_next_row = s1[x + stride] - s2[x + stride] - s1[x + 2*stride] + s2[x + 2*stride];
            score += (diff_current >= 0 ? diff_current : -diff_current);
            score += (diff_next_row >= 0 ? diff_next_row : -diff_next_row);
        }
        s1 += 2 * stride;
        s2 += 2 * stride;
    } else {
        for (x = 0; x < 8; x++) {
            int diff = s1[x] - s2[x] - s1[x + stride] + s2[x + stride];
            score += (diff >= 0 ? diff : -diff);
        }
        s1 += stride;
        s2 += stride;
    }
}
}
