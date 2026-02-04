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
    int coarse_offset = ((1 << 7) * idx + (val >> 7));
    int fine_offset = ((1 << 7) * (width * (val >> 7) + idx) + (val & 0x7F));
    ccoarse[coarse_offset] += 1;
    cfine[fine_offset] += 1;
}
}
