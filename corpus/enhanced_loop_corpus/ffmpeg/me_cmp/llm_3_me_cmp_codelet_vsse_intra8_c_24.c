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
        for (x = 0; x < 8; x++) {
            ptrdiff_t offset = x;
            ptrdiff_t prev_row_offset = x + stride;
            score += (s[offset] - s[prev_row_offset]) * (s[offset] - s[prev_row_offset]);
        }
        s += stride;
    }
}
