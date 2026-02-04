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
int stride = 4;
for (int i = 0; i < width; i++) {
    int base_idx = i * stride;
    for (int s = 0; s < stride && base_idx + s < width; s++) {
        int j = base_idx + s;
        uint16_t val = srcp[j];
        int shift = (12 + 1) / 2;
        int mask = (1 << shift) - 1;
        int coarse_idx = (1 << shift) * j + (val >> shift);
        int fine_offset = (val & mask);
        int fine_idx = (1 << shift) * (width * (val >> shift) + j) + fine_offset;
        ccoarse[coarse_idx] += radiusV + 1;
        cfine[fine_idx] += radiusV + 1;
    }
}
}
