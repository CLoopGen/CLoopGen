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
for (y = 0; y < h; y++) {
    score1 += (s1[0] - s2[0]) * (s1[0] - s2[0]);
    for (x = 1; x < 16; x++) {
        score1 += (s1[x] - s2[x]) * (s1[x] - s2[x]);
        if (y + 1 < h && x < 15) {
            int term1 = s1[x] - s1[x + stride] - s1[x + 1] + s1[x + stride + 1];
            int term2 = s2[x] - s2[x + stride] - s2[x + 1] + s2[x + stride + 1];
            score2 += (term1 >= 0 ? term1 : -term1) - (term2 >= 0 ? term2 : -term2);
        }
    }
    if (y + 1 < h) {
        for (x = 0; x < 1; x++) {
            int term1 = s1[x] - s1[x + stride] - s1[x + 1] + s1[x + stride + 1];
            int term2 = s2[x] - s2[x + stride] - s2[x + 1] + s2[x + stride + 1];
            score2 += (term1 >= 0 ? term1 : -term1) - (term2 >= 0 ? term2 : -term2);
        }
    }
    s1 += stride;
    s2 += stride;
}
}
