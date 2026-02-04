#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t dwtcoef;

extern int height;
extern int x;
extern int y;
extern dwtcoef *synthl;
extern  ptrdiff_t synth_width;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access using pointer arithmetic with precomputed base pointers
    dwtcoef *base = synthl + synth_width;
    for (y = 1; y < height - 1; y++) {
        dwtcoef *current_row = base;
        dwtcoef *prev_row = base - synth_width;
        dwtcoef *next_row = base + synth_width;
        for (x = 0; x < synth_width; x++) {
            current_row[x] -= (prev_row[x] + next_row[x] + 1) >> 1;
        }
        base += (synth_width << 1);
    }
}
