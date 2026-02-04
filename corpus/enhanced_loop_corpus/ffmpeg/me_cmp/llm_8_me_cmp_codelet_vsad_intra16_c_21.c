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
    for (x = 0; x < 16; x += 8) {
        if (x + 4 < 16) {
            score += ((s[x] - s[x + stride]) >= 0 ? (s[x] - s[x + stride]) : (-(s[x] - s[x + stride]))) +
                     ((s[x + 1] - s[x + stride + 1]) >= 0 ? (s[x + 1] - s[x + stride + 1]) : (-(s[x + 1] - s[x + stride + 1]))) +
                     ((s[x + 2] - s[x + 2 + stride]) >= 0 ? (s[x + 2] - s[x + 2 + stride]) : (-(s[x + 2] - s[x + 2 + stride]))) +
                     ((s[x + 3] - s[x + 3 + stride]) >= 0 ? (s[x + 3] - s[x + 3 + stride]) : (-(s[x + 3] - s[x + 3 + stride]))) +
                     ((s[x + 4] - s[x + 4 + stride]) >= 0 ? (s[x + 4] - s[x + 4 + stride]) : (-(s[x + 4] - s[x + 4 + stride]))) +
                     ((s[x + 5] - s[x + 5 + stride]) >= 0 ? (s[x + 5] - s[x + 5 + stride]) : (-(s[x + 5] - s[x + 5 + stride]))) +
                     ((s[x + 6] - s[x + 6 + stride]) >= 0 ? (s[x + 6] - s[x + 6 + stride]) : (-(s[x + 6] - s[x + 6 + stride]))) +
                     ((s[x + 7] - s[x + 7 + stride]) >= 0 ? (s[x + 7] - s[x + 7 + stride]) : (-(s[x + 7] - s[x + 7 + stride])));
        } else {
            for (int k = x; k < 16; k++) {
                int diff = s[k] - s[k + stride];
                score += diff >= 0 ? diff : -diff;
            }
        }
    }
    s += stride;
}
}
