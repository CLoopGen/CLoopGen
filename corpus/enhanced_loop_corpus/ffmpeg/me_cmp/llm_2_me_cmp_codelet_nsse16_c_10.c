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
    // Variant 1: Change memory access pattern to consecutive (unit stride) by precomputing row pointers
    uint8_t *ptr1 = s1;
    uint8_t *ptr2 = s2;
    for (y = 0; y < h; y++) {
        for (x = 0; x < 16; x++) {
            score1 += (ptr1[x] - ptr2[x]) * (ptr1[x] - ptr2[x]);
        }
        if (y + 1 < h) {
            for (x = 0; x < 15; x++) {
                int diff1 = ptr1[x] - ptr1[x + stride] - ptr1[x + 1] + ptr1[x + stride + 1];
                int diff2 = ptr2[x] - ptr2[x + stride] - ptr2[x + 1] + ptr2[x + stride + 1];
                score2 += (diff1 >= 0 ? diff1 : -diff1) - (diff2 >= 0 ? diff2 : -diff2);
            }
        }
        ptr1 += stride;
        ptr2 += stride;
    }
}
