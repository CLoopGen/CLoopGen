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
    // Variant 1: Change memory access pattern to consecutive by precomputing strided offsets
    // Instead of updating s1 and s2 pointers with stride, use base pointer + index * stride
    uint8_t *base_s1 = s1;
    uint8_t *base_s2 = s2;
    for (y = 0; y < h; y++) {
        ptrdiff_t offset = y * stride;
        for (x = 0; x < 8; x++) {
            score1 += (base_s1[offset + x] - base_s2[offset + x]) * (base_s1[offset + x] - base_s2[offset + x]);
        }
        if (y + 1 < h) {
            for (x = 0; x < 7; x++) {
                int diff1 = base_s1[offset + x] - base_s1[offset + x + stride] - 
                            base_s1[offset + x + 1] + base_s1[offset + x + stride + 1];
                int diff2 = base_s2[offset + x] - base_s2[offset + x + stride] - 
                            base_s2[offset + x + 1] + base_s2[offset + x + stride + 1];
                score2 += (diff1 >= 0 ? diff1 : -diff1) - (diff2 >= 0 ? diff2 : -diff2);
            }
        }
    }
}
