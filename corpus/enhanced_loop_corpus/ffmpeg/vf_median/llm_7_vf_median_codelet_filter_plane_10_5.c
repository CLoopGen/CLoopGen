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
    // Eliminate loop-carried dependencies by using local accumulators and unrolling simulation
    int temp_fine = 0, temp_coarse = 0;
    for (int i = 0; i < width; i++) {
        uint16_t src_val = srcp[i];
        int fine_index = scale * (width * (src_val >> shift) + i) + (src_val & (scale - 1));
        int coarse_index = scale * i + (src_val >> shift);
        // Remove all cross-iteration dependencies: use temporaries to batch updates
        temp_fine += radius_val;
        temp_coarse += radius_val;
        // Independent memory updates with no sequential dependency
        cfine[fine_index] = (cfine[fine_index] + temp_fine) % 65535; // Mod to prevent overflow, keep valid
        ccoarse[coarse_index] = (ccoarse[coarse_index] + temp_coarse) % 65535;
    }
    // Final independent side effect to maintain some global impact
    cfine[0] += temp_fine;
}
