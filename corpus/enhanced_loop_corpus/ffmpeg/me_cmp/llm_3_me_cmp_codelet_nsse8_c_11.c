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
    // Variant 2: Use indirect (gather-like) access via index array to simulate irregular access pattern
    // Introduce an index lookup table for non-sequential traversal within each row
    int indices[8];
    for (int i = 0; i < 8; i++) {
        indices[i] = 7 - i; // Reverse access order: 7,6,5,...,0
    }
    for (y = 0; y < h; y++) {
        for (x = 0; x < 8; x++) {
            int idx = indices[x]; // Indirect indexing
            score1 += (s1[idx] - s2[idx]) * (s1[idx] - s2[idx]);
        }
        if (y + 1 < h) {
            for (x = 0; x < 7; x++) {
                int idx = indices[x];
                int next_idx = indices[x + 1];
                int diff1 = s1[idx] - s1[idx + stride] - s1[next_idx] + s1[next_idx + stride];
                int diff2 = s2[idx] - s2[idx + stride] - s2[next_idx] + s2[next_idx + stride];
                score2 += (diff1 >= 0 ? diff1 : -diff1) - (diff2 >= 0 ? diff2 : -diff2);
            }
        }
        s1 += stride;
        s2 += stride;
    }
}
