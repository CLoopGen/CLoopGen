#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *s1;
extern uint8_t *s2;
extern ptrdiff_t stride;
extern int h;
extern int score;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 1; y < h; y++) {
        int temp_score = 0;
        const uint8_t* s1_offset = s1;
        const uint8_t* s2_offset = s2;
        for (x = 0; x < 16; x += 4) {
            temp_score += ((s1_offset[x] - s2_offset[x] - s1_offset[x + stride] + s2_offset[x + stride]) >= 0 ? 
                           (s1_offset[x] - s2_offset[x] - s1_offset[x + stride] + s2_offset[x + stride]) : 
                           (-(s1_offset[x] - s2_offset[x] - s1_offset[x + stride] + s2_offset[x + stride])));
            temp_score += ((s1_offset[x+1] - s2_offset[x+1] - s1_offset[x+1 + stride] + s2_offset[x+1 + stride]) >= 0 ? 
                           (s1_offset[x+1] - s2_offset[x+1] - s1_offset[x+1 + stride] + s2_offset[x+1 + stride]) : 
                           (-(s1_offset[x+1] - s2_offset[x+1] - s1_offset[x+1 + stride] + s2_offset[x+1 + stride])));
            temp_score += ((s1_offset[x+2] - s2_offset[x+2] - s1_offset[x+2 + stride] + s2_offset[x+2 + stride]) >= 0 ? 
                           (s1_offset[x+2] - s2_offset[x+2] - s1_offset[x+2 + stride] + s2_offset[x+2 + stride]) : 
                           (-(s1_offset[x+2] - s2_offset[x+2] - s1_offset[x+2 + stride] + s2_offset[x+2 + stride])));
            temp_score += ((s1_offset[x+3] - s2_offset[x+3] - s1_offset[x+3 + stride] + s2_offset[x+3 + stride]) >= 0 ? 
                           (s1_offset[x+3] - s2_offset[x+3] - s1_offset[x+3 + stride] + s2_offset[x+3 + stride]) : 
                           (-(s1_offset[x+3] - s2_offset[x+3] - s1_offset[x+3 + stride] + s2_offset[x+3 + stride])));
        }
        score += temp_score;
        s1 += stride;
        s2 += stride;
    }
}
