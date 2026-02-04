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
    // Variant 1: Consecutive Memory Access Pattern
    // Reorganize access to cfine and ccoarse with local indices to promote spatial locality.
    // Precompute shift and mask values for readability and performance.
    const int shift = (9 + 1) / 2;  // Equals 5
    const int mask = (1 << shift) - 1;
    const int coarse_stride = (1 << shift);
    uint16_t *local_srcp = srcp;

    for (int i = 0; i < radiusV + (jobnr != 0) * (1 + radiusV); i++) {
        for (int j = 0; j < width; j++) {
            uint16_t val = local_srcp[j];
            int high = val >> shift;
            int low = val & mask;

            // Sequential-like access via predictable indexing
            int cfine_idx = (1 << shift) * (width * high + j) + low;
            int ccoarse_idx = coarse_stride * j + high;

            cfine[cfine_idx]++;
            ccoarse[ccoarse_idx]++;
        }
        local_srcp += src_linesize;
    }
}
