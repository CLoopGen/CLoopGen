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
for (int i = 0; i < width * (radiusV + 1); i++) {
    int idx = i % width;
    uint16_t val = srcp[idx];
    int shift = (9 + 1) / 2;
    int mask = (1 << shift) - 1;
    int coarse_index = ((1 << shift) * idx) + (val >> shift);
    int fine_index = ((1 << shift) * (width * (val >> shift) + idx)) + (val & mask);

    ccoarse[coarse_index] += 1;
    cfine[fine_index] += 1;
}
}
