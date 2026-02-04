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



void loop(){
    for (y = 0; y < height - 1; y++) {
        dwtcoef *row = synthl + synth_width;
        for (x = 0; x < synth_width; x += 4) {
            // Unroll loop: process 4 elements per iteration
            if (x + 0 < synth_width) row[x + 0] -= (9 * synthl[x + 0] + 9 * synthl[x + 0 + 2 * synth_width] - 
                                                    synthl[x + 0 - 2 * synth_width] - synthl[x + 0 + 4 * synth_width] + 8) >> 4;
            if (x + 1 < synth_width) row[x + 1] -= (9 * synthl[x + 1] + 9 * synthl[x + 1 + 2 * synth_width] - 
                                                    synthl[x + 1 - 2 * synth_width] - synthl[x + 1 + 4 * synth_width] + 8) >> 4;
            if (x + 2 < synth_width) row[x + 2] -= (9 * synthl[x + 2] + 9 * synthl[x + 2 + 2 * synth_width] - 
                                                    synthl[x + 2 - 2 * synth_width] - synthl[x + 2 + 4 * synth_width] + 8) >> 4;
            if (x + 3 < synth_width) row[x + 3] -= (9 * synthl[x + 3] + 9 * synthl[x + 3 + 2 * synth_width] - 
                                                    synthl[x + 3 - 2 * synth_width] - synthl[x + 3 + 4 * synth_width] + 8) >> 4;
        }
        synthl += synth_width << 1;
    }
}
