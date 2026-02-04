#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *s1;
extern uint8_t *s2;
extern ptrdiff_t stride;
extern int h;
extern int score1;
extern int score2;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int y_inner;
    for (y = 0; y < h; y++) {
        score1 = 0; // Introduce WAW dependency by resetting score1 each iteration
        for (x = 0; x < 16; x++) {
            int diff = s1[x] - s2[x];
            score1 += diff * diff; // RAW: diff used after definition
        }
        if (y + 1 < h) {
            int temp_score2 = 0;
            for (x = 0; x < 15; x++) {
                int grad1 = s1[x] - s1[x + stride] - s1[x + 1] + s1[x + stride + 1];
                int grad2 = s2[x] - s2[x + stride] - s2[x + 1] + s2[x + stride + 1];
                temp_score2 += (grad1 >= 0 ? grad1 : -grad1) - (grad2 >= 0 ? grad2 : -grad2);
            }
            score2 += temp_score2; // Reduce loop-carried dependency on score2: update once per row
        }
        s1 += stride;
        s2 += stride;
    }
}
