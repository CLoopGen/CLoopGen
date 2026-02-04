#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern int y;
extern int x;
extern int best_score;
extern int block_sum[7];
extern int w;
extern int h;
extern int16_t (*block)[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step size of 2, unrolled-like pattern
    // Simulates processing every second element in a strided manner, then clean-up
    // This changes access pattern to non-unit stride for both src and block
    int i, j;
    // First pass: Stride-2 access to promote spatial sparsity
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x += 2) {
            int v = src[x + y * stride];
            block[0][x + w * y] = v;
            best_score += v * v;
            block_sum[0] += v;
        }
    }
    // Second pass: fill in the odd indices with same logic, creating two-phase strided access
    for (y = 0; y < h; y++) {
        for (x = 1; x < w; x += 2) {
            int v = src[x + y * stride];
            block[0][x + w * y] = v;
            best_score += v * v;
            block_sum[0] += v;
        }
    }
}
