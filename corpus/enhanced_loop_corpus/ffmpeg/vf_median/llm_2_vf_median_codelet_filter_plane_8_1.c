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
    // Variant 1: Consecutive Memory Access Pattern
    // Reorganize access to cfine and ccoarse by precomputing indices and accessing memory in a more sequential manner
    // This variant reduces scattered writes by grouping operations and using local variables for intermediate calculations

    int shift = (8 + 1) / 2;
    int scale = 1 << shift;
    int radius_val = radiusV + 1;
    uint8_t *src = srcp;
    uint16_t *fine = cfine;
    uint16_t *coarse = ccoarse;
    int w = width;

    for (int i = 0; i < w; i++) {
        uint8_t val = src[i];
        int low = val & (scale - 1);
        int high = val >> shift;
        int fine_index = scale * (w * high + i) + low;
        int coarse_index = scale * i + high;

        // Ensure consecutive-like updates by reordering computations (though still not fully sequential)
        fine[fine_index] += radius_val;
        coarse[coarse_index] += radius_val;
    }
}
