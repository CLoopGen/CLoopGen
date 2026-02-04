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
extern  uint8_t *srcp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < radiusV + (jobnr != 0) * (1 + radiusV); i++) {
    for (int j = 0; j < width; j += 2) {
        if (j + 1 < width) {
            // Process two elements per iteration to increase computational intensity
            int val1 = srcp[j];
            int val2 = srcp[j+1];
            int shift = (8 + 1) / 2;
            int coarse_scale = (1 << shift);
            int fine_index1 = coarse_scale * (width * (val1 >> shift) + j) + (val1 & (coarse_scale - 1));
            int fine_index2 = coarse_scale * (width * (val2 >> shift) + (j+1)) + (val2 & (coarse_scale - 1));
            cfine[fine_index1]++;
            cfine[fine_index2]++;
            ccoarse[coarse_scale * j + (val1 >> shift)]++;
            ccoarse[coarse_scale * (j+1) + (val2 >> shift)]++;
        } else {
            // Handle leftover element
            int val = srcp[j];
            int shift = (8 + 1) / 2;
            int coarse_scale = (1 << shift);
            cfine[coarse_scale * (width * (val >> shift) + j) + (val & (coarse_scale - 1))]++;
            ccoarse[coarse_scale * j + (val >> shift)]++;
        }
    }
    srcp += src_linesize;
}
}
