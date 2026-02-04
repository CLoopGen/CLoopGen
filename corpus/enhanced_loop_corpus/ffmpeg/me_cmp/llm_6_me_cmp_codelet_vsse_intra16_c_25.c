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
    int temp_score = 0;
    uint8_t *local_s = s;
    for (y = 1; y < h; y++) {
        for (x = 0; x < 16; x += 4) {
            int diff0 = local_s[x] - local_s[x + stride];
            int diff1 = local_s[x + 1] - local_s[x + stride + 1];
            int diff2 = local_s[x + 2] - local_s[x + stride + 2];
            int diff3 = local_s[x + 3] - local_s[x + stride + 3];
            temp_score += diff0 * diff0 + diff1 * diff1 + diff2 * diff2 + diff3 * diff3;
        }
        local_s += stride;
    }
    score += temp_score;
}
