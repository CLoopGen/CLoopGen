#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *s;
extern ptrdiff_t stride;
extern int h;
extern int score;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 1; y < h; y++) {
    for (int offset = 0; offset < 16; offset += 4) {
        int temp_score = 0;
        for (int step = 0; step < 4; step++) {
            int diff = s[offset + step] - s[offset + step + stride];
            temp_score += diff * diff;
        }
        score += temp_score;
    }
    s += stride;
}
}
