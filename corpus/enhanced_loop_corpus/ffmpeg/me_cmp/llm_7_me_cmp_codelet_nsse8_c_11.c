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
    score1 = 0;
    score2 = 0;
    uint8_t *curr_s1 = s1;
    uint8_t *curr_s2 = s2;
    for (y = 0; y < h; y++) {
        int row_score1 = 0;
        for (x = 0; x < 8; x += 4) {
            row_score1 += (curr_s1[x] - curr_s2[x]) * (curr_s1[x] - curr_s2[x]);
            if (x + 1 < 8) row_score1 += (curr_s1[x+1] - curr_s2[x+1]) * (curr_s1[x+1] - curr_s2[x+1]);
            if (x + 2 < 8) row_score1 += (curr_s1[x+2] - curr_s2[x+2]) * (curr_s1[x+2] - curr_s2[x+2]);
            if (x + 3 < 8) row_score1 += (curr_s1[x+3] - curr_s2[x+3]) * (curr_s1[x+3] - curr_s2[x+3]);
        }
        score1 += row_score1;

        if (y + 1 < h) {
            int row_score2 = 0;
            for (x = 0; x < 7; x++) {
                int val_s1 = curr_s1[x] - curr_s1[x + stride] - curr_s1[x + 1] + curr_s1[x + stride + 1];
                int val_s2 = curr_s2[x] - curr_s2[x + stride] - curr_s2[x + 1] + curr_s2[x + stride + 1];
                row_score2 += (val_s1 >= 0 ? val_s1 : -val_s1) - (val_s2 >= 0 ? val_s2 : -val_s2);
            }
            score2 += row_score2;
        }
        curr_s1 += stride;
        curr_s2 += stride;
    }
}
