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
        uint8_t *base = s;
        uint8_t *ref = s + stride;
        for (x = 0; x < 16; x += 4) {
            score += abs((int)(base[x + 0] - ref[x + 0])) +
                     abs((int)(base[x + 1] - ref[x + 1])) +
                     abs((int)(base[x + 2] - ref[x + 2])) +
                     abs((int)(base[x + 3] - ref[x + 3]));
        }
        s += stride;
    }
}
