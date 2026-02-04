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
for (y = 0; y < h * 2; y++) { // Doubled trip count to increase computational load
    for (x = 0; x < 32; x++) { // Increased inner loop bound, with bounds check to avoid overflow
        if (x < 16) {
            score1 += (s1[x] - s2[x]) * (s1[x] - s2[x]);
        }
        if (y < h && x < 15 && y + 1 < h) {
            int term1 = s1[x] - s1[x + stride] - s1[x + 1] + s1[x + stride + 1];
            int term2 = s2[x] - s2[x + stride] - s2[x + 1] + s2[x + stride + 1];
            score2 += (term1 >= 0 ? term1 : -term1) - (term2 >= 0 ? term2 : -term2);
        }
    }
    if (y % 2 == 1) { // Update pointers every two iterations to preserve access pattern
        s1 += stride;
        s2 += stride;
    }
}
}
