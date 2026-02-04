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
    int radius_plus_one = radiusV + 1;
    for (int i = 0; i < width; i++) {
        uint16_t src_val = srcp[i];
        int fine_index = scale * (width * (src_val >> shift) + i) + (src_val & (scale - 1));
        int coarse_index = scale * i + (src_val >> shift);
        cfine[fine_index] += radius_plus_one;
        ccoarse[coarse_index] += radius_plus_one;
    }
}
