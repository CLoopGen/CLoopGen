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
        for (int inner = 0; inner < 2; inner++) {
            for (x = inner * 4; x < (inner + 1) * 4 && x < 8; x++) {
                score += (s[x] - s[x + stride]) >= 0 ? (s[x] - s[x + stride]) : (-(s[x] - s[x + stride]));
            }
        }
        s += stride;
    }
}
