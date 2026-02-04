#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t requant_tab[8][128];
extern  int8_t offsets[8];
extern  int8_t deltas[8];
extern int i;
extern int j;
extern int step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing requant_tab[i][j] in row-major order, we simulate a strided access by
    // stepping through j with a fixed stride (e.g., 2), processing even indices first, then odd if needed.
    // Here we use stride of 2 and unroll the inner loop into two passes to maintain coverage.
    for (i = 0; i < 8; i++) {
        step = i + 2;
        // First pass: even indices
        for (j = 0; j < 128; j += 2)
            requant_tab[i][j] = (j + offsets[i]) / step * step + deltas[i];
        // Second pass: odd indices
        for (j = 1; j < 128; j += 2)
            requant_tab[i][j] = (j + offsets[i]) / step * step + deltas[i];
    }
}
