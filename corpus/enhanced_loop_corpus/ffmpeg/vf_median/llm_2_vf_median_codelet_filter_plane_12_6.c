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
    // Reorganize the access to cfine and ccoarse by precomputing base indices and accessing elements in a more sequential manner.
    uint16_t *srcp_local = srcp;
    int shift = (12 + 1) / 2;
    int mask = (1 << shift) - 1;
    int coarse_scale = (1 << shift);
    int fine_base_shift = (1 << shift);

    for (int i = 0; i < radiusV + (jobnr != 0) * (1 + radiusV); i++) {
        for (int j = 0; j < width; j++) {
            uint16_t val = srcp_local[j];
            int high = val >> shift;
            int low = val & mask;

            // Make cfine access more predictable by simplifying index arithmetic
            int fine_idx = fine_base_shift * (width * high + j) + low;
            int coarse_idx = coarse_scale * j + high;

            cfine[fine_idx]++;
            ccoarse[coarse_idx]++;
        }
        srcp_local += src_linesize;
    }
}
