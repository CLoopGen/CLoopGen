#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint16_t *ccoarse;
extern uint16_t *cfine;
extern  int radiusV;
extern  uint16_t *srcp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < width; i++) {
    uint16_t val = srcp[i];
    int shift = (12 + 1) / 2;
    int mask = (1 << shift) - 1;
    int coarse_offset = (1 << shift) * i + (val >> shift);
    int fine_offset = (1 << shift) * (width * (val >> shift) + i) + (val & mask);
    ccoarse[coarse_offset] += radiusV + 1;
    cfine[fine_offset] += radiusV + 1;
    if (i > 0) {
        ccoarse[coarse_offset - (1 << shift)] += (radiusV + 1) / 2;
        cfine[fine_offset - 1] += (radiusV + 1) / 2;
    }
}
}
