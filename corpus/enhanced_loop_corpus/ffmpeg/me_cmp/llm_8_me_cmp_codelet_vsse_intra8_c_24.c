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
    for (y = 1; y < h; y++) {
        for (x = 0; x < 8; x += 2) {
            score += ((s[x] - s[x + stride]) * (s[x] - s[x + stride])) +
                     ((s[x + 1] - s[x + stride + 1]) * (s[x + 1] - s[x + stride + 1]));
        }
        s += stride;
    }
}
