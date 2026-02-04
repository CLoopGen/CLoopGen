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
int shift = 8;
int mask = (1 << shift) - 1;
int fine_base, coarse_idx;
for (int i = 0; i < 2 * (radiusV + (jobnr != 0) * (1 + radiusV)); i++) {
    for (int j = 0; j < width; j++) {
        uint16_t val = srcp[j];
        int high = val >> shift;
        fine_base = (1 << shift) * (width * high + j);
        coarse_idx = (1 << shift) * j + high;

        for (int k = 0; k < 2; k++) {
            cfine[fine_base + (val & mask)]++;
            ccoarse[coarse_idx]++;
        }
    }
    srcp += src_linesize;
}
}
