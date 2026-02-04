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
    // Variant 1: Consecutive Memory Access Pattern
    // Reorganize access to cfine and ccoarse by precomputing indices and accessing elements in a more sequential manner
    // This improves cache locality by reducing stride in memory accesses.
    
    int shift = (10 + 1) / 2;
    int scale = 1 << shift;
    int mask = scale - 1;
    int radius_plus_1 = radiusV + 1;

    for (int i = 0; i < width; i++) {
        uint16_t src_val = srcp[i];
        int fine_index = scale * (width * (src_val >> shift) + i) + (src_val & mask);
        int coarse_index = scale * i + (src_val >> shift);

        // Ensure consecutive progression in updates where possible (though index depends on data)
        cfine[fine_index] += radius_plus_1;
        ccoarse[coarse_index] += radius_plus_1;
    }
}
