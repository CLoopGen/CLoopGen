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



void loop() {
    for (y = 1; y < h && y < 10; y++) {
        for (x = 0; x < 16; x += 4) {
            int diff0 = s[x] - s[x + stride];
            int diff1 = s[x + 1] - s[x + stride + 1];
            int diff2 = s[x + 2] - s[x + stride + 2];
            int diff3 = s[x + 3] - s[x + stride + 3];
            score += diff0 * diff0 + diff1 * diff1 + diff2 * diff2 + diff3 * diff3;
        }
        s += stride;
    }
}
