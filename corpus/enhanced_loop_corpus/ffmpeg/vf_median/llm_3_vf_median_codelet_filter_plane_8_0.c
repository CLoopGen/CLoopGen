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
    // Variant 2: Strided Memory Access Pattern
    // Reorder the loop to iterate over color components (high/low bits) first,
    // creating a strided access pattern that groups operations by quantized intensity.
    // This enhances data reuse when multiple pixels share similar coarse values.

    int shift = (8 + 1) / 2;
    int mask = (1 << shift) - 1;
    int num_high_bins = (1 << shift);
    int num_low_bins = (1 << shift);

    uint8_t *local_srcp = srcp;

    // Outer loop over high bits (coarse intensity), inducing strided access
    for (int high = 0; high < num_high_bins; high++) {
        for (int i = 0; i < radiusV + (jobnr != 0) * (1 + radiusV); i++) {
            for (int j = 0; j < width; j++) {
                int val = local_srcp[j];
                if ((val >> shift) == high) {
                    int low = val & mask;

                    // Strided writes: each 'high' value processes all matching j
                    cfine[((1 << shift) * (width * high + j) + low)]++;
                    ccoarse[((1 << shift) * j + high)]++;
                }
            }
            local_srcp += src_linesize;
        }
        // Reset pointer for next high-bin iteration
        local_srcp = srcp;
    }
}
