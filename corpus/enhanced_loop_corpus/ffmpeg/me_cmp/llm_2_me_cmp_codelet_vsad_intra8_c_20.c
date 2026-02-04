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
    for (x = 0; x < 8; x += 4) {
        ptrdiff_t idx0 = x;
        ptrdiff_t idx1 = x + 1;
        ptrdiff_t idx2 = x + 2;
        ptrdiff_t idx3 = x + 3;
        score += ((s[idx0] - s[idx0 + stride]) >= 0 ? (s[idx0] - s[idx0 + stride]) : (-(s[idx0] - s[idx0 + stride]))) +
                 ((s[idx1] - s[idx1 + stride]) >= 0 ? (s[idx1] - s[idx1 + stride]) : (-(s[idx1] - s[idx1 + stride]))) +
                 ((s[idx2] - s[idx2 + stride]) >= 0 ? (s[idx2] - s[idx2 + stride]) : (-(s[idx2] - s[idx2 + stride]))) +
                 ((s[idx3] - s[idx3 + stride]) >= 0 ? (s[idx3] - s[idx3 + stride]) : (-(s[idx3] - s[idx3 + stride])));
    }
    s += stride;
}
}
