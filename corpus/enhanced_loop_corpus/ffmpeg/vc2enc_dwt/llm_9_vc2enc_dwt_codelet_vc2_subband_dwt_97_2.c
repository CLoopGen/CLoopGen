#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t dwtcoef;

extern int width;
extern int x;
extern int y;
extern dwtcoef *synthl;
extern  ptrdiff_t synth_width;
extern  ptrdiff_t synth_height;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < synth_height; y += 2) {
    if (y + 1 < synth_height) {
        // Process two rows per iteration to increase computational intensity
        dwtcoef *row0 = synthl;
        dwtcoef *row1 = synthl + synth_width;

        // First row odd update
        if (width >= 3) {
            row0[1] -= (8 * row0[0] + 9 * row0[2] - row0[4] + 8) >> 4;
            for (x = 1; x < width - 2; x++) {
                row0[2 * x + 1] -= (9 * row0[2 * x] + 9 * row0[2 * x + 2] - row0[2 * x + 4] - row0[2 * x - 2] + 8) >> 4;
            }
            row0[synth_width - 1] -= (17 * row0[synth_width - 2] - row0[synth_width - 4] + 8) >> 4;
            row0[synth_width - 3] -= (8 * row0[synth_width - 2] + 9 * row0[synth_width - 4] - row0[synth_width - 6] + 8) >> 4;

            // Second row odd update
            row1[1] -= (8 * row1[0] + 9 * row1[2] - row1[4] + 8) >> 4;
            for (x = 1; x < width - 2; x++) {
                row1[2 * x + 1] -= (9 * row1[2 * x] + 9 * row1[2 * x + 2] - row1[2 * x + 4] - row1[2 * x - 2] + 8) >> 4;
            }
            row1[synth_width - 1] -= (17 * row1[synth_width - 2] - row1[synth_width - 4] + 8) >> 4;
            row1[synth_width - 3] -= (8 * row1[synth_width - 2] + 9 * row1[synth_width - 4] - row1[synth_width - 6] + 8) >> 4;

            // Even updates for both rows
            row0[0] += (row0[1] + row0[1] + 2) >> 2;
            row1[0] += (row1[1] + row1[1] + 2) >> 2;
            for (x = 1; x < width - 1; x++) {
                int idx = 2 * x;
                row0[idx] += (row0[idx - 1] + row0[idx + 1] + 2) >> 2;
                row1[idx] += (row1[idx - 1] + row1[idx + 1] + 2) >> 2;
            }
            if (width > 2) {
                row0[synth_width - 2] += (row0[synth_width - 3] + row0[synth_width - 1] + 2) >> 2;
                row1[synth_width - 2] += (row1[synth_width - 3] + row1[synth_width - 1] + 2) >> 2;
            }
        }
        synthl += 2 * synth_width;
    } else {
        // Handle last row if synth_height is odd
        if (width >= 3) {
            synthl[1] -= (8 * synthl[0] + 9 * synthl[2] - synthl[4] + 8) >> 4;
            for (x = 1; x < width - 2; x++)
                synthl[2 * x + 1] -= (9 * synthl[2 * x] + 9 * synthl[2 * x + 2] - synthl[2 * x + 4] - synthl[2 * x - 2] + 8) >> 4;
            synthl[synth_width - 1] -= (17 * synthl[synth_width - 2] - synthl[synth_width - 4] + 8) >> 4;
            synthl[synth_width - 3] -= (8 * synthl[synth_width - 2] + 9 * synthl[synth_width - 4] - synthl[synth_width - 6] + 8) >> 4;
            synthl[0] += (synthl[1] + synthl[1] + 2) >> 2;
            for (x = 1; x < width - 1; x++)
                synthl[2 * x] += (synthl[2 * x - 1] + synthl[2 * x + 1] + 2) >> 2;
            if (width > 2)
                synthl[synth_width - 2] += (synthl[synth_width - 3] + synthl[synth_width - 1] + 2) >> 2;
        }
        synthl += synth_width;
    }
}
}
