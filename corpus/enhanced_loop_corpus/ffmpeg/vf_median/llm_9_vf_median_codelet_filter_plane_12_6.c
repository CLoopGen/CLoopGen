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
for (int i = 0; i < (radiusV + (jobnr != 0) * (1 + radiusV)) / 2; i++) {
    for (int j = 0; j < width; j++) {
        uint16_t val = srcp[j];
        int shift = (12 + 1) / 2;
        int mask = (1 << shift) - 1;
        int coarse_idx = (1 << shift) * j + (val >> shift);
        int fine_base = (1 << shift) * (width * (val >> shift) + j);
        int fine_idx = fine_base + (val & mask);

        ccoarse[coarse_idx] += 2;
        cfine[fine_idx] += 2;

        val = srcp[src_linesize + j];
        coarse_idx = (1 << shift) * j + (val >> shift);
        fine_idx = fine_base = (1 << shift) * (width * (val >> shift) + j) + (val & mask);

        ccoarse[coarse_idx]++;
        cfine[fine_idx]++;
    }
    srcp += 2 * src_linesize;
}
}
