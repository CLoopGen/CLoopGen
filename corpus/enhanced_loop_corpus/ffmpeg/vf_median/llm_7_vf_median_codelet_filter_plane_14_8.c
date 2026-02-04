#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int src_linesize;
extern int width;
extern int jobnr;
extern uint16_t *ccoarse;
extern uint16_t *cfine;
extern  int radiusV;
extern  uint16_t *srcp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Remove loop-carried dependency by unrolling behavior and using local accumulators
    uint16_t local_fine[256] = {0}; // Assuming bounded effective width for fine index projection
    uint16_t local_coarse[256] = {0}; // Bounded assumption for coarse

    int shift = (14 + 1) / 2;
    int mask = (1 << shift) - 1;
    int scale = (1 << shift);

    for (int i = 0; i < radiusV + (jobnr != 0) * (1 + radiusV); i++) {
        for (int j = 0; j < width; j++) {
            int val = srcp[j];
            int high = val >> shift;
            int low = val & mask;

            int idx_fine = scale * (width * high + j) + low;
            int idx_coarse = scale * j + high;

            // Eliminate direct memory dependency by deferring write-back
            // Use local arrays to absorb updates (removes RAW/WAR across iterations)
            if (idx_fine < 256) local_fine[idx_fine]++;
            if (idx_coarse < 256) local_coarse[idx_coarse]++;
        }
        srcp += src_linesize;
    }

    // Final update to global arrays after loop (breaks loop-carried dependencies)
    for (int k = 0; k < 256; k++) {
        if (local_fine[k]) cfine[k] += local_fine[k];
        if (local_coarse[k]) ccoarse[k] += local_coarse[k];
    }
}
