#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int src_linesize;
extern int width;
extern int jobnr;
extern uint16_t *ccoarse;
extern uint16_t *cfine;
extern  int radiusV;
extern  uint8_t *srcp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of scattering updates across cfine and ccoarse with complex indexing,
    // accumulate changes in local arrays first, then write back consecutively.
    // This improves spatial locality and reduces cache misses.

    int shift = (8 + 1) / 2;
    int mask = (1 << shift) - 1;
    int cfine_size = (1 << shift) * width * (1 << shift);
    int ccoarse_size = (1 << shift) * width;
    
    // Use temporary arrays to batch updates in consecutive order
    uint16_t *cfine_temp = (uint16_t*)calloc(cfine_size, sizeof(uint16_t));
    uint16_t *ccoarse_temp = (uint16_t*)calloc(ccoarse_size, sizeof(uint16_t));

    uint8_t *local_srcp = srcp;
    for (int i = 0; i < radiusV + (jobnr != 0) * (1 + radiusV); i++) {
        for (int j = 0; j < width; j++) {
            int val = local_srcp[j];
            int high = val >> shift;
            int low = val & mask;

            // Sequential index calculation for cfine and ccoarse
            int cfine_idx = (1 << shift) * (width * high + j) + low;
            int ccoarse_idx = (1 << shift) * j + high;

            cfine_temp[cfine_idx]++;
            ccoarse_temp[ccoarse_idx]++;
        }
        local_srcp += src_linesize;
    }

    // Flush accumulated results back to global arrays with consecutive access
    for (int idx = 0; idx < cfine_size; idx++) {
        cfine[idx] += cfine_temp[idx];
    }
    for (int idx = 0; idx < ccoarse_size; idx++) {
        ccoarse[idx] += ccoarse_temp[idx];
    }

    free(cfine_temp);
    free(ccoarse_temp);
}
