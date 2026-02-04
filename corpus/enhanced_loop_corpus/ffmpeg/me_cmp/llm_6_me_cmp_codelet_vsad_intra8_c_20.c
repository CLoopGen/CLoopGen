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
        int temp_score = 0;
        for (x = 0; x < 8; x += 4) {
            temp_score += abs(s[x] - s[x + stride]);
            temp_score += abs(s[x + 1] - s[x + stride + 1]);
            temp_score += abs(s[x + 2] - s[x + stride + 2]);
            temp_score += abs(s[x + 3] - s[x + stride + 3]);
        }
        score += temp_score;
        s += stride;
    }
}
