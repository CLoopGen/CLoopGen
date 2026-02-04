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
    int shift = (12 + 1) / 2;
    int coarse_scale = 1 << shift;
    int radius_plus_1 = radiusV + 1;
    for (int i = 0; i < width; i++) {
        uint16_t src_val = srcp[i];
        int fine_index = coarse_scale * (width * (src_val >> shift) + i) + (src_val & (coarse_scale - 1));
        int coarse_index = coarse_scale * i + (src_val >> shift);
        // Introduce temporary accumulators to remove immediate write dependencies
        // This eliminates potential WAW and WAR hazards by deferring updates
        uint16_t temp_fine = cfine[fine_index];
        uint16_t temp_coarse = ccoarse[coarse_index];
        temp_fine += radius_plus_1;
        temp_coarse += radius_plus_1;
        cfine[fine_index] = temp_fine;
        ccoarse[coarse_index] = temp_coarse;
    }
}
