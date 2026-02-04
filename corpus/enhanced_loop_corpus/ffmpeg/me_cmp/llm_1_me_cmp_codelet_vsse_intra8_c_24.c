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
        for (x = 0; x < 8; x += 8) {
            if (x + 4 <= 8) {
                score += ((s[x] - s[x + stride]) * (s[x] - s[x + stride])) + 
                         ((s[x + 1] - s[x + stride + 1]) * (s[x + 1] - s[x + stride + 1])) + 
                         ((s[x + 2] - s[x + stride + 2]) * (s[x + 2] - s[x + stride + 2])) + 
                         ((s[x + 3] - s[x + stride + 3]) * (s[x + 3] - s[x + stride + 3]));
            }
            if (x + 8 <= 8) {
                score += ((s[x+4] - s[x + stride + 4]) * (s[x+4] - s[x + stride + 4])) + 
                         ((s[x + 5] - s[x + stride + 5]) * (s[x + 5] - s[x + stride + 5])) + 
                         ((s[x + 6] - s[x + stride + 6]) * (s[x + 6] - s[x + stride + 6])) + 
                         ((s[x + 7] - s[x + stride + 7]) * (s[x + 7] - s[x + stride + 7]));
            }
        }
        s += stride;
    }
}
