#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *s1;
extern uint8_t *s2;
extern ptrdiff_t stride;
extern int h;
extern int score1;
extern int score2;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_score1 = 0;
    int temp_score2 = 0;
    uint8_t *local_s1 = s1;
    uint8_t *local_s2 = s2;
    for (y = 0; y < h; y++) {
        for (x = 0; x < 8; x++) {
            int diff = local_s1[x] - local_s2[x];
            temp_score1 += diff * diff;
        }
        if (y + 1 < h) {
            for (x = 0; x < 7; x++) {
                int term1 = local_s1[x] - local_s1[x + stride] - local_s1[x + 1] + local_s1[x + stride + 1];
                int term2 = local_s2[x] - local_s2[x + stride] - local_s2[x + 1] + local_s2[x + stride + 1];
                temp_score2 += (term1 >= 0 ? term1 : -term1) - (term2 >= 0 ? term2 : -term2);
            }
        }
        local_s1 += stride;
        local_s2 += stride;
    }
    score1 = temp_score1;
    score2 = temp_score2;
}
