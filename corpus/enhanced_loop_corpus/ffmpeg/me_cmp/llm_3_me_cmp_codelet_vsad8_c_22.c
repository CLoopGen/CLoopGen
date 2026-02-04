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
        uint8_t *temp_s1 = s1;
        uint8_t *temp_s2 = s2;
        for (x = 0; x < 8; x++) {
            ptrdiff_t idx = x * 2; // Strided access with step of 2 elements
            if (idx < 8) {
                int diff = temp_s1[idx] - temp_s2[idx] - temp_s1[idx + stride] + temp_s2[idx + stride];
                score += (diff >= 0 ? diff : -diff);
            }
        }
        s1 += stride;
        s2 += stride;
    }
}
