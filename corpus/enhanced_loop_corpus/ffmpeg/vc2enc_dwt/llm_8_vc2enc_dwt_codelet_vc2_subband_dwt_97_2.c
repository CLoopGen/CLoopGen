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
for (y = 0; y < synth_height; y++) {
    if (width >= 3) {
        synthl[1] -= (8 * synthl[0] + 9 * synthl[2] - synthl[4] + 8) >> 4;
        for (x = 1; x < width - 2; x += 2) {
            int idx = 2 * x;
            dwtcoef t1 = (9 * synthl[idx] + 9 * synthl[idx + 2] - synthl[idx + 4] - synthl[idx - 2] + 8) >> 4;
            synthl[idx + 1] -= t1;
            if (x + 1 < width - 2) {
                int idx2 = idx + 2;
                dwtcoef t2 = (9 * synthl[idx2] + 9 * synthl[idx2 + 2] - synthl[idx2 + 4] - synthl[idx2 - 2] + 8) >> 4;
                synthl[idx2 + 1] -= t2;
            }
        }
        if (width > 4) {
            synthl[synth_width - 1] -= (17 * synthl[synth_width - 2] - synthl[synth_width - 4] + 8) >> 4;
            synthl[synth_width - 3] -= (8 * synthl[synth_width - 2] + 9 * synthl[synth_width - 4] - synthl[synth_width - 6] + 8) >> 4;
        }
        synthl[0] += (2 * synthl[1] + 2) >> 2;
        for (x = 1; x < width - 1; x++) {
            synthl[2 * x] += (synthl[2 * x - 1] + synthl[2 * x + 1] + 2) >> 2;
        }
        if (width > 2)
            synthl[synth_width - 2] += (synthl[synth_width - 3] + synthl[synth_width - 1] + 2) >> 2;
    }
    synthl += synth_width;
}
}
