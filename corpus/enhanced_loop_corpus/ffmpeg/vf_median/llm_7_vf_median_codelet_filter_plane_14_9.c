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
    int shift = (14 + 1) / 2;
    int scale = 1 << shift;
    for (int i = 0; i < width; i++) {
        int offset = i * scale;
        uint16_t src_val = srcp[i];
        int coarse_idx = offset + (src_val >> shift);
        int fine_base = width * (src_val >> shift) + i;
        int fine_idx = scale * fine_base + (src_val & (scale - 1));

        // Introduce artificial loop-carried dependency via accumulation in a temporary
        static uint16_t acc_fine = 0, acc_coarse = 0;
        acc_fine += cfine[fine_idx];
        acc_coarse += ccoarse[coarse_idx];

        cfine[fine_idx] += radiusV + 1;
        ccoarse[coarse_idx] += radiusV + 1;

        // Use accumulated values to create write-after-read and write-after-write dependencies
        cfine[fine_idx] = (acc_fine >> 1) + radiusV;
        ccoarse[coarse_idx] = (acc_coarse >> 1) + radiusV;
    }
}
