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
        int block_sum = 0;
        for (x = 0; x < 16; x += 4) {
            block_sum += ((local_s[x] - local_s[x + stride]) * (local_s[x] - local_s[x + stride])) +
                         ((local_s[x + 1] - local_s[x + stride + 1]) * (local_s[x + 1] - local_s[x + stride + 1]));
            x += 2;
            if (x < 16) {
                block_sum += ((local_s[x] - local_s[x + stride]) * (local_s[x] - local_s[x + stride])) +
                             ((local_s[x + 1] - local_s[x + stride + 1]) * (local_s[x + 1] - local_s[x + stride + 1]));
            }
            x -= 2;
        }
        local_score += block_sum;
        local_s += stride;
    }
    score = local_score;
}
