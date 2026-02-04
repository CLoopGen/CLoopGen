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
    uint8_t *local_s = s;
    int local_score = score;
    for (y = 1; y < h; y++) {
        for (x = 0; x < 8; x += 4) {
            int diff0 = local_s[x] - local_s[x + stride];
            int diff1 = local_s[x + 1] - local_s[x + stride + 1];
            int diff2 = local_s[x + 2] - local_s[x + stride + 2];
            int diff3 = local_s[x + 3] - local_s[x + stride + 3];
            local_score += diff0 * diff0 + diff1 * diff1 + diff2 * diff2 + diff3 * diff3;
        }
        local_s += stride;
    }
    s = local_s;
    score = local_score;
}
