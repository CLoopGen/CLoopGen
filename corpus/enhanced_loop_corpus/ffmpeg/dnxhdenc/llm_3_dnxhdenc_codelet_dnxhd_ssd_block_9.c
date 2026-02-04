#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *qblock;
extern int16_t *block;
extern int score;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (gather-style) memory access using a fixed index map
    // Simulate non-sequential access via an index permutation table (reversed order)
    // This changes spatial locality and access pattern
    static const int index_map[64] = {
        63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48,
        47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32,
        31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16,
        15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
    };
    int temp_score = 0;
    for (i = 0; i < 64; i++) {
        int idx = index_map[i];
        int diff = block[idx] - qblock[idx];
        temp_score += diff * diff;
    }
    score += temp_score;
}
