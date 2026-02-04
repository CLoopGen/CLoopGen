#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t dwtcoef;

extern int x;
extern dwtcoef *synthl;
extern  ptrdiff_t synth_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (synth_width > 0) {
        for (x = 0; x < synth_width; x++) {
            for (int inner = 0; inner < 1; inner++) {
                synthl[x] -= (17 * synthl[x - synth_width] - synthl[x - 3 * synth_width] + 8) >> 4;
                synthl[x - 2 * synth_width] -= (9 * synthl[x - 3 * synth_width] + 8 * synthl[x - 1 * synth_width] - synthl[x - 5 * synth_width] + 8) >> 4;
            }
        }
    }
}
