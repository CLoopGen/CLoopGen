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
    for (x = 0; x < 8; x++) {
        int diff1 = s1[x] - s2[x] - s1[x + stride] + s2[x + stride];
        int diff2 = s1[x + stride] - s2[x + stride] - s1[x + 2*stride] + s2[x + 2*stride];
        score += (diff1 >= 0 ? diff1 : -diff1);
        score += (diff2 >= 0 ? diff2 : -diff2);
    }
    s1 += 2 * stride;
    s2 += 2 * stride;
}
}
