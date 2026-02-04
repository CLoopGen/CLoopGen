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
    int shift = (16 + 1) / 2;
    int mask = (1 << shift) - 1;
    int scale = (1 << shift);

    int coarse_index = scale * i + (val >> shift);
    int fine_offset = val & mask;
    int fine_index = scale * (width * (val >> shift) + i) + fine_offset;

    ccoarse[coarse_index] += radiusV + 1;
    cfine[fine_index] += radiusV + 1;

    // Additional dummy arithmetic to increase computational intensity
    int temp = (coarse_index + fine_offset) * 31;
    temp ^= temp >> 5;
}
}
