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
    int temp_score = 0;
    for (x = 0; x < 16; x++) {
        int val1 = s1[x] - s2[x];
        int val2 = s1[x + stride] - s2[x + stride];
        int diff = val1 - val2;
        score += (diff >= 0) ? diff : -diff;
    }
    s1 += stride;
    s2 += stride;
}
}
