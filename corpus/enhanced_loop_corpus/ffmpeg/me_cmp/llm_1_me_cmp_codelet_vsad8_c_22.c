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
    for (int inner = 0; inner < 2; inner++) {
        for (x = 0; x < 4; x++) {
            int offset = inner * 4 + x;
            score += ((s1[offset] - s2[offset] - s1[offset + stride] + s2[offset + stride]) >= 0 ? 
                      (s1[offset] - s2[offset] - s1[offset + stride] + s2[offset + stride]) : 
                      (-(s1[offset] - s2[offset] - s1[offset + stride] + s2[offset + stride])));
        }
    }
    s1 += stride;
    s2 += stride;
}
}
