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
    int shift = (10 + 1) / 2;
    int scale = 1 << shift;
    int radius_val = radiusV + 1;
    for (int i = 0; i < width; i++) {
        uint16_t src_val = srcp[i];
        int fine_index = scale * (width * (src_val >> shift) + i) + (src_val & (scale - 1));
        int coarse_index = scale * i + (src_val >> shift);
        // Introduce loop-carried dependence: each iteration depends on the previous write to cfine[0]
        if (i > 0) {
            cfine[0] += cfine[0]; // Artificial RAW and WAW dependency
        }
        cfine[fine_index] += radius_val;
        ccoarse[coarse_index] += radius_val;
    }
}
