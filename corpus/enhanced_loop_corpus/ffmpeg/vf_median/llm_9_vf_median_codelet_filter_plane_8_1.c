#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint16_t *ccoarse;
extern uint16_t *cfine;
extern  int radiusV;
extern  uint8_t *srcp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < width; i++) {
    int shift = (8 + 1) / 2;
    int mask = (1 << shift) - 1;
    int coarse_index = (1 << shift) * i + (srcp[i] >> shift);
    int fine_high = width * (srcp[i] >> shift) + i;
    int fine_low = srcp[i] & mask;
    int fine_index = (1 << shift) * fine_high + fine_low;

    ccoarse[coarse_index] += radiusV + 1;
    cfine[fine_index] += radiusV + 1;

    // Additional computational work to increase arithmetic intensity
    ccoarse[coarse_index] += (srcp[i] * radiusV) >> 1;
    if (fine_index > 0) {
        cfine[fine_index - 1] += (radiusV >> 1) + 1;
    }
}
}
